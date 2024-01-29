// 455. Assign Cookies

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the maximum number of content children
int findContentChildren(vector<int>& g, vector<int>& s) {
    // Sort the cookie array in descending order
    sort(s.rbegin(), s.rend());

    // Sort the child greed array in descending order
    sort(g.rbegin(), g.rend());

    int curr = 0;  // Index to iterate through the cookie array
    int total = 0; // Count of content children who can be satisfied
    int n = g.size(); // Number of children
    int m = s.size(); // Number of cookies

    // Iterate through each child's greed
    for (int i = 0; i < n; i++) {
        // Check if there are more cookies available and if the current child's greed can be satisfied
        if (curr < m && g[i] <= s[curr]) {
            // Increment the count of satisfied children and move to the next cookie
            total++;
            curr++;
        }
    }

    // Return the total count of content children who can be satisfied
    return total;
}

// Main function to test the findContentChildren function
int main() {
    // Example usage
    vector<int> childGreed = {1, 2, 3};
    vector<int> cookieSize = {1, 1};
    
    int result = findContentChildren(childGreed, cookieSize);
    
    // Output the result
    cout << "Maximum content children that can be satisfied: " << result << endl;

    return 0;
}
