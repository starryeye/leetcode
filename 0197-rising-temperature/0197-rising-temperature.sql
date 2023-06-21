# Write your MySQL query statement below


select w1.id
from Weather w1
join Weather w2
where w1.temperature > w2.temperature and datediff(w1.recordDate, w2.recordDate) = 1


# 밑에 풀이는 안됨.... 이유 찾아보기..
# select w2.id
# from Weather w1
# join Weather w2
# where w1.temperature < w2.temperature and datediff(w1.recordDate, w2.recordDate) = 1

# select w2.id
# from Weather w1
# join Weather w2
# where w1.temperature < w2.temperature and w1.recordDate + 1 = w2.recordDate