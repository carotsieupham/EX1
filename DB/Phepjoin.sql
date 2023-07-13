create table R1
(	 A int,
 	 B int
)
create table R2
(	 B int,
 	 C int
)
create table R3
(	 C int,
 	 D int
)
create table R(
 A int ,
 B int)
create table S(
 B int)
insert into R1
values
(1,2),
(3,4)
insert into R2
values
(2,3),
(5,6)
delete from R3
insert into R3
values
(3,7),
(8,9)
insert into R
values
(3,1),
(3,2),
(3,3),
(4,1),
(4,2),
(5,1),
(6,2)
select * from R
insert into S
values
(1),
(2)
select * 
from R1 inner join R2 on R2.B=R1.B
select *
from (R1 inner join R2 on R1.B=R2.B)
inner join R3 on R2.C=R3.C
select R1.*
from R1 inner join R2 on R1.B=R2.B
select *
from r1 left join R2 on R1.B=R2.B
select *
from r1 right join R2 on R1.B=R2.B
select *
from r1 full join R2 on R1.B=R2.B
select *
from r1 left join r2 on r1.B=r2.B
where C is null
select distinct A
from R x
where not exists(select *
				from S
				where B not in(select B
								from R 
								where x.A= A))