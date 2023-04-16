from typing import List
import math


class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        word_len = 0
        start = 0
        result = []
        for i in range(len(words)):
            windows = []
            if (len(words[i]) + word_len + i - start) > maxWidth:
                gap = 0
                rem = 0
                if i - start > 1:
                    gap = (maxWidth - word_len) // (i - start - 1)
                    rem = (maxWidth - word_len) % (i - start - 1)
                windows.append((start, i-1, gap, rem))
                start = i
                word_len = 0
            if i == (len(words) - 1):
                gap = 1
                rem = 0
                word_len += len(words[i])
                windows.append((start, i, gap, rem))
            for w in windows:
                wl, wr, gap, rem = w
                space_count = maxWidth

                r = ""
                for j in range(wl, wr + 1):
                    if j > wl:
                        gapp = min(space_count - len(words[j]), gap)
                        sp = " " * gapp
                        r += sp
                        space_count -= gapp
                        if rem > 0:
                            r += " "
                            rem -= 1
                            space_count -= 1
                    r += words[j]
                    space_count -= len(words[j])
                r += (" " * space_count)
                result.append(r)
            word_len += len(words[i])
        return result


if __name__ == "__main__":
    sol = Solution()
    r = sol.fullJustify(["This", "is", "an", "example", "of", "text",
                         "justification."], 16)
    for rr in r:
        print("|"+rr+"|")

    r = sol.fullJustify(["Science", "is", "what", "we", "understand", "well", "enough", "to",
                        "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"], 20)
    for rr in r:
        print("|"+rr+"|")
