class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>> pq;

        for(int i = 0;i<classes.size();i++){
            pq.push({((double)classes[i][0]+1)/(classes[i][1]+1) -(double)classes[i][0]/classes[i][1],i});
        }

        while(extraStudents--){
            auto curr = pq.top(); pq.pop();
            classes[curr.second][0]++;
            classes[curr.second][1]++;
            int i = curr.second;
            // cout<< i <<endl;
            pq.push({((double)classes[i][0]+1)/(classes[i][1]+1) -(double)classes[i][0]/classes[i][1],i});
        }
        cout << classes[0][1]<<endl;
        cout<< classes[0][0]<<endl;
        double ans = 0;

        for(auto &x:classes){
            ans+= ((double)x[0]/x[1]);
        }


        return ans/classes.size();
        
    }
};