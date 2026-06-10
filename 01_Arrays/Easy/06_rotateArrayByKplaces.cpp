/*

*** Rotate array by K elements ***

$ Problem Statement: Given an array of integers, rotating array of elements by k elements either left or right.

$ Examples:
    Input : nums = [1, 2, 3, 4, 5, 6, 7], k = 2, right
    Output : [6, 7, 1, 2, 3, 4, 5]
    Explanation : rotate 1 step to the right: [7, 1, 2, 3, 4, 5, 6]
    rotate 2 steps to the right: [6, 7, 1, 2, 3, 4, 5] 

    Input : nums = [1, 2, 3, 4, 5, 6], k=2, left
    Output : [3, 4, 5, 6, 1, 2]
    Explanation :rotate 1 step to the left: [2, 3, 4, 5, 6, 1]
    rotate 2 steps to the left: [3, 4, 5, 6, 1, 2]

$ Approach:
1) Brute Force:
Right Rotation: We store the last k elements of the array into a temporary array. Then we shift all the other elements (n-k elements) to the right by k positions. Finally, we place the elements from the temporary array at the beginning of the original array. This achieves a right rotation by k positions.
    Take the last k elements and store them in a temporary array.
    Shift the first n-k elements to the right by k positions.
    Copy the k stored elements from the temporary array to the start of the original array.

Left Rotation: We store the first k elements in a temporary array. Then we shift the remaining n-k elements to the left by k positions. Finally, we copy the elements from the temporary array to the end of the array. This achieves a left rotation by k positions.
    Store the first k elements in a temporary array.
    Shift the remaining elements to the left by k positions.
    Copy the k stored elements to the end of the original array.

    Time Complexity: O(n), We are performing a constant number of linear operations copying `k` elements and shifting up to `n-k` elements.
    Space Complexity: O(k) ,A temporary array of size `k` is used to store either the first `k` or last `k` elements depending on the direction of rotation.

2) Optimal Solution:
Instead of simulating each rotation one by one, we can get the rotated array in-place by reversing specific parts of the array. This works because rotating is just rearranging sections of the array.
    For Right Rotation by k steps:
    Reverse the entire array
    Reverse the first k elements
    Reverse the remaining n - k elements
For Left Rotation by k steps:
    Reverse the first k elements
    Reverse the remaining n - k elements
    Reverse the entire array

Normalize k by doing k = k % N
If direction is "right":
    Reverse the entire array
    Reverse the first k elements
    Reverse the rest (from k to end)
If direction is "left":
    Reverse the first k elements
    Reverse the rest (from k to end)
    Reverse the entire array

    Time Complexity: O(N), We reverse parts of the array each reverse takes linear time. So total work is 3 × O(N) = O(N).
    Space Complexity: O(1) All modifications are done in-place, using only a few temporary variables.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// My Approach  -- Brute force
vector<int> leftRotate1(vector<int> arr, int n, int k) {
    if(n == 0) {
        return arr;
    }

    k = k % n;

    vector<int> dummy(k);
    for(int i = 0; i < k; i++) {
        dummy[i] = arr[i];
    }

    for(int i = k; i < n; i++) {
        arr[i-k] = arr[i];
    }

    int j = 0;
    for(int i = n-k; i < n; i++) {
        arr[i] = dummy[j++];
    }

    return arr;
}
// My Approach  -- Brute force
vector<int> rightRotate1(vector<int> arr, int n, int k) {
    if(n == 0) {
        return arr;
    }

    k = k % n;

    vector<int> dummy(k);
    for(int i = 0; i < k; i++) {
        dummy[i] = arr[n-k+i];
    }

    for(int i = n-k-1; i >= 0; i--) {
        arr[i+k] = arr[i];
    }

    for(int i = 0; i < k; i++) {
        arr[i] = dummy[i];
    }

    return arr;
}

// Optimal Approach
vector<int> leftRotate2(vector<int> arr, int n, int k) {
    if(n == 0) return arr;
    k = k % n;
    reverse(arr.begin(), arr.begin()+k);
    reverse(arr.begin()+k, arr.end());
    reverse(arr.begin(), arr.end());

    return arr;
}
// Optimal Approach
vector<int> rightRotate2(vector<int> arr, int n, int k) {
    if(n == 0) return arr;
    k = k % n;
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin()+k);
    reverse(arr.begin()+k, arr.end());

    return arr;
}

int main() {
    int n;
    cout << "enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "enter array element: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    string dir;
    cout << "Enter Direction to rotate in lowercase: ";
    cin >> dir;

    if(dir == "left") {
        // vector<int> dummy = leftRotate1(arr, n, k);
        vector<int> dummy = leftRotate2(arr, n, k);
        for(int it: dummy) {
            cout << it << " ";
        }
    }
    else {
        // vector<int> dummy = rightRotate1(arr, n, k);
        vector<int> dummy = rightRotate2(arr, n, k);
        for(int it: dummy) {
            cout << it << " ";
        }
    }
}