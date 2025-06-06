class Solution {
public:
    vector<int> lexicalOrder(int n) {

        vector<int> ans;
        int s = 0;
        backtrackSol(s,n,ans);

        return ans;
        
    }

   void backtrackSol(int &s,int n,vector<int> & ans){

        if(s!=0) ans.push_back(s);
        

        for(int c= 0;c<=9;c++){
            
            s= s*10+c;
            if(s==0) continue;
           
            if(s<=n) backtrackSol(s,n,ans);
           
            s/=10;
        }

    
    }
};