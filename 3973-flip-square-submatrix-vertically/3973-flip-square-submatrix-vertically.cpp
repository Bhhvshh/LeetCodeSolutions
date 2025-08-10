class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i = x;i<x+k/2;i++){
            for(int j = y;j<y+k;j++){
                swap(grid[i][j],grid[k+x- (i-x)-1][j]);
            }
        }

        return grid;
        
    }
};