class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, std::vector<pair<int,int>>, std::greater<pair<int,int>>> pq;
        for(int i = 0;i<nums.size();i++){
            if(pq.size()<k) pq.push({nums[i],i});
            else if(pq.top().first<nums[i])
            {pq.pop();
            pq.push({nums[i],i});
            }
        }

        vector<pair<int,int>> vp;
        while(!pq.empty()){
            vp.push_back(pq.top());
            pq.pop();
        }

        sort(vp.begin(),vp.end(),[](const auto a,const auto b){ return a.second<b.second;});

        vector<int> result(k);

        for(int i = 0;i<k;i++)
          result[i] = vp[i].first;


        return result;


        
    }
};