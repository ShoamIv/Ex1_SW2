
#include <queue>
#include "Dijkstra.hpp"
#include "Traverse.hpp"


void Dijkstra::Initiate(int source, int dest,Graph& g) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int v=0; v<g.num_ver; v++){
        g.d[v]= MAX;  g.p[v]=-1; g.color[v]=Traverse::WHITE;
    }
    g.d[source]=0;
    pq.push(pair(source,0));
    while(!pq.empty()){
        int first=pq.top().first;
        int second=pq.top().second;
        g.color[first]=Traverse::GRAY;
        pq.pop();
        vector<int> neighbors_list = g.neighbors[first]; // Assuming neighbors is now a vector
        for(int v: neighbors_list) {
            if (g.graph[first][v] != 0) {        //if [a][v]==0 no edge.
                Traverse::relax(first, v, g);
                if(g.color[v]==Traverse::WHITE){
                pq.push(make_pair(v, g.d[v]));
                }
            }
        }
    }
    Print_ShortestBy_Dijkstra(source,dest,g);

     }

void Dijkstra::Print_ShortestBy_Dijkstra(int source, int target,Graph &g) {
    int v = target;
    vector<int> path = vector<int>(g.num_ver);
    while (v != source || v>0) {
        path.push_back(v);
        v = g.p[target];
    }
    if (v == source) {
        for (int i = (int) path.size() - 1; i >= 0; i--) {
            cout << path[i];
            cout << "->";
        }
    }else cout << "No path detected.";
}


