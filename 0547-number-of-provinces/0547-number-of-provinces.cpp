class Solution {
public:
    void dfs(int row, vector<vector<int>>& isConnected, vector<int>& visited)
    {
        visited[row] = 1;

        for (int col = 0; col < isConnected.size(); col++)  // col through all cities
        {
            if (isConnected[row][col] == 1 && visited[col] == 0)
            {
                dfs(col, isConnected, visited); // visit the connected city
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        int provinces = 0;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) 
        {
            if (visited[i]==0) 
            {
                dfs(i, isConnected, visited); // start DFS from unvisited city
                provinces++; // new province mil gaya
            }
        }

        return provinces;
    }
};
