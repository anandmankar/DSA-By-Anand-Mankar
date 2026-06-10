/*

*** Remove Duplicates in-place from Sorted Array ***

$ Problem Statement: Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each 
unique element appears only once. The relative order of the elements should be kept the same.

If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. 
It does not matter what you leave beyond the first k elements.

$ Examples:
    Input: arr[]=[1,1,2,2,2,3,3]
    Output: [1,2,3,_,_,_,_]
    Explanation: Total number of unique elements are 3, i.e[1,2,3] and Therefore return 3 after assigning [1,2,3] in the 
    beginning of the array.
    
    Input: arr[]=[1,1,1,2,2,3,3,3,3,4,4]
    Output: [1,2,3,4,_,_,_,_,_,_,_]
    Explanation: Total number of unique elements are 4, i.e[1,2,3,4] and Therefore return 4 after assigning [1,2,3,4] in the    
    beginning of the array.

$ Approach: 
1) Brute Force:
    Since we need to store only unique elements, we can use the set data structure. We can insert all the elements of the array 
    in the set irrespective of their frequency as set only allows one occurence of each element.
        Declare a set and insert all the elements of the array into the set.
        The number of unique elements in array is equal to size of the set.
        Traverse the set and fill the first k indices with elements in set.

    Time Complexity: O(N log N), We traverse the entire array and insert elements into set.
    Space Complexity: O(N), additional space used to store elements in set.

2) Optimal Solution:   
    Instead of using a set to store the unique elements, we can implement a two pointer strategy to optimize the space. 
    Since the array is sorted, we know that all the duplicate values will be adjacent to each other.
        Begin at the first position, which will always be part of the final unique list.
        Move through the list one item at a time, comparing the current item with the most recently kept unique item.
        If the current item is the same as the last kept one, skip it because it’s a duplicate.
        If it’s different, place it right after the last kept unique item to keep all unique values grouped at the front.
        Continue until every element in the list has been checked. The first part of the list now contains all the unique values in their original order, and the rest can be ignored.

        Time Complexity: O(N), We traverse the entire original array only once.
        Space Complexity: O(1), constant additional space is used to check unique elements.
*/

#include <iostream>
#include <set>
#include <vector>
using namespace std;

// Brute Force
int removeDuplicates1(int n, vector<int> &arr) {
    set<int> st;

    for(int i = 0; i < n; i++) {
        st.insert(arr[i]);
    }

    int index = 0;

    for(auto it: st) {
        arr[index] = it;
        index++;
    }

    return index;
}

// Optimal Solution
int removeDuplicates2(int n, vector<int> &arr) {
    int i = 0;

    for(int j = 1; j < n; j++) {
        if(arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }

    return i+1;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements: ";
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // int index = removeDuplicates1(n, arr);
    int index = removeDuplicates2(n, arr);

    for(int i = 0; i < index; i++) {
        cout << arr[i] << " ";
    }
}