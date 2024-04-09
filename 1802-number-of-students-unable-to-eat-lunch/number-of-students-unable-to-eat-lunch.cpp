#include<bits/stdc++.h>
class Solution {
public:
    int countStudents(vector<int>& boys, vector<int>& food) {
        deque<int> q;
        stack<int> st;
        int bsum=0,fsum=0;
        for(int i=food.size()-1;i>=0;i--)st.push(food[i]),fsum+=food[i];
        for(int i=boys.size()-1;i>=0;i--)q.push_front(boys[i]),bsum+=boys[i];
        if(bsum==fsum)return 0;
        while(true){
            if(st.top()==q.front()){ // boy get the required food
                bsum-=q.front();
                st.pop();
                q.pop_front();
            }
            else{
                q.push_back(q.front());
                q.pop_front();
                if(bsum==q.size() || bsum==0)break;
            }  
        }
        return q.size();
    }
};