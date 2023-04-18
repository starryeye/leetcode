# Write your MySQL query statement below

select
    employee_id,
    if(employee_id % 2 = 1 and name not like 'M%', salary, 0) as bonus
from Employees
order by employee_id;


#if 사용법 : if(condition, value_if_true, value_if_false)


#union 사용

# select 
#     employee_id, 
#     salary as bonus
# from Employees
# where employee_id % 2 = 1 and name not like 'M%'

# union

# select 
#     employee_id, 
#     0 as bonus
# from Employees
# where employee_id % 2 = 0 or name like 'M%'

# order by employee_id;