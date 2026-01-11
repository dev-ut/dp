class Solution {
public:
void generate(int n, string ans, vector<string> &fans, int ob, int cb) 
{
    // Agar close brackets (cb) ki count n ke barabar ho gayi, to string push karke return karo.
    if (cb == n) 
    {
        fans.push_back(ans);
        return;
    }

    // Agar open brackets (ob) ki count n se kam hai, ek open bracket daalo aur aage badho.
    if (ob < n) 
        generate(n, ans + '(', fans, ob + 1, cb);

    // Agar close brackets ki count open se kam hai, ek close bracket daalo aur aage badho.
    if (cb < ob) 
        generate(n, ans + ')', fans, ob, cb + 1);
}

    vector<string> generateParenthesis(int n) 
    {
        vector<string> fans;
        string ans="";
        generate(n,ans,fans,0,0);
        return fans;
    }

};