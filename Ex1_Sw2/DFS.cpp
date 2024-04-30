//
// Created by vboxuser on 4/26/24.
//

#include "DFS.hpp"



void DFS::DFS_init(int vertex,Graph &g) {
    int ans=0;
   for(int i=0; i<g.num_ver; i++) {
       g.color[i] = Traverse::WHITE;
   }
   if(g.color[vertex]==Traverse::WHITE) {
       DFS_Visit(vertex,g);
   }
}
void DFS::DFS_Visit(int vertex, Graph &g) {
    g.color[vertex]=Traverse:: GRAY;
   // cout<<g.color[vertex]<<endl;
    vector<int> neighbors_list = g.neighbors[vertex]; // Assuming neighbors is now a vector
    for (int adjacentVertex: neighbors_list) {
        if (g.color[adjacentVertex] == Traverse::WHITE){
            DFS_Visit(adjacentVertex, g);}
    }
}


bool DFS::is_Cyclic(Graph &g) {
    bool cycle=false;
    for(int i=0; i<g.num_ver; i++){
        if(g.color[i]==Traverse::WHITE) {
        //   cycle=DFS_init(i,g);
        }
        if(cycle)break;
    }
    return cycle;
}

int DFS::isConnected_ByDFS(Graph &g) {
    DFS_init(0,g);
    for(int i=0; i<g.num_ver; i++){
        if(g.color[i]== Traverse::WHITE) return 0;
    }
    Graph t= Traverse::Transpose(g);
    DFS_init(0,t);
    for(int i=0; i<g.num_ver; i++){
        if(g.color[i]== Traverse::WHITE) {
            return 0;
        }

    }

    return 1;
}





