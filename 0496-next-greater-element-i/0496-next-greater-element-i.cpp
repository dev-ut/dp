class Solution {
public:
vector<int> nge(vector<int>& nums2) 
{
    stack<int> st;
    int n = nums2.size();

    // Answer vector ko n size ka bana rahe hain aur initialize kar rahe hain -1 se
    vector<int> ans(n);
    ans[n-1] = -1;  // Last element ke liye pehle se -1 set kar diya
    st.push(nums2[n-1]);

    for (int i = n - 2; i >= 0; i--) 
    {
        while (st.size() > 0 && st.top() <= nums2[i]) 
        {
            st.pop();
        }

        if (st.size() == 0) ans[i] = -1;
        else ans[i] = st.top();

        st.push(nums2[i]);
    }

    return ans;  // Answer ko return kar rahe hain
}


vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
{
    vector<int> ans = nge(nums2);  // Pehle NGE nikaal lo

    // Ab create a hashmap
    unordered_map<int, int> mp;

    for (int i = 0; i < nums2.size(); i++) 
    {
        mp[nums2[i]] = ans[i];  // Map ho gaya
    }

    // Ab nums1 ko traverse karke NGE find karo
    vector<int> result;  // Final result array

    for (int i = 0; i < nums1.size(); i++) 
    {
        if (mp.find(nums1[i]) != mp.end()) 
        {
            result.push_back(mp[nums1[i]]);  // nums1 ke element ka NGE uthao
        } else 
        {
            result.push_back(-1);  // Agar nahi mila to -1 daal do
        }
    }

    return result;  // Final result return karo
}
};