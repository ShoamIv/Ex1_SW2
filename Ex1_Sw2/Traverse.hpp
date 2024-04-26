//
// Created by vboxuser on 4/25/24.
//

#ifndef EX1_SW2_TRAVERSE_HPP
#define EX1_SW2_TRAVERSE_HPP
#include "Graph.hpp"

class Traverse {

    const Graph  g;
    int num_ver;
    vector<vector<int>> neighbors;
    bool * visit{};
    bool directed{};
    void populated_neighbors();
    bool is_directed();

     Traverse(Graph& graph) : g(graph) {
         num_ver=(int)graph.graph[0].size();
         this->neighbors = vector<vector<int>>(num_ver);
         directed=is_directed();
    }

public:
     int DFS_Undirected(int vertex);
     int DFS_Directed(int vertex);
     void BFS(int vertex);    //Single source no weights shortest path
};


#endif //EX1_SW2_TRAVERSE_HPP
