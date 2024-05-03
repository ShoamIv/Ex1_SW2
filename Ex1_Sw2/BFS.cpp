
#include <iostream>
#include <queue>
#include "BFS.hpp"



void BFS::BFS_init(int vertex,int target,Graph &g ) {
    BFS_SET(g);
    string ans;
    queue<int> q;
    g.color[vertex] = Traverse::GRAY;
    g.d[vertex] = 0;
    q.push(vertex);
    while (!q.empty()) {
        int u = q.front();
        vector<int>neighbors_list = g.neighbors[u]; // Assuming neighbors is now a vector
        q.pop();
        ans += std::to_string(u) + "->";
        for (int adjacentVertex=0;adjacentVertex<neighbors_list.size(); adjacentVertex++) {
            if(g.graph[u][adjacentVertex]==0)continue;
            if (g.color[adjacentVertex] == Traverse::WHITE) {
                g.color[adjacentVertex] = Traverse::GRAY;
                g.d[adjacentVertex]= g.d[u]+1;
                g. p[adjacentVertex]= g.p[u];
                q.push(adjacentVertex);
            }
        }
        g.color[vertex]=Traverse::BLACK;
    }
    if(g.color[target]==Traverse::WHITE) cout <<-1<<endl;else
    cout<<ans<<endl;
}



void BFS:: BFS_SET(Graph &g){
    for(int i=0; i<g.num_ver ; i++){
        g.color[i]=Traverse::WHITE;
       g.d[i]=0;g.p[i]=0;
    }
}

