# Write your MySQL query statement below

# select seller_name
# from Seller
# where seller_id not in (
#     select seller_id
#     from Orders
#     where year(sale_date) = '2020'
# )
# order by seller_name asc;

select s.seller_name as SELLER_NAME
from Seller s
left join Orders o
    on s.seller_id = o.seller_id
    and year(o.sale_date) = '2020'
where o.order_id is null
order by seller_name asc;