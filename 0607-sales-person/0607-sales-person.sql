# Write your MySQL query statement below


select name
from SalesPerson as s
where s.sales_id not in(
    select o.sales_id
    from Orders as o
    join Company as c on o.com_id = c.com_id
    where c.name='RED'
);


# 방법 2
# select name
# from SalesPerson
# where sales_id not in (
#     select sales_id
#     from Orders
#     where com_id in (
#         select com_id
#         from Company
#         where name = 'RED'
#     )
# )