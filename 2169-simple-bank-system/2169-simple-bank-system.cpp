class Bank {
public:
int n;
vector<long long> b;
    Bank(vector<long long>& balance) {
        b = balance;
        n = balance.size();
        
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(validac(account1) && validac(account2) && (b[account1-1]-money)>=0) {
          
          b[account1-1]-=money;
          b[account2-1]+=money;



            return true;

        }

        return false;
        
    }
    
    bool deposit(int account, long long money) {
        if(validac(account)){
            b[account-1]+=money;
            return true;
        }

        return false;
        
    }
    
    bool withdraw(int account, long long money) {
        if(validac(account) && b[account-1]-money >=0){
            b[account-1]-=money;
            return true;
        }
        

        return false;
    }
    bool validac(int &ac){
        return ac>=1 && ac<=n;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */