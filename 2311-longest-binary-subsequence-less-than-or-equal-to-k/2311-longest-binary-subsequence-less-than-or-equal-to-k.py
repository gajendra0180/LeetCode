class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        while True:
            val=int(s,2)
            if val<=k:
                return len(s)
            index=s.find('1')
            if index==-1:
                return len(s)
            s=s[:index]+s[index+1:]
        