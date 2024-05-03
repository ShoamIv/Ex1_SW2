//
// Created by vboxuser on 4/24/24.
//

#ifndef EX1_SW2_ALGORITHMS_HPP
#define EX1_SW2_ALGORITHMS_HPP
#include "Graph.hpp"

class Algorithms {
public:
    static void  isConnected(Graph& g);
    static void isContainsCycle(Graph& g);
    static void shortestPath( Graph& g,int start,int end);
    static void isBipartite(Graph& g);
};


#endif //EX1_SW2_ALGORITHMS_HPP
