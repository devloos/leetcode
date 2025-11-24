class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        l = 0

        for num in s:
            # if its not in the set, it is a starting value
            if (num - 1) not in s:
                length = 1

                while (num + length) in s:
                    length += 1

                l = max(l, length)

        return l
