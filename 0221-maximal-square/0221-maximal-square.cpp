class Solution {
public:
    int maximalSquare(vector<vector<char>>& m) {

         int n = m.size(), mi = m[0].size();

        vector<vector<int>> matrix(n,vector<int> (mi));
        int ans = 0;


        for(int i = 0;i<n;i++){
            for(int  j = 0;j<mi;j++){
                if(m[i][j]=='0') continue;
                else{
                    int t1 = (j>0) ? matrix[i][j-1] : 0;
                    int t2 = (i>0) ? matrix[i-1][j] : 0;
                    int t3 = (i>0 && j>0) ? matrix[i-1][j-1] : 0;

                    matrix[i][j] = min(min(t1,t2),t3) + 1;
                    ans= max(matrix[i][j]*matrix[i][j],ans);
                }
            }
        }


        return ans;



        
    }
};