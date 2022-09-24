class Solution:
    def concatenatedBinary(self, n: int) -> int:
        s=""
        for gp in range(1,n+1):
            s+=bin(gp)[2::]
        # print(int(s,2))
        return int(s,2)%(1000000007)