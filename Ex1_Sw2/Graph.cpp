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
        this->edge_list=std::vector<Edge>();
        Classified();
    }
}

void Graph::printGraph() {
    int count_edges=0;
    for(auto & i : graph){
        for(int j=0; j<graph[0].size(); j++){
            if(i[j]!=0) count_edges++;
        }
    }
    cout<< "Graph with " << graph.size() << " vertices and "<<count_edges<< " edges."<<endl;
}


void Graph::Classified() {
    Type=0;
    for(int src=0; src<this->num_ver; src++){
        for(int dest=0; dest<this->num_ver; dest++) {
            if (this->graph[src][dest] != this->graph[dest][src])this->directed = false;
            if (this->graph[src][dest] != 0)
                this->edge_list.push_back({src, dest, this->graph[src][dest]});
            if(Type!=2) {
                if (graph[src][dest] > 1) Type = 1;  // Weighted
                if (graph[src][dest] < 0) Type = 2;         //NegativeWeighted
                }
            }
        }
    }
void Graph::clear() {
    graph.clear();
    num_ver = 0;
    edge_list.clear();
    Type = 0;

}

int Graph::getType() {
    return this->Type;
}

bool Graph::getDirected() {
    return this->directed;
}





