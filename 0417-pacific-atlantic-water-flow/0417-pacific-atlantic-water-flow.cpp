class Solution {
public:
vector<vector<int>> dir = {{0,1},
                            {1,0},
                            {-1,0},
                            {0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size(),m=heights[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> v1(n,vector<int>(m,0));

        for(int i = 0;i<m;i++){
            // cout<<
            q.push({0,i});
            v1[0][i] = true;
        }
        for(int i = 1;i<n;i++){
            q.push({i,0});
            v1[i][0] = true;
        }

        while(!q.empty()){
            auto top = q.front(); q.pop();
            int x = top.first, y = top.second;

            for(auto &d:dir){
                int newx=x+d[0],newy = y+d[1];
                cout<<newx<<" "<<newy<<endl;
                if(newx>=0 && newx<n &&  newy>=0 && newy<m && heights[x][y]<=heights[newx][newy]&&!v1[newx][newy]){
                    q.push({newx,newy});
                    v1[newx][newy] = true;
                    
                }
            }
        }

        queue<pair<int,int>> q2;
        vector<vector<int>> v2(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            q2.push({i,m-1});
            v2[i][m-1] = true;
        }
        for(int i = 0;i<m-1;i++){
            q2.push({n-1,i});
            v2[n-1][i] = true;
        }

         while(!q2.empty()){
            auto top = q2.front(); q2.pop();
            int x = top.first, y = top.second;

            for(auto &d:dir){
                int newx=x+d[0],newy = y+d[1];
                if(newx>=0 &&newx<n &&  newy>=0 && newy<m &&heights[x][y]<=heights[newx][newy]&&!v2[newx][newy]){
                    q2.push({newx,newy});
                    v2[newx][newy] = true;
                    
                }
            }
        }

        vector<vector<int>> ans;

        for(int i = 0;i<n;i++)
         for(int j = 0;j<m;j++)
          if(v1[i][j] && v2[i][j])
             ans.push_back({i,j});


        return ans;



        
    }
};