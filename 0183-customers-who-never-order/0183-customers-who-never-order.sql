# Write your MySQL query statement below
# left outer join. == left join
# inner join == join
select c.name as Customers
from Customers as c
left outer join Orders as o on c.id = o.customerId
where o.customerId is null;