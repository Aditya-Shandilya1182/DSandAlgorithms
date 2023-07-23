#include <iostream>
using namespace std;

bool dfs(int src, int parent, vector<int> adj[], bool vis[]){
    vis[src] = true;
    for(int node : adj[src]){
        if(!vis[node]){
            if(dfs(node, src, adj, vis) == true){
                return true;
            }
        } else {
            if(node != parent){
                return true;
            }
        }
    }
    return false;
}

bool bfs(int src, vector<int> adj[], bool vis[]){
    vis[src] = true;
    queue<pair<int,int>> q; 
    q.push({src, -1}); 
    
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.poll();
        
        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                vis[adjNode] = true;
                q.push({adjNode, node});
            } else {
                if(adjNode != parent){
                    return true;
                }
            }
        }
        
    }
    return false;
}
