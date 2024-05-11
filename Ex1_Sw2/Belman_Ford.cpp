//
// Created by vboxuser on 4/26/24.
//

#include <iostream>
#include "Belman_Ford.hpp"
#include "Traverse.hpp"
bool Belman_Ford::neg_cycle = false;



bool Belman_Ford::DetectCycle(Graph &g) {
    vector<int>d(g.num_ver+1);vector<int>p(g.num_ver+1);vector<int>color(g.num_ver+1);
    vector<vector<int>> matrix (g.num_ver+1,vector<int>(g.num_ver+1));
    for(int i=0; i<g.num_ver; i++){
        for(int j=0; j<g.num_ver; j++){
            matrix[i][j]=g.graph[i][j];
        }
    }
    for(int i=0;i<g.num_ver+1; i++){
        matrix[g.num_ver][i]=1000;}
    g.load_graph(matrix);
    for (int v=0; v<g.num_ver; v++) {
        d[v] = 1000000;
        p[v] = -1;
    }
    d[g.num_ver] = 0;
    for (int E = 0; E < g.num_ver - 1; E++) {
        for (auto &edge : g.edge_list) {
            if(d[edge.dest]>d[edge.source]+ edge.weight) {
                d[edge.dest] = d[edge.source] + edge.weight;
                p[edge.dest] = edge.source;
            }
        }
    }
    std:: vector<int>Neg_Cycle;
    for(auto &edge : g.edge_list)
    {
        if (d[edge.dest] > d[edge.source] + edge.weight) {
            int curr = edge.dest;
            for (int i = 0; i < g.num_ver; i++) {
                color[i] = Traverse::WHITE;
            }
            while (color[curr] != Traverse::BLACK) {
                Neg_Cycle.push_back(curr);
                if (color[curr] == Traverse::GRAY) color[curr] = Traverse::BLACK;
                else color[curr] = Traverse::GRAY;
                curr = p[curr];
            }
        }
        break;
    }
    if(Neg_Cycle.empty()){
        neg_cycle=false;
        std::cout<<"No Cycle Detected."<<endl;
    }
        else {
            neg_cycle=true;
            int count=0;
            int marker=Neg_Cycle.at(Neg_Cycle.size()-1);
        for(int i=(int)Neg_Cycle.size()-1; i>=0; i--){
                    if(count==2)break;
                    if(Neg_Cycle.at(i)==marker)count++;
                    std::cout << Neg_Cycle.at(i) << " ";
        }
        std::cout<<endl;
    }
        return neg_cycle;
}

void Belman_Ford:: printCycle(int a,int b,Graph &g){
    vector<vector<int>>old_matrix=g.graph;
    vector<int>d(g.num_ver);vector<int>p(g.num_ver);vector<int>color(g.num_ver);
    if(neg_cycle){
        std:: cout << "negative cycle detected" << endl;
        g.load_graph(old_matrix);
        return;
    }
    vector<int>ans;
    while(p[b]!=p[a]){
        ans.push_back(p[b]);
        int temp=p[b];
        p[b]=p[temp];
    }
    for(int an : ans){
        cout << ans[an] << " ";
    }
    g.load_graph(old_matrix);
}


bool Belman_Ford::BF_ShortestPath(Graph &g,int start,vector<int>&d,vector<int>&p) {
    int flag= false;
    for (int v=0; v<g.num_ver; v++) {
        d[v] = 1000000;
        p[v] = -1;
    }
    d[start] = 0;
    for (int E = 0; E < g.num_ver - 1; E++) {
        for (auto &edge : g.edge_list) {
            if(d[edge.dest]>d[edge.source]+ edge.weight) {
                d[edge.dest] = d[edge.source] + edge.weight;
                p[edge.dest] = edge.source;
            }
        }
    }
    for(auto &edge : g.edge_list){
        if (d[edge.dest] > d[edge.source] + edge.weight) {
                flag=true; break;
            }
        }
    return flag;
}

void Belman_Ford::PrintPath(int a, int b, Graph &g) {
    vector<int>d(g.num_ver);vector<int>p(g.num_ver);
    neg_cycle= BF_ShortestPath(g,a,d,p);
    if(neg_cycle){
        std:: cout << "Negative cycle detected" << endl;
        return;
    }
    vector<int>ans;
    while(b!=a){
        ans.push_back(p[b]);
        b=p[b];
    }
    std::cout<<"Path is: ";
    for(int an : ans){
        std::cout << ans[an] << " ";
    }
    std::cout<<endl;
}

