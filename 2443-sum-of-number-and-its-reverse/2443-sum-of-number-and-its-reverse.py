class Solution:
    def sumOfNumberAndReverse(self, num: int) -> bool:
        for gp in range(0,num+1):
            if gp + int(str(gp)[::-1])==num:
                return True;
        return False;