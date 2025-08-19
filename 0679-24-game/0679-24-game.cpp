class Solution {
public:
vector<char> operators{'+','-','*','/'};
    bool judgePoint24(vector<int>& cards) {
        vector<int> mark(4,0);
        bool ans = false;
        for(int i = 0;i<4;i++){
            mark[i] = true;
            helper(cards,mark,ans,0,to_string(cards[i]));
            mark[i]= false;
        }
       
            
          

        return ans;
        
    }

    bool helper(vector<int> &cards,vector<int> &mark,bool &ans,int id,string pass){
        if(id==3){
            // cout << pass <<endl;'
            if(check(pass)){ans = true; return true;}
            return false;

        }

        for(int i = 0;i<4;i++){
            if(mark[i]==0){
                mark[i] = 1;
                
            for(auto op:operators){
                string  curr = pass;
                
                switch(op){
                    case '+': curr= curr+ "+" + to_string(cards[i]);
                             break;
                    case '-': curr= curr+ "-" + to_string(cards[i]);
                             break;
                    case '*': curr=curr+  "*" + to_string(cards[i]);
                             break;
                    case '/': curr= curr+ "/" + to_string(cards[i]);
                             break;
                }

                if(helper(cards,mark,ans,id+1,curr)) return true;

            }
            mark[i] = 0;
            }
            // mark[i] = 0;
        }
        return false;


    }
float applyOp(double a, double b, char op) {
    switch(op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return b!=0 ? a/b : 0; // avoid div by zero
    }
    return 0;
}

    bool check(string &s){
        vector<int> mark(3,0);
        vector<double> val;vector<char> op;

        for(int i = 0;i<s.size();i++){
            if(i%2) op.push_back(s[i]);
            else val.push_back(s[i]-'0');
        }
        
          // 1. ((v0 op0 v1) op1 v2) op2 v3
    
    double r1 = applyOp(applyOp(applyOp(val[0],val[1],op[0]), val[2],op[1]), val[3],op[2]);

    // 2. (v0 op0 (v1 op1 v2)) op2 v3
    double r2 = applyOp(applyOp(val[0], applyOp(val[1],val[2],op[1]), op[0]), val[3], op[2]);

    // 3. v0 op0 ((v1 op1 v2) op2 v3)
double r3 = applyOp(val[0], applyOp(applyOp(val[1],val[2],op[1]), val[3],op[2]), op[0]);

    // 4. v0 op0 (v1 op1 (v2 op2 v3))
    double r4 = applyOp(val[0], applyOp(val[1], applyOp(val[2],val[3],op[2]), op[1]), op[0]);

    // 5. ( (v0 op0 v1) op1 (v2 op2 v3) )
    double r5 = applyOp(applyOp(val[0],val[1],op[0]), applyOp(val[2],val[3],op[2]), op[1]);

    return (fabs(r1-24))<1e-5 ||( fabs(r2-24))<1e-5 ||( fabs(r3-24))<1e-5 ||( fabs(r4-24))<1e-5 || (fabs(r5 -24))<1e-5;
          

    }

  



};