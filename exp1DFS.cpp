#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, set<int>> &adjlist, unordered_map<int, bool> &visited, vector<int> &component, int node)
{
    component.push_back(node);
    visited[node] = true;
    for (auto i : adjlist[node])
    {
        if (!visited[i])
        {
            dfs(adjlist, visited, component, i);
        }
    }
}

vector<vector<int>> DFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjlist;
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;

    for (int i = 0; i < edges.size(); i++)
    {

        int u = edges[i].first;
        int v = edges[i].second;

        adjlist[u].insert(v);
        adjlist[v].insert(u);
    }

    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(adjlist, visited, component, i);
            ans.push_back(component);
        }
    }
    return ans;
}

int main()
{
    vector<pair<int, int>> edges = {{0, 2}, {0, 1}, {1, 2}, {3, 4}};
    vector<vector<int>> res = DFS(5, edges);
    for (auto i : res)
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
