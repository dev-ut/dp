class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    // ek extra vector banaya jisme final answer store hoga
    vector<int> ans(m+n);

    int i = 0; // nums1 ke liye
    int j = 0; // nums2 ke liye
    int idx = 0; // ans ke liye

    // jab tak dono me elements hain compare karte raho
    while(i < m && j < n)
    {
        if(nums1[i] <= nums2[j])
        {
            ans[idx] = nums1[i];
            idx++;
            i++;
        }
        else
        {
            ans[idx] = nums2[j];
            idx++;
            j++;
        }
    }

    // agar nums1 me elements bach gaye
    while(i < m)
    {
        ans[idx] = nums1[i];
        idx++;
        i++;
    }

    // agar nums2 me elements bach gaye
    while(j < n)
    {
        ans[idx] = nums2[j];
        idx++;
        j++;
    }

    // ab ans ke saare elements nums1 me daal do
    for(int i = 0; i < ans.size(); i++)
    {
        nums1[i] = ans[i];
    }
}
};
