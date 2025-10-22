class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());
        int curr = k;

        int i = 0;
        while(i<nums.size()){
            if(nums[i++]==curr) curr+=k;
            
        }


        return curr;
        
    }
};