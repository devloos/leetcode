class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix = nums.copy()
        postfix = nums.copy()

        for i in range(1, n):
            prefix[i] *= prefix[i - 1]

        for i in range(n - 2, -1, -1):
            postfix[i] *= postfix[i + 1]

        answer = []
        postfix.append(1)

        for i in range(0, n):
            if i - 1 < 0:
                answer.append(postfix[i + 1])
            else:
                answer.append(prefix[i - 1] * postfix[i + 1])

        return answer
