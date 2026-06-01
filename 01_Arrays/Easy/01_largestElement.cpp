/*

*** Find the Largest element in an array ***

$ Problem Statement:- Given an array, we have to find the largest element in the array.

$ Examples: 
    Input: arr[] = {2, 5, 1, 3, 0}  
    Output: 5  
    Explanation: 5 is the largest element in the array.

    Input: arr[] = {8, 10, 5, 7, 9}  
    Output: 10  
    Explanation: 10 is the largest element in the array.

$ Approach: 
1) Brute Force:
    Sort the array in ascending order.
    Print the element at the (size of the array - 1)th index, which corresponds to the largest element in the array.

    Time Complexity: O(N log N), where N is the size of the array, as we are sorting the array.
    Space Complexity: O(1), as we are using a constant

2) Optimal Solution: 
    Create a variable called max and initialize it with the value of the first element in the array.
    Use a for loop to iterate through the rest of the elements in the array.
    In each iteration, compare the current element with the max variable.
    If the current element is greater than the max value, update the max value with the current element's value.
    After completing the loop, print the max variable, which will hold the largest value in the array.

    Time Complexity: O(N), where N is the size of the array, as we are iterating through the array once.
    Space Complexity: O(1), as we are using a constant
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Brute Force
int largeElement1(int n, vector<int> arr) {
    sort(arr.begin(), arr.end());
    return arr[arr.size()-1];
}

// Optimal Approach
int largeElement2(int n, vector<int> arr) {
    int maxi = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > maxi) {
            maxi = arr[i];
        }
    }
    return maxi;
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

    // Brute Force
    int res = largeElement1(n, arr);

    // Optimal Approach
    // int res = largeElement2(n, arr);
    cout << "The largest element in array is: " << res;

}