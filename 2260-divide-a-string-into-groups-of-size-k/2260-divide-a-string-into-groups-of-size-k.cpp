class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.size();

        for(int i = 0;i<n;i+=k){
        
            ans.push_back(s.substr(i,min(k,n-i)));
        }

        if(ans.back().size()<k){
            ans.back() = ans.back() + string(k-ans.back().size(),fill);
        }


        return ans;
        
    }
};