class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
       double ans = 0;

        int n = points.size();
        for(int i = 0;i<n;i++)
          for(int j = i+1;j<n;j++)
           for(int k = j+1;k<n;k++){
            double dist1 =   sqrt((double)((points[i][0]-points[j][0])*(points[i][0]-points[j][0])) + ((points[i][1]-points[j][1])*(points[i][1]-points[j][1])));
            double dist2 =   sqrt((double)((points[i][0]-points[k][0])*(points[i][0]-points[k][0])) + ((points[i][1]-points[k][1])*(points[i][1]-points[k][1])));
            double dist3 =   sqrt((double)((points[j][0]-points[k][0])*(points[j][0]-points[k][0])) + ((points[j][1]-points[k][1])*(points[j][1]-points[k][1])));
            double s = (dist1 + dist2 + dist3) /2;


            cout <<dist1 << " "<<dist2<<" " <<dist3<<endl;
            double curr = sqrt(s*abs(s-dist1)*abs(s-dist2)*abs(s-dist3));

            // double curr = 0;
            ans = max(curr,ans);
           }


        return ans;


        
    }
};