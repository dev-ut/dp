class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        //if length hi same nhi hui to anagaram kis baat ka 
        if(s.length()!=t.length()) return false;

        unordered_map<char,int>m1;
        unordered_map<char,int>m2;

        // filling themap 
        for(int i=0;i<s.length();i++)
        {
            m1[s[i]]++;
        }
        for(int i=0;i<t.length();i++)
        {
            m2[t[i]]++;
        }

        //ab we will just check the frequency
        for(auto it : m1)
        {
            char key=it.first;
            int frq=it.second;

            if(m2[key]!=frq) return false;
        } 

        return true;

    }
};