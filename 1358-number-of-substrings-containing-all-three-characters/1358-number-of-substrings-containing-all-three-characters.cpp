class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int n = s.length();
        unordered_map<char,int> mp;

        int i = 0, j = 0;
        int count = 0;

        while(j < n) {
            // pehle j ko include karo
            mp[s[j]]++;

            // jab tak window valid hai (a,b,c present)
            while(mp.size() == 3) {
                // yahan se n-1 tak saare substrings valid honge
                count += (n - j);

                // ab left se shrink karo
                mp[s[i]]--;
                if(mp[s[i]] == 0) {
                    mp.erase(s[i]);   // important
                }
                i++;
            }

            // ab window invalid ho chuki hogi, so j aage badhao
            j++;
        }

        return count;
    }
};