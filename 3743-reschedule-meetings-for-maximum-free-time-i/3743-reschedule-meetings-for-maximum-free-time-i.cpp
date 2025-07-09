class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& st, vector<int>& et) {

        sort(st.begin(),st.end());
        sort(et.begin(),et.end());
        int n = st.size();
        int sum = 0;
        int ans = 0;

        vector<int> gap;

        gap.push_back(st[0]);
        for(int i = 1;i<n;i++){
            // if(st[i]-et[i-1])
             gap.push_back(st[i]-et[i-1]);
        }

        // if(eventTime-et[n-1])
         gap.push_back(eventTime-et[n-1]);

        vector<int> pre(gap.size());


        for(int i = 0;i<gap.size();i++){
           sum+=gap[i];

            int curr = (i>k) ? sum - pre[i-k-1] : sum ;

            ans = max(ans,curr);
            pre[i] = sum;


        }

       
       return ans;

        
    }
};