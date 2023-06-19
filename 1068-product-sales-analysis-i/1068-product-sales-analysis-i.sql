# Write your MySQL query statement below


select p.product_name, s.year, s.price
from Sales s
join Product p on s.product_id = p.product_id

# discuss
# SELECT DISTINCT 
#     P.product_name, S.year, S.price 
# FROM 
#     (SELECT DISTINCT product_id, year, price FROM Sales) S
# INNER JOIN
#     Product AS P
# USING (product_id);