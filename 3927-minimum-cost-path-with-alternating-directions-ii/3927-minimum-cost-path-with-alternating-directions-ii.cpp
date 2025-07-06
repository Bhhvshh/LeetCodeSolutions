class Solution {
public:


    long long minCost(int m, int n, vector<vector<int>>& waitCost) {

        vector<vector<pair<long long,long long >>> dp(m,vector<pair<long long,long long>>(n,{LLONG_MAX,-1}));

        dp[0][0] = {1,1};
      

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i>0){
                    if(dp[i-1][j].second%2==0){
                      dp[i][j] = min(dp[i][j],{dp[i-1][j].first+((i+1)*(j+1))+waitCost[i-1][j],dp[i-1][j].second+2});
                    }
                    else{
                        dp[i][j] = min(dp[i][j],{dp[i-1][j].first+((i+1)*(j+1)),dp[i-1][j].second+1});

                    }

                }
                if(j>0){
                    if(dp[i][j-1].second%2==0){
                        dp[i][j] = min(dp[i][j],{dp[i][j-1].first+((i+1)*(j+1))+waitCost[i][j-1],dp[i][j-1].second+2});

                    }
                    else{
                         dp[i][j] = min(dp[i][j],{dp[i][j-1].first+((i+1)*(j+1)),dp[i][j-1].second+1});

                    }

                }

            }
        }

        return dp[m-1][n-1].first;


        
    }
};