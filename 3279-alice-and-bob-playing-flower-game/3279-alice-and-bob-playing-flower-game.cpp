class Solution {
public:
    long long flowerGame(int n, int m) {
        int e1 = n/2, o1 =(n+1)/2;
        int e2 = m/2, o2 = (m+1)/2;


        return (1LL*e1*o2) + (1LL*o1*e2);
        
    }
};