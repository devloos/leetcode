class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = defaultdict(int)

        for num in nums:
            freq[num] += 1

        bucket = [[] for i in range(len(nums) + 1)]

        for key, val in freq.items():
            bucket[val].append(key)

        res = []
        i = len(bucket) - 1

        while len(res) < k and i >= 0:
            for num in bucket[i]:
                res.append(num)

            i -= 1

        return res
