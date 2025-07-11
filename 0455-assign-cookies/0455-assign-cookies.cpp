class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        int n=g.size();
        int m=s.size();
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
            int i=0;
            int j=0;
      while(i<n && j<m)
      {
        if(s[j] >= g[i])
        {
            i++;    // mllb ki wo satistfied hua hai aur i is the count
        }

        j++ ;//// ye to hoga hi
      }
       return i;
    }
};