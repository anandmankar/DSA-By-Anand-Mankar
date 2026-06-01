/*

*** Second Largest Element ***

$ Problem Statement: Given an array, find the second largest element in the array. 
                    Print ‘-1’ in the event that either of them doesn’t exist

$ Examples: 
    Input: [1, 2, 4, 7, 7, 5]  
    Output: Second Largest : 5  
    Explanation: The elements are sorted as 1, 2, 4, 5, 7, 7. Hence the second largest element is 5.

    Input: [1]  
    Output: Second Largest : -1  
    Explanation: Since there is only one element in the array. Therefore, there is no second largest element present.

$ Approach: 
1) Brute Force: 
    Sort the array in ascending order.
    The element at the second index from the end (index length-2) is the second largest element.
    
    Time Complexity: O(N log N), for sorting the array.
    Space Complexity: O(1), as we are using a constant amount of space for variables.

2) Better Approach: 
    Perform a single traversal to find the largest elements in the array.
    Similarly, find the element just smaller than the largest element (this will be the second largest).

    Time Complexity: O(N), we do two linear traversals in our array.
    Space Complexity: O(1), as we are using a constant amount of space for variables.

3) Optimal Approach: 
    If the current element is larger than 'large', update the values of second_large and large.
    Else if the current element is larger than 'second_large', update the value of second_large.
    After traversing the array, the second largest element will be stored in the variable second_large.

    Time Complexity: O(N), we do two linear traversals in our array.
    Space Complexity: O(1), as we are using a constant

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

// Brute Force --> Only work when elements in array are distinct
int sLargest1(int n, vector<int> arr) {
    if(n <= 1) {
        return -1;
    }

    sort(arr.begin(), arr.end());

    return arr[n-2];
}

// Better Approach 
int sLargest2(int n, vector<int> arr) {
    if(n <= 1) {
        return -1;
    }

    int large = INT_MIN;
    int slarge = INT_MIN;

    for(int i = 0; i < n; i++) {
        large = max(large, arr[i]);
    }

    for(int i = 0; i < n; i++) {
        if(arr[i] > slarge && arr[i] != large) {
            slarge = arr[i];
        }
    }

    return slarge;
}

int sLargest3(int n, vector<int> arr) {
    if(n <= 1) {
        return -1;
    }

    int large = INT_MIN;
    int slarge = INT_MIN;

    for(int i = 0; i < n; i++) {
        if(arr[i] > large) {
            slarge = large;
            large = arr[i];
        }
        else if(arr[i] > slarge && arr[i] != large) {
            slarge = arr[i];
        }
    }

    return slarge;
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

    // int result = sLargest1(n, arr);
    // int result = sLargest2(n, arr);
    int result = sLargest3(n, arr);
    cout << "The second largest element in array is: " << result;
}