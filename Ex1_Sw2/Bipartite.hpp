//
// Created by vboxuser on 4/27/24.
//

#ifndef EX1_SW2_BIPARTITE_HPP
#define EX1_SW2_BIPARTITE_HPP

#include "Traverse.hpp"
#include <map>
#include <queue>
#include <iostream>
#include "Graph.hpp"

class Bipartite {
    static void Print_Bip(const map<int,int>&color);
    static int bip_flag;
public:
    static int is_Bip(Graph &g, int vertex);

};
#endif //EX1_SW2_BIPARTITE_HPP
