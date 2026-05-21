#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>parent;
vector<int>Rank;
int find(int node){
    if(parent[node]==node) return node;
    return parent[node] = find(parent[node]);
}

void union_op(int u,int v){
    int pu = find(u);
    int pv = find(v);

    if(pu==pv) return;

    else if(Rank[pu]==Rank[pv]){
        parent[pv] = pu;
        Rank[pu]++;
    }

    else if(Rank[pu]>Rank[pv]) parent[pv] = pu;
    else parent[pu] = pv;
}
int main(){
    int n;
    cout<<"enter no. of nodes: ";
    cin>>n;

    int e;
    cout<<"Enter edges: ";
    cin>>e;

    vector<pair<int,pair<int,int>>>adj;
    for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj.push_back({wt,{u,v}});
    }
    parent.resize(n);
    Rank.resize(n,0);

    sort(adj.begin(),adj.end());
    reverse(adj.begin(),adj.end());

    for(int i=0;i<n;i++){
        parent[i] = i;
    }

    int max_cost = 0;

    for(int i=0;i<adj.size();i++){
        int wt = adj[i].first;
        int u = adj[i].second.first;
        int v = adj[i].second.second;

        if(find(u)!=find(v)){
            union_op(u,v);
            max_cost+=wt;
            cout<<u<<"-"<<v<<":"<<wt<<endl;
        }

    }

    cout<<"Max_cost: "<<max_cost;



}