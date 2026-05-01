class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for (auto& m : grid)
            for (auto n : m)
                v.push_back(n);
        int a = v[0] % x;
        for (int i = 1; i < v.size(); i++) {
            int b = v[i] % x;
            if (b != a)
                return -1;
        }
        sort(v.begin(), v.end());
        int med;
        int n = v.size();
        if (v.size() % 2 != 0)
            med = v[n / 2];
        else
            med = v[(n - 1) / 2];
        // cout << "med" << med << endl;

        int ans = 0;

        for (auto m : v)
            ans += abs(m - med) / x;

        return ans;
    }
};