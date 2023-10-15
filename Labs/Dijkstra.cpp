#include <bits/stdc++.h>
using namespace std;
void dijkstra(map<string, vector<pair<string, int>>> &adj, map<string, string> &par, map<string, int>&dis, string src, string des)
{
    priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
    for(auto it:adj)
    {
        dis[it.first]=1e9;
    }
    dis[src]=0;
    pq.push({0,src});
    while(!pq.empty())
    {
        pair<int,string>x=pq.top();
        pq.pop();
        string p=x.second;
        int d=x.first;
        for(auto it:adj[x.second])
        {
            if(dis[it.first]>d+it.second)
            {
                dis[it.first]=d+it.second;
                par[it.first]=p;
                pq.push({dis[it.first],it.first});
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    map<string, vector<pair<string, int>>> adj;
    map<string, string> par;
    map<string, int> dis;
    for (int i = 0; i < n; ++i)
    {
        string u, v;
        int w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    string src,des;
    cin>>src>>des;
    dijkstra(adj,par,dis,src,des);
    vector<string>path;
    while(des!=src)
    {
        path.push_back(des);
        des=par[des];
    }
    path.push_back(src);
    reverse(path.begin(),path.end());
    for(auto it:path)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
/*
6 6
A B 2
B C 3
C D 2
A E 1
E F 4
F D 3
A D
*/