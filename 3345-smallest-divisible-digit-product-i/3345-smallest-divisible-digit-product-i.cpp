class Solution {
public:
    int digitproduct(int n){
        int ans = 1;
        while(n){
            ans *= (n%10);
            n /= 10;
        }

        return ans;
    }
    int smallestNumber(int n, int t) {
       
      while(digitproduct(n)%t) n++;

      return n;
        
    }
};