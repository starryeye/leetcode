# Write your MySQL query statement below

select e1.employee_id, (
    select count(e2.employee_id)
    from Employee e2
    group by e2.team_id
    having e1.team_id = e2.team_id
) as team_size
from Employee e1;

## discuss
# select employee_id, 
#     count(employee_id) over(partition by team_id) as team_size
# from employee;