class Solution {
public:
    void rotate(vector<int>& arr, int k) 
    {
         int n = arr.size();
    
        k = k % n; // Effective rotation steps

        if (n == 0 || k == 0 || k == n) 
        {
        return ; // No need to rotate
        }

        vector<int> temp(k); // Extra array to store elements to be moved

    // Copy the last k elements from the array to the temp array
    for (int i = 0; i < k; i++) 
    {
        temp[i] = arr[n - k + i];
    }

    // Shift the elements to the right by k positions
    for (int i = n - 1; i >= k; i--) 
    {
        arr[i] = arr[i - k];
    }

    // Copy the last k elements from temp array back to the original array
    for (int i = 0; i < k; i++) 
    {
        arr[i] = temp[i];
    }
    return;
 }
};