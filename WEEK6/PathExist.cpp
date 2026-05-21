#include<iostream>
#include<vector>
using namespace std;
bool dfs(int src, int dest , vector<vector<int>>&adj,vector<int>&visited){
    if(src==dest) return true;

    visited[src] = true;
    for(int i=0;i<adj[src].size();i++){
        int next = adj[src][i];
        if(visited[next]==false){
            if(dfs(next,dest,adj,visited)) return true;
        }
    }
    return false;
}
int main(){
    int v;
    cout<<"enter no vertices: ";
    cin>>v;

    int e;
    cout<<"Enter no. of edges: ";
    cin>>e;

    vector<vector<int>>adj(v);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>visited(v,false);

    int src;
    cout<<"Enter source: ";
    cin>>src;

    int dest;
    cout<<"enter destination: ";
    cin>>dest;

    if(dfs(src,dest,adj,visited)) cout<<"path exist";
    else cout<<"path donot exist";
}