class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int limit = nums[0]-k, ans = 1;

        for(int i = 1;i<n;i++){
            if(nums[i]+k>limit){

               
                    limit = (nums[i]-k > limit) ? nums[i]-k : limit+ 1;
                    ans++;
                
            }
        }

        return ans;
        
    }
};