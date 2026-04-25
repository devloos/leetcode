class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        """
        bin search input
        check if mid is peak
        cut solution by checking if left or right is greater and taking the greater side
        repeat
        """

        l = 0
        r = len(nums) - 1

        while l <= r:
            mid = ((r - l) // 2) + l

            if mid > 0 and nums[mid - 1] > nums[mid]:
                r = mid - 1
            elif mid < len(nums) - 1 and nums[mid + 1] > nums[mid]:
                l = mid + 1
            else:
                return mid

        return 0
