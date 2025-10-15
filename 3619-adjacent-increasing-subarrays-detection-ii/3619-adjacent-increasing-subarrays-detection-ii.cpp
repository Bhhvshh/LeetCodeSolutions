class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {

       int curr = 1,prev = 0;
       int ans = 1;

       for(int i = 1;i<nums.size();i++){
         if(nums[i]>nums[i-1]){
            curr++;
         }
         else{
            prev =curr;
            curr = 1;
         }

         ans = max(ans,min(prev,curr));
         ans = max(ans,curr/2);
       }

       return ans;

        
    }
};