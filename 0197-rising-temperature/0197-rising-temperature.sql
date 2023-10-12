# Write your MySQL query statement below
# DATEDIFF is a function in sql used to find the difference between first and second date.
# DATEDIFF ( firstDate, secondDate ) = diff
select d1.id 
from weather as d1 , weather as d2
where  datediff(d1.recorddate, d2.recorddate)=1 and d1.temperature>d2.temperature;