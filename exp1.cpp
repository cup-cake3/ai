#include <bits/stdc++.h>
using namespace std;



void makeAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{

    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int frontnode = q.front();
        q.pop();

        ans.push_back(frontnode);

        for (auto i : adjList[frontnode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    makeAdjList(adjList, edges);

    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}

int main()
{
    vector<pair<int, int>> edges = {{0, 1}, {0, 3}, {1, 2}, {2, 3}};
    vector<int> res = BFS(4, edges);

    for (auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}

