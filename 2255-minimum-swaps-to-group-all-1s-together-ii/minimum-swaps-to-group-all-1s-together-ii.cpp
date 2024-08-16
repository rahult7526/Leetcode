class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int len=nums.size();
        int arr[len];
        int cnt=0;
        memset(arr,0,sizeof(arr));
        if(nums[0]==1){
                arr[0]=1;
                cnt++;
        }
        for(int i=1;i<len;i++){
            arr[i]=arr[i-1];
            if(nums[i]==1){
                arr[i]++;
                cnt++;
            }
        }

        //cout<<cnt<<endl;

        int mx=len-cnt;
        if(cnt==0)return 0;
        for(int i=0;i<len;i++){
            int ran=i+cnt-1;
            int chk;
            if(i==0)chk=cnt-arr[ran];
            else if(ran>=len){
                    ran=ran-len;
                    int k=arr[len-1]-arr[i-1];
                    chk=cnt-(arr[ran]+k);
            }
            else
                chk=cnt-(arr[ran]-arr[i-1]);

            //cout<<arr[ran]<<" "<<arr[i-1]<<endl;
            mx=min(mx,chk);
            //cout<<i<<" "<<chk<<endl;
        }
        return mx;
    }
};