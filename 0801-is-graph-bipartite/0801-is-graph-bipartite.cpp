class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int v = graph.size();
        vector<int> visited(v, -1); // -1 = unvisited

        for(int i = 0; i < v; i++) // handle disconnected graph
        {
            if(visited[i] != -1) continue; // already visited

            queue<pair<int,int>> q; // store node and its color
            q.push({i, 0});     // start with color 0
            visited[i] = 0;

            while(!q.empty())
            {
                auto [node, color] = q.front();
                q.pop();

                for(int j = 0; j < graph[node].size(); j++)
                {
                    if(visited[graph[node][j]] == -1)
                    {
                        visited[graph[node][j]] = 1 - color; // assign opposite color
                        q.push({graph[node][j], visited[graph[node][j]]});
                    }
                    else
                    {
                        if(visited[graph[node][j]] == color)
                            return false; // same color -> not bipartite
                    }
                }
            }
        }

        return true;
    }
};
