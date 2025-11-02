class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int max1 = INT_MIN,max2 = INT_MIN;

        for(auto x:nums){
            if(abs(x)>max1){
                max2 = max1;
                max1 = abs(x);
            }
            else if(abs(x)>max2) max2 = abs(x);
        }


        return (long long)max1*max2*1e5;
        
    }
};