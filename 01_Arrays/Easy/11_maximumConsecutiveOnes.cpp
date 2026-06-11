/*

*** Count Maximum Consecutive One's in the array ***

$ Problem Statement: Given an array that contains only 1 and 0 return the count of maximum consecutive ones in the array..

$ Examples:
    Input: prices = {1, 1, 0, 1, 1, 1}
    Output: 3
    Explanation: There are two consecutive 1’s and three consecutive 1’s in the array out of which maximum is 3.

    Input: prices = {1, 0, 1, 1, 0, 1} 
    Output: 2
    Explanation: There are two consecutive 1's in the array. 

$ Approach:
We need to find the longest streak of consecutive 1’s in a binary array. 
A simple idea is to traverse the array while maintaining a counter. Every 
time we encounter a 1, we increase the counter. If we encounter a 0, the streak 
breaks, so we reset the counter to 0. At each step, we track the maximum streak 
length seen so far.

    Initialize two variables:
        cnt → counts the current streak of 1’s.
        maxi → stores the maximum streak found so far.
    Traverse through the array:
        If nums[i] == 1, increment cnt.
        If nums[i] == 0, reset cnt to 0.
        Update maxi = max(maxi, cnt) at each step.
    Finally, return maxi, which contains the length of the longest consecutive 1’s.

    Time Complexity: O(N), since we scan the array once.
    Space Complexity: O(1), as only constant extra variables are used.
*/

#include <iostream>
#include <vector>
using namespace std;

int maxConsecutiveOnes(int n, vector<int> arr) {
    int cnt = 0;
    int maxCount = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] == 1) {
            cnt++;
        }
        else {
            cnt = 0;
        }
        maxCount = max(maxCount, cnt);
    }

    return maxCount;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cnt = maxConsecutiveOnes(n, arr);
    cout << "The maximum consecutive ones in array is: " << cnt;
}