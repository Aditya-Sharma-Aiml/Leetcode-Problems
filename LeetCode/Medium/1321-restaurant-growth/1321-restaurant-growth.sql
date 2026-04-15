# Write your MySQL query statement below
WITH simple AS(
    SELECT visited_on
    FROM customer
    GROUP BY visited_on
    LIMIT 999999 OFFSET 6
)
SELECT l.visited_on,
       SUM(r.amount) AS amount,
       ROUND(SUM(r.amount)/7,2) AS average_amount
FROM simple l
JOIN customer r 
ON DATEDIFF(l.visited_on, r.visited_on) BETWEEN 0 AND 6
GROUP BY l.visited_on
ORDER BY l.visited_on;