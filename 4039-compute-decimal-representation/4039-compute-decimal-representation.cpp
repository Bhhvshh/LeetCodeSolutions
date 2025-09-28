class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans;
        long long num = 1;

        while(n){
            if(n%10) ans.push_back(n%10*num);
            num*=10;
            n/=10;
        }

        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};