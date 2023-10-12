# Write your MySQL query statement below
SELECT c.name as Customers
from Customers as c 
where c.id not in(SELECT o.customerId
                    from Orders as o);