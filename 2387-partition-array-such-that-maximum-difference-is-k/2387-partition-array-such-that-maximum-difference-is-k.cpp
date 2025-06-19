class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int last = nums[0];
        int n =  nums.size();
        int ans = 0;

        for(int i = 0;i<n;i++){
            if(nums[i]-last>k){
                ans++;
                last =  nums[i];
            }

        }


        return ans+1;
        
    }
};