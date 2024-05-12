/*
id:206698359    mail:shoamivgi1234@gmail.com
*/

#include "Graph.hpp"
#include <iostream>

using namespace ariel;
using namespace std;

Graph::Graph()= default;

void Graph::loadGraph(vector<vector<int>> graph_matrix) {
    clear();
    vector<int> vect;
    bool flag=true;
     if (graph_matrix.size() != graph_matrix[0].size()) {
        throw std::invalid_argument("Invalid graph: The graph is not a square matrix");
    }
    if(flag) {                
        this-> graph =graph_matrix;
        this-> num_ver=graph.size();
        this->directed=true;
        this->edge_list=std::vector<Edge>();
        Classified();
    }
}

void Graph::printGraph() {
    int count_edges=0;
    for(auto & i : graph){
        for(size_t j=0; j<graph[0].size(); j++){
            if(i[j]!=0) count_edges++;
        }
    }
    cout<< "Graph with " << graph.size() << " vertices and "<<count_edges<< " edges."<<endl;
}


void Graph::Classified() {
    Type=0;
    for(size_t src=0; src<this->num_ver; src++){
        for(size_t dest=0; dest<this->num_ver; dest++) {
            if (this->graph[src][dest] != this->graph[(int)dest][(int)src])this->directed = false;
            if (this->graph[src][dest] != 0)
                this->edge_list.push_back({(int)src,(int)dest,this->graph[src][dest]});
            if(Type!=2) {
                if (graph[(int)src][(int)dest] > 1) Type = 1;  // Weighted
                if (graph[(int)src][(int)dest] < 0) Type = 2;         //NegativeWeighted
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





