class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int c = 0;// number of shift performing 
        while(left != right){
            left /= 2;
            right/= 2;
            c++;      
        }
        return right << c;// shifting 1 side to the other side bez both are equal
    }
};