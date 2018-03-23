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

#define LargeValue 99999999

/*
void clearVisited(Graph &g)
// Mark all nodes in g as not visited.
{
  pair <vertex_iterator, vertex_iterator> vItrRange = vertices(g);
  for (vertex_iterator vItr = vItrRange.first; vItr != vItrRange.second; ++vItr)
  {
    g[*vItr].visited = false;
  }
}
*/

void setNodeWeights(Graph &g, int w)
// Set all node weights to w.
{
  pair <vertex_iterator, vertex_iterator> vItrRange = vertices(g);
  for (vertex_iterator vItr = vItrRange.first; vItr != vItrRange.second; ++vItr)
  {
    g[*vItr].weight = w;
  }
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
       m.clearVisited(g);
       //setNodeWeights(g, 5);

       stack <Vertex> moves;
       Vertex start = m.getNode(0,0);
       cout << "starting node is " << start << endl;
       Vertex end = m.getNode(m.numRows()-1, m.numCols()-1);
       cout << "ending node is " << end << endl;
       m.findPathDFSRecursive(g, start, end, moves);
       m.printPath(end, moves, g);
/*
       pair <vertex_iterator, vertex_iterator> vItrRange = vertices(g);
       for (vertex_iterator vItr = vItrRange.second; vItr != vItrRange.first; vItr--)
       {
         if (*vItr == 9 ||
              *vItr == 8 ||
              *vItr == 6 ||
              *vItr == 5 ||
              *vItr == 3 ||
              *vItr == 2 ||
              *vItr == 1 ||
              *vItr == 0)
              s.push(g[*vItr]);
       }

       Vertex end = m.getNode(m.numRows()-1, m.numCols()-1);
       m.printPath(end, s, g);
*/
       //cout << g;
   
      // cout << " the number of vertices in graph g is " << num_vertices(g) << endl;
       //cout << " the number of edges in graph g is " << num_edges(g) << endl;
    }
    catch (const std::exception& e)
    {
      int x = 0;
    }
}
