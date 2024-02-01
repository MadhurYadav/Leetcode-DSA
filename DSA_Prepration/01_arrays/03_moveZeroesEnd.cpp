// 283. Move Zeroes

// M1 - BF
/*

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // temporary array
        vector<int> temp;

        // copy non-zero elements from orginal -> temp array
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0) temp.push_back(nums[i]);
        }

        // number of non zero elements
        int nonZeroSize = temp.size();


        // copy elements from temp
        // fill first non zero fields of orginal array

        for(int i=0; i<nonZeroSize; i++){
            nums[i] = temp[i];
        }

        // fill rest of the cells with 0
        for(int i=nonZeroSize; i<nums.size(); i++){
            nums[i] = 0;
        }
    }
};

Time Complexity: O(N) + O(X) + O(N-X) ~ O(2*N), where N = total no. of elements,
X = no. of non-zero elements, and N-X = total no. of zeros.
Reason: O(N) for copying non-zero elements from the original to the temporary array. O(X) for again copying it back from the temporary to the original array. O(N-X) for filling zeros in the original array. So, the total time complexity will be O(2*N).

Space Complexity: O(N), as we are using a temporary array to solve this problem and the maximum size of the array can be N in the worst case.
Reason: The temporary array stores the non-zero elements. In the worst case, all the given array elements will be non-zero.

*/

// M2 (Using 2 pointers)

class Solution {
public:
    void zoveZeroes(vector<int>& nums) {
        int j = -1;
        // place the pointer j:
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
        }


        // no non-zero elements:
        
        // Move the pointers i and j
        // and swap accordingly:

        // j->0 , and if i is non-zero then swap
        for(int i=j+1; i<nums.size(); i++){
            if(nums[i] != 0 && j != -1){
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)

 