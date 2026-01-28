class Solution {
public:
void solve(vector<vector<char>>& board, string &word, int windx, int r, int c, bool &flag)
{
    if(windx == word.length()-1)
    {
        flag = true;
        return;
    }

    char temp = board[r][c];
    board[r][c] = '.';

    // up
    if(r-1 >= 0 && board[r-1][c] == word[windx+1])
        solve(board, word, windx+1, r-1, c, flag);

    // down
    if(r+1 < board.size() && board[r+1][c] == word[windx+1])
        solve(board, word, windx+1, r+1, c, flag);

    // left
    if(c-1 >= 0 && board[r][c-1] == word[windx+1])
        solve(board, word, windx+1, r, c-1, flag);

    // right
    if(c+1 < board[0].size() && board[r][c+1] == word[windx+1])
        solve(board, word, windx+1, r, c+1, flag);

    board[r][c] = temp; // backtrack
}

    bool exist(vector<vector<char>>& board, string word) 
    {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    bool flag=false;
                    solve(board,word,0,i,j,flag);
                    if(flag==true) return true;
                }
            }
        }
     return false;   
    }
};

// note : Mark visited” kyun zaroori hai?

// Tu bol raha:

// “agar word us index par nahi hua to udhar jaayega hi kyu?”

// Ye baat character matching ke liye sahi hai 👍
// Lekin visited marking character matching ke liye nahi,
// 👉 cycle todne ke liye hoti hai

// upar wala c already traversed tha, wo condition kahin check kyu nahi hui?”

// Bahut badhiya observation 👌

// Ye condition yahan hidden hoti hai:

// if(board[nr][nc] == word[nextIndex])


// Aur kyuki hum visited cell ko '.' bana dete hain,
// to wo kabhi match hi nahi karega word ke character se.