class Solution:
    def maxArea(self, h: List[int]) -> int:
        # move the pointer that is smaller
        # area = length * width
        l = 0
        r = len(h) - 1
        m = 0

        while l < r:
            if h[l] < h[r]:
                m = max(m, h[l] * (r - l))
                l += 1
            else:
                m = max(m, h[r] * (r - l))
                r -= 1

        return m
