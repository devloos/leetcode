class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = defaultdict(int)

        for num in nums:
            freq[num] += 1

        sorted_freq = sorted(
            freq.items(), key=lambda item: item[1], reverse=True)

        arr = []
        for i in range(k):
            arr.append(sorted_freq[i][0])

        return arr
