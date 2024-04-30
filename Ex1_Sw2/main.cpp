#include <iostream>
#include <queue>
#include "Graph.hpp"
#include "Algorithms.hpp"
#include "vector"
#include "Traverse.hpp"
using namespace std;

int main() {

    Graph g;
    vector<vector<int>> graph = {
           //0  1  2
            {0, 1, 0},
            {1, 0, 1},
            {0, 1,0}};

    g.load_graph(graph);
  //  int ans1=Algorithms::isConnected(g);
   // Algorithms::shortestPath(g,0,2);
    Algorithms::isBipartite(g);
   //   cout<<ans1<<endl;

    return 0;
}