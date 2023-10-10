#include <bits/stdc++.h>
using namespace std;
void BellmanFord(int n, int m, char src, char dest, vector<vector<pair<char, int>>> &edges)
{
    vector<int> dist(n + 1, INT_MAX);
    vector<char> parent(n + 1, '\0');
    dist[src - 'A' + 1] = 0;

    for (int i = 0; i < n; i++) // n-1 times relaxation
    {
        for (int j = 1; j <= n; j++) // iterates through each vertex
        {
            for (int k = 0; k < edges[j].size(); k++) // iterates through all the outgoing edges of the currrent vertex j
            {
                char u = j + 'A' - 1;
                char v = edges[j][k].first;
                int wt = edges[j][k].second;
                if (dist[j] != INT_MAX && ((dist[j] + wt) < dist[v - 'A' + 1]))
                {
                    dist[v - 'A' + 1] = dist[j] + wt;
                    parent[v - 'A' + 1] = u;
                }
            }
        }
    }

    vector<char> path;
    char cur = dest;
    while (cur != src)
    {
        path.push_back(cur);
        cur = parent[cur - 'A' + 1];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
    cout << "Vertex distances: " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << char('A' + i - 1) << ": " << dist[i] << endl;
    }
    cout << "Shortest path from " << src << " to " << dest << " is: ";
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }
    cout << endl;
}
int main()
{
    int v, e;
    cout << "No of vertices: ";
    cin >> v;
    cout << "No of edges: ";
    cin >> e;
    vector<vector<pair<char, int>>> adj(v + 1);

    for (int i = 0; i < e; i++)
    {
        char u, v;
        int wt;
        cin >> u >> v >> wt;
        adj[u - 'A' + 1].push_back({v, wt});
    }
    char src, dest;
    cout << "Enter source node: ";
    cin >> src;
    cout << "Enter destination node: ";
    cin >> dest;
    BellmanFord(v, e, src, dest, adj);
}
/*
5
7
A B 2
A C 4
B C 1
B D 7
C E 3
D E 1
E A -6
A
E
*/