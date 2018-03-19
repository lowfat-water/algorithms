#include <iostream>
#include <limits.h>
#include <vector>
#include <list>
#include <fstream>
#include <queue>

#include <boost/graph/adjacency_list.hpp>
using namespace boost;
using namespace std;

struct vertexProperties;
struct edgeProperties;

typedef adjacency_list<vecS, vecS, bidirectionalS, vertexProperties, edgeProperties> Graph;
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

#include "maze.h"
//typedef adjacency_list<vecS, vecS, bidirectionalS, vertexProperties, edgeProperties> Graph;

// typedef property<edge_weight_t, int> EdgeProperty;

#define LargeValue 99999999

void clearVisited(Graph &g)
// Mark all nodes in g as not visited.
{
  // TODO: finish
  int x = 0;
}

void setNodeWeights(Graph &g, int w)
// Set all node weights to w.
{
  // TODO: finish
  int x = 0;
}

void clearMarked(Graph &g)
{
  // TODO: finish
  int x = 0;
}
   
int main()
{
    try
    {
       ifstream fin;
   
       // Read the maze from the file.
       string fileName = "maze-files/maze13.txt";
       
       fin.open(fileName.c_str());
       if (!fin)
       {
          cerr << "Cannot open " << fileName << endl;
          exit(1);
       }
   
       maze m(fin);
       fin.close();
       
       m.print(m.numRows()-1,m.numCols()-1,0,0);
   
       Graph g;
       m.mapMazeToGraph(g);
   
      // cout << " the number of vertices in graph g is " << num_vertices(g) << endl;
       //cout << " the number of edges in graph g is " << num_edges(g) << endl;
       //cout << " the locations of the vertices are: " << endl;
       pair<vertex_iterator, vertex_iterator> vItrRange = vertices(g);
       for (vertex_iterator vItr = vItrRange.first; vItr != vItrRange.second; ++vItr)
       {
         //cout << "vertex " << *vItr << " located at cell (" << g[*vItr].cell.first << ", " << g[*vItr].cell.second << "]" << endl; 
         //int i = g[*vItr].cell.first;
         //int j = g[*vItr].cell.second;
         //cout << "vertex " << *vItr << " located at cell (" << i << ", " << j << "]" << endl; 
         
         //cout << "vertex " << m.getNode(i,j) << " located at cell (" << i << ", " << j << ")" << endl;
       }

       // cout << g << endl;
    }
    catch (const std::exception& e)
    {
      int x = 0;
    }
}
