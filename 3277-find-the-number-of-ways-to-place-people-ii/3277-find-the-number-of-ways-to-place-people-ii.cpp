class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {

         sort(points.begin(),points.end(),[](const vector<int> &a,const vector<int> &b){
            if(a[0]!=b[0]) return a[0]<b[0];
            return a[1]>b[1];
            
        });
        
        int ans = 0;


        for(int i = 0;i<points.size();i++){
            int x = points[i][1],y = INT_MAX;
            for(int j = i-1;j>=0;j--){
                if(points[j][1]<y&& points[j][1]>=x ){
                    ans++;
                    y = points[j][1];
                }
            }
           
        }


        return ans;
        
        
    }
};