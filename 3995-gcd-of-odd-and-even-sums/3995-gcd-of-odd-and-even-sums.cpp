class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = (double)n/2*(2 + (n-1)*2);
        int sumEven = (double) n/2*(4+ (n-1)*2);

        return __gcd(sumOdd,sumEven);

        
    }
};