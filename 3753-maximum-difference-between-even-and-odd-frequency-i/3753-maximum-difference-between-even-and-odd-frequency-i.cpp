class Solution {
public:
    int maxDifference(string s) {
          vector<int> f(26, 0);

     // freq if cgharacter
 for (char c : s) f[c - 'a']++;

      int maxO = INT_MIN, minE = INT_MAX;
    bool hasO = false, hasE = false;

    //find max ans min
    for (int cnt : f) {
        
        if (cnt > 0) {
            if (cnt % 2 == 1) {
                maxO = max(maxO, cnt);
                hasO = true;
                
            } 
            else {
                minE = min(minE, cnt);
                 hasE = true;
                
               }
         }
  }

    // If no valid 
        
        if (!hasO || !hasE) return -1;

      return maxO - minE;

        
    }
};