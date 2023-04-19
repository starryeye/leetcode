# Write your MySQL query statement below

#initcap 은 oracle 이다..

select 
    user_id, 
    concat(upper(substring(name, 1, 1)), lower(substring(name, 2, length(name)-1))) as name 
from Users
order by user_id;

#concat(name, address) : name + address
#upper : 대문자 치환
#lower : 소문자 치환
#substring(name, 2, 3) : name 의 2 번째 문자 부터 3 개의 문자로 -> 2,3,4 문자로 substring