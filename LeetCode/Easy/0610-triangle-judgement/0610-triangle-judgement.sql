# Write your MySQL query statement below
-- a+b>c a+c>b b+c>a
SELECT x, y , z , 
CASE
    WHEN (x+y>z) AND (x+z>y) AND (y+z>x) THEN "Yes"
    ELSE "No"

END AS triangle
FROM Triangle;
