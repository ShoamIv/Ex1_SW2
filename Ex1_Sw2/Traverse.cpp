
#include <iostream>
#include <queue>
#include "Traverse.hpp"




bool Traverse::is_directed(Graph &g) {
    for (int i = 0; i < g.num_ver; i++) {
        for (int j = 0; j < g.num_ver; j++) {
            if (g.graph[i][j] != g.graph[j][i]) {
                return false;
            }
        }
    }
    return true;
}
void Traverse::relax(int a, int b, Graph &g) {
    if(g.d[b]>g.d[a]+ g.graph[a][b]){
        g.d[b]=g.d[a]+g.graph[a][b];
        g.p[b]=a;
    }
}

Graph Traverse::Transpose(Graph &g) {
    Graph t;
        vector<vector<int>>gt=vector<vector<int>>(g.num_ver, vector<int>(g.num_ver));
    for(int i=0; i<g.num_ver; i++){
        for(int j=0; j<g.num_ver; j++){
            gt[i][j]=g.graph[j][i];
        }
    }
    t.load_graph(gt);
    return t;
}
