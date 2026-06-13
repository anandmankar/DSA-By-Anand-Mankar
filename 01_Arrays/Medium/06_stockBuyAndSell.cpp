/*

*** Stock Buy And Sell ***

$ Problem Statement: You are given an array of prices where prices[i] is the price of a given
stock on an ith day. You want to maximize your profit by choosing a single day to buy one 
stock and choosing a different day in the future to sell that stock. Return the maximum 
profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

$ Examples
    Input: prices = [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    Note: That buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transactions are done and the max profit = 0.

$ Approach:
1) Brute Force:
We try every possible pair of days (buy day and sell day after buy) and calculate the profit. 
The maximum profit among all these pairs is our answer. If no profit is possible, return 0.
    Loop through all days to consider each as a possible buy day.
    For each buy day, loop through all future days to consider them as sell days.
    Calculate the profit for each (buy, sell) pair.
    Track the maximum profit seen.

    Time Complexity: O(n²) Because for each element, we are checking every future element nested loops.
    Space Complexity: O(1) No extra space used, only variables for storing max profit.

2) Optimal Solution:
The idea is to track the minimum price so far while traversing the array and calculate the 
profit if we sold today. This way, we can constantly update the maximum profit without using 
nested loops. We’re basically simulating:
    What’s the lowest price we’ve seen so far?
    What’s the profit if we sold today?
    Is it better than our best so far?

    Initialize a variable to store the minimum price so far, set it to a very large value initially.
    Initialize a variable to store the maximum profit seen so far, set it to 0 initially.
    Loop through each price in the array.
    Update the minimum price if the current price is smaller.
    Calculate the profit if the stock were bought at the minimum price and sold at the current price.
    Update the maximum profit if this new profit is higher.
    Return the maximum profit after the loop ends.

    Time Complexity: O(n),This is because we are iterating through the array of prices exactly once. There are no nested loops or recursive calls.
    Space Complexity: O(1),Only two variables are used to store the minimum price and maximum profit, regardless of the input size.

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Brute Force
int buySell1(int n, vector<int> arr) {
    int maxProfit = 0;
    for(int i = 0; i < n-1; i++) {
        int profit = 0;
        for(int j = i+1; j < n; j++) {
            profit = arr[j] - arr[i];
            maxProfit = max(maxProfit, profit);
        }
    }

    return maxProfit;
}

// Optimal Solution
int buySell2(int n, vector<int> arr) {
    int minPrice = INT_MAX;
    int maxProfit = 0;
    int profit = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] < minPrice) {
            minPrice = arr[i];
        }

        profit = arr[i] - minPrice;

        if(profit > maxProfit) {
            maxProfit = profit;
        }
    }

    return maxProfit;
}

// Ankit Mankar's Solution
int buySell3(int n, vector<int> arr) {
    int profit = 0;
    int maxSell = 0;
    
    for (int i = n-1; i >= 0; i--) {
        int currProfit = maxSell - arr[i];
        maxSell = max(maxSell, arr[i]);
        profit = max(profit, currProfit);
    }

    return profit;
}

int main() {
    int n;
    cout << "enter array size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // int profit = buySell1(n, arr);
    // int profit = buySell2(n, arr);
    int profit = buySell3(n, arr);
    cout << "The profit is: " << profit;
}