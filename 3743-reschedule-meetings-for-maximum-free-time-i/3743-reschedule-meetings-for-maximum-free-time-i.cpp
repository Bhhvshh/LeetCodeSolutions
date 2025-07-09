class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& st, vector<int>& et) {

       
        int n = st.size();
        int sum = 0;
        int ans = 0;

        vector<int> gap;

        gap.push_back(st[0]);

        for(int i = 1;i<n;i++)  gap.push_back(gap.back() + st[i]-et[i-1]);
        
        gap.push_back(gap.back() + eventTime-et[n-1]);

       


        for(int i = 0;i<gap.size();i++){
           

            int curr = (i>k) ? gap[i] - gap[i-k-1] : gap[i] ;

            ans = max(ans,curr);
        


        }

       
       return ans;

        
    }
};