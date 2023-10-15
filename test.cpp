#include <bits/stdc++.h>
using namespace std;
map<char, vector<pair<char, int>>> adj;

bool bellmanFord(map<char, int> &dis, char src)
{
    int n = dis.size();
    for (int i = 1; i <= n - 1; ++i)
    {
        for (auto it : adj)
        {
            char u = it.first;//A->b,10,c,2
            for (auto it2 : adj[u])
            {
                char v = it2.first;
                int wt = it2.second;
                if (dis[u] + wt < dis[v])
                {
                    dis[v] = dis[u] + wt;
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
    map<char, int> dis;
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
        dis[u] = INT_MAX;
        dis[v] = INT_MAX;
    }
    cout << "Enter the source vertex" << endl;
    char src;
    cin >> src;
    dis[src] = 0;
    if (bellmanFord(dis, src))
    {
        cout << "No negative cycle detected" << endl;
        cout << "Shortest distance from source vertex " << src << endl;
        for (auto it : dis)
        {
            cout << it.first << " " << it.second << endl;
        }
    }
    else
    {
        cout << "Negative cycle detected" << endl;
    }
    return 0;
}