# Write your MySQL query statement below
select s.name
from salesperson as s
where s.sales_id not in (select o.sales_id
                        from orders as o, company as c
                        where o.com_id=c.com_id and c.name="red");
