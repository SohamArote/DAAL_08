#include <iostream>

using namespace std;

int coinChange(int coins[], int n, int sum) {
    // Create a dp array to store the number of ways to make each sum
    int dp[sum + 1];
    dp[0] = 1;
    
    // Initialize all other values of dp array as 0
    for (int i = 1; i <= sum; i++) {
        dp[i] = 0;
    }

    // Iterate through each coin
    for (int i = 0; i < n; i++) {
        // Update the dp array for each sum
        for (int j = coins[i]; j <= sum; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[sum];
}

int main() {
    int sum;
    cout << "Enter the sum: ";
    cin >> sum;

    int n;
    cout << "Enter the number of coins: ";
    cin >> n;

    int coins[n];
    cout << "Enter the coins: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // Call the coinChange function
    int num_ways = coinChange(coins, n, sum);

    // Print the result
    cout << "Number of ways to make " << sum << " is " << num_ways << endl;

    return 0;
}