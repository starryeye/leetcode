# Write your MySQL query statement below

select distinct c.customer_id, c.customer_name
from Orders o
join Customers c
    on o.customer_id = c.customer_id
where o.customer_id not in (select customer_id from Orders where product_name = 'C')
    and o.customer_id in (select customer_id from Orders where product_name = 'A')
    and o.customer_id in (select customer_id from Orders where product_name = 'B')
order by c.customer_id;


# SELECT DISTINCT customer_id, customer_name
#   FROM Customers
#  WHERE customer_id in (
#     SELECT customer_id
#       FROM Orders
#      GROUP BY customer_id
#     HAVING SUM(product_name = 'A') > 0
#        AND SUM(product_name = 'B') > 0 
#        AND SUM(product_name = 'C') = 0
# )


