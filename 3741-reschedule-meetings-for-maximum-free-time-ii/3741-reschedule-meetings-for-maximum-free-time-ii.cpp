class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& st, vector<int>& et) {

        vector<int> gap;
        gap.push_back(st[0]);
        int n = st.size();
        for(int i = 1;i<n;i++){
            gap.push_back(st[i]-et[i-1]);

        }
        gap.push_back(eventTime-et[n-1]);
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i = 0;i<gap.size();i++){
            pq.push({gap[i],i});
            if(pq.size()>3) pq.pop();
        }


        vector<pair<int,int>> vp;
        while(!pq.empty()){
            vp.push_back(pq.top());
            pq.pop();
        }

        int ans = gap[0];

        for(int i = 1;i<gap.size();i++){
        int prev = et[i-1] - st[i-1];
        ans = max(ans,gap[i]+gap[i-1]);
        bool flag = false;
        for(auto x:vp){
            if(x.first>=prev && x.second!=i && x.second!=i-1) flag = true;
        }

        if(flag) ans = max(ans,gap[i]+gap[i-1]+prev);

        }


        return ans;


        
    }
};