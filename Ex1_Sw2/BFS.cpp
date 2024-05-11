
#include <iostream>
#include <queue>
#include "BFS.hpp"



void BFS::BFS_init(int source,int dest,Graph &g ) {
    vector<int>d(g.num_ver);vector<int>p(g.num_ver);vector<int>color(g.num_ver);
    BFS_SET(d,p,color);
    vector<int>ans;
    queue<int> q;
    color[source] = Traverse::GRAY;
    d[source] = 0;
    q.push(source);
    while (!q.empty()) {
        int u = q.front();
        vector<int>neighbors_list = g.graph[u]; // Assuming neighbors is now a vector
        q.pop();
        ans.push_back(u);
        for (int adjacentVertex=0;adjacentVertex<neighbors_list.size(); adjacentVertex++) {
            if(g.graph[u][adjacentVertex]==0)continue;
            if (color[adjacentVertex] == Traverse::WHITE) {
                color[adjacentVertex] = Traverse::GRAY;
                d[adjacentVertex]= d[u]+1;
                p[adjacentVertex]= p[u];
                q.push(adjacentVertex);
            }
        }
        color[source]=Traverse::BLACK;
    }
    if(color[dest]==Traverse::WHITE) cout <<"There is no path between "<<source<<" and "<<dest<<endl;else {
        for (int i = 0; i < ans.size() - 1; i++) std::cout << ans.at(i) << "->";
        std::cout << ans.at(ans.size() - 1) << endl;
    }
}



void BFS:: BFS_SET(vector<int>&d,vector<int>&p,vector<int>&color){
    for(int i=0; i<d.size();  i++){
        color[i]=Traverse::WHITE;
       d[i]=0;p[i]=-1;
    }
}

