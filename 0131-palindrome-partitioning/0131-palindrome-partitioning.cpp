class Solution {
public:
bool isPalindrome(string &s,int si,int ei)
{
    int i=si;
    int j=ei;
    while(i<=j)
    {
      if(s[i++]!=s[j--])
      {
       return false;
      }
    
    }
    return true;
}
void solve(string &s,int indx,vector<string>&ans,vector<vector<string>>&fans)
{
    // base cade
    if(indx==s.length())
    {
        fans.push_back(ans);
        return;
    }

    for(int i=indx;i<s.size();i++)  // devide krna chalu kro 
    {
       if(isPalindrome(s,indx,i)==true)
       {
        ans.push_back(s.substr(indx,i-indx+1));
        solve(s,i+1,ans,fans);
        // pop back as return
        ans.pop_back();
       }
    }
}
    vector<vector<string>> partition(string s) 
    {
        int n=s.length();
        vector<string>ans;
        vector<vector<string>>fans;
        solve(s,0,ans,fans);
        return fans;
    }
};