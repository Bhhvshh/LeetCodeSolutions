class Solution {
public:
vector<vector<int>> dir = {{0,1},
                            {1,0},
                            {-1,0},
                            {0,-1},
                           };
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int,int>> q;
        // vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size()));

        for(int i = 0;i<grid.size();i++)
            for(int j = 0;j<grid[i].size();j++)
                if(grid[i][j]==2) {q.push({i,j}); }
           
        int count = 0;

        while(!q.empty()){
            int level = q.size();
            // count++;
            for(int i = 0;i<level;i++){
                auto u = q.front();
                int x = u.first, y = u.second;
                q.pop();

                for(auto z:dir){
                    int newX = z[0]+x, newY = y+z[1];
                    if(newX>=0 && newX<grid.size() && newY>=0 && newY<grid[0].size() &&  grid[newX][newY]==1)
                     {
                        grid[newX][newY] = 2;
                        q.push({newX,newY});
                     }
                }



            }
            count+=!q.empty();

            
        }
      for(int i = 0;i<grid.size();i++)
            for(int j = 0;j<grid[i].size();j++)
                if(grid[i][j]==1) return -1;

       return count;

        
    }
};