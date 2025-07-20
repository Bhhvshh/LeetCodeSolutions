class Solution {
public:
    long long mod = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
       map<int,int> m;
        for(auto x:points) m[x[1]]++;

        long long prev = 0;

        long long ans = 0;

        for(auto x:m ){
            if(x.second>1){
                long com = ((x.second%mod) * ((x.second -1)%mod) * (500000004LL % mod)) %mod;
                ans = ( ans + ( (com * prev) %mod) )%mod;
                prev = (prev + com) % mod;
            }
        }

        return ans;
    }
};