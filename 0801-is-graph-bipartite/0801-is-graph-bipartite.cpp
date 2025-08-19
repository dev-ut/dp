class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // 0 = blue
        // 1 = red
        int v = graph.size();
        vector<int> visited(v, -1);  // -1 means unvisited

        for (int i = 0; i < v; i++) {
            // agar ye node abhi tak unvisited hai tabhi BFS karo
            if (visited[i] == -1) {
                queue<pair<int,int>> q;
                q.push({i, 1});  
                visited[i] = 1;  // is node ko color kar diya

                while (q.size() > 0) {
                    auto [node, color] = q.front();
                    q.pop();

                    // sabhi neighbour check
                    for (int j = 0; j < graph[node].size(); j++) {
                        
                        if (visited[graph[node][j]] == -1) {
                            // agar abhi visit nahi hua, to opposite color do
                            visited[graph[node][j]] = 1 - visited[node];
                            q.push({graph[node][j], visited[graph[node][j]]});
                        } 
                        else {
                            // agar same color mila to bipartite nahi hai
                            if (visited[graph[node][j]] == visited[node]) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};

