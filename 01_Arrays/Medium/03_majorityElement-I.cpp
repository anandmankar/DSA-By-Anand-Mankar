/*

*** Find the Majority Element that occurs more than N/2 times ***

$ Problem Statement: Given an integer array nums of size n, return the majority element of the array.
The majority element of an array is an element that appears more than n/2 times in the array. The array is guaranteed to have a majority element.

$ Examples:
    Input: nums = [7, 0, 0, 1, 7, 7, 2, 7, 7]  
    Output: 7  
    Explanation: The number 7 appears 5 times in the 9-sized array, making it the most frequent element.

    Input: nums = [1, 1, 1, 2, 1, 2]  
    Output: 1  
    Explanation: The number 1 appears 4 times in the 6-sized array, making it the most frequent element.

$ Approach:
1) Brute Force:
Iterate through the array to select each element one by one.
For each selected element, run another loop to count its occurrences in the given array.
If the occurrence of any element is greater than the floor of (N/2), return that element immediately as the majority element.

Time Complexity: O(N^2), where N is the size of the input array. This is because we are using a nested loop to count the occurrences of each element.
Space Complexity: O(1), as we are using a constant amount of space for the counters and indices.

2) Better Approach:
Use a hashmap to store elements as (key, value) pairs, where the key is the element of the array and the value is the number of times it occurs.
Traverse the array and update the value of the corresponding key in the hashmap.
Simultaneously check if the value (the count) of any key is greater than the floor of (N/2).
If the value is greater than the floor of (N/2), return the key immediately as the majority element.
If no majority element is found, continue iterating through the array

Time Complexity: O(N), where N is the size of the input array. This is because we are iterating through the array once to count occurrences and then iterating through the hashmap to find the majority element.
Space Complexity: O(N), as we are using a hashmap to store the counts of each element, which can take up to N space in the worst case

3) Optimal Solution:
Initialize two variables: count to track the count of elements, and element to keep track of the element being counted.
Traverse through the given array. If count is 0, store the current value of the array as element.
If the current element in the array is the same as element, increment the count by 1.
If the current element is different from element, decrement the count by 1.
At the end of the traversal, the integer stored in element will be the expected result (the majority element).

Time Complexity: O(N), where N is the size of the input array. This is because we are iterating through the array once to find the potential majority element and then again to verify it.
Space Complexity: O(1), as we are using only a constant amount of extra space.

*/

#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

// Brute Force
int majorityElement1(int n, vector<int> arr) {
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for(int j = i; j < n; j++) {
            if(arr[i] == arr[j]) {
                cnt++;
            }
        }
        if(cnt > (n/2)) {
            return arr[i];
        }
    }

    return -1; // Never executed as guaranteed to have majority element
}

// Better Approach
int majorityElement2(int n, vector<int> arr) {
    unordered_map<int, int> mp;
    for(int it: arr) {
        mp[it]++;
    }

    for(auto it: mp) {
        if(it.second > (n/2)) {
            return it.first;
        }
    }

    return -1; // Never executed
}

// Optimal Solution
int majorityElement3(int n, vector<int> arr) {
    int cnt = 0;
    int ele;

    for(int i = 1; i < n; i++) {
        if(cnt == 0) {
            ele = arr[i];
            cnt = 1;
        }  
        else if(ele == arr[i]) {
            cnt++;
        }    
        else {
            cnt--;
        }
    }

    int cntFinal = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == ele) {
            cntFinal++;
        }
    }

    if(cntFinal > (n/2)) {
        return ele;
    }

    return -1; //Never Executed
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // int majority = majorityElement1(n, arr);
    // int majority = majorityElement2(n, arr);
    int majority = majorityElement3(n, arr);
    cout << "The majority element in array is: " << majority;
}