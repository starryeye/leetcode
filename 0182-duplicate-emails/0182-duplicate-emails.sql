# Write your MySQL query statement below

# select distinct(p1.email) as Email
# from Person as p1 #as 생략 가능한듯
# join Person as p2 #as 생략 가능한듯
#     on p1.email = p2.email and 
#         p1.id <> p2.id;

select email
from Person
group by email
having count(email) > 1;

# select distinct(p1.email)
# from Persion p1, Person p2
# where p1.email = p2.email and p1.id <> p2.id;

