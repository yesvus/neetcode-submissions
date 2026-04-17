class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            // If the current subarray is already sorted
            if (nums[left] < nums[right]) {
                return nums[left];
            }

            int mid = left + (right - left) / 2;

            // If mid is in the left sorted portion, search right
            if (nums[mid] >= nums[left]) {
                left = mid + 1;
            } 
            // If mid is in the right sorted portion, search left (including mid)
            else {
                right = mid;
            }
        }

        return nums[left];
    }
};