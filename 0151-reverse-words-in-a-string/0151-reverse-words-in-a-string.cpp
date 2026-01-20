class Solution {
public:
    string reverseWords(string s) 
{
    // words ko vector me daalenge
    vector<string> v;
    string words = "";

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] != ' ')
        {
            words += s[i];
        }
        else
        {
            if(!words.empty()) // trailing + multiple spaces handle
            {
                v.push_back(words);
                words = "";
            }
        }
    }

    // last word add (kyunki end me space nahi hota)
    if(words.length() > 0)
    {
        v.push_back(words);
    }

    // reverse order me add karenge
    string fans = "";

    for(int i = v.size() - 1; i >= 0; i--)
    {
        fans += v[i];
        if(i != 0) fans += " ";  // words ke beech space
    }

    return fans;
}

};