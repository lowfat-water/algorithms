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
    }

    while (fin.peek() != '.')
    {
        fin >> i >> j;

        pair <Edge, bool> newEdge = add_edge(i,j,g);
        e = newEdge.first;
        fin >> g[e].weight;
    }
}

int main()
{
    try
    {
        ifstream fin;

        string fileName = "graph1.txt";

        fin.open(fileName.c_str());
        if(!fin)
        {
            cerr << "Cannot open " << fileName << endl;
            exit(1);
        }

        Graph g;

        initializeGraph(g, fin);
        fin.close();

        int numV = num_vertices(g);
        int numE = num_edges(g);
        cout << "This graph has " << numV << " vertices and " << numE << " edges" << endl;
    }

    catch(const std::exception& e)
    {
        int x = 0;
    }
}