class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
       long long last = -1,ans = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=0) last = -1;
            else if(last==-1){
                last = i;
                ans++;
            }
            else{
                ans+=(i-last+1);
            }
        }

        return ans;
    }
};