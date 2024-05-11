//
// Created by vboxuser on 4/26/24.
//

#ifndef EX1_SW2_DIJKSTRA_HPP
#define EX1_SW2_DIJKSTRA_HPP
#include "Traverse.hpp"

//Single source None negative weighted  shortest path


class Dijkstra {
public:
    static void Initiate(int source, int dest,Graph& g);
    static void Print_ShortestBy_Dijkstra(int source, int target,Graph& g,vector<int>&p);
};


#endif //EX1_SW2_DIJKSTRA_HPP
