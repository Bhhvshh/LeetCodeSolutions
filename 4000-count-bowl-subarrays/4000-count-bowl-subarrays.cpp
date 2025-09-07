class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<bool> left(n),right(n);

        int max_  = INT_MIN;

        for(int i = 0;i<n;i++){
            left[i] =( max_ > nums[i]);
            max_ = max(max_, nums[i]);
        }
        max_ = INT_MIN;

        for(int i = n-1;i>=0;i--){
            right[i] =( max_ > nums[i]);
            max_ = max(max_, nums[i]);
        }

        long long ans = 0;

        for(int i = 0;i<nums.size();i++)
           ans+= (left[i] && right[i]);

        return ans;
        
    }
};