//
// Created by vboxuser on 4/26/24.
//

#ifndef EX1_SW2_BELMAN_FORD_HPP
#define EX1_SW2_BELMAN_FORD_HPP

//Single source negative weighted shortest path

#include "Graph.hpp"

class Belman_Ford {
    static bool  neg_cycle;
public:
    static void PrintPath(int a, int b, Graph &g);
    static bool BF_ShortestPath(Graph &g,int start,vector<int>&d,vector<int>&p);
    static bool DetectCycle(Graph &g);
    static void printCycle(int a, int b, Graph &g);

};
#endif //EX1_SW2_BELMAN_FORD_HPP
