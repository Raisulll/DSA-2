#include <bits/stdc++.h>
using namespace std;
map<char, vector<pair<char, int>>> adj;
map<char, int> dis;
map<char,char>par;
bool bellmanFord(char src)
{
    for(auto it:adj)
    {
        dis[it.first]=1e9;
    }
    dis[src]=0;
    int n =adj.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (auto it : adj)
        {
            char u = it.first;
            for (auto it2 : adj[u])
            {
                char v = it2.first;
                int wt = it2.second;
                if (dis[u] + wt < dis[v])
                {
                    dis[v] = dis[u] + wt;
                    par[v]=u;
                }
            }
        }
    }
    for (auto it : adj)
    {
        char u = it.first;
        for (auto it2 : adj[u])
        {
            char v = it2.first;
            int wt = it2.second;
            if (dis[u] + wt < dis[v])
            {
                return false; // Negative cycle detected
            }
        }
    }
    return true;
}
void print()
{
    for (auto it : adj)
    {
        char u = it.first;
        for (auto it2 : adj[u])
        {
            char v = it2.first;
            int wt = it2.second;
            cout << u << " " << v << " " << wt << endl;
        }
    }
}
int main()
{
    cout << "Enter the number of edges" << endl;
    int n;
    cin >> n;
    cout << "Enter the edges" << endl;
    for (int i = 0; i < n; ++i)
    {
        char u, v;
        int wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    cout << "Enter the source vertex" << endl;
    char src;
    cin >> src;
    if (bellmanFord(src))
    {
        cout << "No negative cycle detected" << endl;
        cout<<"Shortest path :\n";
        vector<char>p;
        for(auto it:dis)
        {
            char ch=it.first;
            while(ch!=src)
            {
                p.push_back(ch);
                ch=par[ch];
            }
            p.push_back(ch);
            reverse(p.begin(),p.end());
            for(auto it1:p)
            {
                cout<<it1<<" ";
            }
            cout<<it.second<<endl;
            p.clear();
        }
    }
    else
    {
        cout << "Negative cycle detected" << endl;
    }
    return 0;
}
/*
6 
A B 2
B C 3
C D 2
A E 1
E F 4
F D 3
A 
*/