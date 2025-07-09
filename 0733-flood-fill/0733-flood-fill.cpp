class Solution {
public:
 vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        // simmilar to rotten ornges 
        int n = image.size();
        int m = image[0].size();
        int oldColor = image[sr][sc];

        // Agar same color hai to kuch karne ki zarurat nahi
        if (oldColor == color) return image;

        // Queue banayi jisme har pixel ka {row, col} store karenge
        queue<pair<int, int>> q;
        q.push({sr, sc});

        // Start pixel ko paint kar diya
        image[sr][sc] = color;

        // Jab tak queue khali na ho jaaye
        while (q.size() > 0)
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                auto [row, col] = q.front();
                q.pop();

                // UP
                if (row - 1 >= 0 && image[row - 1][col] == oldColor)
                {
                    image[row - 1][col] = color;
                    q.push({row - 1, col});
                }

                // DOWN
                if (row + 1 < n && image[row + 1][col] == oldColor)
                {
                    image[row + 1][col] = color;
                    q.push({row + 1, col});
                }

                // LEFT
                if (col - 1 >= 0 && image[row][col - 1] == oldColor)
                {
                    image[row][col - 1] = color;
                    q.push({row, col - 1});
                }

                // RIGHT
                if (col + 1 < m && image[row][col + 1] == oldColor)
                {
                    image[row][col + 1] = color;
                    q.push({row, col + 1});
                }
            }
        }

        return image;
    }
};
