// 2610. Convert an Array Into a 2D Array With Conditions

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size(); // Check total elements

        unordered_map<int, int> mp; // To store frequency

        vector<vector<int>> result; // 2D array
        for (int i = 0; i < n; i++) {
            int freq = mp[nums[i]];

            // If the frequency matches the number of rows in the result, add one more row
            if (freq == result.size()) {
                result.push_back({});
            }

            // Add the current number to the corresponding row
            result[freq].push_back(nums[i]);
            mp[nums[i]]++;
        }

        return result;
    }
};

// Main function to test the findMatrix function
int main() {
    Solution solution;

    // Example usage
    vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    vector<vector<int>> resultMatrix = solution.findMatrix(nums);

    // Output the result matrix
    for (const auto& row : resultMatrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}


// Approach
/*
Step 1: 
#freq in map:
(num,freq)
1-1
3-1
4-1

#result.size() = 1 (this will same as freq of first element i.e, 1 here)


#result (2d arr):
1 3 4

---------
Step 2:
#freq in map:
1-2
3-1
4-1

#result.size() = 2

#result (2d arr):
1 3 4
1

---------
Step 3:
 #freq in map:
1-2
3-1
4-1
2-1

#result.size() = 2

#result (2d arr):
1 3 4 2
1

---------

Step 4:
 #freq in map:
1-2
3-2
4-1
2-1

#result.size() = 2

#result (2d arr):
1 3 4 2
1 3

how to add 3 in row 1 -> result[1].push_back(3);

--------
Step 5:
 #freq in map:
1-3
3-2
4-1
2-1

#result.size() = 3

#result (2d arr):
1 3 4 2
1 3
1

--------------


How to add extra row in cpp?


result.push_back({});








*/