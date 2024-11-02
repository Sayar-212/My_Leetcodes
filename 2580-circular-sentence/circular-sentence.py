class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        words = sentence.split()
        if words[0][0] == words[-1][-1]:
            for x in range(len(words)-1):
                if words[x][-1] != words[x+1][0]:
                    return False
        else:
            return False
        return True