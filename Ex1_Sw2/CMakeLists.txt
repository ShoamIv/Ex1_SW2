cmake_minimum_required(VERSION 3.28)
project(Ex1_Sw2)

set(CMAKE_CXX_STANDARD 23)

add_executable(Ex1_Sw2 main.cpp
        Graph.cpp
        Graph.hpp
        Algorithms.cpp
        Algorithms.hpp
        Traverse.cpp
        Traverse.hpp
        Dijkstra.cpp
        Dijkstra.hpp
        Belman_Ford.cpp
        Belman_Ford.hpp
        DFS.cpp
        DFS.hpp
        BFS.cpp
        BFS.hpp
        Bipartite.cpp
        Bipartite.hpp)
