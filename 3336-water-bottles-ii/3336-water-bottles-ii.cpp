class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        
        int rem = 0;
         int ans = 0;
         while(numBottles){
            ans+=numBottles;
            rem+=numBottles;
            if(rem>=numExchange){
                numBottles = 1;
                rem-=numExchange++;;

            }
            else numBottles = 0;
         }

         return ans;
    }
};