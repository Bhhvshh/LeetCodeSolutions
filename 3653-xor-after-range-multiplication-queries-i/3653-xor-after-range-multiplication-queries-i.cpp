
class Solution {
public:
long long MOD = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        for(auto &x : queries){
            for(int i = x[0]; i<=x[1]; i+=x[2]){
                nums[i] = ((long long)nums[i] * x[3]) % MOD;
            }
        }
        int ans = 0;
        for(auto x:nums) ans ^=x;

        return ans;
    }
};