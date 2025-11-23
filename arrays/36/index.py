class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        cols = defaultdict(set)
        sqrs = defaultdict(set)

        for r in range(9):
            seen = set()

            for c in range(9):
                num = board[r][c]

                if num == '.':
                    continue

                if num in seen or num in cols[c]:
                    return False

                sqr = (r // 3, c // 3)

                if num in sqrs[sqr]:
                    return False

                seen.add(num)
                cols[c].add(num)
                sqrs[sqr].add(num)

        return True
