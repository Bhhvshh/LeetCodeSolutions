class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        int n = nums.size(), m = nums[0].size();
        int max_element = INT_MIN;
        for(int i = 0;i<n;i++) {pq.push({nums[i][0],i});
        max_element = max(max_element,nums[i][0]);}


        int ans = INT_MAX;

        vector<int> result;
        vector<int> point(n,1);

        while(true){

            auto ele = pq.top();
            pq.pop();

            int val = ele.first;
            if(max_element-val <ans){
                ans = max_element - val;
                result = {val,max_element};
            }

            if(point[ele.second]<nums[ele.second].size()){
                pq.push({nums[ele.second][point[ele.second]],ele.second});
                max_element =  max(max_element,nums[ele.second][point[ele.second]++]);

            }
            else break;


        }

        return result;
        
    }
};