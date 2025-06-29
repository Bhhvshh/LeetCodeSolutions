class Solution {
public:
    struct N {
    array<N*, 128> n{};
    N() { n.fill(nullptr); }
    // ~N() { for (auto x : n) if (x) delete x; }
};

vector<string> partitionString(string s) {
    N* r = new N();
    vector<string> res;
    for (int i = 0, m = s.size(); i < m; ) {
        N* p = r;
        string cur;
        int j = i;
        bool flag = false;
        while (j < m) {
            unsigned char ch = s[j];
            cur += ch;
            if (!p->n[ch]) {             
                p->n[ch] = new N();
                ++j;
                flag = true;
                
                break;
            }
            p = p->n[ch];
            ++j;
        }
        if(flag)res.push_back(cur);
        i = j;
    }
    // delete r;
    return res;
}
    
};