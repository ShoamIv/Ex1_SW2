//
// Created by vboxuser on 4/26/24.
//

#include "DFS.hpp"


void DFS::DFS_Visit(Graph &g, vector<int> &p, vector<int> &color) {
    Set_DFS(p,color);
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int top=q.front(); q.pop();
        color[top] = Traverse::GRAY;
        vector<int> neighbors_list = g.graph[top]; // Assuming neighbors is now a vector
        for (int adjacentVertex=0; adjacentVertex<neighbors_list.size(); adjacentVertex++) {
          if(neighbors_list.at(adjacentVertex)==0) continue;
            if (color[adjacentVertex] == Traverse::WHITE) {
                p[adjacentVertex] = top;
                q.push(adjacentVertex);
            }
        }
        color[top] = Traverse::BLACK;
    }
}

void DFS::is_Cyclic(Graph &g) {
    bool FLAG = false;
    vector<int>color(g.num_ver);
    vector<int>p(g.num_ver);
    for(int i=0;i<g.num_ver;++i){
        color[i] = 1;
            FLAG = Cycle_util(g,i,p,color);
            if(FLAG) break;
    }
    if(!FLAG) std::cout<<"no cycle detected."<<endl;
}
int DFS::isConnected_ByDFS(Graph &g) {
    vector<int>color(g.num_ver);
    vector<int>p(g.num_ver);
    int flag= 1;
    DFS_Visit(g, p, color);
    for(int i=0; i<g.num_ver; i++){
        if(color[i]== Traverse::WHITE) flag=0;}
    if(!g.getDirected()) return flag;
    Graph t= Traverse::Transpose(g);
    DFS_Visit(t, p, color);
    for(int i=0; i<g.num_ver; i++){
        if(color[i]== Traverse::WHITE) {
            flag=0; break;
        }
    }
    return flag;
}
void DFS::Print_Cycle(vector<int>cycle) {
for(int i=(int)cycle.size()-1; i>=1; i--){
    std::cout << cycle.at(i) << "->";
    }
    std::cout << cycle.at(0)<<endl;
}

bool DFS::Cycle_util(Graph &g,int vertex,vector<int>&p,vector<int>&color){
    color[vertex] = Traverse::GRAY;
    vector<int>cycle;
    for (int i = 0; i < g.num_ver; ++i) {
        if (g.graph[vertex][i] == 0) continue;
        if (color[i] == Traverse::GRAY && p[vertex] != i) {
            std::cout << "Cycle detected: ";
            int curr = vertex;
            cycle.push_back(i);
            while (curr != i) {
                cycle.push_back(curr);
                curr = p[curr];
          }cycle.push_back(curr);
            Print_Cycle(cycle);
            return true;
        }
        if (color[i] == Traverse::WHITE) {
            p[i] = vertex;
            if (Cycle_util(g,i,p,color)) return true;
        }
    }
    color[vertex] = Traverse::BLACK;
    return false;
}

void DFS::Set_DFS(vector<int>p,vector<int>color) {
    for(int i=0; i<p.size(); i++){
        color[i]=Traverse::WHITE;
        p[i]=-1;
    }
}




