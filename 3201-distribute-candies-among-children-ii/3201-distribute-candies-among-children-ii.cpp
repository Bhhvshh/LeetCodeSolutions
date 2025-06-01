class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;

        for(int i = 0;i<=limit;i++){
            int rem = n - i;
         
            if(rem<0 ||rem-2*limit>0) continue;
            else if(rem<=limit) ans+=(rem+ 1);
            else{
                ans+= (long long)(2*limit -  rem + 1);
            }
        }

        return ans;
        
    }
};