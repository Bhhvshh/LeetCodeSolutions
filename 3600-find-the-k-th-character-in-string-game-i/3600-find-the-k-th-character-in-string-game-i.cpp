class Solution {
public:
  char next(char c){
    return 'a' + ((c-'a' + 1)%26) ;
  }

 char helper(int k){
    if(k==1) return 'a';
    int ch = log2(k-1);
    return next(helper(k-(1<<ch)));
 }
    
    char kthCharacter(int k) {
       
       return helper(k);
        
    }
};