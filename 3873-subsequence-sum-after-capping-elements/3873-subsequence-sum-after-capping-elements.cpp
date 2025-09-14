class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        vector<vector<bool>> dp(nums.size()+1,vector<bool>(k+1,false));
        dp[0][0] = true;
        for(int i = 1;i<=nums.size();i++){
            for(int j = 0;j<=k;j++){
                dp[i][j] = dp[i-1][j] or (j - nums[i-1] >=0 ? dp[i-1][j-nums[i-1]]: false);
                
            }
        }

        vector<bool> ans(nums.size());
        int j = 0;

        for(int i = 1;i<=nums.size();i++){
            while(j<nums.size() && nums[j]<=i)j++;
            // vector<bool> pre = dp[j];
            // vector<bool>curr(k+1);
            bool flag = false;
           for(int a = 0;a<=k;a++){
               if(dp[j][a]){
                   flag |= ((k-a) % i == 0  && (k-a)/i <= nums.size()-j);
               }
           }

            ans[i-1] = flag;
            
        }


        return ans;

        
        
    }
};