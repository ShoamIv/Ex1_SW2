//
// Created by vboxuser on 4/26/24.
//

#ifndef EX1_SW2_DFS_HPP
#define EX1_SW2_DFS_HPP
#include <utility>
#include "Traverse.hpp"

class DFS {
    static void DFS_init(int vertex,Graph &g);
    static void DFS_Visit(int vertex,Graph &g);
    static void Print_Cycle();
    static std::vector<int>cycle;
public:
    static int isConnected_ByDFS(Graph &g);
    static void is_Cyclic(Graph &g);

};


#endif //EX1_SW2_DFS_HPP
