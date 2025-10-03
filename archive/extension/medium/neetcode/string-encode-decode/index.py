class Solution:
    def encode(self, strs: list[str]) -> str:
        new_list = []
        for string in strs:
            new_list.append(f'{len(string)}#{string}')

        return ''.join(new_list)

    def decode(self, s: str) -> list[str]:
        if len(s) == 0:
            return []

        prev_char = ''
        new_list = []
        i = 0

        while i < len(s):
            string = ''

            if s[i] == '#':
                number_of_char = i + int(prev_char)
                i += 1

                while i < number_of_char:
                    string += s[i]

            new_list.append(string)
            prev_char = s[i]
            i += 1

        return new_list
