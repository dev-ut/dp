class Solution {
public:
void bfs(vector<vector<int>>& mat) 
{
    int n = mat.size();
    int m = mat[0].size();
    queue<pair<int, int>> q;

    // pehle sab 0 wale cell queue me daal do, baaki ko -1 mark karo
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
                q.push({i, j});
            } else {
                mat[i][j] = -1;
            }
        }
    }

    while (q.size() > 0) {
        auto [r, c] = q.front();
        q.pop();

        // UP
        if (r - 1 >= 0 && mat[r - 1][c] == -1) {
            mat[r - 1][c] = mat[r][c] + 1;
            q.push({r - 1, c});
        }

        // DOWN
        if (r + 1 < n && mat[r + 1][c] == -1) {
            mat[r + 1][c] = mat[r][c] + 1;
            q.push({r + 1, c});
        }

        // LEFT
        if (c - 1 >= 0 && mat[r][c - 1] == -1) {
            mat[r][c - 1] = mat[r][c] + 1;
            q.push({r, c - 1});
        }

        // RIGHT
        if (c + 1 < m && mat[r][c + 1] == -1) {
            mat[r][c + 1] = mat[r][c] + 1;
            q.push({r, c + 1});
        }
    }
}

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
    bfs(mat);  // matrix ko update kar diya jaayega
    return mat;
    }
};