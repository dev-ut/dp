class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        // our very first move will be ki we wil sort peopl acoording to their woieght
        sort(people.begin(),people.end());

       // sine we are given liit that two people acan be at the baot at same time so our logiv builds that they should be beolow or equal to our limit 
       int i=0;
       int j=people.size()-1;
       // two people got handled at the same time 
       int boatreq=0;

       while(i<=j)
       {
        if(people[i]+people[j]<=limit)
        {
          boatreq++;
          i++;
          j--;
        }
        else
        {
            boatreq++;
            j--;
        }
       }
       return boatreq;

    }
};