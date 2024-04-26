#include <iostream>
#include "Graph.hpp"
#include "Algorithms.hpp"
#include "vector"
using namespace std;

int main() {
    Graph g;
    vector<vector<int>> graph = {
           //0  1  2
            {0, 1, 0},
            {1, 0, 1},
            {0, 1,0}};

    g.load_graph(graph);
    cout << Algorithms::isConnected(g) << endl;

    return 0;
}
