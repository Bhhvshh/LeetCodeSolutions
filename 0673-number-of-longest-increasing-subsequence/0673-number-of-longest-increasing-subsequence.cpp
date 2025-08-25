class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
       int n = nums.size();
       vector<pair<int,int>> dp(n,{1,1});
       int ans = 0;
       int count = 0;
       for(int i = 0;i<n;i++){
        int max_ = 0;
        int curr = 1;
        for(int j = i-1;j>=0;j--){
            if(nums[i]>nums[j]) {
                if(dp[j].first==max_){
                    curr+=dp[j].second;
                }
                else if(dp[j].first>max_){
                    max_=dp[j].first;
                    curr = dp[j].second;

                }
               }

        }
        
        dp[i].first +=max_;
        dp[i].second = curr;
        cout << dp[i].first << " " << dp[i].second<< endl;
        if(dp[i].first==ans){
            count+=(curr);
        }
        else if(dp[i].first>ans){
            count=dp[i].second;
            ans = dp[i].first;
        }

       }


       return count;
        
    }
};