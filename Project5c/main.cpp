#include <iostream>
#include <limits.h>
#include <vector>
#include <list>
#include <fstream>
#include <queue>
#include <stack>


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
   pair<int,int> cell; // maze cell (x,y) value
   Vertex pred; // predecessor node
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

#include "heapV.h"

void initializeGraph(Graph &g,
    Vertex &start,
    Vertex &end, ifstream &fin)
// Initialize g using data from fin.  Set start and end equal
// to the start and end nodes.
{
    Edge e;

    int n, i, j;
    int startId, endId;
    fin >> n;
    fin >> startId >> endId;
    Vertex v;

    // Add nodes.
    for (int i = 0; i < n; i++)
    {
        v = add_vertex(g);
    
        if (i == startId)
        start = v;
        if (i == endId)
        end = v;
    }


    while (fin.peek() != '.')
    {
        fin >> i >> j;

        pair <Edge, bool> newEdge = add_edge(i,j,g);
        e = newEdge.first;
        fin >> g[e].weight;
    }
}

void initSingleSource(Graph &g, Vertex start)
// Set all node weights to w, except source node
{
  pair <vertex_iterator, vertex_iterator> vItrRange = vertices(g);
  for (vertex_iterator vItr = vItrRange.first; vItr != vItrRange.second; ++vItr)
  {
    if (*vItr == start)
      g[*vItr].weight = 0; //Init-Single-Source: sets source node's weight to 0
    else g[*vItr].weight = LargeValue;
  }
}

void relax(Graph &g, Vertex u, Vertex v)
{
    pair <Edge, bool> checkEdge = edge(u, v, g);
    Edge e = checkEdge.first;
    if (g[v].weight > g[u].weight + g[e].weight)
    {
        g[v].weight = g[u].weight + g[e].weight;
            cout << "the weight of vertex " << v << " is now " << g[v].weight << endl;
        g[v].pred = u;
            cout << "the predecessor to vertex " << v << " is now " << u << endl << endl;
    }
}

bool bellmanFord(Graph &g, Vertex s, Vertex goal, stack<Vertex> &moves)
{
  initSingleSource(g, s);
  pair <edge_iterator, edge_iterator> eItrRange = edges(g);

  int size = num_vertices(g);

  for(int i = 1; i < size; i++)
  { 
    cout << "Round " << i << endl << endl;
    for (edge_iterator eItr = eItrRange.first; eItr != eItrRange.second; ++eItr)
    {
        Vertex u = source(*eItr, g);
        cout << "vertex u is " << u << endl;
        Vertex v = target(*eItr, g);
        cout << "vertex v is " << v << endl << endl;
        relax(g, u, v);
    }
  }

  for(edge_iterator eItr = eItrRange.first; eItr != eItrRange.second; ++eItr)
  {
      Vertex u = source(*eItr, g);
      Vertex v = target(*eItr, g);
      if(g[v].weight > g[u].weight + g[*eItr].weight)
          return false;
      //else return true;
  }
  
  Vertex curr = goal;
  while(curr != s)
  {
    moves.push(curr);
    curr = g[curr].pred;
  }
  moves.push(s);
  return true;
}

bool dijkstra(Graph &g, Vertex start, Vertex goal, stack<Vertex> &moves)
{
    initSingleSource(g, start);

    stack <Vertex> s;
    vector <Vertex> v;

    pair <vertex_iterator, vertex_iterator> vItrRange = vertices(g);
    for (vertex_iterator vItr = vItrRange.first; vItr != vItrRange.second; ++vItr)
    {
        v.push_back(*vItr);
    }

    heapV<Vertex, Graph> pq;
    pq.initializeMinHeap(v, g);

/*     cout << pq << endl;
    return true; */

    while(pq.size() != 0)
    {
        Vertex u = pq.extractMinHeapMinimum(g);
        s.push(u);
        pair <adj_iterator, adj_iterator> adjV = adjacent_vertices(u, g);
        for(adj_iterator vItr = adjV.first; vItr != adjV.second; ++vItr)
        {
            pair <Edge, bool> newEdge = edge(u, *vItr, g);
            Edge e = newEdge.first;
            if(g[e].weight < 0)
                return false;
            else relax(g, u, *vItr);
        }
    }
    //cout << pq << endl;

    Vertex curr = goal;
    while(curr != start)
    {
      moves.push(curr);
      curr = g[curr].pred;
    }
    moves.push(start);

    return true;

}

void printPath(stack <Vertex> &s, Graph &g)
{
    if(s.empty())
    {
        cout << "No path exists." << endl;
    }

    while(!s.empty())
    {
        Vertex u = s.top();
        s.pop();
        cout << u << endl;
    }
}

int main()
{
    try
    {
        ifstream fin;

        string fileName = "graph/graph7.txt";

        fin.open(fileName.c_str());
        if(!fin)
        {
            cerr << "Cannot open " << fileName << endl;
            exit(1);
        }

        Graph g;
        Vertex start, end;

        initializeGraph(g, start, end, fin);
        fin.close();

        cout << "Start vertex is " << start << endl;
        cout << "End vertex is " << end << endl << endl;

        int num = num_vertices(g);
        cout << "This graph has " << num << " vertices" << endl;

         stack <Vertex> moves;
/*        if (!bellmanFord(g, start, end, moves))
            cout << "Negative cycles reachable from source." << endl;
        else 
        {
            cout << "Shortest path: " << endl;
            printPath(moves, g);
        } */
        
        if (!dijkstra(g, start, end, moves))
            cout << "Negative edge weights. Use Bellman-Ford for this graph." << endl;
        else 
        {
            cout << "Shortest path: " << endl;
            printPath(moves, g);
        }    
    }
    catch(const std::exception& e)
    {
        int x = 0;
    }
}