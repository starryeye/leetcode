# Write your MySQL query statement below


select 
    s1.id,
    (case
        when s1.id % 2 = 0 and s2.id is not null
            then s2.student
        when s1.id % 2 = 1 and s3.id is not null
            then s3.student
        else
            s1.student
     end) as student
from Seat s1
left join Seat s2
    on s1.id = s2.id + 1
left join Seat s3
    on s1.id = s3.id - 1
order by id;


# discuss solution
# SELECT
# 	CASE
# 		WHEN seat.id % 2 <> 0 AND seat.id = (SELECT COUNT(*) FROM seat) THEN seat.id
# 		WHEN seat.id % 2 = 0 THEN seat.id - 1
# 		ELSE
# 			seat.id + 1
# 	END as id,
# 	student 
# FROM seat
# ORDER BY id;