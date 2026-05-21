#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void bellman(int src , vector<vector<pair<int,int>>>&adj,vector<int>&dist,int V){
    dist[src] = 0;

    for(int i=0;i<V-1;i++){
        for(int u=0;u<V;u++){
            for(int k=0;k<adj[u].size();k++){
                int wt = adj[u][k].first;
                int v = adj[u][k].second;

                if(dist[u]!=INT_MAX &&dist[v]>dist[u]+wt){
                    dist[v] = dist[u]+wt;
                }
            }
        }
    }

    for(int u=0;u<V;u++){
        for(int k=0;k<adj[u].size();k++){
            int wt = adj[u][k].first;
            int v= adj[u][k].second;
            if(dist[u]!=INT_MAX && dist[v]>dist[u]+wt){
                cout<<"negative wt cycle exist";
                return;
            }
        }
    }

    for(int i=0;i<V;i++){
        cout<<i<<":"<<dist[i]<<endl;
    }
}
int main(){
    int n;
    cout<<"enter no. of nodes: ";
    cin>>n;

    int e;
    cout<<"Enter no. of edges: ";
    cin>>e;

    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({wt,v});
    }

    int src;
    cout<<"Enter source: ";
    cin>>src;

    vector<int>dist(n+1,INT_MAX);
    bellman(src,adj,dist,n);

}