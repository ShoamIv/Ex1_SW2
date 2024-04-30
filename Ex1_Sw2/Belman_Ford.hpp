//
// Created by vboxuser on 4/26/24.
//

#ifndef EX1_SW2_BELMAN_FORD_HPP
#define EX1_SW2_BELMAN_FORD_HPP

//Single source negative weighted shortest path

#include "Graph.hpp"

class Belman_Ford {

    static void relax_all(int a,int b,Graph &g);

    static bool  neg_cycle;
public:
    static bool DetectCycle(Graph &g);
    static void printPath(int a, int b, Graph g);

};
#endif //EX1_SW2_BELMAN_FORD_HPP
