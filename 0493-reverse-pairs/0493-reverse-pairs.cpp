class Solution {
public:

int merge(vector<int>&a, vector<int>&b, vector<int>& nums)
{
    int n1 = a.size();
    int n2 = b.size();
    int count = 0;

    // Step 1: Count reverse pairs using two pointers
    int i = 0;
    int j = 0;
     

    // this loop sche cks the given conditions 
    while(i < n1 && j < n2)
    {
        if(a[i] > 2LL * b[j])  // 2LL to avoid overflow
        {
            // b[j] chota hai to aage ke sab b bhi honge
            count += (n1 - i); 
            j++;
        }
        else
        {
            i++;
        }
    }

    // thi is the gernral Merge two sorted arrays a and b into nums
    i = 0;
    j = 0;
    int k = 0;
    while(i < n1 && j < n2)
    {
        if(a[i] <= b[j])
        {
            nums[k++] = a[i++];
        }
        else
        {
            nums[k++] = b[j++];
        }
    }
    while(i < n1) nums[k++] = a[i++];  // bcha ho a to 
    while(j < n2) nums[k++] = b[j++];  //bcha ho b to 

    return count;
}

int reversePairs(vector<int>& nums) 
{
    int n = nums.size();
    if(n <= 1) return 0;

    int n1 = n / 2;
    int n2 = n - n1;

    // left aur right vector bna liya
    vector<int> a(n1);
    vector<int> b(n2);

    //copy in the vectores 

    for(int i = 0; i < n1; i++)
    {
        a[i] = nums[i];
    }

    for(int i = 0; i < n2; i++)
    {
        b[i] = nums[i + n1];
    }

    // recursive call for left and right half
    int count = 0;
    count += reversePairs(a);
    count += reversePairs(b);

    // merge step mein count + merge result
    count += merge(a, b, nums);

    return count;
}
};
