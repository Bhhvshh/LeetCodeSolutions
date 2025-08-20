class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int last = -1;

        for(int i = 0;i<prices.size();i++){
            if(last== -1) last = prices[i];
            else if(last<prices[i]){
                ans+= (prices[i]-last);
                last = prices[i];
            }
            else last = prices[i];

        }

        return ans;
        
    }
};