//
// Created by vboxuser on 4/24/24.
//

#ifndef EX1_SW2_ALGORITHMS_HPP
#define EX1_SW2_ALGORITHMS_HPP
#include "Graph.hpp"

class Algorithms {
public:
    static int isConnected(const Graph& g);
    static void isContainsCycle(const Graph& g);
    static void shortestPath(const Graph& g,int,int);
    static void isBipartite(const Graph& g);
    static bool is_symmetric(const Graph& g);
};


#endif //EX1_SW2_ALGORITHMS_HPP
