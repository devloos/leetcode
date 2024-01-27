class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        dic = defaultdict(list)

        for string in strs:
            t_string = tuple(sorted(string))
            dic[t_string].append(string)

        return dic.values()
