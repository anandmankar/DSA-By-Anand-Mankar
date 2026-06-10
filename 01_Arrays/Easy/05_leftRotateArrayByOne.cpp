/*

*** Left Rotate the Array by One ***

$ Problem Statement: Given an integer array nums, rotate the array to the left by one.
Note: There is no need to return anything, just modify the given array.

$ Examples:
    Input: nums = [1, 2, 3, 4, 5]  
    Output: [2, 3, 4, 5, 1]  
    Explanation: Initially, nums = [1, 2, 3, 4, 5]  
    Rotating once to the left results in nums = [2, 3, 4, 5, 1].

    Input: nums = [-1, 0, 3, 6]  
    Output: [0, 3, 6, -1]  
    Explanation: Initially, nums = [-1, 0, 3, 6]  
    Rotating once to the left results in nums = [0, 3, 6, -1].

$ Approach:
1) Brute Force:
    Create a dummy array of the same length as the original array.
    Shift all elements in the original array toward the left, copying them into the dummy array.
    After shifting, place the value of the 0th index of the original array into the last element of the dummy array.
    Finally, print the dummy array which now contains the left-shifted elements with the 0th element moved to the last position.

    Time Complexity: O(N), where N is the size of the array. This is because we traverse the array once to shift the elements.
    Space Complexity: O(N), as we are using a temporary array of the same size as the input array to store the shifted elements.
 
2) Optimal Solution:
    Store the value of the first element of the array in a temporary variable.
    Iterate through the array starting from the second element.
    Shift each element one position to the left by assigning the current element to the position of its predecessor.
    After completing the iteration, place the value from the temporary variable into the last position of the array.

    Time Complexity: O(N), where N is the size of the input array. This is because we traverse the array once to shift the elements.
    Space Complexity: O(1), as we are using only a constant amount of extra space for the temporary variable.

*/

#include <iostream>
#include <vector>
using namespace std;

// Brute Force
vector<int> leftRotate1(vector<int> arr, int n) {
    vector<int> dummy(n);
    for(int i = 0; i < n-1; i++) {
        dummy[i] = arr[i+1];
    }
    dummy[n-1] = arr[0];

    return dummy;
}

// Optimal Solution
vector<int> leftRotate2(vector<int> arr, int n) {
    int temp = arr[0];
    for(int i = 0; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;

    return arr;
}

int main() {
    int n;
    cout << "enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array after Left rotate by one: ";
    // vector<int> dummy = leftRotate1(arr, n);
    vector<int> dummy = leftRotate2(arr, n);
    for(auto it: dummy) {
        cout << it << " ";
    }
}