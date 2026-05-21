#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int shortest_path(int src,int dest,int k,vector<vector<pair<int,int>>>&adj){
    if(src==dest && k==0) return 0;

    if(k==0) return INT_MAX;

    int ans = INT_MAX;
    for(int i=0;i<adj[i].size();i++){
        int v = adj[src][i].second;
        int wt = adj[src][i].first;

        int temp = shortest_path(v,dest,k-1,adj);
        if(temp!=INT_MAX) ans = min(ans,temp);
    }

    return ans;

}
int main(){
    int n;
    cout<<"enter no. of nodes: ";
    cin>>n;

    int e;
    cout<<"Enter no. of edges: ";
    cin>>e;


    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({wt,v});
    }

    int src,dest,k;
    cout<<"Enter src: ";
    cin>>src;
    cout<<"dest: ";
    cin>>dest;
    cout<<"enter k: ";
    cin>>k;

    int ans = shortest_path(src,dest,k,adj);

    if(ans==INT_MAX) cout<<"No path";

    else cout<<"shortest path weight: "<<ans;
}