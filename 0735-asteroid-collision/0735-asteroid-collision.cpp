class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        int n = asteroids.size();
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            if (asteroids[i] < 0) // agr wo negative asteroid hai
            {
                // jab tak stack me positive asteroid hai jo chhota hai, pop karo
                while (st.size() > 0 && st.top() > 0 && abs(asteroids[i]) > abs(st.top()))  
                {
                    st.pop();
                }

                // same size wale destroy ho jate hai
                if (st.size() > 0 && st.top() > 0 && abs(st.top()) == abs(asteroids[i]))
                {
                    st.pop();
                }
                // agar stack empty ho gaya ya top negative hai, to negative ko push karo
                else if (st.empty() || st.top() < 0)
                {
                    st.push(asteroids[i]);
                }
            }
            else 
            {  
                // positive asteroid simply push
                st.push(asteroids[i]);
            }
        }

        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--)
        {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};
