class Solution {
public:
    int countValidSelections(vector<int>& nums) {

        int total = 0;
        for(auto &x:nums) total += x;

        int ans = 0, curr = 0;

        for(int i = 0;i<nums.size();i++){
            curr+=nums[i];
            if(nums[i]== 0){

                if(abs(total-2*curr)==0) ans+=2;
                else if(abs(total-2*curr)==1) ans+=1;
            }
            
        }

        return ans;

        
    }
};