//
// Created by vboxuser on 4/26/24.
//

#include <iostream>
#include "Belman_Ford.hpp"
#include "Traverse.hpp"

bool Belman_Ford::neg_cycle = false;

bool Belman_Ford::DetectCycle(Graph &g) {
    for (int v: g.graph[0]) {
        g.d[v] = MAX;
        g.p[v] = 0;
    }
    g.d[0] = 0;
    for (int E = 0; E < g.graph.size() - 1; E++) {
        relax_all(g.edge_list[E].source, g.edge_list[E].dest, g);
    }
    std:: vector<int>Neg_Cycle;
    for(auto & i : g.edge_list){
        int temp_dest=g.d[i.dest];
        int temp_src=g.d[i.source];
        if (temp_dest > temp_src + i.weight){
            Neg_Cycle.push_back(temp_dest);
        }
    }
    if(Neg_Cycle.empty()){
        neg_cycle=false; std:: cout << "No negative cycle detected" << endl;
    }
        else {
        for(auto & i : Neg_Cycle){
            std:: cout << Neg_Cycle.at(i) << endl;
        }
    }
        return neg_cycle;
}



void Belman_Ford::relax_all(int a, int b, Graph &g) {
    for(auto & E : g.edge_list){

        Traverse::relax(E.source,E.dest,g);
    }
}
void Belman_Ford:: printPath(int a,int b,Graph g){
    bool flag=DetectCycle(g);
    if (flag) return;
    vector<int>ans;
    ans.push_back(b);
    while(g.p[b]!=g.p[a]){
        ans.push_back(g.p[b]);
        int temp=g.p[b];
        g.p[b]=g.p[temp];
    }
    for(int an : ans){
        cout << ans[an] << "->";
    }
}