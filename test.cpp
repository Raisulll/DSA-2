#include <bits/stdc++.h>
using namespace std;
void BellmanFord(int n, char src, vector<vector<pair<char, int>>> &edges, vector<int> &dist, vector<char> &parent)
{
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

    int flag = 0;
    for (int j = 1; j <= n; j++) // iterates through each vertex
    {
        for (int k = 0; k < edges[j].size(); k++) // iterates through all the outgoing edges of the currrent vertex j
        {
            char u = j + 'A' - 1;
            char v = edges[j][k].first;
            int wt = edges[j][k].second;

            if (dist[j] != INT_MAX && ((dist[j] + wt) < dist[v - 'A' + 1]))
            {
                flag = 1;
            }
        }
    }
    if (flag == 0)
    {
        cout << "NO NEG CYCLE" << endl;
        cout << "Vertex distances: " << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << char('A' + i - 1) << ": " << dist[i] << endl;
        }
    }
    else
        cout << "NEG CYCLE FOUND" << endl;
}
void printPath(int n, char src, char dest, vector<int> &dist, vector<char> &parent)
{
    vector<char> path;
    char cur = dest;
    while (cur != src)
    {
        path.push_back(cur);
        cur = parent[cur - 'A' + 1];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
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
    vector<int> dist(v + 1, INT_MAX);
    vector<char> parent(v + 1, '\0');
    set<char> st;
    vector<vector<pair<char, int>>> adj(v + 1);
    for (int i = 0; i < e; i++)
    {
        char u, v;
        int wt;
        cin >> u >> v >> wt;
        adj[u - 'A' + 1].push_back({v, wt});
        st.insert(u);
        st.insert(v);
    }
    char src;
    cout << "Enter source node: ";
    cin >> src;
    BellmanFord(v, src, adj, dist, parent);
    for (auto it : st)
    {
        if (it != src)
        {
            printPath(v, src, it, dist, parent);
        }
    }
}
/*
5
7
A B 3
A C 1
B D 1
B E 2
C B 1
C D 4
D E 3
A
*/