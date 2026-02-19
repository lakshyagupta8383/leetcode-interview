class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int j=1;
        int n=intervals.size();
        sort(intervals.begin(), intervals.end());

        int current_start=intervals[0][0];
        int current_end=intervals[0][1];
        if(n<=1) return intervals;
        while(j<n){
            if(intervals[j][0]<=current_end){
                current_end= 
                max(current_end,intervals[j][1]);
            }
            else{
                result.push_back(
                    {
                        current_start,
                        current_end,
                    }
                );
                current_start=intervals[j][0];
                current_end=intervals[j][1];
            }
            j++;
        }
        result.push_back
            ({current_start, current_end});
        return result;
    }
};