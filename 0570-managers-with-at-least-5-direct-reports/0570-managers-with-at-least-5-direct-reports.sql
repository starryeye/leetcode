# Write your MySQL query statement below

select e1.name
from Employee e1
where id in (
    select managerId
    from Employee e2
    group by e2.managerId
    having count(id) >= 5
)

# select e2.Name
# from Employee e1 
# join Employee e2
#     on e1.managerId = e2.Id
# group by e1.managerId
# having count(e1.managerId) >= 5