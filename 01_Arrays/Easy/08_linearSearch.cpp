/*

*** Linear Search in C ***

$ Problem Statement: Given an array, and an element num the task is to find if num is present in the given array or not. If present print the index of the element or print -1.

$ Examples: 
    Input: arr[] = 1 2 3 4 5, num = 3  
    Output: 2
    Explanation: 3 is present at the 2nd index of the array.

    Input: arr[] = 5 4 3 2 1, num = 5  
    Output: 0  
    Explanation: 5 is present at the 0th index of the array.

$ Approach:
    Given an array, traverse through the entire array.
    For each element, check if the element is present in the array.
        If the element is found, print the index of the element.
        If the element is not found, print -1.

    Time Complexity: O(N), where N is the number of elements in the array. This is because we traverse the entire array to find the element.
    Space Complexity: O(1), as we are using a constant
*/

#include <iostream>
#include <vector>
using namespace std;

int linear1(vector<int> arr, int element, int n) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == element) {
            return i;
        }
    }

    return -1;
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

    int element;
    cout << "enter element to found: ";
    cin >> element;

    int index = linear1(arr, element, n);
    cout << "The element found at index: " << index;
}