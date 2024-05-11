
#include "Algorithms.hpp"
#include "Traverse.hpp"



void Algorithms::isConnected(Graph& g) {
    cout<<DFS::isConnected_ByDFS(g)<<endl;}

void Algorithms::isContainsCycle(Graph& g) {
    if (g.getType() == NegativeWeight) Belman_Ford::DetectCycle(g);
    else
         DFS::is_Cyclic(g);
}

void Algorithms::shortestPath(Graph& g, int start, int end) {
    switch(g.getType()){
        case NoneWeight:
            BFS::BFS_init(start, end, g);
            break;
        case Weight:
            Dijkstra::Initiate(start, end, g);
            break;
        case NegativeWeight:
            Belman_Ford::PrintPath(start,end,g);
            break;
        default:
            break;}}

void Algorithms::isBipartite(Graph& g) {
    Bipartite::is_Bip(g,0);}
