
#ifndef EX1_SW2_GRAPH_HPP
#define EX1_SW2_GRAPH_HPP
#include <vector>
#include <list>
#include <string>
#include <map>

using namespace std;

class Graph{
    void clear();
    void Classified();
    int Type{};
    bool directed{};
public:
    Graph();
    vector<vector<int>> graph;
    int num_ver{};
    void printGraph();
    void load_graph(vector<vector<int>> graph);
    int getType();
    bool getDirected();
    typedef struct edge {
        int source;
        int dest;
        int weight;
    } Edge;
    vector<Edge> edge_list;
};

#endif //EX1_SW2_GRAPH_HPP
