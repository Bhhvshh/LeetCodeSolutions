class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int num = 0;

        for(auto &x:operations){
            if(x[1]=='+')num++;
            else num--;
        }


        return num;
        
    }
};