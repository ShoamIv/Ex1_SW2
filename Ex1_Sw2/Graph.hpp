
#ifndef EX1_SW2_GRAPH_HPP
#define EX1_SW2_GRAPH_HPP
#include <vector>
#include <list>
#include <string>

using namespace std;

class Graph{

public:
    Graph();
    vector<vector<int>> graph;
    vector<vector<int>> neighbors;
    std::vector<int> color;
    std::vector<int> d;
    std::vector<int> p;
    int num_ver{};
    int Type{};
    void printGraph();
    void getType();
    void load_graph(vector<vector<int>> graph);
    void populated_neighbors();
    typedef struct edge {
        int source;
        int dest;
        int weight;
    } Edge;
    void Set_Edge(Graph &g);
    vector<Edge> edge_list;

};

#endif //EX1_SW2_GRAPH_HPP
