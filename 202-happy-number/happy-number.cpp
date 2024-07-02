class Solution {
public:
    bool isHappy(int n) {
        if (n==1 || n==7) return true;
        if (n==2 || n==3 || n==4 || n==5 || n==6 || n==8 || n==9) return false;
        int ans=0;
        int temp=0;
        int nn=n;
        while(nn>0){
            temp=nn%10;
            ans=ans+(temp*temp);
            nn=nn/10;
            temp=0;
        }
        return isHappy(ans);
    }
};