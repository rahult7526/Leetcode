class Solution {
public:
    bool isUgly(int x){
        if(x<1){
            return false;
        }
        if(x==1){
            return true;
        }
        while(x%2==0){
            x/=2;
        }
        while(x%3==0){
            x/=3;
        }
        while(x%5==0){
            x/=5;
        }
        if(x==1){
            return true;
        }
        return false;
    }
};