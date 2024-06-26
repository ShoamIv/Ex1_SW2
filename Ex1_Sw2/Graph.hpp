/*
id:206698359    mail:shoamivgi1234@gmail.com
*/
#ifndef EX1_SW2_GRAPH_HPP
#define EX1_SW2_GRAPH_HPP
#include <vector>
#include <list>
#include <string>
#include <map>
using namespace std;
namespace ariel{
class Graph{
    void clear();
    void Classified();
    int Type{};
    bool directed{};
public:
    Graph();
    std::vector<std::vector<int>> graph;
    int num_ver{};
    void printGraph();
    void loadGraph(std::vector<std::vector<int>> graph);
    int getType();
    bool getDirected();
    typedef struct edge {
        int source;
        int dest;
        int weight;
    } Edge;
    std::vector<Edge> edge_list;
    };
}
#endif //EX1_SW2_GRAPH_HPP
