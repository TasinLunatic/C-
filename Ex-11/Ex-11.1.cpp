#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[1005];
bool visited[1005];

void dfs(int u)
{
    visited[u] = true;
    cout << u << " ";

    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (!visited[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    // Sort adjacency list to match sample output
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(1); // start DFS from node 1

    return 0;
}


