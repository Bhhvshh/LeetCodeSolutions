class Solution {
public:
    int distributeCandies(int n, int limit) {

        int ans = 0;

        for(int i =0;i<=limit;i++){
            for(int j = 0;j<=limit;j++){
                int rem = n - i -  j;
                if(rem>=0 && rem<=limit) ans++;
            }
        }

        return ans;
        
    }
};