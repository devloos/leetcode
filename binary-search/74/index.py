class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        i = 0

        t = 0
        b = len(matrix) - 1

        m = 0

        while t <= b:
            m = ((b - t) // 2) + t

            if target > matrix[m][-1]:
                t = m + 1
            elif target < matrix[m][0]:
                b = m - 1
            else:
                break

        if not (t <= b):
            return False

        row = matrix[((b - t) // 2) + t]

        l = 0
        r = len(row) - 1

        while l <= r:
            m = ((r - l) // 2) + l

            if target > row[m]:
                l = m + 1
            elif target < row[m]:
                r = m - 1
            else:
                return True
        

        return False
        