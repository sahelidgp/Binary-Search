# Number of occurrence
Difficulty: EasyAccuracy: 59.34%Submissions: 330K+Points: 2Average Time: 20m
Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 

Examples :
```
Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
Output: 4
 Explanation: target = 2 occurs 4 times in the given array so the output is 4.
```
```
Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
Output: 0
Explanation: target = 4 is not present in the given array so the output is 0.
```
```
Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
Output: 3
Explanation: target = 12 occurs 3 times in the given array so the output is 3.
```

Constraints:
```
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
1 ≤ target ≤ 106
```
# c++ code
```c++
class Solution{
    public:
    int lower_bound(vector<int>& arr,int target){
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int ans = n; 
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] >= target){
                ans = mid;
                high = mid-1;
            }
            else if(arr[mid] < target){
                low = mid+1;
            }else {
                high = mid-1;
            }
        }
        return ans;
    }
    // smallest index for which the element at the index is strictly greater than the target
    int upper_bound(vector<int>& arr,int target){
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int ans = n; 
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] > target){
                ans = mid;
                high = mid-1;
            }
          else {
                low = mid+1;
            }
        }
        return ans;
    }
   
  
    int countFreq(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int lb = lower_bound(arr,target);
        if(lb == n || arr[lb] != target) return 0;
        int d = upper_bound(arr,target)-1 - lb ;
        return d+1;
        
    }
};
```
# approach 2
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
    int countFreq(vector<int>& arr, int target) {
        // code here
        vector<int>v;
        v = searchRange(arr,target);
        if(v[1] == -1 && v[0] == -1)return 0;
        return v[1]-v[0]+1;
    }
};
```