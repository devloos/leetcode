class Solution:

    def encode(self, strs: List[str]) -> str:
        # take the number of elements and add that to the delimeter
        s = ''
        for string in strs:
            n = len(string)
            s += f"{n}#{string}"

        return s

    def decode(self, s: str) -> List[str]:
        res = []
        i = 0

        while i < len(s):
            j = i

            while s[j] != '#':
                j += 1

            n = int(s[i:j])
            i = j + 1  # skip #, we would be at the begining of the word
            j = i + n  # no need to sub 1 because slice end is not inclusive
            res.append(s[i:j])
            i = j

        return res
