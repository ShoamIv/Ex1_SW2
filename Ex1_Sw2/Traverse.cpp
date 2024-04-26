
#include <iostream>
#include <queue>
#include "Traverse.hpp"




int Traverse::DFS_Undirected(int vertex) {
    std::fill_n(visit, this->num_ver, false);    //init array to false
    this->visit[vertex] = true;
    vector<int> nei_list =this->neighbors[vertex]; // Assuming neighbors is now a vector
    for (int adjacentVertex : nei_list) {
        if (!this->visit[adjacentVertex]) {
            DFS_Undirected( adjacentVertex);
        }
    }
    for(int i=0; i<this->num_ver; i++){
        if(!this->visit[i])return 0;
    }
    return 1;
}

int Traverse::DFS_Directed(int vertex) {
    while(vertex!=this->num_ver-1) {
        DFS_Undirected(vertex);
        DFS_Directed(++vertex);
    }
    return 1;
}
void Traverse::BFS(int vertex) {
    std::fill_n(visit, this->num_ver, false);
    queue <int> q;
    visit[vertex]=true;
    q.push(vertex);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        cout << curr << "->";
        for (int neighbor : this->neighbors[curr]) {
            if (!visit[neighbor]) {
                visit[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

}


void Traverse::populated_neighbors() {
    this->neighbors = vector<vector<int>>(num_ver);
    for (int vertex = 0; vertex < num_ver; vertex++) {
        for (int j = 0; j < num_ver; j++) {
            if (this->g.graph[vertex][j] == 1) {
                this->neighbors[vertex].push_back(j);            }
        }
    }

}

bool Traverse::is_directed() {
    for (int i = 0; i < num_ver; i++) {
        for (int j = 0; j < num_ver; j++) {
            if (this->g.graph[i][j] != this->g.graph[j][i]) {
                return false;
            }
        }
    }
    return true;
}