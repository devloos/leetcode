class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # [1, 2, 3, 4]
        # [1, 2, 6, 24] prefix mul
        # [24, 24, 12, 4] suffix mul
        # [24, 12, 8, 6]
        # why this works essentially take the i - 1 index and you will get everything before
        # then take the i + 1 and you will get everything after

        n = len(nums)
        prefix = nums.copy()

        for i in range(1, n):
            prefix[i] *= prefix[i - 1]

        suffix = nums.copy()

        for i in range(n - 2, -1, -1):
            suffix[i] *= suffix[i + 1]

        res = []
        for i in range(n):
            pre = prefix[i - 1] if i > 0 else 1
            suf = suffix[i + 1] if i < n - 1 else 1

            res.append(pre * suf)

        return res
