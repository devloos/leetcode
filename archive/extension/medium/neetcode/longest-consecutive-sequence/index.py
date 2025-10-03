class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        if len(nums) == 0:
            return 0

        nums.sort()

        value = 1
        iter_max = 1
        prev_num = nums[0]

        for num in nums:
            if num == prev_num + 1:
                iter_max += 1
            elif num == prev_num:
                pass
            else:
                iter_max = 1

            if iter_max > value:
                value = iter_max

            prev_num = num

        return value
