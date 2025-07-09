class Solution {
public:
long long mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
         long long ans = 0, n = arr.size();
        
        vector<int> left(n);
        vector<int> right(n);
        
        stack<pair<int,int>> st;
        
        for(int i = 0;i<n;i++){
            while(!st.empty() && st.top().first>=arr[i]) st.pop();
            left[i] = (st.empty()) ? -1: st.top().second;
            
            st.push({arr[i],i});
        }
        
        stack<pair<int,int>> st2;
        
        for(int i = n-1;i>=0;i--){
             while(!st2.empty() && st2.top().first>arr[i]) st2.pop();
             right[i] = (st2.empty()) ? -1 : st2.top().second;
             
             st2.push({arr[i],i});
             
             
        }
        
        for(int i = 0;i<n;i++){
            int l = (left[i]==-1) ? i+1 : i-left[i];
            int r = (right[i]==-1) ? arr.size() - i : right[i] - i;
           
            
            ans= (ans%mod + ((l%mod)*(r%mod)*(arr[i]%mod))%mod)%mod;
           
        }
        
        
        
        
        return ans;
        
    }
};