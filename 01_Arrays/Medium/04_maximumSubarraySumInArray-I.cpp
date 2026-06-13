/*

*** Kadane's Algorithm : Maximum Subarray Sum in an Array ***

$ Problem Statement: Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.
A subarray is a contiguous non-empty sequence of elements within an array.

$ Examples: 
    Input: nums = [2, 3, 5, -2, 7, -4]  
    Output: 15  
    Explanation: The subarray from index 0 to index 4 has the largest sum = 15, which is the maximum sum of any contiguous subarray.

    Input: nums = [-2, -3, -7, -2, -10, -4]  
    Output: -2  
    Explanation: The largest sum is -2, which comes from taking the element at index 0 or index 3 as the subarray. Since all numbers are negative, the subarray with the least negative number gives the largest sum.

$ Approach:
1) Brute Force:
Iterate through the array with variable i, which represents the starting index of each subarray. The possible values for i range from 0 to n-1, where n is the size of the array.
Inside the first loop, run another loop with variable j that represents the ending index of the subarray. For each i, j can range from i to n-1.
For each subarray defined by i and j, iterate through its elements to calculate the sum. Maintain a variable, max, to store the maximum sum encountered so far during the iteration.
At each step, compare the current subarray sum with the current max value. If the current sum is greater, update the max value with the new sum.
Finally, after completing all iterations, return the max variable, which holds the maximum sum of any subarray.

Time Complexity: O(N^3), where N is the size of the array. This is because we have three nested loops: one for the starting index, one for the ending index, and one for calculating the sum of the subarray.
Space Complexity: O(1), as we are using a constant amount of space for variables, regardless of the input size.

2) Better Approach:
Iterate through the array with variable i, which represents the starting index of each subarray. The possible values for i range from 0 to n-1, where n is the size of the array.
Inside the first loop, iterate again with variable j to signify the ending index of the subarray and the current element of the subarray. For each i, j can range from i to n-1.
For each subarray defined by i and j, add the current element at arr[j] to the sum of the previous subarray.
Keep track of the maximum sum encountered during the iteration using a variable, say maxSum, and update it whenever a greater sum is found.
Once all iterations are complete, return maxSum as the maximum sum of all subarrays.

Time Complexity: O(N^2), where N is the size of the array. This is because we have two nested loops: one for the starting index and one for the ending index of the subarray.
Space Complexity: O(1), as we are using a constant amount of space for variables, regardless of the input size.

3) Optimal Solution:
Iterate through the array using a variable i. During each iteration, add the current element arr[i] to a running sum variable.
Keep track of the maximum sum encountered during the iteration by comparing the current sum with the previous maximum sum, and update it if the current sum is greater.
If at any point the sum becomes negative, reset it to 0, as a negative sum won't contribute positively to the overall maximum sum.
Continue the iteration until all elements in the array are processed.
Finally, return the maximum sum encountered during the iteration.

Time Complexity: O(n), where n is the number of elements in the array. We traverse the array only once.
Space Complexity: O(1). We use a constant amount of space for variables.

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Brute Force
int maximumSubarraySum1(int n, vector<int> arr) {
    int maxiSum = INT_MIN;

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int sum = 0;
            for(int k = i; k <= j; k++) {
                sum += arr[k];
            }
            maxiSum = max(maxiSum, sum);
        }
    }

    return maxiSum;
}

// Better Approach
int maximumSubarraySum2(int n, vector<int> arr) {
    int maxiSum = INT_MIN;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];

            if(sum > maxiSum) {
                maxiSum = sum;
            }
        }
    }
    return maxiSum;
}

// Optimal Approach
int maximumSubarraySum3(int n, vector<int> arr) {
    int maxiSum = INT_MIN;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        maxiSum = max(maxiSum, sum);
        if(sum < 0) {
            sum = 0;
        }
    }
    return maxiSum;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // int sum = maximumSubarraySum1(n, arr);
    // int sum = maximumSubarraySum2(n, arr);
    int sum = maximumSubarraySum3(n, arr);
    cout << "The maximum subarray sum in array is: " << sum;
}