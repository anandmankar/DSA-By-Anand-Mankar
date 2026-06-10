/*

*** Union of Two Sorted Arrays ***

$ Problem Statement: Given two sorted arrays, arr1, and arr2 of size n and m. Find the union of two sorted arrays.
The union of two arrays can be defined as the common and distinct elements in the two arrays.
NOTE: Elements in the union should be in ascending order.

$ Example: 
    Input:n = 5,m = 5 arr1[] = {1,2,3,4,5}  arr2[] = {2,3,4,4,5}
    Output: {1,2,3,4,5}
    Explanation: Common Elements in arr1 and arr2  are:  2,3,4,5
    Distnict Elements in arr1 are : 1
    Distnict Elemennts in arr2 are : No distinct elements.
    Union of arr1 and arr2 is {1,2,3,4,5}

    Input:n = 10,m = 7,arr1[] = {1,2,3,4,5,6,7,8,9,10}arr2[] = {2,3,4,4,5,11,12}
    Output: {1,2,3,4,5,6,7,8,9,10,11,12}
    Explanation: Common Elements in arr1 and arr2  are:  2,3,4,5
    Distnict Elements in arr1 are : 1,6,7,8,9,10
    Distnict Elemennts in arr2 are : 11,12
    Union of arr1 and arr2 is {1,2,3,4,5,6,7,8,9,10,11,12}
    
$ Approach:
1) Using Map :- 
Our aim is to find the common elements in arr1 and arr2, and the distinct elements of arr1,arr2. Use a Single map to find the frequencies of elements in arr1 and arr2.
As we are using only a single map the common element in arr1 and arr2 are treated as a single element for finding frequency, so there would be no duplicates.

Why not unordered_map?
In unordered_map the keys are stored in random order, while in the map the keys are stored in sorted order (ascending order by default). As we require elements of the union to be in ascending order, using a map is preferable.

We can also use unordered_map, but after finding the union of arr1 and arr2, we need to sort the union vector to get the elements of the union in sorted order.
    Initialize an empty map named freq to store element frequencies
    Initialize an empty vector named Union to store unique elements
    Loop through the first array arr1:
        For each element, increment its count in freq
    Loop through the second array arr2:
        For each element, increment its count in freq
    Iterate over each key-value pair in freq (keys will be sorted because map is ordered):
        Push the key (element) into the Union vector

    Time Compleixty : O( (m+n)log(m+n) ) . Inserting a key in map takes logN times, where N is no of elements in map. At max map can store m+n elements {when there are no common elements and elements in arr,arr2 are distntict}. So Inserting m+n th element takes log(m+n) time. Upon approximation across insertion of all elements in worst it would take O((m+n)log(m+n) time.
    Using HashMap also takes the same time, On average insertion in unordered_map takes O(1) time but sorting the union vector takes O((m+n)log(m+n))  time. Because at max union vector can have m+n elements.
    Space Complexity : O(m+n) {If Space of Union ArrayList is considered} ,O(1) {If Space of union ArrayList is not considered}

2) Using Set: 
Using a set we can find the distinct elements because the set does not hold any duplicates. Hence we can find the union of arr1 and arr2.
    Initialize an empty set.
    Insert all elements from the first array into set.
    Insert all elements from the second array into set.
    Convert the set into a list/array to get the result.
    If required in sorted order, sort the list before returning.
    Return/print the union result.

Why not unordered_set?
In unordered_set the elements are stored in random order, while in a set the keys are stored in sorted order (ascending order by default). As we require elements of the union to be in ascending order, using a set is preferable.
We can also use unordered_set, but after finding the union of arr1 and arr2, we need to sort the union vector to get the elements of the union in sorted order.

Time Compleixty : O( (m+n)log(m+n) ) . Inserting an element in a set takes logN time, where N is no of elements in the set. At max set can store m+n elements {when there are no common elements and elements in arr,arr2 are distntict}. So Inserting m+n th element takes log(m+n) time. Upon approximation across inserting all elements in worst, it would take O((m+n)log(m+n) time.
Using HashSet also takes the same time, On average insertion in unordered_set takes O(1) time but sorting the union vector takes O((m+n)log(m+n))  time. Because at max union vector can have m+n elements.
Space Complexity : O(m+n) {If Space of Union ArrayList is considered} ,O(1) {If Space of union ArrayList is not considered}

3) Optimal Solution: Two Pointer Approach
Since both arrays are sorted, we can efficiently find their union by iterating through them simultaneously. Using two pointers, one for each array, we compare elements and add the smaller one to the result (skipping duplicates). If elements are equal, add once and move both pointers. This way, we merge the arrays like in merge sort, avoiding extra space for maps or sets and achieving linear time complexity.
Initialize two pointers at the start of both arrays.
    While neither pointer has reached the end:
    If element pointed by first pointer is smaller, add it to result if not duplicate, move first pointer.
    If element pointed by second pointer is smaller, add it to result if not duplicate, move second pointer.
    If both elements are equal, add one to result if not duplicate, move both pointers.
    After exiting loop, append remaining elements from either array, skipping duplicates.
    Return the result array containing the union.

    Time Complexity: O(m+n), Because at max i runs for n times and j runs for m times. When there are no common elements in arr1 and arr2 and all elements in arr1, arr2 are distinct. 
    Space Complexity : O(m+n) {If Space of Union ArrayList is considered} O(1) {If Space of union ArrayList is not considered}
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

// using Map
vector<int> unionOfTwo1(vector<int> arr1, vector<int> arr2, int n, int m) {
    map<int, int> mpp;

    for(int it : arr1) {
        mpp[it]++;
    }

    for(int it: arr2) {
        mpp[it]++;
    }

    vector<int> res;

    for(auto it: mpp) {
        res.push_back(it.first);
    }

    return res;
}

// using Set
vector<int> unionOfTwo2(vector<int> arr1, vector<int> arr2, int n, int m) {
    set<int> st;

    for(int it: arr1) {
        st.insert(it);
    }

    for(int it: arr2) {
        st.insert(it);
    }

    vector<int> res(st.begin(), st.end());
    return res;
}
    
// using Two Pointer
vector<int> unionOfTwo3(vector<int> a, vector<int> b, int n, int m) {
    int i = 0, j = 0;

    vector<int> res;

    while(i < n && j < m) {
        if(a[i] < b[j]) {
            if(res.empty() || res.back() != a[i]) {
                res.push_back(a[i]);
            }
            i++;
        }
        else if(b[j] < a[i]) {
            if(res.empty() || res.back() != b[j]) {
                res.push_back(b[j]);
            }
            j++;
        }
        else {
            if(res.empty() || res.back() != a[i]) {
                res.push_back(a[i]);
            }
            i++;
            j++;
        }
    }

    while(i < n) {
        if(res.empty() || res.back() != a[i]) {
            res.push_back(a[i]);
        }
        i++;
    }

    while(j < m) {
        if(res.empty() || res.back() != b[j]) {
            res.push_back(b[j]);
        }
        j++;
    }

    return res;
}

int main() {
    int n;
    cout << "Enter array 1 size: ";
    cin >> n;

    int m;
    cout << "Enter array 2 size: ";
    cin >> m;

    vector<int> arr1(n);
    cout << "Enter arr 1 elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    vector<int> arr2(m);
    cout << "Enter arr 2 elements: ";
    for(int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    cout << "Union of Two Sorted arrays: ";
    // vector<int> res = unionOfTwo1(arr1, arr2, n, m);
    // vector<int> res = unionOfTwo2(arr1, arr2, n, m);
    vector<int> res = unionOfTwo3(arr1, arr2, n, m);
    for(int it: res) {
        cout << it << " ";
    }
}