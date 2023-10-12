# Write your MySQL query statement below
select p.project_id, round(avg(experience_years),2) as average_years 
from project as p
inner join employee as e
USING(employee_id)
group by p.project_id;