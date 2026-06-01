/*

*** Check if an Array is Sorted ***

$ Problem Statement:  Given an array of size n, write a program to check if the given array is sorted in 
(ascending / Increasing / Non-decreasing) order or not. If the array is sorted then return True, Else return False.

$ Examples:
    Input: N = 5, array[] = {1,2,3,4,5}
    Output: True.
    Explanation: The given array is sorted i.e Every element in the array is smaller than or equals to its next values, 
    So the answer is True.

    Input: N = 5, array[] = {5,4,6,7,8}
    Output: False.
    Explanation: The given array is Not sorted i.e Every element in the array is not smaller than or equal to its next values, 
    So the answer is False. Here element 5 is not smaller than or equal to its future elements.

$ Approach:
1) Brute Force: 
    The idea is pretty simple here, We will start with the element at the 0th index, and will compare it with all of its 
        future elements that are present in the array.
    If the picked element is smaller than or equal to all of its future values then we will move to the next Index/element 
        until the whole array is traversed.
    If any of the picked elements is greater than its future elements, Then simply we will return False.
    If the size of the array is Zero or One i.e ( N = 0 or N = 1 ) or the entire array is traversed successfully 
        then we will simply return True.

    Time Complexity: O(N2), as it uses two nested loops to compare every pair of elements in the array.
    Space Complexity: O(1), as no extra space is used apart from a few variables.

2) Optimal Solution:
    As we know that for a sorted array the previous of every element is smaller than or equal to its current element.
    So, Through this, we can conclude that if the previous element is smaller than or equal to the current element then. 
        Then we can say that the two elements are sorted. If the condition is true for the entire array then the array is sorted.
    We will check every element with its previous element if the previous element is smaller than or equal to the current element 
        then we will move to the next index.
    If the whole array is traversed successfully or the size of the given array is zero or one (i.e N = 0 or N = 1). 
        Then we will return True else return False.
    
    Time Complexity: O(N), as it checks each adjacent pair once in a single pass through the array.
    Space Complexity: O(1), as it uses constant extra space regardless of input size.

*/

#include <iostream>
#include <vector>
using namespace std;

// Brute Force
bool checkSorted1(int n, vector<int> arr) {
    if(n <= 1) {
        return true;
    }

    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) {
                return false;
            }
        }
    }

    return true;
}

// Optimal Approach
bool checkSorted2(int n, vector<int> arr) {
    if(n <= 1) {
        return true;
    }

    for(int i = 0; i < n-1; i++) {
        if(arr[i] > arr[i+1])  {
            return false;
        }
    }

    return true;
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

    // bool res = checkSorted1(n, arr);
    bool res = checkSorted2(n, arr);
    if(res) {
        cout << "The array is sorted...";
    }
    else {
        cout << "The array is not sorted...";
    }
}