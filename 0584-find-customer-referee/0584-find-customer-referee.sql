# Write your MySQL query statement below

select name
from Customer
where COALESCE(referee_id, 0) <> 2;
# COALESCE(referee_id, 0) : referee_id 값이 null 이면 0 으로 치환됨
# <> : !=

# select name
# from Customer
# where referee_id != 2 or referee_id is null;