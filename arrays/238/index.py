class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # [1, 2, 3, 4]
        # [1, 2, 6, 24]
        # [24, 24, 12, 4]

        pre = []
        post = [1] * len(nums)

        for i in range(len(nums)):
            pre_num = pre[i - 1] if i > 0 else 1
            pre.append(nums[i] * pre_num)

            index = (len(nums) - 1) - i
            post_num = post[index + 1] if index < len(post) - 1 else 1
            post[index] = nums[index] * post_num
        
        ans = []

        for i in range(len(nums)):
            pre_num = pre[i - 1] if i > 0 else 1
            post_num = post[i + 1] if i < len(post) - 1 else 1

            ans.append(pre_num * post_num)

        return ans

