class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) 
    {
        int n=fruits.size();
        int m=baskets.size();
        int placed=0;
        int unplaced=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(fruits[i]<=baskets[j])
                {
                   placed++;
                   baskets[j]=-1;
                   break;
                }
            }
        }
       unplaced=n-placed;
       return unplaced;
    }
};