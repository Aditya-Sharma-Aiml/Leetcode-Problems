# Write your MySQL query statement below
SELECT S1.student_id, S1.student_name, S2.subject_name,
(
    SELECT COUNT(*)
    FROM Examinations E
    WHERE E.student_id = S1.student_id
    AND E.subject_name = S2.subject_name
) AS attended_exams

FROM Students S1
CROSS JOIN Subjects S2
ORDER BY S1.student_id, S2.subject_name;