/*
There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.
*/
//Dijkstra based solution
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (vector<int> f : flights)
        {
            adj[f[0]].push_back({f[1], f[2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> Q;
        Q.push({0, src, K + 1});
        while (!Q.empty())
        {
            vector<int> top = Q.top();
            Q.pop();
            int d = top[0];
            int p = top[1];
            int e = top[2];
            if (p == dst)
                return d;
            if (e > 0)
            {
                for (pair<int, int> &p : adj[p])
                {
                    Q.push({d + p.second, p.first, e - 1});
                }
            }
        }
        return -1;
    }
};

//DP based Solution
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        int adj[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adj[i][j] = INT_MAX;
        for (int i = 0; i < flights.size(); i++)
        {
            adj[flights[i][0]][flights[i][1]] = flights[i][2];
        }
        int dp[n][n][K + 2];
        for (int e = 0; e <= K + 1; e++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dp[i][j][e] = INT_MAX;
                    if (e == 0 && i == j)
                        dp[i][j][e] = 0;
                    if (e == 1 && adj[i][j])
                        dp[i][j][e] = adj[i][j];
                    if (e > 1)
                    {
                        for (int a = 0; a < n; a++)
                        {
                            if (adj[i][a] != INT_MAX && i != a && j != a && dp[a][j][e - 1] != INT_MAX)
                            {
                                dp[i][j][e] = min(dp[i][j][e], dp[a][j][e - 1] + adj[i][a]);
                            }
                        }
                    }
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i <= K + 1; i++)
        {
            ans = min(ans, dp[src][dst][i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

//BFS Based Solution

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        int stops = 0;
        queue<pair<int, int>> q;
        vector<vector<pair<int, int>>> adj(n);
        for (vector<int> f : flights)
        {
            adj[f[0]].push_back({f[1], f[2]});
        }
        int ans = INT_MAX;
        q.push({src, 0});
        while (stops++ <= K)
        {
            int len = q.size();
            while (len--)
            {
                pair<int, int> top = q.front();
                q.pop();
                int u = top.first;
                int d = top.second;
                for (int i = 0; i < adj[u].size(); i++)
                {
                    int v = adj[u][i].first;
                    int w = adj[u][i].second;
                    if (w + d < ans)
                        q.push({v, d + w});
                    if (v == dst)
                    {
                        ans = min(ans, d + w);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

//DP solution 2

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        int dp[K + 2][n];
        for (int i = 0; i <= K + 1; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = INT_MAX;
        for (int i = 0; i <= K + 1; i++)
            dp[i][src] = 0;
        for (int i = 1; i <= K + 1; i++)
        {
            for (auto &f : flights)
            {
                int u = f[0];
                int v = f[1];
                int w = f[2];
                if (dp[i - 1][u] != INT_MAX)
                {
                    dp[i][v] = min(dp[i][v], dp[i - 1][u] + w);
                }
            }
        }
        return dp[K + 1][dst] == INT_MAX ? -1 : dp[K + 1][dst];
    }
};
