/*

*** Longest Subarray with given Sum K(Positives) ***

$ Problem Statement: Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.

$ Examples:
    Input: nums = [10, 5, 2, 7, 1, 9], k = 15  
    Output: 4  
    Explanation: The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.

    Input: nums = [-3, 2, 1], k = 6  
    Output: 0  
    Explanation: There is no sub-array in the array that sums to 6. Therefore, the output is 0.

$ Approach:
1) Brute Force:
    We first run a loop with index i to select every possible starting index of the subarray. These starting indices range from 0 to n-1 where n is the size of the array.
    Inside this loop, we run another loop with index j to select the ending index of the subarray. For each subarray starting at index i, the ending index j can range from i to n-1.
    Next, for each subarray starting from index i and ending at index j (i.e., arr[i...j]), we run an additional loop to calculate the sum of all the elements in that subarray.
    If the sum equals k, we consider its length, which is (j - i + 1). Among all such subarrays, we keep track of the maximum length by comparing all the lengths found so far.

    Time Complexity: O(n3), where n is the size of the array. This is because we have three nested loops: one for the starting index, one for the ending index, and one for calculating the sum of the subarray.
    Space Complexity: O(1), as we are using a constant amount of space for variables and not using any additional data structures that grow with input size.

2) Optimal Solution:
    Two pointers, left and right, are used to maintain the current window of elements in the array. These pointers represent the start and end of the current subarray.
    A variable, sum, is used to keep track of the sum of the elements in the current window between left and right.
    The right pointer expands the window by including new elements, increasing the sum.
    If the sum of the window exceeds k, the left pointer shrinks the window by removing elements from the start until the sum is less than or equal to k.
    If the sum of the current window equals k, the maximum length of such a subarray is updated.
    The process continues until the right pointer traverses the entire array.
    Finally, the maximum length of the subarray with sum k is returned as the result.

    Time Complexity: O(2N), where N is the size of the array. The algorithm traverses the array once with two pointers, making it linear in time complexity.
    Space Complexity: O(1), as it uses a constant amount of space.

*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int longestSubarray1(int n, vector<int> arr, int k) {
    int maxCnt = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        int cnt = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            cnt++;
            if(sum == k) {
                maxCnt = max(cnt, maxCnt);
            }
        }
    }

    return maxCnt;
}

// Brute Force
int longestSubarray2(int n, vector<int> arr, int k ) {
    int maxLength = 0;
    for(int startIndex = 0; startIndex < n; startIndex++) {
        for(int endIndex = startIndex; endIndex < n; endIndex++) {
            int currentSum = 0;
            for(int i = startIndex; i <= endIndex; i++) {
                currentSum += arr[i];
            }

            if(currentSum == k) {
                maxLength = max(maxLength, endIndex-startIndex+1);
            }
        }
    }

    return maxLength;
}

// Optimal Solution
int longestSubarray3(int n, vector<int> arr, int k) {
    int maxLen = 0;
    int left = 0, right = 0;
    int sum = arr[0];

    while(right < n) {
        while(left <= right && sum > k) {
            sum -= arr[left];
            left++;
        }

        if(sum == k) {
            maxLen = max(maxLen, right-left+1);
        }

        right++;
        if(right < n) sum += arr[right];
    }

    return maxLen;
}

// Better Solution
int longestSubarray4(int n, vector<int> arr, int k) {
    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == k) {
            maxLen = max(maxLen, i+1);
        }

        int rem = sum - k;

        if(preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        if(preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements in array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the k sum: ";
    cin >> k;

    // int num = longestSubarray1(n, arr, k);
    // int num = longestSubarray2(n, arr, k);
    // int num = longestSubarray3(n, arr, k);
    int num = longestSubarray4(n, arr, k);
    cout << "The longest Subarray with sum k is: " << num;
}


