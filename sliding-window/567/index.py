class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        # first find freq
        freq = defaultdict(int)
        win_freq = defaultdict(int)

        for c in s1:
            freq[c] += 1

        l = 0

        for r in range(len(s2)):
            win_freq[s2[r]] += 1

            while (r - l + 1) > len(s1):
                win_freq[s2[l]] -= 1

                if win_freq[s2[l]] == 0:
                    del win_freq[s2[l]]

                l += 1
            
            if freq == win_freq:
                return True
                
        return False
        