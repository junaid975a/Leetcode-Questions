# Write your MySQL query statement below
SELECT a.name as Employee 
FROM Employee as a
WHERE a.salary > (SELECT b.salary
                FROM Employee as b
                WHERE b.id=a.managerId and 
                b.salary<a.salary);