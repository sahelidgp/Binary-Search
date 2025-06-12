class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return nums[0];
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            
            //corner cases
            if(mid == 0 && nums[mid]!= nums[mid+1])return nums[mid];
            if(mid == n-1 && nums[mid] != nums[mid-1])return nums[mid];

            //check if the mid element is the single or not
            if(nums[mid] != nums[mid-1] && nums[mid]!= nums[mid+1])return nums[mid];

            //total length of the array will always be odd as all element are duplicates except one

            // 2 possible cases

            //Even mid Even

            if(mid % 2 == 0){
                //the single element will lie on only one half
                if(nums[mid] == nums[mid-1]){
                    //so the remaining length of the left half will be odd if we pair nums[mid] and nums[mid-1]
                    // so it is sure that the single element will lie in the left half
                    high = mid-1;
                }else {//nums[mid] == nums[mid+1]
                    // in this case the remaining lenght of the right half will be odd if we pair nums[mid] and nums[mid+1]      // one element has no pair   
                    // the single element definitely lies on the right half 
                    low = mid+1;     
                        }
            }

            //Odd mid Odd
            else{
                if(nums[mid] == nums[mid-1]){// remaining length in the left half is even means perfect duplicates
                // the single element is in the right half as right half lenght is odd
                low = mid+1; 

                }else{
                    // nums[mid] == nums[mid+1] // the remaining length in the right half is even // so perfect duplicates 
                    // the single element lies inthe left half
                    high = mid-1;
                }
            }
        }
        return -1; // if there is no single element // not possible as per the question
    }
};