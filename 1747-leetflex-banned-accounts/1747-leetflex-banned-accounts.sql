# Write your MySQL query statement below

select distinct l1.account_id
from LogInfo l1
join LogInfo l2
    on l1.account_id = l2.account_id and l1.ip_address <> l2.ip_address
where
    l1.login <= l2.login and l2.login <= l1.logout
    or
    l2.login < l1.login and l1.login <= l2.logout


# discuss    
# select distinct a.account_id
# from LogInfo a, LogInfo b
# where a.login between (b.login) and (b.logout)
# and a.account_id = b.account_id
# and a.ip_address !=b.ip_address