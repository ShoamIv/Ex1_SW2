
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
        vector<int> neighbors_list = g.neighbors[u]; // Assuming neighbors is now a vector
        q.pop();
        for (int adjacentVertex: neighbors_list) {
          if(color[adjacentVertex]==color[u]) bip_flag=0;else{
              if (color[adjacentVertex] == Traverse::GRAY) {
                  if(color[u]==Traverse::WHITE) {
                      color[adjacentVertex] = Traverse::BLACK;
                  }else color[adjacentVertex] = Traverse::WHITE;
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
    for(int i : White_Team) {
        std::cout << "White: " << i << std::endl;
    }
    for(int i : Black_Team) {
        std::cout << "Black: " << i << std::endl;
        }
    }


