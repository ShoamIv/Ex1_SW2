//
// Created by vboxuser on 4/24/24.
//

#include "Graph.hpp"
#include <iostream>


using namespace std;

Graph::Graph()= default;

void Graph::load_graph(vector<vector<int>> graph_matrix) {
    vector<int> vect;
    bool flag=true;
    if(graph_matrix.size()!=graph_matrix[0].size()){
        cout << "Invalid graph: The graph is not a square matrix" << endl;
        flag=false;
    }
    if(flag) {                //init graph.
        this-> graph = graph_matrix;
        this-> num_ver=(int)graph.size();
        this->color=std::vector<int>(num_ver);
        this->d=std::vector<int>(num_ver);
        this->p=std::vector<int>(num_ver);
        getType();
        populated_neighbors();
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
            if (graph[i][j] < 0) {Type =2 ;break;}//NegativeWeighted
        }
    }
}

void Graph::Set_Edge(Graph &g) {
    int i=0;
    for(int src=0; src<g.graph.size(); src++){
        for(int dest=0; dest<g.graph.size(); dest++){
            g.edge_list[i]={src,dest,g.graph[src][dest]};i++;
        }
    }
}
void Graph::populated_neighbors() {
    this->neighbors=vector<vector<int>>(num_ver);
    for (int vertex = 0; vertex < this->num_ver; vertex++) {
        for (int j = 0; j < this->num_ver; j++) {
            if (this->graph[vertex][j] == 1) {
                this->neighbors[vertex].push_back(j);
            }
        }
    }
    for (int i = 0; i < this->num_ver; i++) {
     //   cout << "Neighbors of vertex " << i << ": ";
        for (int j = 0; j < this->neighbors[i].size(); j++) {
    //        cout << this->neighbors[i][j] << " ";
        }
    //    cout << endl;
    }
}




