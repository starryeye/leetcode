# Write your MySQL query statement below

# group by customer_id : customer_id 로 묶겠다.
# having XXX : group by 를 진행한 결과에 조건 XXX 에 부합하는 애들만 보겠다는 의미이다.
# 여기서는 count(distinct product_key) 와 select count(distinct product_key) from product 가 동일한 조건을 걸었다. 
select customer_id
from customer
group by customer_id
having 
    count(distinct product_key) = (select count(distinct product_key) from product)