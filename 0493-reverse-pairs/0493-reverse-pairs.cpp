class bit{
    public:
    vector<int> t;
    bit(int n){
        t.resize(n+1,0);
    }
    
    int getsum(int id){
        int sum = 0;
        id++;
        while(id>0){
            sum+=t[id];
            id -= (id &(-id));
            
        }
        
        return sum;
        
    }
    void update(int id,int val){
        id++;
        while(id<t.size()){
            t[id]+=val;
            id+= (id & (-id));
            
        }
    }
};
class Solution {
public:
    int reversePairs(vector<int>& arr) {
        int ans = 0;
        
        vector<long long> tmp;
        for(auto x:arr) tmp.push_back((long long)2*x);
        
        bit bit(arr.size());
        sort(tmp.begin(),tmp.end());
        
        for(int i = arr.size()-1;i>=0;i--){
            int idx = lower_bound(tmp.begin(),tmp.end(),arr[i]) - tmp.begin();
            
            if(idx)ans+= bit.getsum(idx-1);
            // cout << ans <<endl;
            int updateidx = lower_bound(tmp.begin(),tmp.end(),(long long)2*arr[i]) -tmp.begin();
            bit.update(updateidx,1);
            
        }
        
        return ans;
        
    }
};