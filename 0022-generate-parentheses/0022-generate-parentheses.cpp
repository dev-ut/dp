class Solution {
public:
void generate(vector<string>&fans, string str,int ob,int cb,int n)
{
    if(cb==n)
    {
        fans.push_back(str);
        return ;
    }
    if(ob<n)
    {
        generate(fans,str+'(',ob+1,cb,n);
    }
    if(cb<ob)
    {
         generate(fans,str+')',ob,cb+1,n);
    }
}
    vector<string> generateParenthesis(int n) 
    {
        vector<string>fans;
        string str="";
        generate(fans,str,0,0,n);
        return fans;

    }
};