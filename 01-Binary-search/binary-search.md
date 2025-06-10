# 🔍 704. Binary Search

> **Level:** Easy    📚 **Topic:** Binary Search  
> **Leetcode Link:** [704. Binary Search](https://leetcode.com/problems/binary-search/)

---

## 🧩 Problem

Given a sorted array of **unique integers**, and a target value, return the **index** if the target is found. If not, return **-1**.

You **must** implement the solution using a **binary search** algorithm with a time complexity of **O(log n)**.

---

## 📥 Input

- `nums`: An array of integers sorted in ascending order.
- `target`: Integer value to search.

## 📤 Output

- Return the **index** of the target if found.
- Otherwise, return **-1**.

---

<details>
<summary>📘 Example 1</summary>

**Input:**
nums = [-1, 0, 3, 5, 9, 12]
target = 9

**Output:**

**Explanation:**  
Target `9` is found at index `4`.

</details>

<details>
<summary>📙 Example 2</summary>

**Input:**
nums = [-1, 0, 3, 5, 9, 12]
target = 2



**Output:**
-1

markdown
Copy
Edit

**Explanation:**  
Target `2` is not in the array.

</details>

---

## ⛓ Constraints

- `1 <= nums.length <= 10⁴`
- `-10⁴ < nums[i], target < 10⁴`
- All integers in `nums` are **unique**
- `nums` is sorted in **ascending order**

---

## 🧠 Approach

We use the **Binary Search** technique to achieve `O(log n)` runtime:

1. Set `low = 0`, `high = nums.size() - 1`
2. Repeat while `low <= high`:
   - Compute `mid = (low + high) / 2`
   - If `nums[mid] == target`: ✅ return `mid`
   - If `nums[mid] < target`: 🔍 Search in right half
   - If `nums[mid] > target`: 🔍 Search in left half
3. Return `-1` if not found.

---

## 🧾 C++ Code

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1; // Target not found
    }
};
