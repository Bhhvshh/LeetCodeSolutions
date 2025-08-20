class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j]=='0') continue;
                dp[i][j] = (i>0) ? dp[i-1][j] + 1 : 1;
                // cout << dp[i][j]<< " ";
                
                int min_ = INT_MAX;
                for(int k = j;k>=0;k--){
                    min_ = min(dp[i][k],min_);
                    // cout << min_<<" "<< i << " "<< j << " "<< ans << endl;
                    ans = max(ans,min_*(j-k+1));
                    

                }
                // cout ;

            }
            cout << endl;
        }


        return ans;
        
    }
};