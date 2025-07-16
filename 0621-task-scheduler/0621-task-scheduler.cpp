class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> fr(26);

        for(auto x:tasks) fr[x-'A']++;

        priority_queue<int> pq;
        int ans = 0;
        for(auto x:fr) if(x) pq.push(x);
        
        while(true){
            vector<int> v;
            int count = 0;
            for(int i = 0;i<min(n+1,26) && !pq.empty();i++){
                count++;
                if(pq.top()>1) v.push_back(pq.top()-1);
                pq.pop();
            }

            if(v.empty()) break;
             

            ans+= (n+1-count);
            cout<<ans<<endl;
            
            for(auto x:v) if(x) pq.push(x);

        }

        for(auto x:fr) ans+=x;

        return ans;
    }
};