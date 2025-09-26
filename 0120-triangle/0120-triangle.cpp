class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {

        int m = tri.size();

        for(int i = 1;i<m;i++){
            tri[i][0]+=tri[i-1][0];
            
            for(int j = 1;j<tri[i].size()-1;j++)
                 tri[i][j]+= min(tri[i-1][j],tri[i-1][j-1]);

            tri[i][tri[i].size()-1] += tri[i-1][tri[i].size()-2];

        }


        int ans = INT_MAX;

        for(auto x:tri[m-1]) ans = min(ans,x);

        return ans;
        
    }
};