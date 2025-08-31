class Solution {
public:
    void solveSudoku(vector<vector<char>>& mat) {
     vector<vector<bool>> row(9,vector<bool>(10));
        vector<vector<bool>> col(9,vector<bool>(10));
        vector<vector<bool>> box(9,vector<bool>(10));
        
        for(int i = 0;i<9;i++)
          for(int j = 0;j<9;j++){
              if(mat[i][j]!='.'){
                  row[i][mat[i][j]-'0'] = true;
                  col[j][mat[i][j]-'0'] = true;
                  box[3*(i/3) + j/3][mat[i][j]- '0'] = true;
              }
          }
          
          
        backtrack(mat,row,col,box,0,0);
        
        
    }

    bool   backtrack(vector<vector<char>> &mat,vector<vector<bool>> &row,vector<vector<bool>> &col,
        vector<vector<bool>> &box,int i, int j){
            if( j>=9) return true;
            if(mat[i][j]!='.')    return backtrack(mat,row,col,box,(i+1)%9,j+(i+1)/9);
            
            for(char x = 1;x<=9;x++){
                if( !row[i][x] && !col[j][x] && !box[3*(i/3) + j/3][x]){
                    row[i][x] = true; col[j][x] = true; box[3*(i/3) + j/3][x] = true;
                    mat[i][j] = (char)(x+'0');
                    if(backtrack(mat,row,col,box,(i+1)%9,j+(i+1)/9)) return true;
                    mat[i][j] = '.';
                    row[i][x] = false; col[j][x] = false; box[3*(i/3) + j/3][x] = false;
                    
                }
                
                
            }
            
            return false; 
        }
};