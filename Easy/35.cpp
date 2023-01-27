class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lft = 0, rht = nums.size() - 1;
        int mid;
        
        do
        {
            mid = (lft + rht)/2;
            
            if (target == nums[mid])
                return mid;
            else if (target > nums[mid])
                lft = mid + 1;
            else if (target < nums[mid])
                rht = mid - 1;
        }while (lft <= rht);
        return lft;
    }
};
