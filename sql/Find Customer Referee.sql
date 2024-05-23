# Write your MySQL query statement below

Select l.name AS name
FROM Customer l
WHERE l.referee_id != 2
OR l.referee_id IS NULL