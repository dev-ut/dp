class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
       // we will be generating the false index an solving it using binary search 
       int r=matrix.size();
       int c=matrix[0].size();
       int lo=0;
       int hi=(r*c)-1; 
       while(lo<=hi)
       {
        int mid=lo+(hi-lo)/2;
        int ro=mid/c;
        int co=mid%c;
        if(matrix[ro][co]==target) return true;
        else if(target<matrix[ro][co])
        {
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
        }
       }
 return false;
    }
};