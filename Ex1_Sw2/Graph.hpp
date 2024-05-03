
#ifndef EX1_SW2_GRAPH_HPP
#define EX1_SW2_GRAPH_HPP
#include <vector>
#include <list>
#include <string>
#include <map>

using namespace std;

class Graph{
    void clear();

public:
    Graph();
    vector<vector<int>> graph;
    vector<vector<int>> neighbors;
    std::vector<int> color;
    std::vector<int> d;
    std::vector<int> p;
    bool directed;
    vector<std::map<int,int>> ne;
    int num_ver{};
    int Type{};
    void printGraph();
    void getType();
    void load_graph(vector<vector<int>> graph);
    typedef struct edge {
        int source;
        int dest;
        int weight;
    } Edge;
    void Set_Edge();
    vector<Edge> edge_list;

};

#endif //EX1_SW2_GRAPH_HPP
