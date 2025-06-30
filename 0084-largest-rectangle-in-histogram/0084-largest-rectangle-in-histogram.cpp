class Solution {
public:

vector<int> pseidx(vector<int>& heights)
{
    int n = heights.size();
    vector<int> result(n); // Initialize result with size n
    stack<int> st; // Monotonic stack for PSE

    // 1. Find PSE (Previous Smaller Element)
    for (int i = 0; i < n; i++) 
    {
        // Agar current element se bada ya equal hai, toh pop karte raho
        while (!st.empty() && heights[st.top()] >= heights[i]) 
        {
            st.pop();
        }
        // Agar stack empty hai toh -1 daalo (left pe koi smaller nahi hai)
        if (st.empty()) 
        {
            result[i] = -1;
        } 
        // Agar nahi, toh top element ka index daalo
        else 
        {
            result[i] = st.top();
        }
        st.push(i); // current index ko stack mein push karo
    }
    
    return result;
}

vector<int> nseidx(vector<int>& heights)
{
    int n = heights.size();
    vector<int> result(n); // Initialize result with size n
    stack<int> st; // Monotonic stack for NSE

    // 2. Find NSE (Next Smaller Element)
    for (int i = n - 1; i >= 0; i--) 
    {
        // Agar current element se bada ya equal hai, toh pop karte raho
        while (!st.empty() && heights[st.top()] >= heights[i]) 
        {
            st.pop();
        }
        // Agar stack empty hai toh n daalo (right pe koi smaller nahi hai)
        if (st.empty()) 
        {
            result[i] = n;
        } 
        // Agar nahi, toh top element ka index daalo
        else 
        {
            result[i] = st.top();
        }
        st.push(i); // current index ko stack mein push karo
    }
   
    return result;
}

int largestRectangleArea(vector<int>& heights) 
{
    int n = heights.size(); // n ki size le lo

    vector<int> pse = pseidx(heights); 
    vector<int> nse = nseidx(heights); 
    
    // 3. Har bar rectangle ka area calculate karo
    int maxArea = 0;
    for (int i = 0; i < n; i++) 
    {
        int width = nse[i] - pse[i] - 1; // Rectangle ka width  bs isili ke liye humne pse or nse nikali hai taki range mil jye .
        int area = heights[i] * width; // Area calculate karo
        maxArea = max(maxArea, area); // Max area ko update karo
    }

    return maxArea; // Largest rectangle ka area return karo
}


};