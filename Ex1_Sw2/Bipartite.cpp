
#include "Bipartite.hpp"
int Bipartite::bip_flag = -1;


int Bipartite::is_Bip(Graph &g, int vertex) {
    bip_flag=1;
    std::map<int,int>color;
    for(int ver=0; ver<g.num_ver; ver++){
        color[ver]=Traverse::GRAY;
    }
    queue<int> q;
    color[vertex] = Traverse::WHITE;
    q.push(vertex);
    while (!q.empty()) {
        int u=q.front();
        vector<int> neighbors_list = g.graph[u]; // Assuming neighbors is now a vector
        q.pop();
        for (int adjacentVertex=0; adjacentVertex<neighbors_list.size(); adjacentVertex++) {
            if(adjacentVertex!=u && neighbors_list[adjacentVertex]!=0){
                if(color[adjacentVertex]==color[u])
                    bip_flag=false;
                if (color[adjacentVertex] == Traverse::GRAY && g.graph[u][adjacentVertex] != 0) {
                    if (color[u] == Traverse::WHITE) {
                        color[adjacentVertex] = Traverse::BLACK;
                    } else color[adjacentVertex] = Traverse::WHITE;
                    q.push(adjacentVertex);
            }
          }
        }
    }
    if(bip_flag==0) cout << 0 << endl;
    else Print_Bip(color);
    return bip_flag;
}

void Bipartite::Print_Bip(const map<int, int>& color) {
    std::vector<int>White_Team;
    std::vector<int>Black_Team;
    for (const auto& pair : color) {
        if(pair.second==Traverse::WHITE)
                White_Team.push_back(pair.first);
        else Black_Team.push_back(pair.first);
    }

    std::cout<<"The graph is bipartite:"<<endl<<"White:{";
    for(int i : White_Team) {
        std::cout <<i<<" ";
    }std::cout <<"}"<<endl<< "Black:{";
    for(int i : Black_Team) {
        std::cout << i<<" ";
        }std::cout<<"}"<<endl;
    }


