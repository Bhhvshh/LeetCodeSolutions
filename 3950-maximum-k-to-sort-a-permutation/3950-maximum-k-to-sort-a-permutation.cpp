class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int min_ = INT_MAX, n = nums.size();
        for(int i = 0;i<n;i++){
            if(i!=nums[i]) min_&=nums[i];
        }


        return min_==INT_MAX ? 0 : min_;
        
    }
};