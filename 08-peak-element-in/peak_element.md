# 852. 👩🏻‍💻Peak Index in a Mountain Array

You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.

 

Example 1:
```
Input: arr = [0,1,0]

Output: 1
```
Example 2:
```
Input: arr = [0,2,1,0]

Output: 1
```
Example 3:
```
Input: arr = [0,10,5,2]

Output: 1

 ```

Constraints:
```
3 <= arr.length <= 105
0 <= arr[i] <= 106
arr is guaranteed to be a mountain array.
```

# 💡Approach
 

 we have to find the peak element 

 [1 2 6 7 `8`6 4 3]   
 here  the peak element  is 8 
 
 * the portion before the peak element will lie in the  increasing slope
 * the portion after the peak element will lie in the decreasing slope
 * here we can apply binary search 
 * we will initialize the low as 1 and high as n-2 as the 1st and the last element can not be the peak element as it is given in the question that the array will always be mountain  array . so we can apply binary search in   `[2 6 7 8 4 3]`
 * now there are three possibilities :
*  arr[mid] is the peak element : a[mid-1]<a[mid]>a[mid+1]
* mid lies in the increasing slope : a[mid-1]<a[mid] => search in the right half
* mid lies in the decreasing slope : a[mid]>a[mid+1] = >search in the left half


               8
              / \
             7   \
            /     \
           6       \
          /         4
         /           \
        /             3
       2