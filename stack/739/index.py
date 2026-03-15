class Solution:
    def dailyTemperatures(self, temps: List[int]) -> List[int]:
        ans = [0] * len(temps)
        s = []

        for i in range(len(temps)):
            while s and temps[i] > temps[s[-1]]:
                idx = s[-1]
                s.pop()
                ans[idx] = abs(i - idx)

            s.append(i)


        
        return ans