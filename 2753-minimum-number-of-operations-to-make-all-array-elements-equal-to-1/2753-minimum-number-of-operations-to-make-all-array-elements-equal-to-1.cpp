class Solution {
public:
    int minOperations(vector<int>& nums) {

        int n = nums.size();

       int min_ = INT_MAX;
       int ones = 0;
       for(auto x:nums) if(x==1) ones++;

       if(ones) return n-ones;

       for(int i = 0;i<n;i++){
        int curr = nums[i];
        for(int j = i+1;j<n;j++){
            curr  = __gcd(curr,nums[j]);
            if(curr==1){
                min_ = min(min_,j-i);
                break;
            }
        }
       }


        return min_==INT_MAX ? -1 : min_+n-1;
        
    }
};