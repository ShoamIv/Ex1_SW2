//
// Created by vboxuser on 4/24/24.
//

#include "Graph.hpp"
#include <iostream>


using namespace std;

Graph::Graph()= default;

void Graph::load_graph(vector<vector<int>> graph_matrix) {
    clear();
    vector<int> vect;
    bool flag=true;
    if(graph_matrix.size()!=graph_matrix[0].size()){
        cout << "Invalid graph: The graph is not a square matrix" << endl;
        flag=false;
    }
    if(flag) {                //init graph.
        this-> graph = graph_matrix;
        this-> num_ver=(int)graph.size();
        this->directed=true;
        this->color=std::vector<int>(num_ver);
        this->d=std::vector<int>(num_ver);
        this->p=std::vector<int>(num_ver);
        this->edge_list=std::vector<Edge>();
        this->neighbors=vector<vector<int>>(num_ver);
        getType();
        Set_Edge();
    }
}

void Graph::printGraph() {
    int count_edges=0;
    for(auto & i : graph){
        for(int j=0; j<graph[0].size(); j++){
            if(i[j]>0) count_edges++;
        }
    }
    cout<< "Graph with " << graph.size() << " vertices and "<<count_edges<< " edges."<<endl;
}

    void Graph::getType() {
    Type=0;   //NoneWeighted
    for(int i=0; i<num_ver; i++) {
        for (int j = 0; j <num_ver; j++) {
            if (graph[i][j] > 1) Type =1;  // Weighted
            if (graph[i][j] < 0) {Type =2;break;}//NegativeWeighted
        }
    }
}

void Graph::Set_Edge() {
    for(int src=0; src<this->num_ver; src++){
        for(int dest=0; dest<this->num_ver; dest++){
                this->edge_list.push_back({src, dest, this->graph[src][dest]});
                this->neighbors[src].push_back(this->graph[src][dest]);
                std::map<int,int> nei;
                if(this->graph[src][dest]>0){nei[src]=dest;
                this->ne.push_back(nei);}

                if(this->graph[src][dest]!=this->graph[dest][src])this->directed=false;
        }
    }
}
void Graph::clear() {
    graph.clear();
    num_ver = 0;
    color.clear();
    d.clear();
    p.clear();
    neighbors.clear();
    edge_list.clear();
    Type = 0;

}




