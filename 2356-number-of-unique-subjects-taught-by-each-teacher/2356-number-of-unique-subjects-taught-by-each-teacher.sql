# Write your MySQL query statement below

# distinct : 중복 데이터를 제거하고 조회한다.
# group by : 데이터를 그룹화(중복 제거)하고 집계 함수를 사용하고자 할 때 사용한다.

select teacher_id, count(distinct subject_id) as cnt
from Teacher
group by teacher_id