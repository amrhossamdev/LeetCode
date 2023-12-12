class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int repeated_number;
        int n = nums.size();
        for (int i = 0; i < n + 1; i++) {
            int current_num = abs(nums[i]);

            if (nums[current_num] < 0) {
                repeated_number = current_num;
                break;
            }
            nums[current_num] = -nums[current_num];
        }

        return repeated_number;
    }
};