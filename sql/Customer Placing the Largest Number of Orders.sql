# Write your MySQL query statement below

WITH cte AS
(SELECT o.customer_number, COUNT(o.order_number) AS numOrd
FROM Orders o
GROUP BY o.customer_number)

SELECT c.customer_number
FROM cte c
WHERE c.numOrd = (SELECT MAX(c2.numOrd) FROM cte c2)