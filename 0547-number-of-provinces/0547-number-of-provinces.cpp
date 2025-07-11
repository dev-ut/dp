class Solution {
public:
    void dfs(int row, vector<vector<int>>& isConnected, vector<int>& visited)
    {
        visited[row] = 1;

        for (int j= 0; j < isConnected.size(); j++)  // col through all cities
        {
            if (isConnected[row][j] == 1 && visited[j] == 0)
            {
                dfs(j, isConnected, visited); // visit the connected city
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        int provinces = 0;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++)   // why we have put looop is to accesss the uncooncted part throuygh visted array 
        {
            if (visited[i]==0) /// vsited nhi hi to vsitr kro 
            {
                dfs(i, isConnected, visited); // 
                provinces++; // new province mil gaya
            }
        }

        return provinces;
    }
};
