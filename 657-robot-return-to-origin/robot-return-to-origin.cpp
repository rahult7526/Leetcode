class Solution {
public:
    bool judgeCircle(string moves) {

        // map to store the counts of R,L,D,U
        map<int,int>mp;
        for(int i=0;i<moves.size();i++){
            mp[moves[i]]++;
        }

       // yadi R hai toh L hona hi chahiye apne position per vapas ane ke liye\U0001f601
        if(mp['R']!=mp['L'])return false;
        if(mp['U']!=mp['D'])return false;
        return true;
    }
};