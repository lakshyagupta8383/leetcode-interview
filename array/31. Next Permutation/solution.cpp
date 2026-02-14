class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return;
        int pivot_ind=-1;
        for(int i=n-2;i>=00;i--){
            if(nums[i+1]>nums[i]){
                pivot_ind=i;
                break;
            }
        }
        if(pivot_ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]>nums[pivot_ind]){
                nums[i]=nums[i]^nums[pivot_ind];
                nums[pivot_ind]=nums[i]^nums[pivot_ind];
                nums[i]=nums[i]^nums[pivot_ind];
                break;
            }
        }
        reverse(nums.begin()+pivot_ind+1,nums.end());
    }
};