class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # [3, 5, 1, 3, 4]
        # [3, 5, -1, 3, 4] eventually we will get to the other 3 and find same index

        for num in nums:
            i = abs(num) - 1

            if nums[i] < 0:
                return abs(num)

            nums[i] *= -1

        return -1
