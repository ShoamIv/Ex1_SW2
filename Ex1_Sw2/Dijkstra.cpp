

#include <queue>
#include "Dijkstra.hpp"
#include "Traverse.hpp"

void Dijkstra::Initiate(int a, int b,Graph& g) {
    priority_queue <int, vector<int>, greater<>> pq;
    for(int v : g.graph[0]){
        g.d[v]= MAX;  g.p[v]=0;
        pq.push(v);
    }
    while(!pq.empty()){
        int u=pq.top();
        pq.pop();
        for(int v:g.neighbors[u]){
            if(g.graph[a][v]!=0){        //if [a][v]==0 no edge.
                Traverse::relax(a,b,g);
            }
        }
    }
}






