class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int firstrow = INT_MAX, lastrow = -1;
        int firstcol = INT_MAX, lastcol = -1;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]){
                    firstrow= min(firstrow,i);
                    firstcol = min(firstcol,j);
                    lastrow= max(lastrow,i);
                    lastcol = max(lastcol,j);
                    
                   
                }
            }
        }

        if(lastrow==-1) return 1;

        return (lastrow-firstrow+1)*(lastcol-firstcol+1);
        
    }
};