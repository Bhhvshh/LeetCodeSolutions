class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int ans = 0;
        int n = mat.size(), m = mat[0].size();

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j]==0) continue;
                mat[i][j]+= (i>0) ? mat[i-1][j]: 0;
                int min_ = INT_MAX;
                for(int k = j;k>=0;k--){
                    min_ = min(min_,mat[i][k]);
                    ans+=min_;

                }
                cout << i << " "<< j << " "<<ans<<endl;

            }
        }

        return ans;
        
    }
};