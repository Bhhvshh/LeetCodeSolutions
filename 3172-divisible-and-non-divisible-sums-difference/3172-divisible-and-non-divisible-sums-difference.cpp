class Solution {
public:
    int differenceOfSums(int n, int m) {
      int totalSum = n*(n+1)/2;
      int divisibleNum = n/m;
      int divisible = (divisibleNum)*(divisibleNum+1)/2*m;
    // cout << totalSum <<" "<<divisibleNum << endl;

        return totalSum-2*divisible;
    }
};