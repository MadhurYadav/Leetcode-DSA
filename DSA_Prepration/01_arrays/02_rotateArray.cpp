// *** Brute Force
// Store last elem of arr in var
// iterate from second last and shift all elem to right
// now add var (last elem) in starting

/*

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        for(int i=0; i<k; i++){
            int var = nums[size-1];
            for(int j=size-2; j>=0; j--){
                nums[j+1] = nums[j];
            }
            nums[0] = var;
        }
    }
};

TC - O(KN)
SC - O(1)

*/

// *** Method 2 - Optimized
// Using temp Arr
// temp[(i + k) % size] = nums[i];

/*

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        std::vector<int> temp(size);  // Initialize temp with the same size as nums

        for (int i = 0; i < size; i++) {
            temp[(i + k) % size] = nums[i];
        }

        nums = temp;  // Update nums with the rotated values
    }
};

TC - O(N)
SC - O(N)

*/

// *** Method 3 - Using Array Reversal

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // divide arr in 2 parts
        // n-k and k
        // reverse n-k and k part seprately
        // reverse whole arr 
        int size = nums.size();
        k = k % size;  // Handle cases where k is greater than the size of the array

        // Reverse the entire array
        reverse(nums.begin(), nums.end());

        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Reverse the remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};
