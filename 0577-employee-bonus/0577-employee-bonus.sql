# Write your MySQL query statement below

select e.name, b.bonus
from Employee e
left join Bonus b
    on e.empId = b.empId
where b.bonus is null or b.bonus < 1000


# discuss null 처리 없는 버전
# SELECT E.name, B.bonus
# FROM Employee E
# LEFT JOIN Bonus B ON B.empId = E.empId
# WHERE COALESCE(B.bonus, 0) < 1000