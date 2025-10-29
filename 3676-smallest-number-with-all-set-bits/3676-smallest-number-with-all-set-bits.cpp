class Solution {
public:
    int smallestNumber(int n) {

        int ans = 0;

        for(int i = 0;i<32&&n;i++){
            ans|=(1<<i);

            n>>=1;
        }

        return ans;
        
    }

   
};