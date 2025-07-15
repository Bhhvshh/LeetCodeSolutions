class Solution {
public:
vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<bool>> visited(mat.size(),vector<bool>(mat[0].size()));

        queue<pair<int,int>> q;

        for(int i = 0;i<mat.size();i++){
            for(int j = 0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        }
       int dist = 0;
        while(!q.empty()){
            int level = q.size();

            for(int i = 0;i<level;i++){
                auto [x,y] = q.front(); q.pop();
                mat[x][y] = dist;

                for(auto z:dir){
                       int nx = x + z[0], ny = y +z[1];

                       if(nx>= 0 && nx < mat.size() && ny>=0 && ny<mat[0].size() && !visited[nx][ny]){
                        q.push({nx,ny});
                        visited[nx][ny] = true;
                       }
                }


            }
            dist++;


        }

        return mat;
        
    }
};