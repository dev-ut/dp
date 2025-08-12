class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int n=image.size();
        int m=image[0].size();

        // now we will save the oldcolor coz everytime the color is given diffrent in matrix and we ill be using bfs
        int currentcolor=image[sr][sc];

        if(currentcolor==color) return image;

        queue<pair<int,int>>q;
        q.push({sr,sc});
        // and update the cuurent box to the color we have to assign 
        image[sr][sc]=color;

        while(q.size()>0)
        {
            int size=q.size();
            for (int i = 0; i < size; i++)
            {
                auto [r, c] = q.front();
                q.pop();

                // up
                if (r-1 >= 0 && image[r-1][c] == currentcolor) {
                    image[r-1][c] = color;
                    q.push({r-1, c});
                }
                // down
                if (r+1 < n && image[r+1][c] == currentcolor) {
                    image[r+1][c] = color;
                    q.push({r+1, c});
                }
                // left
                if (c-1 >= 0 && image[r][c-1] == currentcolor) {
                    image[r][c-1] = color;
                    q.push({r, c-1});
                }
                // right
                if (c+1 < m && image[r][c+1] == currentcolor) {
                    image[r][c+1] = color;
                    q.push({r, c+1});

            }
        }
        }

        return image;
    }
};