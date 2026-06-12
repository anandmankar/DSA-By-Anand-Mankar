/*

*** Sort an array of 0s, 1s and 2s ***

$ Problem Statement: Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order. The sorting must be done in-place, without making a copy of the original array.

$ Examples:
    Input: nums = [1, 0, 2, 1, 0]
    Output: [0, 0, 1, 1, 2]
    Explanation: The nums array in sorted order has 2 zeroes, 2 ones and 1 two

    Input: nums = [0, 0, 1, 1, 1]
    Output: [0, 0, 1, 1, 1]
    Explanation: The nums array in sorted order has 2 zeroes, 3 ones and zero twos.

$ Approach:
1) Brute Force:
We are given an array containing only 0s, 1s, and 2s. Since the values are fixed and known, the simplest approach is to first count how many 0s, 1s, and 2s are present in the array. After counting, we overwrite the original array based on the frequency of these values first fill it with 0s, then 1s, then 2s. This does not require any extra array and modifies the input array in-place.
Initialize three counters to count the frequency of 0s, 1s, and 2s
Loop through the array once and count each number
In the second loop, fill the array based on the frequency of each number: first 0s, then 1s, then 2s

Time Complexity: O(n),We traverse the array twice: once to count, once to overwrite. Each operation is O(n).
Space Complexity: O(1), We use only a constant number of counters regardless of the input size. No extra array is used.

2) Better Approach:
Since the array contains only 0s, 1s, and 2s, we can exploit this limited range of values to count how many of each element exists. Once we know how many 0s, 1s, and 2s are in the array, we can simply overwrite the original array by placing that many 0s, then 1s, and then 2s in order. This approach avoids sorting and gives a linear-time, constant-space solution.
Initialize three counters to zero: one each for 0s, 1s, and 2s.
Traverse the entire array and increment the respective counter based on the element value.
After counting, overwrite the array:
Place all 0s first (based on count of 0s).
Then all 1s (based on count of 1s).
Then all 2s (based on count of 2s).

Time Complexity:,O(n) We make two passes through the array: one for counting and one for updating. So the total time is proportional to the size of the array.
Space Complexity:O(1),Only three integer variables (cnt0, cnt1, cnt2) are used for counting. No extra space is used proportional to the input size.

3) Optimal Solution --> Dutch National Flag Algorithm
This approach is a direct implementation of the Dutch National Flag algorithm.

We divide the array into three partitions using three pointers – low, mid, and high.
    From 0 to low-1, we’ll keep only 0s
    From low to mid-1, only 1s
    From high+1 to n-1, only 2
The range from mid to high is the unsorted zone we’re scanning and fixing. At each step:
    If arr[mid] == 0, it belongs to the left section → swap with low, move both low and mid.
    If arr[mid] == 1, it’s already in the middle section → just move mid.
    If arr[mid] == 2, it belongs to the right section → swap with high, only move high.
When you swap with high, you don’t move mid because the incoming value might still be 0 or 2 which needs processing.This ensures we sort the array in one single pass without using extra space.
    Start with three pointers at the beginning, middle, and end of the array.
    Iterate while the middle pointer is less than or equal to the end pointer.
    If the current element belongs to the front section:
        Swap it with the element at the front boundary.
        Move both front and middle boundaries forward.
    If the current element belongs to the middle section:
        Move the middle boundary forward.
    If the current element belongs to the end section:
        Swap it with the element at the end boundary.
        Move the end boundary backward.
    Repeat until all elements are in their correct zones.

Time Complexity: O(n) The array is traversed only once using the `mid` pointer. Each element is checked at most once, and swaps are done in constant time.
Space Complexity: O(1) Only a few integer pointers (`low`, `mid`, `high`) are used. Sorting is done in-place, requiring no additional space.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Using sort function
vector<int> sort1(int n, vector<int> arr) {
    sort(arr.begin(), arr.end());
    return arr;
}

// Better Approach
vector<int> sort2(int n, vector<int> arr) {
    int cntZero = 0;
    int cntOne = 0;
    int cntTwo = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            cntZero++;
        }
        else if(arr[i] == 1) {
            cntOne++;
        }
        else {
            cntTwo++;
        }
    }

    for(int i = 0; i < cntZero; i++) {
        arr[i] = 0;
    }

    for(int i = cntZero; i < cntZero+cntOne; i++) {
        arr[i] = 1;
    }

    for(int i = cntZero+cntOne; i < n; i++) {
        arr[i] = 2;
    }

    return arr;
}

// Brute Force
vector<int> sort3(int n, vector<int> arr) {
    int cntZero = 0;
    int cntOne = 0;
    int cntTwo = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            cntZero++;
        }
        else if(arr[i] == 1) {
            cntOne++;
        }
        else {
            cntTwo++;
        }
    }

    int index = 0;

    while(cntZero--) {
        arr[index] = 0;
        index++;
    }

    while(cntOne--) {
        arr[index++] = 1;
    }

    while(cntTwo--) {
        arr[index++] = 2;
    }

    return arr;
}

// Optimal Approach --> Dutch National Flag Algorithm
vector<int> sort4(int n, vector<int> arr) {
    int left = 0;
    int right = n-1;
    int mid = 0;

    while(mid <= right) {
        if(arr[mid] == 0) {
            swap(arr[mid], arr[left]);
            left++;
            mid++;
        }
        else if(arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[right]);
            right--;
        }
    }

    return arr;
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

    cout << "Array after sorting: ";
    // vector<int> nums = sort1(n, arr);
    // vector<int> nums = sort2(n, arr);
    // vector<int> nums = sort3(n, arr);
    vector<int> nums = sort4(n, arr);
    for(int it: nums) {
        cout << it << " ";
    }
}