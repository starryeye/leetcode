# Write your MySQL query statement below

# distinct 는 결과 컬럼에 대해 수행한다.
select distinct author_id as id
from Views
where author_id = viewer_id
order by author_id asc