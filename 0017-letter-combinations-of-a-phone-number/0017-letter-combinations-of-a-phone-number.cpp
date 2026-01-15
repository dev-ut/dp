class Solution {
public:
void combo(string &digits, vector<string>&fans,string ans,int indx,unordered_map<char,string>&mp)
    
    {
      if(indx==digits.size())
      {
        fans.push_back(ans);
        return;
      }

      string str=mp[digits[indx]];
      for(int i=0;i<str.length();i++)
      {
        //atke
        ans.push_back(str[i]);
        combo(digits,fans,ans,indx+1,mp);
        ans.pop_back();
        
      }
    } 
    vector<string> letterCombinations(string digits) 
    {
        // first of all we are going to create a map which can store which digit(key) is associated with which 
        // value(string)
        unordered_map<char,string>mp;
        vector<string>fans;
        string ans;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        combo(digits,fans,ans,0,mp);
        return fans;        
    }
};