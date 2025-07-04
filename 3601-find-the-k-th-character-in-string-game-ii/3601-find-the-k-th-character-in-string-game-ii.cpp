class Solution {
public:
 char next(char c){
    return 'a' + ((c - 'a' + 1) %26);
 }
    char kthCharacter(long long k, vector<int>& operations) {
        if(k==1) return 'a';
        int ch = log2(k-1);
        if(operations[ch]) return next(kthCharacter(k-(1LL<<ch),operations));
        return kthCharacter(k-(1LL<<ch),operations);
        
    }
};