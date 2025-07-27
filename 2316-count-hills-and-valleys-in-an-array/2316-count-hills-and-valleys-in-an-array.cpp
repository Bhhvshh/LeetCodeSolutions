class Solution {
public:
    int countHillValley(vector<int>& v) {
        
        
        //  vector<int> v;
         int n = v.size();
         int ans = 0;
         int last = 0;
         int lastlast = 0;
        //  int count = 0;
        for(int i = 1;i<n;i++){
            if(v[last]==v[i]) continue;
            

            if(last>0){
                if(v[last]>v[lastlast] && v[last]>v[i]) ans++;
                else if(v[last]<v[lastlast] && v[last]<v[i]) ans++;

            }
            lastlast = last;
            last = i;

            

        }

        return ans;
    }
};