class Solution {
public:
vector<int> nextGreaterElements(vector<int>& nums) 
{
    int n = nums.size();         // Array ka size
    vector<int> ans(n);      // Answer vector ko -1 se initialize kiya (by default -1 hoga agar next greater element na mile)
    stack<int> st;               // Monotonic stack use karenge jisme elements dalenge

    // Hum 2*n-1 se lekar 0 tak reverse loop kar rahe hain taaki circular array ka effect aaye
    for (int i = 2 * n - 1; i >= 0; i--) 
    {
        int actualindx = i % n;  // Circular index nikalne ke liye mod operation

        // Monotonic stack ke 3 steps apply karenge:
        
        // Step 1: Jab tak stack ka top element current element se chhota hai, stack se pop karte rahenge
        while (st.size()>0 && st.top() <= nums[actualindx]) 
        {
            st.pop();  // Chhote elements ko hata rahe hain kyunki hume next greater element chahiye
        }

        // Step 2: Agar stack empty ho gaya, iska matlab koi greater element nahi mila
        if (st.size()==0) 
        {
            ans[actualindx] = -1;  // Answer me -1 daal do
        } 
        else 
        {
            ans[actualindx] = st.top();  // Jo stack ka top hai, wahi next greater element hai
        }

        // Step 3: Current element ko stack me push kar do
        st.push(nums[actualindx]);  
    }

    return ans;  // Final result return karenge

}

};