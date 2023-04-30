# Write your MySQL query statement below

# 1 (subquery)
# IN 절은 "=" 등호 연산자가 내포 되어 있다고 생각하면 편하다.
# c.seat_id - 1 in (select seat_id from Cinema where free = 1) 
# 의 의미는.. in 절의 결과가 c.seat_id - 1 과 동일한 경우 true 이다.
# select c.seat_id
# from Cinema c
# where c.free = 1 and (
#     c.seat_id - 1 in (select seat_id from Cinema where free = 1) 
#     or
#     c.seat_id + 1 in (select seat_id from Cinema where free = 1)
# )

# 2 (join)
select distinct c1.seat_id
from cinema c1
join cinema c2
where c1.free = 1 and (
	(c1.seat_id + 1 = c2.seat_id and c2.free = 1)
	or
	(c1.seat_id - 1 = c2.seat_id and c2.free = 1)
)

# 서브쿼리와 조인 성능 비교
# 첫 번째 쿼리에서 서브쿼리를 두 번 실행하므로, 데이터베이스가 각 서브쿼리의 결과를 캐시하지 않거나 최적화하지 않는 경우 성능이 저하될 수 있다. 또한 서브쿼리를 사용하는 경우, 인덱스를 효율적으로 사용하지 못할 수도 있다.

# 반면 두 번째 쿼리에서는 JOIN을 사용하여 두 테이블을 결합하므로, 데이터베이스가 조인을 최적화할 수 있는 경우 성능이 더 좋을 수 있다. JOIN 작업은 인덱스를 활용하여 효율적으로 수행될 수 있다.

# 그러나 정확한 성능 비교를 위해서는 실제 데이터베이스에서 두 쿼리를 실행해 보고 실행 계획을 분석하는 것이 좋다. 실행 계획은 데이터베이스가 쿼리를 어떻게 처리하는지에 대한 정보를 제공하므로, 두 쿼리의 성능 차이를 더 정확하게 비교할 수 있다.

# 오답
# select seat_id
# from Cinema
# where seat_id in(
#     select c1.seat_id
#     from Cinema c1
#     join Cinema c2
#         on c2.seat_id - c1.seat_id = 1
#     where c2.free <> c1.free
    
#     union
    
#     select seat_id
#     from Cinema
#     where free = 0
# );