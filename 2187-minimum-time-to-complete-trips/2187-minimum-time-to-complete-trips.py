class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        def condition(time,t,trips) -> bool:
            res=0
            for gp in t:
                res=res+time//gp
            return res>=trips

        left, right = 1, 1000000000000000
        time=sorted(time)# could be [0, n], [1, n] etc. Depends on problem
        while left < right:
            mid = left + (right - left) // 2
            if condition(mid,time,totalTrips):
                right = mid
            else:
                left = mid + 1
        return left

