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

void setNodeWeights(Graph &g, int w)
// Set all node weights to w, except source node
{
  pair <vertex_iterator, vertex_iterator> vItrRange = vertices(g);
  for (vertex_iterator vItr = vItrRange.first; vItr != vItrRange.second; ++vItr)
  {
    if (vItr == vItrRange.first)
      g[*vItr].weight = 0; //Init-Single-Source: sets source node's weight to 0
    else g[*vItr].weight = w;
  }
}

void setEdgeWeights(Graph &g, int w)
// Set all edge weights to w 
{
  pair <edge_iterator, edge_iterator> eItrRange = edges(g);
  for (edge_iterator eItr = eItrRange.first; eItr != eItrRange.second; ++eItr)
  {
    g[*eItr].weight = w;
  }
}
   
int main()
{
    try
    {
       ifstream fin;
   
       // Read the maze from the file.
       string fileName = "maze-files/maze1.txt";
       
       fin.open(fileName.c_str()); 
       if (!fin) // Error handling
       {
          cerr << "Cannot open " << fileName << endl;
          exit(1);
       }
   
       maze m(fin);
       fin.close();
       
       m.print(m.numRows()-1,m.numCols()-1,0,0);
   
       Graph g;
       m.mapMazeToGraph(g);

       stack <Vertex> moves;

       //Define start and end nodes based on position in matrix
       Vertex start = m.getNode(0,0);
       Vertex end = m.getNode(m.numRows()-1, m.numCols()-1);

       m.findPathDFSRecursive(g, start, end, moves);
       m.findPathDFSStack(g, start, end, moves);
       m.findShortestPathBFS(g, start, end, moves);
       

       // Init single source for use with findShortestPathDFS
       setNodeWeights(g, LargeValue); 
       setEdgeWeights(g, 1);
       
       m.findShortestPathDFS(g, start, end, moves);
       m.printPath(end, moves, g);
    }
    catch (const std::exception& e)
    {
      int x = 0;
    }
}
