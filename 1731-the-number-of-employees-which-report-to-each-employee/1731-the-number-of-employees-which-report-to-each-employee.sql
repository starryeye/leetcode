# Write your MySQL query statement below

# group by 없이 집계함수를 사용하면 예상치 못한 결과가 나올 수 있다.
# round 함수는 반올림을 해준다.

select 
    e1.employee_id, 
    e1.name, 
    count(e2.employee_id) as reports_count, 
    round(avg(e2.age)) as average_age
from Employees e1
join Employees e2
    on e1.employee_id = e2.reports_to
group by e1.employee_id
order by e1.employee_id;