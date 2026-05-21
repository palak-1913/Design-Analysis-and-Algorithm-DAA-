#include<iostream>
#include<vector>
using namespace std;
bool dfs(int curr ,vector<vector<int>>&graph,vector<int>&recpath,vector<int>&visited){
    visited[curr] = true;
    recpath[curr] = true;

    for(int i=0;i<graph[curr].size();i++){
        int neigh = graph[curr][i];
        if(visited[neigh]==false){
            if(dfs(neigh,graph,visited,recpath)) return true;
        }

        else if(recpath[neigh]) return true;
    }

    //backtrack
    recpath[curr] = false;
    return false;
}
int main(){
    int n;
    cout<<"enter no. of nodes: ";
    cin>>n;

    int e;
    cout<<"enter edges: ";
    cin>>e;

    vector<vector<int>>adj(n);

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);  
    }

    vector<int>recpath(n,false);
    vector<int>visited(n,false);

    if(dfs(0,adj,recpath,visited)) cout<<"cycle exist";
    else cout<<"cycle donot exist";


    
}