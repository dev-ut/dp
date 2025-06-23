class Solution {
public:
void sfound(vector<vector<char>>& board, string word,int windx,int r,int c,bool &flag)
{
    if(windx==word.length())
    {
        flag = true;
            return;
    }


    if(c<0 ||c>=board[0].size()||r<0||r>=board.size()||board[r][c]!= word[windx]) return ;

     // Mark as visited
        char temp = board[r][c];
        board[r][c] = '.';

    // moving in right direction 
    sfound(board,word,windx+1,r,c+1,flag);
    // moving in down direction 
    sfound(board,word,windx+1,r+1,c,flag);
     // moving in left direction 
    sfound(board,word,windx+1,r,c-1,flag);
     // moving inup direction 
    sfound(board,word,windx+1,r-1,c,flag);

    // mark it unvisted and rstore the element
    board[r][c] = temp;  /// backtrack




}
    bool exist(vector<vector<char>>& board, string word) 
    {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0]) // mtlb ki jaise hi first leete mile ap search krna chlu kro in all possible directuos
                {
                    bool flag=false;
                    sfound(board,word,0,i,j,flag);
                    if(flag==true) return true;
                }
            }
        }
        return false;
    }
};