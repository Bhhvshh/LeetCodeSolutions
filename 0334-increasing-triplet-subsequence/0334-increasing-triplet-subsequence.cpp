class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        stack<int> st;
        int n = nums.size();
        vector<int> maxsuffix(n), minprefix(n);
        int min_ = INT_MAX, max_ = INT_MIN;

        for(int i = 0;i<n;i++){
            minprefix[i] = min_;
            min_ = min(min_,nums[i]);
        }
        for(int i=n - 1;i>=0;i--){
            maxsuffix[i]= max_;
            max_ = max(max_,nums[i]);
        }

        for(int i =0;i<n;i++){
            if(minprefix[i]<nums[i] && nums[i]<maxsuffix[i]) return true;
        }


        return false;
        
    }
};