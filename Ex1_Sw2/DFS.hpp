//
// Created by vboxuser on 4/26/24.
//

#ifndef EX1_SW2_DFS_HPP
#define EX1_SW2_DFS_HPP
#include <utility>
#include "Traverse.hpp"

class DFS {
    static void DFS_Visit(Graph &g, vector<int> &p, vector<int> &color);
    static void Print_Cycle(vector<int>cycle);
    static bool Cycle_util(Graph &g,int vertex,vector<int>&p,vector<int>&color);
    static void Set_DFS(vector<int>p,vector<int>color);
public:
    static int isConnected_ByDFS(Graph &g);
    static void is_Cyclic(Graph &g);
};


#endif //EX1_SW2_DFS_HPP
