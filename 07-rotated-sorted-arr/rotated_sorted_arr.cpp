class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target)return mid;

            // if the left portion is sorted
            if(nums[low] <= nums[mid]){
                //now check if the target lies in this region
                if(nums[low]<= target && target< nums[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            //if the right portion is sorted
            else if(nums[mid] <= nums[high]){
                if(nums[mid]< target && target<= nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }

            }
            
        }
        return -1;
    }
};