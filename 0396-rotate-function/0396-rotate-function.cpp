class Solution {
public:
struct three{
    int a;
    int b;
    int c;
};
    int maxRotateFunction(vector<int>& nums) {

        int ans = INT_MIN;
        int sum = 0 , cont = 0;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++ ){
            sum += (i * nums[i]);
            cont += nums[i];

        }
       

        for(int i = 0 ; i < n; i++){
            sum = sum - cont + nums[i]*n;
            ans = max(ans, sum);
        }

        return ans;
        
    }
};