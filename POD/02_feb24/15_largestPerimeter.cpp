// 2971. Find Polygon With the Largest Perimeter

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int size = nums.size();

        // Step 1: Sort the array in ascending order
        sort(begin(nums), end(nums));

        long long perimeter = 0;
        long long remainingSum = 0; // cumSum (cumulative sum)

        // Step 2: Iterate through the sorted array
        for(int i=0; i<size; i++){
            // Step 3: Check if the current element can contribute to a valid triangle
            if(remainingSum > nums[i]){
                // If the remaining sum is greater than the current (largest) element,
                // it can form a valid triangle. Update the perimeter accordingly.
                perimeter = remainingSum + nums[i];
            }

            remainingSum += nums[i]; // Update the cumulative sum
        }

       // Step 4: Return -1 if perimeter is zero, else return the calculated perimeter
        return perimeter == 0 ? -1 : perimeter;
    }
};