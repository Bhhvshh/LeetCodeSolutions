class Solution {
public:
    int longestSubsequence(string s, int k) {

        int n = s.size();
        int multi = 0;
        int total = 0;
        int ans = 0;
        int msb = log2(k);

        for(int i = n-1;i>=0;i--){
            if(s[i]=='0'){
                ans++;
                multi++;

            }
            else if(multi<=msb && pow(2,multi)+total<=k){
                ans++;
                total+=pow(2,multi);
                multi++;

            }

        }

        return ans;
        
    }
};