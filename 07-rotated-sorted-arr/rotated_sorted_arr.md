# 👩🏻‍💻 33. Search in Rotated Sorted Array

`Medium`
## 💡 [problem link](https://leetcode.com/problems/search-in-rotated-sorted-array/description/)
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:
```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```
Example 2:
```
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```
Example 3:
```
Input: nums = [1], target = 0
Output: -1
 
```
Constraints:
```
1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104
```

# Approach
This code implements a modified Binary Search algorithm to efficiently find a target value in a rotated sorted array.

Approach Summary
The core idea is to leverage the fact that even though the entire array is rotated, at least one half of the array (from left to mid or mid to right) will always remain sorted.

The algorithm works as follows:

1 ) Initialize Pointers: Set left to the start of the array (index 0) and right to the end of the array (last index).
2 ) Iterate with Binary Search: Continue the loop as long as left <= right.
3 ) Calculate Midpoint: Compute mid = left + (right - left) / 2 to prevent potential integer overflow compared to (left + right) / 2.
4 ) Target Found: If nums[mid] == target, we've found the target, so return mid.
5 ) Identify Sorted Half:

Case 1: Left half is sorted (nums[mid] >= nums[left])

This means the elements from nums[left] to nums[mid] are in ascending order.
Check if the target falls within this sorted left half: nums[left] <= target && target <= nums[mid].
If yes, the target must be in this half. Discard the right half by setting right = mid - 1.
If no, the target must be in the unsorted right half. Discard the left half by setting left = mid + 1.
Case 2: Right half is sorted (nums[mid] < nums[left])

This means the elements from nums[mid] to nums[right] are in ascending order.
Check if the target falls within this sorted right half: nums[mid] <= target && target <= nums[right].
If yes, the target must be in this half. Discard the left half by setting left = mid + 1.
If no, the target must be in the unsorted left half. Discard the right half by setting right = mid - 1.
6 ) Target Not Found: If the loop finishes (left > right) without finding the target, it means the target is not in the array, so return -1.

Complexity:

Time Complexity: O(logN) - In each step, the search space is halved, similar to a standard binary search.
Space Complexity: O(1) - Only a few constant extra variables are used.
Complexity
Time complexity:O(log n)
Space complexity:O(1)