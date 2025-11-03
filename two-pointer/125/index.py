class Solution:
    def isPalindrome(self, s: str) -> bool:
        """
        Two pointer method and we are breaking early if a key doesnt match
        """

        l = 0
        r = len(s) - 1

        while l < r:
            if not s[l].isalnum():
                l += 1
            elif not s[r].isalnum():
                r -= 1
            elif s[l].lower() != s[r].lower():
                return False
            else:
                l += 1
                r -= 1

        return True
