// lower bound means the smallest index for which the element at that index is equal or larger than the target

#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
    int lower_bound(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n; //hypothetical index in case there is no element lsrger then the atrget in the array 
        while(low <= high){ // the loop will exit when low > high 
            int mid = (low + high)/2; //find the mid index
            if(nums[mid] >=  target){// if nums[mid] >= target then it can be a probable ans 
                ans = mid; // so store this into the ans until we get a smaller index for which nums[i]>=target

                high = mid-1; // we have found an index for which nums[i]>=target 
                // now we have to find smaller indices for which the condition is true 
                // as the array is sorted so going rightwards will give higher indices 
                //so reduce the search spaces 

            }
            else low =  mid+1; // if nums[mid]<target then the condotion is not true //

            // so for sure we have to go rightward so reduce the search spaces by eliminating the left half
       }
        return ans;
    }
    int main(){
        vector<int>nums;
        nums.push_back(1);
        nums.push_back(2);
        nums.push_back(2);
        nums.push_back(7);
        nums.push_back(9);
        nums.push_back(89);
        nums.push_back(98);
        cout<<lower_bound(nums,2);

    }