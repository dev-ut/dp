class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int time = 0;

        // Step 1: Add all initially rotten oranges by aading there row and colm or location 
        for (int row = 0; row < n; row++) 
        {
            for (int col = 0; col < m; col++) 
            {
                if (grid[row][col] == 2) 
                {
                    q.push({row, col});
                }
            }
        }

        while (!q.empty()) 
        {
            int size = q.size();         // Kitne rotten oranges hai is minute me
            bool Rothua = false;

            for (int i = 0; i < size; i++) 
            {
                auto [row, col] = q.front();
                q.pop();

                // UP
                if (row - 1 >= 0 && grid[row - 1][col] == 1) 
                {
                    grid[row - 1][col] = 2;
                    q.push({row - 1, col});
                    Rothua = true;
                }

                // DOWN
                if (row + 1 < n && grid[row + 1][col] == 1) 
                {
                    grid[row + 1][col] = 2;
                    q.push({row + 1, col});
                    Rothua = true;
                }

                // LEFT
                if (col - 1 >= 0 && grid[row][col - 1] == 1) 
                {
                    grid[row][col - 1] = 2;
                    q.push({row, col - 1});
                    Rothua = true;
                }

                // RIGHT
                if (col + 1 < m && grid[row][col + 1] == 1) 
                {
                    grid[row][col + 1] = 2;
                    q.push({row, col + 1});
                    Rothua = true;
                }
            }

            if (Rothua==true) time++;  // Is minute me kuch fresh orange rot hua? time++
        }

        // Final check for any remaining fresh orange
        for (int row = 0; row < n; row++) 
        {
            for (int col = 0; col < m; col++) 
            {
                if (grid[row][col] == 1) return -1;
            }
        }

        return time;
    }
};

