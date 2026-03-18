# Write your MySQL query statement below
-- SELECT S1.student_id, S1.student_name, S2.subject_name,
-- (
--     SELECT COUNT(*)
--     FROM Examinations E
--     WHERE E.student_id = S1.student_id
--     AND E.subject_name = S2.subject_name
-- ) AS attended_exams

-- FROM Students S1
-- CROSS JOIN Subjects S2
-- ORDER BY S1.student_id, S2.subject_name;

Select Students.student_id, Students.student_name, Subjects.subject_name, count(Examinations.student_id) as attended_exams 
from Students 
Join Subjects
Left join Examinations 
on Students.student_id = Examinations.student_id
and Subjects.subject_name = Examinations.subject_name
group by students.student_id, subjects.subject_name
order by student_id asc, subject_name asc;