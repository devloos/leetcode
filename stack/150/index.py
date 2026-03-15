class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        # 4, 13, 5
        # if op: pop the 2 els and perform op
        # take result and push back onto stack
        # clarifying question: would there be a possibilty of having one number
        # on the stack and then op?

        stack = []

        for token in tokens:
            try:
                numeric_token = int(token)
                stack.append(numeric_token)
                continue
            except:
                # do nothing it was a op
                pass
                
            second = stack.pop()
            first = stack.pop()
            
            if token == '+':
                stack.append(first + second)
            elif token == '-':
                stack.append(first - second)
            elif token == '*':
                stack.append(first * second)
            elif token == '/':
                result = first / second

                if result <= 0:
                    stack.append(ceil(result))
                else:
                    stack.append(floor(result))


        

        return stack[-1]



            
