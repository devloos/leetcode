class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        s = defaultdict(int)

        for num in nums:
            s[num] += 1

        res = []
        for key, v in s.items():
            res.append([v, key])
        res.sort(reverse=True)

        result = []
        for i in range(k):
            result.append(res[i][1])

        return result
