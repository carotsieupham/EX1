create database QLSV;
use QLSV;
create table Subject 
( 
	 SubjectID char(3) primary key, 
	 SubjectName varchar(30), 
	 Units int 
);

create table Classes 
( 
	ClassID char(3) primary key, 
	ClassName varchar(30), 
	ClassYear int 
);

create table Student 
( 
	StudentID char(3) primary key, 
	StudentName varchar(30),
	StudentAddress varchar(30), 
	ClassID char(3), 
    Foreign key(classid)references classes(classid)
);

create table StudentGrades 
( 
	StudentID char(3), 
	SubjectID char(3), 
	Grades real,
	primary key(StudentID , 
	SubjectID),
	Foreign key(studentid)references student(studentid),
	Foreign key(subjectid)references subject(subjectid)

);

insert into subject
values
('S01','Toan',3),
('S02','Ly',2),
('S03','Hoa',2),
('S04','Sinh',1),
('S05','Su',1)
insert into classes
values
('C01','CN',2021),
('C02','XD',2022),
('C03','QC',2019)
delete from classes
insert into student
values
('T01','Tran Minh Tri','Binh Thanh','C01'),
('T02','Tri Minh Tran','Binh Tan','C01'),
('T03','Tran Minh Hieu','Quan 7','C02'),
('T04','Nguyen Van Ba','Quan 8','C02'),
('T05','Nguyen Quang Trung','TPHCM','C01'),
('T06','Nguyen Hue','Quan 12','C03'),
('T07','Le Loi','Quan 1','C03'),
('T08','Le Phuong Linh','Quan 1','C03'),
('T09','Nguyen Hy Lap','Binh Thanh','C01'),
('T10','Vu Tri','Quan 2','C03'),
('T11','Nguyen Don Lu','Quan 9 ','C01'),
('T12','Le Thi Anh Duong','Binh Tan','C03'),
('T13','Vo Quoc Huy','Thu Duc','C01'),
('T14','Do Thi Bao Tran','Quan 8','C03'),
('T15','Ho Luc','Quan 4','C02'),
('T16','Nguyen Hoang','Quan 1','C02'),
('T17','Phan Thinh','Quan 12','C02'),
('T18','Ho Gia Bao','Quan 2','C03'),
('T19','Ho Gia Y','Quan 8','C03'),
('T20','Do Thi Hoa','Quan 7','C03')
insert into studentgrades
values
('T01','S01',2),
('T01','S03',7),
('T01','S04',3),
('T01','S02',9),
('T01','S05',6),
('T02','S01',8),
('T02','S02',9),
('T02','S03',7),
('T02','S04',8),
('T02','S05',5),
('T03','S03',7),
('T03','S01',5),
('T04','S02',6),
('T04','S01',7),
('T04','S03',5),
('T05','S01',7),
('T05','S03',7),
('T05','S04',8),
('T05','S05',6),
('T06','S01',3),
('T06','S02',9),
('T06','S03',6),
('T06','S04',8),
('T06','S05',5),
('T07','S01',8),
('T07','S02',1),
('T07','S03',4),
('T07','S04',3),
('T07','S05',5),
('T08','S01',8),
('T08','S02',6),
('T08','S03',6),
('T08','S04',5),
('T09','S01',7),
('T09','S02',9),
('T09','S03',7),
('T09','S04',8),
('T09','S05',5),
('T10','S01',8),
('T10','S02',4),
('T10','S03',3),
('T10','S04',8),
('T10','S05',7);

