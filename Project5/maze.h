// Project 5b--Alina Rossi-Conaway & Dan Bartels

#include <iostream>
#include <limits.h>
#include <list>
#include <fstream>
#include <queue>
#include <vector>
#include <stack>

#include <boost/graph/adjacency_list.hpp>
#include "d_except.h"
#include "d_matrix.h"
using namespace std;
using namespace boost;

#define LargeValue 99999999

typedef adjacency_list<vecS, vecS, bidirectionalS, vertexProperties, edgeProperties> Graph;
typedef Graph::vertex_descriptor Vertex;
typedef Graph::edge_descriptor Edge;
typedef Graph::edge_iterator edge_iterator;
typedef Graph::vertex_iterator vertex_iterator;
typedef Graph::adjacency_iterator adj_iterator;

class maze
{
public:
   maze(ifstream &fin);
   void print(int,int,int,int);
   bool isLegal(int i, int j);
   void mapMazeToGraph(Graph &g);
   void printPath(Vertex end,
                  stack<Vertex> &s,
                  Graph g);
   int numRows(){return rows;};
   int numCols(){return cols;};
   Vertex getNode(int i, int j){return nodes[i][j];};
   void addEdges(Vertex v, Graph &g);
   void verify(int i, int j, Vertex v, Graph &g);
   friend ostream &operator<<(ostream &ostr, const Graph &g);
   void clearVisited(Graph &g);
   void clearMarked(Graph &g);
   bool findPathDFSRecursive(Graph &g, 
                            Vertex start, 
                            Vertex goal, 
                            stack <Vertex> &moves);
   bool findPathDFSRecursive2(Graph &g, Vertex start, Vertex goal, stack <Vertex> &moves);
   bool findPathDFSStack(Graph &g, Vertex start, Vertex goal, stack <Vertex> &moves);
   bool findShortestPathDFS(Graph &g, Vertex start, Vertex goal, stack<Vertex> &bestMoves);
   bool findShortestPathBFS(Graph &g, Vertex start, Vertex goal, stack<Vertex> &moves);
  private:
   int rows; // number of rows in the maze
   int cols; // number of columns in the maze
   
   matrix<bool> value;
   matrix<Vertex> nodes;
};

maze::maze(ifstream &fin)
// Initializes a maze by reading values from fin.  Assumes that the
// number of rows and columns indicated in the file are correct.
{
   fin >> rows;
   fin >> cols;
   
   char x;
   
   value.resize(rows, cols);
   nodes.resize(rows, cols);
   for (int i = 0; i <= rows-1; i++)
   {
      for (int j = 0; j <= cols-1; j++)
      {
         fin >> x;
         if (x == 'O')
            value[i][j] = true;
         else
            value[i][j] = false;
      }
    }
}

void maze::print(int goalI, int goalJ, int currI, int currJ)
// Print out a maze, with the goal and current cells marked on the
// board.
{
   cout << endl;

   if (goalI < 0 || goalI > rows || goalJ < 0 || goalJ > cols)
      throw rangeError("Bad value in maze::print");

   if (currI < 0 || currI > rows || currJ < 0 || currJ > cols)
      throw rangeError("Bad value in maze::print");

   for (int i = 0; i <= rows-1; i++)
   {
      for (int j = 0; j <= cols-1; j++)
      {
        if (i == goalI && j == goalJ)
           cout << "*";
        else
           if (i == currI && j == currJ)
              cout << "+";
           else
              if (value[i][j])
                cout << " ";
              else
                cout << "X";	  
      }
      cout << endl;
   }
   cout << endl;
}

bool maze::isLegal(int i, int j)
// Return the value stored at the (i,j) entry in the maze, indicating
// whether it is legal to go to cell (i,j).
{
   if (i < 0 || i > rows || j < 0 || j > cols)
      throw rangeError("Bad value in maze::isLegal");

   return value[i][j];
}

void maze::mapMazeToGraph(Graph &g)
// Create a graph g that represents the legal moves in the maze m.
{
  //Create a vertex for each free space
  for (int i = 0; i < rows; i++) 
  {
    for (int j = 0; j < rows; j++)
    {
      if (isLegal(i, j))
      {
        Vertex v1 = add_vertex(g); // adds vertex to graph g
        g[v1].cell = make_pair(i, j); // stores the cell values for vertex in the 'cell' member of the vertexProperties struct
        nodes[i][j] = v1; //stores vertex descriptor in data structure nodes, with indices corresponding to the cell
      }
    }
  }

  pair<vertex_iterator, vertex_iterator> vItrRange = vertices(g);

  for (vertex_iterator vItr= vItrRange.first; vItr != vItrRange.second; ++vItr)
  {
      addEdges(*vItr, g);
  }
}

void maze::printPath(Vertex end, stack<Vertex> &s, Graph g)
// Print the path represented by the vertices in stack s
{
  if(s.empty())
  {
    cout << "No path exists." << endl;
  }

  int goalI = g[end].cell.first;
  int goalJ = g[end].cell.second;

  while (!s.empty())
  {
    Vertex u = s.top();
    s.pop();
    int currI = g[u].cell.first;
    int currJ = g[u].cell.second;
    print(goalI, goalJ, currI, currJ);
  }
}

void maze::addEdges(Vertex v, Graph &g)
// Calls verify function to define edges coming outward from Vertex v
{
  int i = g[v].cell.first;
  int j = g[v].cell.second;
  
  verify(i+1, j, v, g);
  verify(i-1, j, v, g);
  verify(i, j+1, v, g);
  verify(i, j-1, v, g);
}

void maze::verify(int i, int j, Vertex v, Graph &g)
// Helper function to check whether it is legal to add edges from v in all directions
{
  if(i >= 0 && i < numRows() && j >= 0 && j < numCols())
  {
    if(isLegal(i, j))
    {
      Vertex next = getNode(i, j);
      pair<Edge, bool> checkEdge = edge(v, next, g);
      {
        if (!checkEdge.second) // checks to see if edge exists
        {
          pair <Edge, bool> newEdge = add_edge(v, next, g);
        }
      } 
    }
  }
}

ostream &operator<<(ostream &ostr, const Graph &g)
//Prints vertices and their properties, edges and their properties
{
  ostr << "Vertices: " << endl;
  pair <vertex_iterator, vertex_iterator> vItrRange = vertices(g);
  for (vertex_iterator vItr = vItrRange.first; vItr != vItrRange.second; ++vItr)
  {
    ostr << "Vertex " << *vItr << ":" << endl;
    ostr << " -Cell: (" << g[*vItr].cell.first << ", " << g[*vItr].cell.second << ")" << endl;
    ostr << " -Predecessor: Vertex " << g[*vItr].pred << endl;
    ostr << " -Weight: " << g[*vItr].weight << endl;
    ostr << " -Visited: " << g[*vItr].visited << endl;
    ostr << " -Marked: " << g[*vItr].marked << endl;
  }
  ostr << endl;
  ostr << "Edges: " << endl;

  pair <edge_iterator, edge_iterator> eItrRange = edges(g);
  for (edge_iterator eItr = eItrRange.first; eItr != eItrRange.second; ++eItr)
  {
    ostr << "Edge " << *eItr << ":" << endl;
    ostr << " -Weight: " << g[*eItr].weight << endl;
    ostr << " -Visited: " << g[*eItr].visited << endl;
    ostr << " -Marked: " << g[*eItr].marked << endl;
  }
  return ostr;
}

void maze::clearVisited(Graph &g)
// Mark all nodes in g as not visited.
{
  pair <vertex_iterator, vertex_iterator> vItrRange = vertices(g);
  for (vertex_iterator vItr = vItrRange.first; vItr != vItrRange.second; ++vItr)
  {
    g[*vItr].visited = false;
  }
}

void maze::clearMarked(Graph &g)
// Mark all nodes in g as not marked
{
  {
    pair <vertex_iterator, vertex_iterator> vItrRange = vertices(g);
    for (vertex_iterator vItr = vItrRange.first; vItr != vItrRange.second; ++vItr)
    {
      g[*vItr].marked = false;
    }
  }
}

bool maze::findPathDFSRecursive(Graph &g, Vertex start, Vertex goal, stack <Vertex> &moves)
// Helper function to call the main findPathDFSRecursive2 function
{
  clearVisited(g);
  return findPathDFSRecursive2(g, start, goal, moves);
}

bool maze::findPathDFSRecursive2(Graph &g, Vertex start, Vertex goal, stack <Vertex> &moves)
// Uses recursion to find a path from start to goal
{
  if (start == goal) //done!
    return true;
  else
  {
    g[start].visited = true;
    bool found = false;
    pair<adj_iterator, adj_iterator> vItrRange = adjacent_vertices(start, g);
    adj_iterator vItr = vItrRange.first;
    while (vItr != vItrRange.second && found == false) //triggers recursion
    {
      if (!g[*vItr].visited)
      {
        found = findPathDFSRecursive2(g, *vItr, goal, moves);
      }
      vItr++;
    }
    if (found)
      moves.push(start);
    return found;
  }
}

bool maze::findPathDFSStack(Graph &g, Vertex start, Vertex goal, stack <Vertex> &moves)
// Iteratively finds path from start to goal and stores path in stack
{
  clearMarked(g);
  clearVisited(g);
  adj_iterator vItr;
  if (start == goal)
    return true;

  moves.push(start);
  while (!moves.empty())
  {
    Vertex u = moves.top();
    moves.pop();
    if (!g[u].visited)
    {
      g[u].visited = true;
      pair <adj_iterator, adj_iterator> vItrRange = adjacent_vertices(u, g);
      for (vItr = vItrRange.first; vItr != vItrRange.second; ++vItr)
      {
        if(!g[*vItr].visited)
        {          
          cout << "adding vertex " << *vItr << " to stack" << endl;
          moves.push(*vItr); 
          g[*vItr].pred = u;
        }
      }
    }
  }
  
  Vertex curr = g[goal].pred;
  while (curr != start)
  {
    moves.push(curr);
    curr = g[curr].pred;
  }
  moves.push(start);
  return true;
}

bool maze::findShortestPathBFS(Graph &g, Vertex start, Vertex goal, stack<Vertex> &moves)
// Finds shortest path using BFS. First path found is the shortest
{
  clearVisited(g);
  clearMarked(g);
  queue <Vertex> q;
  if (start == goal)
    return true;
  q.push(start);
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
  Vertex curr = goal;
  while(curr != start)
  {
    moves.push(curr);
    curr = g[curr].pred;
  }
  moves.push(start);
  return true;
}

bool maze::findShortestPathDFS(Graph &g, Vertex start, Vertex goal, stack<Vertex> &moves)
// Finds shortest path using DFS. Does so by weighting the edges and determining the shortest distance from the source to every node
{
  if(start == goal)
    return true;
  moves.push(start);
  while(!moves.empty())
  {
    Vertex u = moves.top();
    moves.pop();
    if(!g[u].visited)
    {
      g[u].visited = true;
      pair <adj_iterator, adj_iterator> vItrRange = adjacent_vertices(u, g);
      for(adj_iterator vItr = vItrRange.first; vItr != vItrRange.second; ++vItr)
      {
        if(!g[*vItr].visited)
        {
          moves.push(*vItr);
          pair<Edge, bool> checkEdge = edge(*vItr, u, g);
          if(g[*vItr].weight > g[u].weight + g[checkEdge.first].weight)
          {
            g[*vItr].weight = g[u].weight + g[checkEdge.first].weight;
            g[*vItr].pred = u;
          }
        }
      }      
    } 
  }
  Vertex curr = goal;
  while (curr != start)
  {
    moves.push(curr);
    curr = g[curr].pred;
  }
  moves.push(start);
  return true;
}

