class Solution {
public:
int revNum(int num){
    int rev = 0;
    while(num){
        rev = rev*10 + (num % 10);
        num /= 10;
    }

    return rev;
}
    int mirrorDistance(int n) {

        return abs(n - revNum(n));
        
    }
};