class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
   map<int,int> m;
   for(auto x:power) m[x]++;

   vector<long long> v;
   for(auto x:m) v.push_back(x.first);
   vector<pair<long long,long long>> dp(v.size());
   long long ans = 0;
    int last = 0;
   for(int i = 0;i<v.size();i++){
    while(last<v.size() && v[last]<v[i]-2) last++;
    long long back = (last>0) ? dp[last-1].second :0;
    ans  = max(ans,dp[i].first = v[i]*m[v[i]] + back);
    dp[i].second = ans;
   }


   return ans;
        
    }


 

   
};