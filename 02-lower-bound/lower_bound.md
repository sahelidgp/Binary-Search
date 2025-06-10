# ✅Implement Lower Bound

**Difficulty:** Easy  
**Accuracy:** 50.04%  
**Points:** 2  
**Source:** [GeeksforGeeks - Implement Lower Bound](https://practice.geeksforgeeks.org/problems/implement-lower-bound/1)

---

## 📝 Problem Statement

Given a sorted array `arr[]` and a number `target`, the task is to find the lower bound of the target in this given array.  
The lower bound of a number is defined as the smallest index in the sorted array where the element is **greater than or equal** to the given number.

> 🔹 If all elements in the array are smaller than the target, return the length of the array.

---

## 📥 Input

- `arr[]`: A sorted array of integers.
- `target`: Integer value to search the lower bound for.

---

## 📤 Output

- Returns the **smallest index** where `arr[index] >= target`.

---

## 🔁 Examples

### Example 1:
Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
Output: 3
Explanation: arr[3] = 10 ≥ 9

shell
Copy code

### Example 2:
Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 11
Output: 4
Explanation: arr[4] = 11 is the first element ≥ 11

shell
Copy code

### Example 3:
Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 100
Output: 7
Explanation: No element ≥ 100, so return length of array = 7

yaml
Copy code

---

## 🚫 Constraints

- `1 ≤ arr.size() ≤ 10^6`
- `1 ≤ arr[i] ≤ 10^6`
- `1 ≤ target ≤ 10^6`

---

## 💡 Approach

- Use binary search to efficiently find the lower bound.
- Initialize:
  - `low = 0`
  - `high = n - 1`
  - `ans = n` (default to array length if no element ≥ target)
- While `low <= high`:
  - Calculate `mid = (low + high) / 2`
  - If `arr[mid] >= target`, update `ans = mid`, and continue to search in the left half.
  - Else, search the right half.
- Return `ans`.

---

## ✅ Code (C++)

```cpp
#include <bits/stdc++.h>
using namespace std;

int lower_bound(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 2, 7, 9, 89, 98};
    int target = 2;
    cout << lower_bound(nums, target) << endl;
    return 0;
}
🔗 Click here to view the original question on GeeksforGeeks
yaml
Copy code
