class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
       int n=fruits.size();
       unordered_map<int,int>mp;
       int mxlength=0;
       int i=0;
       int j=0;
       while(j<n)
       {
        mp[fruits[j]]++;
        if(mp.size()>2)
        {
            while(mp.size()>2)
            {
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0)
                {
                    mp.erase(fruits[i]);
                }
                i++;// shirnk the winndow
            }
        }
          mxlength=max(mxlength,j-i+1); // the 2 types of fruits it can hold and map wull have the trace of no of elemnts in map
          j++;
       } 
       return mxlength;   
    }
};