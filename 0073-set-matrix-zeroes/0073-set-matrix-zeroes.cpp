class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {


       int n = matrix.size(), m = matrix[0].size();


        bool firstColumn  = false;
        bool firstRow = false;

        for(int i =0;i<n;i++)
        if(!matrix[i][0]){
                firstColumn = true;
                break;
            }
        for(int j =0;j<m;j++)
          if(!matrix[0][j]){
            firstRow = true;
            break;
          }

        

        


        for(int i =1;i<n;i++)
          for(int j = 1;j<m;j++)
          {
            
            if(matrix[i][j]==0)
            {
             
               matrix[i][0] = 0;
               matrix[0][j] = 0;
            }

          }



        for(int i = 1;i<n;i++){
            if(!matrix[i][0]){
                for(int j = 1;j<m;j++)
                  matrix[i][j] = 0;

            }
           
        }

        for(int i = 1;i<m;i++){
            if(!matrix[0][i]){
                for(int j = 1;j<n;j++)
                  matrix[j][i] = 0;

            }
           
        }


        if(firstRow) for(int j = 0;j<m;j++) matrix[0][j] = 0;
        if(firstColumn) for(int i = 0;i<n;i++) matrix[i][0] = 0;

    
    }
};