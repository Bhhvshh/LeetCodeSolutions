class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {

        long dia = 0;
       long  area = 0;
        for(auto &x:dimensions){
            if((long long)x[0]*x[0] + x[1]*x[1] > dia){
                dia = (long long)x[0]*x[0] + x[1]*x[1];
                area = (long)x[0]*x[1];
            }
            else if((long long)x[0]*x[0] + x[1]*x[1] == dia){
                // dia = (long long)x[0]*x[0] + x[1]*x[1];
                area = max(area,(long)x[0]*x[1]);
            }
        }


        return area;
        
    }
};