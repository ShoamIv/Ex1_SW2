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
    vector<vector<int>> graph2 = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};

    vector<vector<int>> graph3 = {
            {0, 1, 0, 0, 0},
            {1, 0, 3, 0, 0},
            {0, 3, 0, 4, 0},
            {0, 0, 4, 0, 5},
            {0, 0, 0, 5, 0}};
    g.load_graph(graph2);

      //int ans1=Algorithms::isConnected(g);
    //Algorithms::shortestPath(g,0,2);
    Algorithms::isConnected(g);
    Algorithms ::shortestPath(g, 0, 4);
    Algorithms::isContainsCycle(g);
    Algorithms ::isBipartite(g);

     // cout<<ans1<<endl;

    return 0;
}