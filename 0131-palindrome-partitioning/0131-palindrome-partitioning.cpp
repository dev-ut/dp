class Solution {
public:

bool ispalindrome(const string &s, int start, int end) {
    while (start < end) {
        if (s[start++] != s[end--]) {
            return false;
        }
        // start++;
        // end--;
    }
    return true;
}

void combination(string s, vector<string> &ans, vector<vector<string>> &fans, int index) {
    if (index == s.size()) {
        fans.push_back(ans);
        return;
    }

    for (int i = index; i < s.size(); i++) {
        if (ispalindrome(s, index, i)) {
            ans.push_back(s.substr(index, i - index + 1)); // Add palindrome substring to ans
            combination(s, ans, fans, i + 1); // Recur for remaining string
            ans.pop_back(); // Backtrack to explore other combinations
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<string> ans;
    vector<vector<string>> fans;
    combination(s, ans, fans, 0);
    return fans;
}

};