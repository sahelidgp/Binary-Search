class Solution {
private:
    int lower_bound(vector<int>&nums, int low ,int high, int target){
        while(low <= high){
            int mid = (low+high)>>1;
            if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int startPosition = lower_bound(nums,low,high,target);
        int endPosition = lower_bound(nums,low,high,target+1)-1;
        if(startPosition < n && nums[startPosition] == target){
            return {startPosition,endPosition};
        }
        return {-1,-1};
    }
};