class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        # since it says words and spaces
        # why not split off space
        # take last index (last word)
        # run length on that

        word_arr = s.strip().split(' ')
        return len(word_arr[-1])
        