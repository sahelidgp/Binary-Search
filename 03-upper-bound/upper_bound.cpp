// User function Template for C++
class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int low = 0;
        int high = n-1;
         int ans = n;
        while(low <= high){ // the loop will end when low > high
        
        // upper bound means the smallest index for which the array element is strictly grater than the target
            // imaginary hypothetical index if there is no element which is strictly greater than the target
            int mid = (low+high)/2;
            
            if(arr[mid] > target){ // if we have found any element then we dont have to find the right half so reduce the search space 
            // store the upperbound index in the ans as it can be possible answer
                ans = mid;
            //now search for the smallest index
                high = mid-1;
            }
            else {// if the array element is lesser than or equal to the target then there is no possible answer which can lie in the left half of  that element so reduce the search space and reduce the search space
                low = mid+1;
                
            }
                
        }
            // now return the ans
            return ans;
        
    }
};
