class Solution {
public:
bool isplaindrome(string&s,int si,int ei)
{
    int i=si;
    int j=ei;
    while(i<=j)
    {
        if(s[i++]!=s[j--]) return false;
    }
    return true;
}
 void solve(string &s,int indx,vector<string>ans,vector<vector<string>>&fans)
 {
    //base cae
    if(indx==s.size())
    {
        fans.push_back(ans);
        return ;
    }

    // since we have multiple starting points 

    for(int i=indx;i<s.size();i++)
    {
        if(isplaindrome(s,indx,i)==true)
        {
            ans.push_back(s.substr(indx,i-indx+1));
            solve(s,i+1,ans,fans); // i +1 ie current indx se 
            // backtact 
            ans.pop_back(); /// for exmple aa and include b to aab hogya whicis not a palindome
        }
    }
 }
    vector<vector<string>> partition(string s) 
    {
        int n =s.length();
        vector<string>ans;
        vector<vector<string>>fans;
        solve(s,0,ans,fans);
        return fans;
    }
};