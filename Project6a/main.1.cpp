#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include "limits.h"
#include "d_except.h"
#include <list>

#include <boost/graph/adjacency_list.hpp>
using namespace boost;
using namespace std;

#define LargeValue 999999999

struct vertexProperties;
struct edgeProperties;

typedef adjacency_list<vecS, vecS, directedS, vertexProperties, edgeProperties> Graph;
typedef Graph::vertex_descriptor Vertex;
typedef Graph::edge_descriptor Edge;
typedef Graph::edge_iterator edge_iterator;
typedef Graph::vertex_iterator vertex_iterator;
typedef Graph::adjacency_iterator adj_iterator;

struct vertexProperties
{
   //pair<int,int> cell; // maze cell (x,y) value
   vertex_iterator pred; // predecessor node
   int weight;
   bool visited;
   bool marked;
};

// Create a struct to hold properties for each edge
struct edgeProperties
{
   int weight;
   bool visited;
   bool marked;
};

void clearVisited(Graph &g)
{
    pair <vertex_iterator, vertex_iterator> vItrRange = vertices(g);
    for (vertex_iterator vItr = vItrRange.first; vItr != vItrRange.second; ++vItr)
    {
        g[*vItr].visited = false;
    }
}

void initializeGraph(Graph &g, ifstream &fin)
// Initialize g using data from fin.  Set start and end equal
// to the start and end nodes.
{
    Edge e;
    Vertex v;

    int n, i, j;
    fin >> n;


    // Add nodes.
    for (int i = 0; i < n; i++)
    {
        v = add_vertex(g);
        g[v].pred = NULL;
    }

    while (fin.peek() != '.')
    {
        fin >> i >> j;

        pair <Edge, bool> newEdge = add_edge(i,j,g);
        e = newEdge.first;
        fin >> g[e].weight;
    }
}

void traverseDFSconnected(Graph &g)
{
    stack <Vertex> s;
    pair <vertex_iterator, vertex_iterator> vItrRange = vertices(g);
    vertex_iterator u = vItrRange.first;
    s.push(*u);

    while (!s.empty())
    {
        Vertex v = s.top();
        s.pop();
        if(!g[v].visited)
        {
            g[v].visited = true;
            pair <adj_iterator, adj_iterator> vItrRange = adjacent_vertices(v, g);
            for(adj_iterator vItr = vItrRange.first; vItr != vItrRange.second; ++vItr)
            {
                if(!g[*vItr].visited)
                {
                    s.push(*vItr);
                    g[*vItr].pred = v;

                }
            }
        }
    }
}

bool traverseDFScyclic(Graph &g)
{
    stack <Vertex> s;
    pair <vertex_iterator, vertex_iterator> vItrRange = vertices(g);
    vertex_iterator u = vItrRange.first;
    s.push(*u);

    while (!s.empty())
    {
        Vertex v = s.top();
        s.pop();
        if(!g[v].visited)
        {
            g[v].visited = true;

            //cout << "looking at vertices adjacent to " << v << endl;
            pair <adj_iterator, adj_iterator> vItrRange = adjacent_vertices(v, g);
            for(adj_iterator vItr = vItrRange.first; vItr != vItrRange.second; ++vItr)
            {
                if(g[*vItr].visited && *vItr != g[v].pred)
                {
                    //cout << "vertex " << *vItr << " has been visited but is not the predecessor to vertex " << v << endl;
                    return true;
                }
                if(!g[*vItr].visited)
                {
                    s.push(*vItr);
                    g[*vItr].pred = v;

                    //cout << "Adding vertex " << *vItr << " to stack" << endl;
                    //cout << "The predecessor to " << *vItr << " is now " << v << endl << endl;
                }
            }
        }
    }
    return false;
}

void traverseBFS_SF(Graph &g)
{
    clearVisited(g);
    queue <Vertex> q;
    pair <vertex_iterator, vertex_iterator> vItrRange = vertices(g);
    for (vertex_iterator vItr = vItrRange.first; vItr != vItrRange.second; ++vItr)
    {
        q.push(*vItr);
        while(!q.empty())
        {
            Vertex u = q.front();
            q.pop();

            if (!g[u].visited)
            {

                g[u].visited = true;
                pair<adj_iterator, adj_iterator> vItrRange = adjacent_vertices(u, g);
                for (adj_iterator vItr = vItrRange.first; vItr != vItrRange.second; ++vItr)
                {
                    if(!g[*vItr].visited)
                    {

                        g[*vItr].pred = u;
                        q.push(*vItr);
                    }
                }
            }
    }
}
}

bool isConnected(Graph &g)
{
    traverseDFSconnected(g);
    pair <vertex_iterator, vertex_iterator> vItrRange = vertices(g);
    for (vertex_iterator vItr = vItrRange.first; vItr != vItrRange.second; ++vItr)
    {
        if (!g[*vItr].visited)
            return false;
    }
    return true;
}

bool isCyclic(Graph &g)
{
    if(traverseDFScyclic(g))
        return true;
    else return false;
}

void printGraph(Graph &g)
{
    pair <edge_iterator, edge_iterator> eItrRange = edges(g);
    for (edge_iterator eItr = eItrRange.first; eItr != eItrRange.second; ++eItr)
    {
        cout << source(*eItr, g) << " " << target(*eItr, g) << " " << g[*eItr].weight << endl;
    }
    cout << endl;
}


void findSpanningForest(Graph &g, Graph &sf)
{
    traverseBFS_SF(g);
    int size = num_vertices(g);
    for(int i = 0; i < size; i++)
    {
        Vertex v1 = add_vertex(sf);
    }
    pair <vertex_iterator, vertex_iterator> vItrRange = vertices(g);
    for (vertex_iterator vItr = vItrRange.first; vItr != vItrRange.second; ++vItr)
    {
        if(g[*vItr].pred != *vItr)
        {
            pair <Edge, bool> refEdge = edge(g[*vItr].pred, *vItr, g);
            pair <Edge, bool> newEdge = add_edge(g[*vItr].pred, *vItr, sf);
            sf[newEdge.first].weight = g[refEdge.first].weight;
        }
    }

}

int main()
{
    try
    {
        ifstream fin;

        string fileName = "graph2.txt";

        fin.open(fileName.c_str());
        if(!fin)
        {
            cerr << "Cannot open " << fileName << endl;
            exit(1);
        }

        Graph g;

        initializeGraph(g, fin);
        fin.close();

        printGraph(g);

        int numV = num_vertices(g);
        int numE = num_edges(g);
        cout << "This graph has " << numV << " vertices and " << numE << " edges" << endl;

        clearVisited(g);

        if(!isConnected(g))
            cout << "This graph is not connected " << endl;
        else cout << "This graph is connected " << endl;

        clearVisited(g);

        if(isCyclic(g))
            cout << "This graph contains cycles" << endl;
        else cout << "This graph does not contain cycles " << endl;

        Graph sf;
        //traverseBFS_SF(g, sf);
        findSpanningForest(g, sf);

        cout << "\nSpanning Tree: " << endl;
        printGraph(sf);
    }

    catch(const std::exception& e)
    {
        int x = 0;
    }
}