class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       if (nums.empty()) {
            return 0;
        }

        int k = 1; // Initialize the count of unique elements
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k++] = nums[i]; // Update the array in-place
                // or nums[k] = nums[i]; k++;
            }
        }

        return k; // Return the count of unique elements
    }
};