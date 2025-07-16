class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even = 0;
        int odd = 0;
        for(auto x:nums){
            odd += (x%2);
            even += (x%2==0);
        }

        int ans = max(odd,even);

        int starteven = 0, startodd = 0;
        bool flag = true, flag2 = true;
        
        for(int i = 0;i<nums.size();i++){
            if(flag && (nums[i]%2==0)){ 
                starteven++;
                flag = !flag;

            }
            else if(!flag && (nums[i]%2)){
                starteven++;
                flag = !flag;
            }

            if(flag2 && (nums[i]%2)){ 
                startodd++;
                flag2 = !flag2;

            }
            else if(!flag2 && (nums[i]%2==0)){
                startodd++;
                flag2 = !flag2;
            }
        }


        return max(ans,max(starteven,startodd));
    }
};