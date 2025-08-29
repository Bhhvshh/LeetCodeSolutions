class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp1(n);
        vector<int> dp2(n);
        int maxans = 0;
        int ans = 0;
        int min_ = prices[0];

        for(int i = 1;i<n;i++){
            maxans = max(maxans,prices[i]-min_);
            min_ = min(min_,prices[i]);
            dp1[i] = maxans;


        }
       

        maxans = 0;
       int  max_ = prices[n-1];

        for(int i = n-2;i>=0;i--){
            maxans = max(maxans,max_ - prices[i]);
            max_ = max(max_,prices[i]);
            dp2[i] = maxans;


        }
       

        for(int i = 0;i<n;i++)
         ans = max(ans,dp1[i]+dp2[i]);


         return ans;

        




    }
};