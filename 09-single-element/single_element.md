# 👩🏻‍💻540. Single Element in a Sorted Array
Solved
Medium
Topics
premium lock icon
Companies
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:
```
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
```
Example 2:
```
Input: nums = [3,3,7,7,10,11,11]
Output: 10
 
```
Constraints:
```
1 <= nums.length <= 105
0 <= nums[i] <= 105
```
# 📝 Time & Space Complexity:
Time: O(log n) — binary search.

Space: O(1)

# Approach 1
✅ Correct Strategy: Use Binary Search with Even Index Logic
🔑 Key Observation:
In a perfectly paired sorted array:

Indexes are arranged like: [0,1],[2,3],[4,5]...

So before the single element, pairs start at even indexes.

After the single element, the pairs are misaligned — they start at odd indexes.

# code
```c++
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Make sure mid is even so pairs are aligned as (even, odd)
            if (mid % 2 == 1) {
                mid--; // force mid to be even
            }

            if (nums[mid] == nums[mid + 1]) {
                // Single element must be in the second half
                low = mid + 2;
            } else {
                // Single element is in the first half (including mid)
                high = mid;
            }
        }

        // low will point to the single element
        return nums[low];
    }
};
```
# 🔍 KEY IDEA:
Pattern Before and After the Single Element:
Let’s say the single element is at index k.

Before index k: all pairs are (even index, odd index) → i % 2 == 0

After index k: pairs are misaligned → they become (odd index, even index)

Example:
cpp
Copy
Edit
[1, 1, 2, 2, 3, 3, 4, 5, 5]
                   ↑
                 Single = 4
Indexes:

 0  1  2  3  4  5  6  7  8
[1, 1, 2, 2, 3, 3, 4, 5, 5]
                   ↑
               This is the single element (index 6)
Before index 6:

1,1 at indices 0,1

2,2 at indices 2,3

3,3 at indices 4,5

So: Pairs are at even-odd positions (i, i+1)

After index 6:

5,5 at indices 7,8

Now: the pairs are shifted — no longer aligned properly.

# ✅ CORE STRATEGY:
Use Binary Search:
Keep mid always at even index, because we want to check if the pair starts at mid.

Then compare nums[mid] with nums[mid + 1].

If:
nums[mid] == nums[mid + 1]:
➤ The single element lies after this pair. So, move low = mid + 2.

nums[mid] != nums[mid + 1]:
➤ This means:

Either you're at the single element, or

Pair alignment is broken, so the single lies before.

So, move high = mid.

Loop continues until:
low == high, pointing to the single element.