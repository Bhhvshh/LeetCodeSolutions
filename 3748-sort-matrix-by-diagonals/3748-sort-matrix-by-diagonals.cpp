class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
       
       int n = grid.size(), m = grid[0].size();
       vector<vector<int>> map(n+m);

       for(int i  = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            map[n-i+j].push_back(grid[i][j]);

        }
       }

       for(int i = 0;i<n+m;i++){
         if(i>n) sort(map[i].rbegin(),map[i].rend());
         else sort(map[i].begin(),map[i].end());
       }

        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                grid[i][j] = map[n-i+j].back();
                map[n-i+j].pop_back();
            }
        }


        return grid;

     
    }
};