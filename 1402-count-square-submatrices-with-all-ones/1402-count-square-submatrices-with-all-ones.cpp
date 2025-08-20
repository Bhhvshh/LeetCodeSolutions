class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        vector<vector<int>> dp(n,vector<int> (m));
        int ans = 0;


        for(int i = 0;i<n;i++){
            for(int  j = 0;j<m;j++){
                if(matrix[i][j]==0) continue;
                else{
                    int t1 = (j>0) ? matrix[i][j-1] : 0;
                    int t2 = (i>0) ? matrix[i-1][j] : 0;
                    int t3 = (i>0 && j>0) ? matrix[i-1][j-1] : 0;

                    matrix[i][j] = min(min(t1,t2),t3) + 1;
                    ans+=matrix[i][j];
                }
            }
        }


        return ans;
        
    }
};