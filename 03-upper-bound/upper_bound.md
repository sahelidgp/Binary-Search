

# 🧩  Implement Upper Bound

**Difficulty:** Easy  
**Accuracy:** 52.54%  
**Points:** 2  
🔗 [View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/implement-upper-bound/1)

### 📝 Statement

Given a sorted array `arr[]` and a number `target`, the task is to find the **upper bound** of the target.  
The upper bound is the **smallest index** where the element is **strictly greater** than the given number.

> If all elements are smaller than or equal to the target, return the array’s length.

---

### 📥 Input

- `arr[]`: Sorted array of integers.
- `target`: Integer for which to find the upper bound.

---

### 📤 Output

- Returns the smallest index where `arr[index] > target`.

---

### 🔁 Examples

#### Example 1:
```
Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9  
Output: 3  
```

#### Example 2:
```
Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 11  
Output: 6  
```

#### Example 3:
```
Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 100  
Output: 7  
```

---

### ✅ Constraints

- `1 ≤ arr.size() ≤ 10^6`
- `1 ≤ arr[i] ≤ 10^6`
- `1 ≤ target ≤ 10^6`

---
### ✅ C++ Code

```cpp
int upperBound(vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = n; // default if no such element found

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > target) {
            ans = mid;
            high = mid - 1; // search left
        } else {
            low = mid + 1; // search right
        }
    }
    return ans;
}
```

---


