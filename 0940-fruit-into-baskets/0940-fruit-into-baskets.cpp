class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
       int n=fruits.size();
       int maxlen=0;

       unordered_map<int,int>mp;

       int i=0;
       int j=0;

       while(j<n)
       {
        mp[fruits[j]]++;  // mllb ki elemnt same ya 2 diffrent hai dalte jao 
         if(mp.size()>2)  // jaise hi tesesra elemnt aayega size bdhega nikalo map se
         {
            while(mp.size()>2)
            {
                mp[fruits[i]]--;  // frequency reduce krte rho
                if(mp[fruits[i]]==0)
                {
                    // erse  kr do 
                    mp.erase(fruits[i]);
                }
                 i++;  // eak elment ko poori trike se nikl do {[3,3,3,1,2,1,1,2,3,3,4]} dry run this case
            }
          
         }
         maxlen=max(maxlen,j-i+1);
         j++;

       }
       return maxlen; 
    }
};