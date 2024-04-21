// #include <bits/stdc++.h>
// using namespace std;

// vector<int> djikstra(int v, vector<vector<int>> adj[], int s)
// {
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//     vector<int> dist(v);

//     for (int i = 0; i < v; i++)
//     {
//         dist[i] = 1e9;
//     }
//     dist[s] = 0;
//     pq.push({0, s}); // dist,node

//     while (!pq.empty())
//     {
//         int dis = pq.top().first;
//         int node = pq.top().second;
//         pq.pop();

//         for (auto it : adj[node])
//         {
//             int edgeWeight = it[1];
//             int adjNode = it[0];

//             if (dis + edgeWeight < dist[adjNode])
//             {
//                 dist[adjNode] = dis + edgeWeight;
//                 pq.push({dist[adjNode], adjNode});
//             }
//         }
//     }
//     return dist;
// }

// int main()
// {
//     int v = 2;
//     int s = 0;
//     vector<vector<int>> adj[] = {{{1, 9}}, {{0, 9}}};

//     vector<int> a = djikstra(v, adj, s);
//     for (auto i : a)
//     {
//         cout << i << " ";
//     }
// }

#include <bits/stdc++.h>
using namespace std;

vector<int> djikstra(int v, vector<vector<int>> adj[], int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(v);

    for (int i = 0; i < v; i++)
    {
        dist[i] = 1e9;
    }
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int edgeWeight = it[1];
            int adjNode = it[0];

            if (dis + edgeWeight < dist[adjNode])
            {
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main()
{
    int v = 2;
    int s = 0;
    vector<vector<int>> adj[] = {{{1, 9}}, {{0, 9}}};

    vector<int> a = djikstra(v, adj, s);
    for (auto i : a)
    {
        cout << i << " ";
    }
}
