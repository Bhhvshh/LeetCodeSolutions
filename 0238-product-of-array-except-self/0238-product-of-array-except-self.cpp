class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long total = 1;
        int zero = 0;

        for(auto x:nums){
            if(x) total*=x;
            else zero++;
        }
        vector<int> ans;
        for(auto x:nums){
            if(zero>1 || (x && zero)) ans.push_back(0);
            else if(x==0) ans.push_back(total);
            else ans.push_back(total/x);



        }


        return ans;
        
    }
};