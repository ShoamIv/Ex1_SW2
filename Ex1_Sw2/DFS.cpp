//
// Created by vboxuser on 4/26/24.
//

#include "DFS.hpp"
std::vector<int>DFS::cycle;

void DFS::DFS_init(int vertex,Graph &g) {
   for(int i=0; i<g.num_ver; i++) {
       g.color[i] = Traverse::WHITE;
   }
   if(g.color[vertex]==Traverse::WHITE) {
       DFS_Visit(vertex,g);
   }
}
void DFS::DFS_Visit(int vertex, Graph &g) {
    queue<int> q;
    q.push(vertex);
    while(!q.empty()) {
        int top=q.front(); q.pop();
        g.color[top] = Traverse::GRAY;
        vector<int> neighbors_list = g.neighbors[top]; // Assuming neighbors is now a vector
        for (int adjacentVertex=0; adjacentVertex<neighbors_list.size(); adjacentVertex++) {
            if (g.color[adjacentVertex] == Traverse::GRAY) {
                int pre_ver = top;
                while (pre_ver != adjacentVertex) {
                    cycle.push_back(pre_ver);
                    pre_ver = g.p[pre_ver];
                }
            }
            if (g.color[adjacentVertex] == Traverse::WHITE) {
                g.p[adjacentVertex] = top;
                q.push(adjacentVertex);
            }
        }
        g.color[top] = Traverse::BLACK;
    }
}

void DFS::is_Cyclic(Graph &g) {
    DFS_init(0,g);
    if(!cycle.empty()){  Print_Cycle();}else
        std::cout<<0<<endl;
}

int DFS::isConnected_ByDFS(Graph &g) {
    int flag= 1;
    DFS_init(0,g);
    for(int i=0; i<g.num_ver; i++){
        if(g.color[i]== Traverse::WHITE) flag=0;}
    if(!g.directed) return flag;
    Graph t= Traverse::Transpose(g);
    DFS_init(0,t);
    for(int i=0; i<g.num_ver; i++){
        if(t.color[i]== Traverse::WHITE) {
            flag=0; break;
        }
    }
    return flag;
}

void DFS::Print_Cycle() {
for(int i=(int)cycle.size()-1; i>=1; i--){
    std::cout << cycle.at(i) << "->";
    }
    std::cout << cycle.at(0)<<endl;
}





