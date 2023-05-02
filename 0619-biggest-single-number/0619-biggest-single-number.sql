# Write your MySQL query statement below

select
    case
        when count(num) = 1
            then num
        else
            null
    end as num
from MyNumbers
group by num
order by num desc
limit 1;


# discuss solution:

# select max(num) as num
# from(
# select num
# from my_numbers
# group by num
# having count(num) = 1
# )e