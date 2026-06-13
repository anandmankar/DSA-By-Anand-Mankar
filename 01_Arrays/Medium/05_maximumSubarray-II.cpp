/*

*** Maximum Sub Array ***

$ Problem Statement: Given an array of integers arr[], find the contiguous subarray with the 
maximum sum that contains only non-negative numbers. If multiple subarrays have the same 
maximum sum return the one with longest length. If there is still a tie, return the subarray 
with the smallest starting index. If the array contains only negative numbers, return -1.

Note: A subarray is a contiguous non-empty sequence of elements within an array.

$ Examples:
    Input: arr[] = [1, 2, 3]
    Output: [1, 2, 3]
    Explanation: In the given array, every element is non-negative, so the entire array [1, 2, 3] is the valid subarray with the maximum sum.

    Input: arr[] = [-1, 2]
    Output: [2]
    Explanation: The only valid non-negative subarray is [2], so the output is [2].

    Input: arr[] = [1, 2, 5, -7, 2, 6]
    Output: [1, 2, 5]
    Explanation: The valid non-negative subarrays are [1, 2, 5] and [2, 6]. Both have the same sum of 8, but [1, 2, 5] starts earlier and also longest one so it is the preferred subarray.

$ Approach:
Start by iterating through the array using a variable i. During each iteration, add the current element arr[i] to a running sum variable.
Initialize a start variable to keep track of the starting index of the current subarray.
Use ansStart and ansEnd to store the starting and ending indices of the subarray with the maximum sum found so far. Initially, set both to -1.
If the current sum is greater than the previous maximum sum, update ansStart to start and ansEnd to i.
If the sum becomes negative at any point, reset it to 0 and set start to i + 1 to start a new subarray.
After processing all elements, ansStart and ansEnd will point to the starting and ending indices of the subarray with the maximum sum.
Return the subarray from arr[ansStart] to arr[ansEnd].

Time Complexity: O(n), where n is the number of elements in the array. We traverse the array only once.
Space Complexity: O(1). We use a constant amount of space for variables.

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// This solution is only for without constraint
vector<int> maxiSumSubarray(int n, vector<int> arr) {
    int maxiSum = INT_MIN;
    int sum = 0;
    int starIndex = -1;
    int endIndex = -1;
    int start = 0;

    for(int i = 0; i < n; i++) {
        if(sum == 0) {
            start = i;
        }

        sum += arr[i];

        if(sum > maxiSum) {
            maxiSum = sum;
            starIndex = start;
            endIndex = i;
        }

        if(sum < 0) {
            sum = 0;
        }
    }

    vector<int> ans;
    for(int i = starIndex; i <= endIndex; i++) {
        ans.push_back(arr[i]);
    }

    return ans;
}

// This is the perfect solution for the gfg Problem
vector<int> maxiSumSubarray1(int n, vector<int> arr) {
    int maxiSum = -1;
    int sum = 0;
    int start = 0;
    int ansStart = -1;
    int maxLen = 0;

    for(int i = 0; i <= n; i++) {
        if(i == n || arr[i] < 0) {
            int len = i - start;

            if(len > 0 && (sum > maxiSum || (sum == maxiSum && len > maxLen))) {
                maxiSum = sum;
                ansStart = start;
                maxLen = len;
            }

            sum = 0;
            start = i+1;
        }
        else {
            sum += arr[i];
        }
    }

    if(ansStart == -1) {
        return {-1};
    }

    return vector<int>(arr.begin() + ansStart, arr.begin() + ansStart + maxLen);

}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // vector<int> res = maxiSumSubarray(n, arr);
    vector<int> res = maxiSumSubarray1(n, arr);
    for(int it: res) {
        cout << it << " ";
    }
}