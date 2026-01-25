class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
      int n=s.length();
      int mws=0;
      int i=0;
      int j=0;
      unordered_set<int>st;
      while(j<n)
      {
       // agr pehe sehi char presnt then delte it from set 
       if(st.find(s[j])!=st.end())
       {
         st.erase(s[i]);
         i++; // shrink the window 
       }
       else
       {
        st.insert(s[j]);
        mws=max(mws,j-i+1);
        j++;
       }
      }
      return mws;    
    }
};