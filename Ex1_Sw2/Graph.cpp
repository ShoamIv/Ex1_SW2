//
// Created by vboxuser on 4/24/24.
//

#include "Graph.hpp"
#include <iostream>
using namespace std;

Graph::Graph(){

}
void Graph::load_graph(vector<vector<int>> graph) {
    vector<int> vect;
    bool flag=true;
    if(graph.size()!=graph[0].size()){
        cout << "Invalid graph: The graph is not a square matrix" << endl;
        flag=false;
    }
    if(flag) {                                 //init graph.
        this->graph = graph;
    }
}

void Graph::printGraph() {
    int count_edges=0;
    for(int i=0; i<this->graph.size(); i++){
        for(int j=0; j<this->graph[0].size(); j++){
            if(graph[i][j]>0) count_edges++;
        }
    }
    cout<< "Graph with " << this->graph.size() << " vertices and "<<count_edges<< " edges."<<endl;
}




