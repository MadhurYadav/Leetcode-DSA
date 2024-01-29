// 2870. Minimum Number of Operations to Make Array Empty

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath> // for ceil function

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        // Store frequency in a map
        unordered_map<int, int> mp;
        for (int& num : nums) {
            mp[num]++;
        }

        int result = 0;

        // Iterate over the map
        for (auto& it : mp) {
            int freq = it.second;

            // If frequency is 1, it's not possible to perform the operation
            if (freq == 1) {
                return -1;
            }

            // Calculate the number of operations needed and add to the result
            result += ceil((double)freq / 3);
        }

        return result;
    }
};

// Main function to test the minOperations function
int main() {
    Solution solution;

    // Example usage
    vector<int> nums = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    int result = solution.minOperations(nums);

    // Output the result
    cout << "Minimum operations needed: " << result << endl;

    return 0;
}



// if freq == 1 then return -1


// first check if we can delete a freq of 3

/*
#16
16/2 = 8 operations 

16-2=14, 16-3=13, 16-4=12 
1+1+12/3 = 1+1+4 = 6 operations (min)

#11
11-2 = 9 , 9/3=3
1+3 = 4 ops

-------

(freq, min operations)

1 -> -1
2 -> 1
3 -> 1

4 -> 2
5 -> 2
6 -> 2

7 -> 3
8 -> 3
9 -> 3

10 -> 4
11 -> 4


So we can see pattern,
ceil(num3)

eg,
ceil(23) = 1
ceil(83) = 3

ceil[(double)freq / 3]

*/