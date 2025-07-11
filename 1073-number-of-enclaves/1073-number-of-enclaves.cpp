class Solution {
public:
void bfs(vector<vector<int>>& grid, int sr, int sc)
{
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;
    q.push({sr, sc});
    grid[sr][sc] = 0; // mark visited directly in grid

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();

        // UP
        if (r - 1 >= 0 && grid[r - 1][c] == 1)
        {
            grid[r - 1][c] = 0;
            q.push({r - 1, c});
        }

        // DOWN
        if (r + 1 < n && grid[r + 1][c] == 1)
        {
            grid[r + 1][c] = 0;
            q.push({r + 1, c});
        }

        // LEFT
        if (c - 1 >= 0 && grid[r][c - 1] == 1)
        {
            grid[r][c - 1] = 0;
            q.push({r, c - 1});
        }

        // RIGHT
        if (c + 1 < m && grid[r][c + 1] == 1)
        {
            grid[r][c + 1] = 0;
            q.push({r, c + 1});
        }
    }
}

int numEnclaves(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    // Step 1: BFS on all boundary 1s to mark visited
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 1)
        {
             bfs(grid, i, 0);   // its the first vertical line  
        }
           
        if (grid[i][m - 1] == 1 )
        {
           bfs(grid, i, m - 1);  // its the last vertical line
        }
        
           
    }

    for (int j = 0; j < m; j++)
    {
        if (grid[0][j] == 1 )   // ist horizontal line
        {
           bfs(grid, 0, j);
        }
            
        if (grid[n - 1][j] == 1 )   // 2nd horizontal line
        {
           bfs(grid, n - 1, j);
        }
            
    }

    
    // Step 2: Count remaining 1s in the grid
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                count++;
        }
    }

    return count;
}
};
