class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 1;          // first element cannot be peak
        int high = n - 2;     // last element cannot be peak

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid; // peak element found
            } else if (arr[mid] > arr[mid - 1]) {
                low = mid + 1; // move right
            } else {
                high = mid - 1; // move left
            }
        }
        return -1; // shouldn't be reached if input is valid mountain array
    }
};
