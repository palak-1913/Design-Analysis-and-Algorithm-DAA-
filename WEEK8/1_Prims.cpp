#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
int prims(int src,vector<vector<pair<int,int>>>&adj,vector<int>&visit,int n){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int min_cost=0;

    pq.push({0,src});

    while(!pq.empty()){
        pair<int,int>p = pq.top();
        int u = p.second;
        int wt = p.first;
        pq.pop();

        if(visit[u]==false){
            visit[u] = true;
            min_cost+=wt;

            for(int i=0;i<adj[u].size();i++){
                int v = adj[u][i].second;
                int w = adj[u][i].first;

                if(visit[v]==false){
                    pq.push({w,v});
                }
                
            }
        }

    }
    return min_cost;
    
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
        adj[v].push_back({wt,u});
        
        
    }

    int src;
    cout<<"Enter source: ";
    cin>>src;

    vector<int>visit(n+1,false);
    cout<<prims(src,adj,visit,n);

}