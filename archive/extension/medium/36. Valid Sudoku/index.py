class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        n = 9
        rows = defaultdict(set)
        cols = defaultdict(set)
        sub_grids = defaultdict(set)

        for i in range(n):
            for j in range(n):
                if board[i][j] == '.':
                    continue

                key = f"{int(i / 3)}, {int(j / 3)}"
                if board[i][j] in sub_grids[key]:
                    return False

                if board[i][j] in rows[i]:
                    return False

                if board[i][j] in cols[j]:
                    return False

                cols[j].add(board[i][j])
                rows[i].add(board[i][j])
                sub_grids[key].add(board[i][j])

        return True
