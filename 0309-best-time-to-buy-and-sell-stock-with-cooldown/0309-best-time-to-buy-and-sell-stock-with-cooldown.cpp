class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> memo(prices.size(),-1);
        return helper(0,prices,memo);
        
    }


    int helper(int id,const vector<int> &prices,vector<int> &memo){
        if(id>=prices.size()) return 0;
        if(memo[id]!=-1) return memo[id];

        int curr = 0;
        int min_ = prices[id];
        for(int i = id+ 1; i<prices.size();i++){
            if(prices[i]>=min_){
                curr = max(curr,prices[i]-min_ + helper(i+2,prices,memo));
            }
            min_ = min(prices[i],min_);
        }

        return memo[id]=curr;
    }
};