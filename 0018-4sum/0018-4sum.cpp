class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        for(int i = 0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j =i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int l = j+1, r = n-1;
                long long need = (long long)target - nums[i] - nums[j];


                while(l<r){
                    int sum = nums[l]+nums[r];
                    if(sum==need){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        while(l<n && nums[l]==nums[l-1] ) l++;

                    }
                    else if(sum>need) r--;
                    else l++;

                }

            }
        }

        return ans;
        
    }
};