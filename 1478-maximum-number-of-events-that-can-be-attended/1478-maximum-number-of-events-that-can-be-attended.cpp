class Solution {
public:
struct CompareLast {
    bool operator()(const int & a, const int  b) {
        return a > b;
    }
};

    int maxEvents(vector<vector<int>>& intervals) {
         int n = intervals.size();

        sort(intervals.begin(),intervals.end());
        priority_queue<int, vector<int>, CompareLast> pq;

        int result = 0;
        int last = 0;
        int maxrange = 0;
        for(auto x:intervals) maxrange = max(maxrange,x[1]);
      

        for(int i = 0, j = 0;i<=maxrange;i++){
            while(j<intervals.size() && intervals[j][0]<=i ){
                pq.push(intervals[j][1]);
                j++;
            }

            while(!pq.empty() && pq.top()<i){
                pq.pop();

            }

            if(!pq.empty()){
                pq.pop();
                result++;
            }

        }

        return result;





       
       
        
    }
};