5.1. Show Students of class ID = "C02".
select *
from student
where classid='C02'
5.2. Show Students of class name = "CN".
select D.*
from student D , classes B
where D.classid = B.classid and classname='CN'
5.3. Show Students (All information) of class year = "2019-2023".
select D.*
from student D , classes B
where D.classid = B.classid and classyear=2019
5.4. Show Subject name and units of the Subject ID = S01.
select subjectname,units 
from subject
where subjectid='S01'
5.5. Grades of Subject ID = "S02" of Student ID = "T02".
select grades
from studentgrades
where subjectid='S02' and studentid='T02'
5.6. Find Subject (ID, Name and Grades) that Student ID = "T06" fail
select D.subjectid, subjectname, grades
from subject B ,studentgrades D
where grades <5 and studentid='T06' and B.subjectid=D.subjectid
5.7. Show all the Subject (*) that Student ID = "T03" never took the exam.
select *
from subject
where subjectid not in(
select subjectid
from studentgrades
where studentid='T08')
5.8. Number of Students for each class
select classid,count(*) as ss
from student
group by classid
5.8.1. Number of Students < 7 for each class
select classid,count(*) as ss
from student
group by classid
having  count(*)<7
5.9. Find the classes with the largest number of students.
select classid,count(*) as ss
from student
group by classid
having  count(*)>=all(select count(*)
					 from student 
					 group by classid)
5.10. GPA (grade point average) of student ID = "T02".
select studentid, avg(grades)
from studentgrades
group by studentid
having studentid='T02'
5.11. GPA for each student.
select studentid, avg(grades) as dtb
from studentgrades
group by studentid
5.12. GPA of class ID = "C02"
select classid ,avg(grades) as dtb
from student A, studentgrades B
where A.studentid=B.studentid 
group by classid
having classid='C02'
5.13. GPA for each class.
select classid,avg(grades) as dtb
from studentgrades B, student D
where B.studentid =D.studentid
group by classid
5.14. Find students have the largest GPA
select studentid,avg(grades) as dtb
from studentgrades
group by studentid
having  avg(grades)>=all(select avg(grades)
					 from studentgrades
					 group by studentid)
5.15. Find students (ID and Name) have the largest GPA.
select B.studentid,studentname,avg(grades) as dtb
from studentgrades B ,student D
where B.studentid=D.studentid
group by B.studentid,studentname
having  avg(grades)>=all(select avg(grades)
					 from studentgrades
					 group by studentid)
5.16. Find classes (ID and Name) have the largest GPA
select C.classid,C.classname,avg(grades) as dtb
from studentgrades B ,student D,classes C
where B.studentid=D.studentid and C.classid=D.classid
group by C.classid,C.classname
having  avg(grades)>=all(select avg(grades)
					 from studentgrades
					 group by C.classid)
5.17. GPA with weight for each student.
select studentid,sum(grades*units)/sum(units)
from studentgrades B, subject D
where B.subjectid =D.subjectid
group by studentid
5.18. GPA with weight for each student (ID and name)
select C.studentid,studentname,sum(grades*units)/sum(units) as GPA
from student C , studentgrades B, subject D
where B.subjectid =D.subjectid and C.studentid=B.studentid
group by C.studentid,studentname
5.19. GPA with weight for each class.
select D.classid,sum(grades*units)/sum(units) as GPA
from studentgrades B, student D,subject C
where B.studentid =D.studentid and B.subjectid=C.subjectid
group by D.classid