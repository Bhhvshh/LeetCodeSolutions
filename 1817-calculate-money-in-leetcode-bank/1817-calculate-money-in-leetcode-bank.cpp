class Solution {
public:
    int totalMoney(int n) {
   
        int len = n/7;

        int ans = (float)len/2 * (56 + (len-1)*7);

        for(int i = 1;i<=n%7;i++){
            ans+= len+i;
        }

        return ans;
    }
};