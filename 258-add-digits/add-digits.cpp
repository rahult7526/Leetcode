class Solution {
public:
    int addDigits(int num) {
        if(num<10) 
            return num;
        int d,sum=0;
        while(num>0)
        {
            d=num%10;
            sum+=d;
            num=(int)num/10;
        }
        return addDigits(sum);
        
    }
};