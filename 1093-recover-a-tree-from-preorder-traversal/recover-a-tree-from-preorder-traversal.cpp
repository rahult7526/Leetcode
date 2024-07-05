#define l left
#define r right
#define null nullptr
class Solution {
public:
    vector<char> v;
    int i = 0;
    void solve(TreeNode* root,int pd, int& cd,int& x){
        if (i<v.size() && v[i]=='-'){
            if(x==-1){
                cd++;
                i++;
                solve(root,pd,cd,x);
            }else{
                i--;
            }
        }else if(i<v.size() && x==-1){
            x=v[i]-'0';
            i++;
            solve(root,pd,cd,x);
        }else if (i<v.size() && v[i-1]!='-' && v[i]!='-'){
            x=x*10+(v[i]-'0');
            i++;
            solve(root,pd,cd,x);
        }
        if(cd>pd){
            root->l= new TreeNode(x);
            x=-1;
            i++;
            pd=cd;
            cd=0;
            solve(root->l,pd,cd,x);
        }else{
            return ;
        }
        if(cd==pd){
            root->r= new TreeNode(x);
            x=-1;
            i++;
            pd=cd;
            cd=0;
            solve(root->r,pd,cd,x);
        }
        return ;
    }
    
    TreeNode* recoverFromPreorder(string traversal) {
        for (auto j : traversal )
            v.push_back(j);
        TreeNode* root = new TreeNode();
        int x =0;
        while(i<v.size() && v[i]!='-'){
            x=x*10 + (v[i]-'0');
            i++;
        }
        root->val=x;
        if(traversal.size()==1) return root;
        int d = 0;x=-1;
        solve(root,0,d,x);
        return root;
    }
};