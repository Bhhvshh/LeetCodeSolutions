class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

         int rem = 0;
         int ans = 0;
         while(numBottles){
            ans+=numBottles;
            int totalEmpty = numBottles + rem;
            numBottles = (totalEmpty)/numExchange;
            rem = (totalEmpty)%numExchange;
         }

         return ans;
        
    }
};