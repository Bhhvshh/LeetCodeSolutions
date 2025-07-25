class Solution {
public:
vector<vector<int>> merge(vector<vector<int>>& intervals) {

       
        int n = intervals.size();

        sort(intervals.begin(),intervals.end());

       
        vector<vector<int>> ans;


        for(int i = 0;i<n;i++){
            if(ans.size()== 0 || intervals[i][0]>ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(intervals[i][1],ans.back()[1]);
            }



        }

        return ans;
        
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
     intervals.push_back(newInterval);

        return merge(intervals);

        
        
    }
};