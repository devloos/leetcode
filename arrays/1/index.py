class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        s = {}

        for i in range(len(nums)):
            comp = target - nums[i]

            if comp in s:
                return [i, s[comp]]

            s[nums[i]] = i
