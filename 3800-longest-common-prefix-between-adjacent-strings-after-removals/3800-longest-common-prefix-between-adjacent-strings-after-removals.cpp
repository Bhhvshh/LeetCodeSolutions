class Solution {
public:
  

    static int lcp(const string& a, const string& b) {
    
        int m = min(a.size(), b.size());
    int k = 0;
        
    while (k < m && a[k] == b[k]) ++k;
    return k;
}

vector<int> longestCommonPrefix(vector<string>& w) {
    
    int n = (int)w.size();
    vector<int> ans(n, 0);
    
    if (n <= 1) return ans;

    vector<int> adj(n - 1);
    
    for (int j = 0; j < n - 1; ++j) 
        adj[j] = lcp(w[j], w[j + 1]);

    
    vector<int> pref(adj), suff(adj);
    
    for (int j = 1; j < n - 1; ++j)
          pref[j] = max(pref[j], pref[j - 1]);
    for (int j = n - 3; j >= 0; --j)
          suff[j] = max(suff[j], suff[j + 1]);

    
    for (int i = 0; i < n; ++i) {
        int bestOld = 0;
        
        if (i >= 2)      bestOld = max(bestOld, pref[i - 2]);   
        if (i <= n - 3)  bestOld = max(bestOld, suff[i + 1]);  

        int bridge = 0;
        if (i > 0 && i < n - 1)
              bridge = lcp(w[i - 1], w[i + 1]);

        ans[i] = max(bestOld, bridge);
    }
    return ans;
}

    
};