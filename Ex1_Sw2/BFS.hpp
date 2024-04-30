//
// Created by vboxuser on 4/26/24.
//

#ifndef EX1_SW2_BFS_HPP
#define EX1_SW2_BFS_HPP

#include "Traverse.hpp"

class BFS {
    static void BFS_SET(Graph &g);
    static bool * visit;
    public:
    static void BFS_init(int vertex,int target,Graph &g);

};


#endif //EX1_SW2_BFS_HPP
