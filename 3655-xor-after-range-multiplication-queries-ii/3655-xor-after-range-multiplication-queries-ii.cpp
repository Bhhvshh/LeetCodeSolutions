class Solution {
public:
const long long MOD = 1e9 + 7;

    int power(long long x, long long y, long long m)
{
    if (y == 0)
        return 1;
    int p = power(x, y / 2, m) % m;
    p = (1LL * p * p) % m;

    return (y % 2 == 0) ? p : (x * p) % m;
}
inline static int preCal[100000][317];

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size(), k = sqrt(n);
       
        for(int i = 0 ; i < n ; i++){
            for(int j = 1; j < k;j++){
                preCal[i][j] = 1;
             }
                    


        }
        for(auto &x: queries){
            if(x[2] < k){
                preCal[x[0]][x[2]] = (1LL * preCal[x[0]][x[2]] * x[3]) % MOD;
                int last = x[0] + ((x[1] - x[0]) / x[2]) * x[2];
                int index = last + x[2];
                if(index < n) preCal[index][x[2]] = (1LL * preCal[index][x[2]] * power(x[3],MOD - 2, MOD) ) % MOD;



            }
            else{
                for(int i = x[0]; i <= x[1] ; i += x[2]){
                    nums[i] = (1LL *nums[i] * x[3]) % MOD;
                }

            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 1; j < k;j++){
                if(i - j >= 0){
                    preCal[i][j] = (1LL * preCal[i][j] * preCal[i-j][j])%MOD;
                }
                nums[i] = (1LL* nums[i] * preCal[i][j]) % MOD;
            }
                    ans ^= nums[i];


        }

        return ans;



    }
};