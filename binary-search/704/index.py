class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # l and r, m
        # if nums[m] == target then return m
        # nums[m] < target take left side
        # else we take right side

        l = 0
        r = len(nums) - 1

        while l <= r:
            m = l + ((r - l) // 2)

            print(m)
            
            if nums[m] == target:
                return m
            elif target < nums[m]:
                r = m - 1
            else:
                l = m + 1

        return -1
        