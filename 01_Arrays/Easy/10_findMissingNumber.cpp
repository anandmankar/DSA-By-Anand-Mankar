/*

*** Find Missing Number ***

$ Problem Statement: Given an array arr[] of size n-1 with distinct integers in the range of 
[1, n]. This array represents a permutation of the integers from 1 to n with one element 
missing. Find the missing element in the array.

$ Examples:
    Input: arr[] = [8, 2, 4, 5, 3, 7, 1]
    Output: 6
    Explanation: All the numbers from 1 to 8 are present except 6.

    Input: arr[] = [1, 2, 3, 5]
    Output: 4
    Explanation: Here the size of the array is 4, so the range will be [1, 5]. The missing number between 1 to 5 is 4

$ Approach:
1) Brute Force: 
This approach iterates through each number from 1 to n (where n is the size of the array + 1) 
and checks if the number is present in the array. For each number, it uses a nested loop to 
search the array. If a number is not found, it is returned as the missing number.

 O(n^2) Time and O(1) Space

2) Better Approach:
This approach uses a hash array (or frequency array) to track the presence of each number 
from 1 to n in the input array. It first initializes a hash array to store the frequency of 
each element. Then, it iterates through the hash array to find the number that is missing 
(i.e., the one with a frequency of 0).

O(n) Time and O(n) Space

3) Optimal Solution: (n*(n+1))/2
The sum of the first n natural numbers is given by the formula (n * (n + 1)) / 2. 
The idea is to compute this sum and subtract the sum of all elements in the array from 
it to get the missing number.

O(n) Time and O(1) Space

4) Optimal Solution: XOR
XOR of a number with itself is 0 i.e. x ^ x = 0 and the given array arr[] has numbers in 
range [1, n]. This means that the result of XOR of first n natural numbers with the XOR 
of all the array elements will be the missing number. To do so, calculate XOR of first n 
natural numbers and XOR of all the array arr[] elements, and then our result will be the 
XOR of both the resultant values.

O(n) Time and O(1) Space

*/

#include <iostream>
#include <vector>
using namespace std;

int findMissing1(vector<int> arr, int n) {
    for(int i = 1; i <= n; i++) {
        bool found = false;
        for(int j = 0; j < n-1; j++) {
            if(arr[j] == i) {
                found = true;
                break;
            }
        }

        if(!found) {
            return i;
        }
    }

    return -1;
}

int findMissing2(vector<int> arr, int n) {
    vector<int> hash(n+1, 0);
    for(int i = 0; i < n-1; i++) {
        hash[arr[i]]++;
    }

    for(int i = 1; i <= n; i++) {
        if(hash[i] == 0) {
            return i;                                           
        }
    }

    return -1;
}

int findMissing3(vector<int> arr, int n) {
    int totalSum= (n*(n+1))/2;
    int sum = 0;
    for(int i = 0; i < n-1; i++) {
        sum += arr[i];
    }

    return totalSum - sum;
}

int findMissing4(vector<int> arr, int n) {
    int xor1 = 0, xor2 = 0;

    for(int i = 0; i < n-1; i++) {
        xor2 ^= arr[i];
    }

    for(int i = 1; i <= n; i++) {
        xor1 ^= i;
    }

    return xor1 ^ xor2;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // int missing = findMissing1(arr, n+1);
    // int missing = findMissing2(arr, n+1);
    // int missing = findMissing3(arr, n+1);
    int missing = findMissing3(arr, n+1);
    cout << "The missing number in array is: " << missing; 
}
