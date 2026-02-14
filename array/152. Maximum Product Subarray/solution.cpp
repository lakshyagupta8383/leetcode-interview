class Solution {
public:
    void swap(int &n1, int &n2){
        n1=n1^n2;
        n2=n1^n2;
        n1=n1^n2;
    }
    int maxProduct(vector<int>& nums) {
      int maxi=nums[0];
      int maxprd=nums[0];
      int minprd=nums[0];
      int n=nums.size();
      if(n==1){
        return minprd;
      }
      for(int i=1;i<n;i++){
        if(nums[i]<0) swap(minprd,maxprd);
        maxprd=max(nums[i],maxprd*nums[i]);
        minprd=min(nums[i],minprd*nums[i]);
        
        maxi=max(maxprd,maxi);
      }  
      return maxi;
    }
};