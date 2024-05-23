# Write your MySQL query statement below
-- approach 1
-- SELECT c.name AS Customers
-- From Customers c
-- LEFT JOIN Orders o
-- ON c.id = o.customerId
-- WHERE o.id IS NULL

-- approach 2
SELECT c.name as Customers
FROM Customers c
WHERE c.id NOT IN
(Select c.id
FROM Customers c
INNER JOIN Orders o
ON c.id = o.customerId)
