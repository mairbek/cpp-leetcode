class Solution:
    def tokenize(self, expr: str) -> list[str]:
        result = []
        i = 0
        while i < len(expr):
            if expr[i] == "(" or expr[i] == ")":
                result.append(expr[i])
                i += 1
                continue
            if expr[i] == " ":
                i += 1
                continue
            agg = ""
            while i < len(expr) and expr[i] not in [" ", "(", ")"]:
                agg += expr[i]
                i += 1
            result.append(agg)
        return result

    def evaluate(self, expression: str) -> int:
        def check_int(s):
            if s[0] in ('-', '+'):
                return s[1:].isdigit()
            return s.isdigit()

        def append_val(frame, val):
            vals, ops, table = frame
            if isinstance(val, str) and check_int(val):
                val = int(val)
            if len(ops) > 0 and ops[0] == "let":
                if len(vals) > 0:
                    k = vals.pop()
                    if val in table:
                        table[k] = table[val]
                    else:
                        table[k] = val
                    return
            if isinstance(val, str) and check_int(val):
                vals.append(int(val))
            else:
                # it's a key or last element
                vals.append(val)

        tokens = self.tokenize(expression)
        frames = []
        frames.append(([], [], {}))

        for i in range(len(tokens)):
            if tokens[i] == '(':
                table = {}
                if len(frames) > 0:
                    table = frames[-1][2]
                copy_table = table.copy()
                frames.append(([], [], copy_table))
                continue
            vals, ops, table = frames[-1]
            if tokens[i] in ["let", "add", "mult"]:
                ops.append(tokens[i])
                continue
            if tokens[i] == ')':
                op = None if len(ops) == 0 else ops[0]
                if op == "let":
                    val = vals[-1]
                    if val in table:
                        val = table[val]
                    frames.pop()
                    append_val(frames[-1], val)
                    continue
                if op == "add":
                    result = 0
                    for j in range(len(vals)):
                        v = vals[j]
                        if v in table:
                            v = table[vals[j]]
                        result += v
                    frames.pop()
                    append_val(frames[-1], result)
                    continue
                if op == "mult":
                    result = 1
                    for j in range(len(vals)):
                        v = vals[j]
                        if v in table:
                            v = table[vals[j]]
                        result *= v
                    frames.pop()
                    append_val(frames[-1], result)
                    continue
                val = vals[-1]
                if val in table:
                    val = table[val]
                frames.pop()
                append_val(frames[-1], val)
                continue
            append_val(frames[-1], tokens[i])
                

        return frames[0][0][0]

if __name__ == '__main__':
    sol = Solution()
    #print(sol.evaluate("(((2)))"))
    #print(sol.evaluate("(add 1 2)")) # 3
    #print(sol.evaluate("(let x 2 (mult x (let x 3 y 4 (add x y))))")) # 14
    #print(sol.evaluate("(let x 3 x 2 x)")) # 2
    print(sol.evaluate("(let x 1 y 2 x (add x y) (add x y))")) # 5