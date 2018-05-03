#include <stdio.h>
#include <list>
#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;


    int findPeakElement_helper(vector<int>& nums, int start, int end) {
       if (start == end) {
            return nums[start];
       }
       int mid = start + (end - start) / 2;
        bool left = true;
        bool right = true;
        if (mid - 1 >= 0) {
           if (nums[mid-1] > nums[mid]) {
                left = false;
           }
        } 
        if (mid + 1 <= end) {
            if (nums[mid] < nums[mid+1]) {
                right = false;
            }
        
        }
        if (left && right) {
            return nums[mid];
        } else if (!left) {
            return findPeakElement_helper(nums, start, mid - 1);
        } else if (!right) {
            return findPeakElement_helper(nums, mid + 1, end);
        }
        
    }
    
    int findPeakElement(vector<int>& nums) {
        return findPeakElement_helper(nums, 0, nums.size());
    }


int main() 
{
        //vector <int> nums = {5, 2, 3, 4, 6, 5};
        vector <int> nums = {5, 2, 3, 4, 6, 9};
        cout << findPeakElement_helper(nums, 0, nums.size()) << endl;
}
