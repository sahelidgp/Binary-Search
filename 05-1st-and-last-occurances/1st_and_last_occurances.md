# 👩🏻‍💻34. Find First and Last Position of Element in Sorted Array
# 📖[problem link](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

`Medium`

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return `[-1, -1]`.

You must write an algorithm with `O(log n)` runtime complexity.

 

Example 1:
```
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
```

Example 2:
```
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
```
Example 3:
```
Input: nums = [], target = 0
Output: [-1,-1]
 ```

Constraints:
```
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
```
# Solution 
# 1st approach 
using only lower bound function
```c++
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
```
# another approach
```c++
class Solution {
public:
    //here lower bound means ->the smallest index for which the index of that element is graeter than or equal to that array
    int lower_bound(vector<int>& nums,int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n; 
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid-1;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }else {
                high = mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lower_bound(nums,target) ;
        int n = nums.size();
        if(lb == n || nums[lb] != target){
            return {-1,-1};
        }
        else return {lb,lower_bound(nums,target+1)-1};
    }
};
```
# 2nd approch 
using both upper bound and lower bound function
```c++
class Solution {
public:
    //here lower bound means ->the smallest index for which the index of that element is graeter than or equal to that array
    int lower_bound(vector<int>& nums,int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n; 
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid-1;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }else {
                high = mid-1;
            }
        }
        return ans;
    }
    // smallest index for which the element at the index is strictly greater than the target
    int upper_bound(vector<int>& nums,int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n; 
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] > target){
                ans = mid;
                high = mid-1;
            }
          else {
                low = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lower_bound(nums,target) ;
        int n = nums.size();
        if(lb == n || nums[lb] != target){
            return {-1,-1};
        }
        return {lb,upper_bound(nums,target)-1};
    }
};
```