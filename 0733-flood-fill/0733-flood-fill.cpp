class Solution {
public:
vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        queue<pair<int,int>> q;
        q.push({sr,sc});
        int startColor = image[sr][sc];

        vector<vector<bool>> visited(image.size(),vector<bool> (image[0].size()));


        while(!q.empty()){
            auto u = q.front(); q.pop();
            int x = u.first, y = u.second;
            image[x][y] = color;
            for(auto z:dir){
                int nx = x+z[0],ny =y+z[1];

                if(nx>=0&&nx<image.size()&&ny>=0&&ny<image[0].size() && image[nx][ny]==startColor &&!visited[nx][ny]){
                    visited[nx][ny] = true;

                    q.push({nx,ny});
                }

            }

        }

        return image;
       
        
    }
};