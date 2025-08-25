class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size(), m = mat[0].size();
        bool flag = false;

        for(int i = 0;i<n;i++){
            int id = i;
            vector<int> tmp;
            for(int j = 0;j<m&& id>=0;j++){
                tmp.push_back(mat[id--][j]);
            }
            if(flag) reverse(tmp.begin(),tmp.end());
            flag = !flag;
           for(auto x:tmp) ans.push_back(x);
    
        }

        for(int i = 1;i<m;i++){
            int id = n-1;
            vector<int> tmp;
            for(int j = i;j<m&& id>=0;j++){
                tmp.push_back(mat[id--][j]);
            }
            if(flag) reverse(tmp.begin(),tmp.end());
            flag = !flag;
           for(auto x:tmp) ans.push_back(x);
    
        }


        return ans;
        
    }
};