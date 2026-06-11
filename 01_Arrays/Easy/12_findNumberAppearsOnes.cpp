/*

*** Find the number that appears once, and the other numbers twice ***

$ Problem Statement: Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

$ Examples:
    Input Format: arr[] = {2,2,1}
    Result: 1
    Explanation: In this array, only the element 1 appear once and so it is the answer.

    Input Format: arr[] = {4,1,2,1,2}
    Result: 4
    Explanation: In this array, only element 4 appear once and the other elements appear twice. So, 4 is the answer.

$ Approach:
1) Brute Force:- 
Intuition: 
    For every element present in the array, we will do a linear search and count the occurrence. If for any element, the occurrence is 1, we will return it.
Approach: 
    First, we will run a loop to select the elements of the array one by one.
    For every element of the array, we will perform a linear search using another loop and count its occurrence.
    If for any element the occurrence is 1, we will return it.        

    Time Complexity: O(N*N), since nested for loops are used
    Space Complexity: O(1). No extra space used

2) Better Approach:
In the previous approach, we were finding the occurrence of an element using linear search. 
We can optimize this using hashing technique. We can simply hash the elements along with 
their occurrences in the form of (key, value) pair. Thus, we can reduce the cost of finding 
the occurrence and hence the time complexity. Now, hashing can be done in two different ways 
and they are the following:
    Array hashing(not applicable if the array contains negatives or very large numbers)
    Hashing using the map data structure
Approach:
First, we will find the maximum element(say maxElement) to know the size of the hash array.
Then we will declare a hash array of size maxElement+1.
Now, using another loop we will store the elements of the array along with their frequency in the hash array.
After that, using another loop we will iterate over the hash array, and try to find the element for which the frequency is 1, and finally, we will return that particular element.
While searching for the answer finally, we can either use a loop from 0 to n(i.e. Size of the array) or use a loop from 0 to maxElement. So, the time complexity will change accordingly

    Time Complexity: O(N)+O(N)+O(N), where N = size of the array. One O(N) is for finding the maximum, the second one is to hash the elements and the third one is to search the single element in the array.
    Space Complexity: O(maxElement+1) where maxElement = the maximum element of the array.

3) Optimal Solution:
Intuition:
    Two important properties of XOR are the following:
    XOR of two same numbers is always 0 i.e. a ^ a = 0. ←Property 1.
    XOR of a number with 0 will result in the number itself i.e. 0 ^ a = a. ←Property 2
Approach:
We will just perform the XOR of all elements of the array using a loop and the final XOR will be the answer.

    Time Complexity: O(N). Where N is the size of the array
    Space Complexity: O(1). No extra space used
*/

#include <iostream>
#include <vector>
using namespace std;

// Brute Force
int findNumber1(int n, vector<int> arr) {
    for(int i = 0; i < n; i++) {
        int num = arr[i];
        int cnt = 0;

        for(int j = 0; j < n; j++) {
            if(arr[j] == num) {
                cnt++;
            }
        }

        if(cnt == 1) {
            return num;
        }
    }

    return -1;
}

// Better Approach --> Works with NonNegative
int findNumber2(int n, vector<int> arr) {
    int maxi = arr[0];
    for(int i = 0; i < n; i++) {
        maxi = max(arr[i], maxi);
    }

    vector<int> hash(maxi+1, 0);

    for(int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    for(int i = 0; i < n; i++) {
        if(hash[arr[i]] == 1) {
            return arr[i];
        }
    }

    return -1; 
}

// Optimal Solution --> XOR
int findNumber3(int n, vector<int> arr) {
    int num = arr[0];

    for(int i = 1; i < n; i++) {
        num ^= arr[i];
    }

    return num;
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

    // int num = findNumber1(n, arr);
    // int num = findNumber2(n, arr);
    int num = findNumber3(n, arr);
    cout << "The number that appears Ones is: " << num;
}