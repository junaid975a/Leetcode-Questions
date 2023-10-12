# Write your MySQL query statement below
DELETE d
from Person as o, person as d
where o.email=d.email and o.id<d.id;
