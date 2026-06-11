/*

*** Length of the longest subarray with zero Sum ***

$ Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

$ Examples:
Input: N = 6, array[] = {9, -3, 3, -1, 6, -5}  
Result: 5  
Explanation: The following subarrays sum to zero:
            - {-3, 3}
            - {-1, 6, -5}
            - {-3, 3, -1, 6, -5}
The length of the longest subarray with sum zero is 5.

Input: N = 8, array[] = {6, -2, 2, -8, 1, 7, 4, -10}  
Result: 8  
Explanation: Subarrays with sum zero:
            - {-2, 2}
            - {-8, 1, 7}
            - {-2, 2, -8, 1, 7}
            - {6, -2, 2, -8, 1, 7, 4, -10}
The length of the longest subarray with sum zero is 8.

$ Approach:
1) Brute Force:
Initialize a variable max = 0, which stores the length of the longest subarray with a sum of 0.
Traverse the array from the start and initialize a variable sum = 0, which stores the sum of the subarray starting with the current index.
Traverse from the next element of the current index up to the end of the array. Each time, add the element to the sum and check if it is equal to 0.
If sum = 0, check if the length of the subarray so far is greater than max, and if yes, update max.
Continue adding elements and repeat the above step until the outer loop completes traversing all elements.
Finally, return the max which holds the length of the longest subarray with a sum of 0.

Time Complexity: O(N^2), where N is the size of the array. This is because we are using two nested loops to check all possible subarrays.
Space Complexity: O(1), as we are not using any additional data structures that grow with input size. We are only using a few variables to store the maximum length and the current sum.

2) Optimal Solution:
Initialize a variable sum = 0, which stores the sum of elements traversed so far, and another variable max = 0, which stores the length of the longest subarray with sum zero.
Declare a HashMap<Integer, Integer> to store the prefix sum of every element as a key and its index as a value.
Traverse the array and add the array element to the sum.
If sum = 0, update max with the maximum value between max and current_index + 1, as the subarray from the start to the current index has a sum of 0.
If sum is not equal to zero, check the HashMap to see if we've encountered this sum before.
If the HashMap contains the sum, this indicates that a subarray with the same sum exists, so update max accordingly.
If the sum is not found in the HashMap, insert (sum, current_index) into the HashMap to store the prefix sum until the current index.
After traversing the entire array, the max variable will hold the length of the longest subarray with a sum equal to zero. Return max.

Time Complexity: O(n)
Space Complexity: O(n)

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// brute Force
int longestSubarray1(int n, vector<int> arr) {
    int maxCnt = 0;

    for(int i = 0; i < n; i++) {
        int cnt = 0;
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            cnt++;
            if(sum == 0) {
                maxCnt = max(maxCnt, cnt);
            }
        }
    }

    return maxCnt;
}

// Optimal Solution
int longestSubarray2(int n, vector<int> arr) {
    int sum = 0;
    int maxLen = 0;

    unordered_map<int, int> preSumMap;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == 0) {
            maxLen = max(maxLen, i+1);
        }
        else {
            if(preSumMap.find(sum) != preSumMap.end()) {
                maxLen = max(maxLen, i - preSumMap[sum]);
            }
            else {
                preSumMap[sum] = i;
            }
        }
    }

    return maxLen;
}

int main() {
    int n;
    cout << "enter array size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // int num = longestSubarray1(n, arr);
    int num = longestSubarray2(n, arr);
    cout << "The longest subarray with zero sum is: " << num;
}