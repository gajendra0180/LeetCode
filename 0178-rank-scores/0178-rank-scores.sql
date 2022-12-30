with cte1 
as
(
    select 
        *,
        lag(score) over () as prev,
        lead(score) over () as next
    from scores,(select @count:=0) t order by score DESC
),
cte2
as
(
select
    score,
    (
        case 
            when (cte1.prev is not null and cte1.score=cte1.prev) then (@count) 
            else (@count:=@count+1)
        end
    ) as `rank`
from cte1
)
select score, cast(`rank` as unsigned) as `rank` from cte2;
