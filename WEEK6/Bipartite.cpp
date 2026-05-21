#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool bfs(int curr  , vector<vector<int>>&adj,vector<int>&color){
    queue<int>q;
    q.push(curr);
    color[curr] = 0;

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i=0;i<adj[curr].size();i++){
            int neigh = adj[curr][i];
            if(color[neigh]==-1){
                color[neigh] = !color[curr];
                q.push(neigh);
            } 

            else if(color[neigh]==color[curr]) return false;
        }
    }
    return true;

}
int main(){
    int n;
    cout<<"enter no of nodes: ";
    cin>>n;

    int e;
    cout<<"Enter no. of edges: ";
    cin>>e;

    vector<vector<int>>adj(n);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ans = true;
    vector<int>color(n,-1);
    for(int i=0;i<adj.size();i++){
        if(color[i]==-1){
            if(bfs(i,adj,color)==false){
                ans = false;
            } 
        }
    }

    if(ans) cout<<"Bipartite";
    else cout<<"Not Bipartie";

    


}