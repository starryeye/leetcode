# Write your MySQL query statement below

# 서브 쿼리에 where 문이 들어간 이유는..
# null 은 식별할 수 없는 값이라..
# id 와 비교가 안돼서 Leaf 값 자체가 도출 되지 않음(동작이 안됨)
select id,
    case
        when p_id is null 
            then 'Root'
        when id not in (select p_id from tree where p_id is not null) 
            then 'Leaf'
        else 'Inner'
    end as Type
from tree