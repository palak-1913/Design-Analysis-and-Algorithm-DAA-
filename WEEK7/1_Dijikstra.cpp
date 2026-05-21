#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
void dijikstra(int src,int dest,vector<vector<pair<int,int>> >&adj,vector<int>&dist){
    dist[src] = 0;
    priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>> >pq;
    pq.push({0,src});

    while(pq.size()>0){
        int u = pq.top().second;
        pq.pop();

        for(int i=0;i<adj[u].size();i++){//edges relaxation step
            int v = adj[u][i].second;
            int wt = adj[u][i].first;

            if(dist[v]>dist[u]+wt){
                dist[v] = dist[u] + wt;
                pq.push({dist[v],v});
            }
        }
    }

    for(int i=0;i<adj.size();i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"enteer the nodes: ";
    cin>>n;

    int e;
    cout<<"enter the no. of edges: ";
    cin>>e;

    vector<vector<pair<int,int>> >adj(n);
    for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({wt,v});
    }

    int src;
    cout<<"enter src: ";
    cin>>src;

    int dest;
    cout<<"enter dest: ";
    cin>>dest;

    vector<int>dist(n,INT_MAX);
    vector<int>parent(n,-1);
    dijikstra(src,dest,adj,dist);
}