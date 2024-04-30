
#include "Algorithms.hpp"
#include "Traverse.hpp"

int Algorithms::isConnected(Graph& g) {
    return DFS::isConnected_ByDFS(g);
}

void Algorithms::isContainsCycle(Graph& g) {
    if(g.Type==NegativeWeight) Belman_Ford::DetectCycle(g);else
        DFS::is_Cyclic(g);
}

void Algorithms::shortestPath(Graph& g, int start, int end) {
    switch(g.Type){
        case NoneWeight:
            BFS::BFS_init(start, end, g);
            break;
        case Weight:
            Dijkstra::Initiate(start, end, g);
            break;
        case NegativeWeight:
            Belman_Ford::printPath(start, end, g);
            break;
        default:
            break;

    }
}
void Algorithms::isBipartite(Graph& g) {
    Bipartite::is_Bip(g,0);
}


