
#ifndef EX1_SW2_GRAPH_HPP
#define EX1_SW2_GRAPH_HPP
#include <vector>
#include <list>

using namespace std;

class Graph{

public:
    vector<vector<int>> graph;
    Graph();
    void load_graph(vector<vector<int>> graph);
    void printGraph();
};

#endif //EX1_SW2_GRAPH_HPP
