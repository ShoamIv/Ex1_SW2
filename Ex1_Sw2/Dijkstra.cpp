
#include <queue>
#include "Dijkstra.hpp"
#include "Traverse.hpp"

void Dijkstra::Initiate(int source, int dest,Graph& g) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int>d(g.num_ver);vector<int>p(g.num_ver);vector<int>color(g.num_ver);
    for(int v=0; v<g.num_ver; v++){
        d[v]= MAX;  p[v]=-1; color[v]=Traverse::WHITE;
    }
    d[source]=0;
    pq.push(pair(source,0));
    while(!pq.empty()){
        int first=pq.top().first;
        color[first]=Traverse::GRAY;
        pq.pop();
        vector<int> neighbors_list = g.graph[first]; // Assuming neighbors is now a vector
        for(int v=0; v<neighbors_list.size(); v++) {
                if(g.graph[first][v]==0)continue;
                Traverse::relax(first, v, g,d,p);
                if(color[v]==Traverse::WHITE){
                pq.push(make_pair(v, d[v]));
            }
        }
    }
    if(color[dest]==Traverse::WHITE) std::cout<<"There is no path between "<<source<<" and "<<dest<<endl;else
        Print_ShortestBy_Dijkstra(source,dest,g,p);

     }

void Dijkstra::Print_ShortestBy_Dijkstra(int source, int target,Graph &g,vector<int>&p) {
    int v = target;
    vector<int> path;
    while (v != source || v>0) {
        path.push_back(v);
        v = p[v];
    }
    if (v == source) {
        path.push_back(v);
        for (int i = (int) path.size() - 1; i >= 1; i--) {
            cout << path[i];
            cout << "->";
        }
        cout << path[0]<<endl;
    }else cout << "No path detected.";
}


