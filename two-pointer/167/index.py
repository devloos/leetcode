class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # input sorted
        # binary search
        # iterate ith
        # perfrom bin search on j
        # add ith and j values check >< target:
        # split binary off result
        # nlog(n)

        # [2,7,11,15
        # n = 3
        # i = 0
        # comp = 2
        # l = 0
        # r = 2
        # mid = 1

        n = len(nums)

        for i in range(n):
            comp = target - nums[i]

            l = i + 1
            r = n - 1
            while l <= r:
                mid = (r - l) // 2 + l

                if comp == nums[mid]:
                    return [i + 1, mid + 1]
                elif comp < nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
        
        return []


        