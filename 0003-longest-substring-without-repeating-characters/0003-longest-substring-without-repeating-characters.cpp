class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
      int n=s.length();
      unordered_set<char>st;
      int i=0;
      int j=0;
      int mwsum=0;
      while(j<n)
      {
        if(st.find(s[j])!=st.end())
        {
            st.erase(s[i]);
            i++;  // shrink the window
        }
        else
        {
            st.insert(s[j]);
            mwsum=max(mwsum,j-i+1);
            j++;
        }
      }
      return mwsum;  
    }
};