# Write your MySQL query statement below

select employee_id
from Employees
where 
    not manager_id in (select employee_id from Employees)
    and manager_id is not null
    and salary < 30000
order by employee_id asc;


# discuss faster solution .. 
# where 조건 순서가 중요하네...
# SELECT employee_id
# FROM Employees
# WHERE salary < 30000
# AND manager_id IS NOT NULL
# AND manager_id NOT IN (SELECT employee_id FROM Employees)
# ORDER BY employee_id;


# discuss using self join
# SELECT DISTINCT emp.employee_id
# FROM   employees emp
#        LEFT JOIN employees mng
#               ON( emp.manager_id = mng.employee_id )
# WHERE  emp.manager_id IS NOT NULL
#        AND emp.salary < 30000
#        AND mng.employee_id IS NULL
# ORDER  BY emp.employee_id 

