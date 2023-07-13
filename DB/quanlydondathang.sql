create table category
(
    categoryID char(3) primary key,
    categoryName varchar(30)
)

create table Product
(
    ProductID char(3) primary key,
    ProductName varchar(30),
    UnitPrice real,
    categoryID char(3)
)

create table customer
(
    customerID char(3) primary key,
    customerName varchar(30),
    customerAddress varchar(30)
)

create table orders
(
    orderID char(3) primary key, 
    orderDate date,
    RequiredDate date,
    customerID char(3)
)

create table OrderDetail 
( 
    OrderID char(3), 
    ProductID char(3), 
    OrderQuantity int,
    primary key(orderID, productid)
)

create table Delivery 
( 
    DeliveryID char(3) primary key,
    DeliveryDate date, 
    OrderID char(3) 
)

create table DeliveryDetail 
( 
    DeliveryID char(3), 
    ProductID char(3), 
    DeliveryQuantity int,
    primary key(DeliveryID, productid)
)

insert into category
values
    ('C01','A'),
    ('C02','B'),
    ('C03','C'),
    ('C04','D'),
    ('C05','E')

insert into Product
values
    ('P01','pepsi',10,'C01'),
    ('P02','siting',10,'C01'),
    ('P03','7up',10,'C01'),
    ('P04','mirinda',10,'C01'),
    ('P05','aquafina',5,'C01'),
    ('P06','lavie',5,'C01'),
    ('P07','socola',10,'C02'),
    ('P08','banh trang',10,'C02'),
    ('P09','banh bong lan',7,'C02'),
    ('P10','banh gao',4,'C02'),
    ('P11','banh pia',10,'C02'),
    ('P12','keo gum',2,'C02'),
    ('P13','Tivi',100,'C03'),
    ('P14','may tinh de ban',200,'C03'),
    ('P15','laptop',200,'C03'),
    ('P16','ban phim',50,'C03'),
    ('P17','chuot may tinh',50,'C03'),
    ('P18','loa',40,'C03'),
    ('P19','giuong',100,'C04'),
    ('P20','tu',80,'C04'),
    ('P21','ghe',80,'C04'),
    ('P22','ban trang diem',50,'C04'),
    ('P23','ban go',60,'C04'),
    ('P24','tu kinh',50,'C04'),
    ('P25','ao tay ngan',65,'C05'),
    ('P26','ao tay dai',60,'C05'),
    ('P27','ao khoac',70,'C05'),
    ('P28','quan tay',80,'C05'),
    ('P29','quan dui',40,'C05'),
    ('P30','quan jean',50,'C05')

insert into customer
values 
    ('M01','Nguyen Thanh Dat','Binh Duong'),
    ('M02','Do Hoang Giang','Tan Phu'),
    ('M03','Pham Minh An','Tan Binh'),
    ('M04','Huynh Thanh Hau','Phu Nhuan'),
    ('M05','Vu Hoang Phong','Binh Thanh'),
    ('M06','Nguyen Van A','Phu Chanh'),
    ('M07','Nguyen Van B','Quan 1'),
    ('M08','Nguyen Van C','Quan 2'),
    ('M09','Nguyen Van D','Quan 4'),
    ('M10','Le Quoc Viet','Quan 12'),
    ('M11','Le Thanh dinh','Quan 7'),
    ('M12','Nguyen van Hoang','Quan 10')


insert into orders
values
    ('R01','2022-01-18','2022-02-18','M01'),
    ('R02','2022-02-15','2022-02-27','M01'),
    ('R03','2022-03-01','2022-03-10','M01'),
    ('R04','2022-04-05','2022-04-14','M04'),
    ('R05','2022-05-31','2022-06-09','M05'),
    ('R06','2022-06-10','2022-07-01','M07'),
    ('R07','2022-07-20','2022-07-27','M07'),
    ('R08','2022-08-01','2022-08-10','M09'),
    ('R09','2022-10-15','2022-11-01','M11'),
    ('R10','2022-12-19','2022-12-25','M11')

-- sửa lại
insert into OrderDetail
values 
    ('R01','P05',30),
    ('R01','P06',10),
    ('R01','P04',1),
    ('R01','P03',8),
    ('R01','P02',7),
    ('R02','P01',10),
    ('R02','P14',1),
    ('R02','P16',1),
    ('R02','P17',1),
    ('R03','P11',10),
    ('R03','P10',10),
    ('R04','P25',2),
    ('R04','P26',2),
    ('R04','P27',2),
    ('R04','P28',2),
    ('R04','P29',2),
    ('R04','P20',2),
    ('R05','P15',1),
    ('R05','P16',1),
    ('R05','P17',1),
    ('R06','P21',4),
    ('R07','P23',1),
    ('R08','P13',2),
    ('R08','P21',2),
    ('R08','P18',2),
    ('R09','P25',2),
    ('R10','P21',2)

-- sửa lại
insert into Delivery
values
    ('L01','2022-02-18','R01'),
    ('L02','2022-02-23','R01'),
    ('L03','2022-02-24','R01'),
    ('L04','2022-02-25','R01'),
    ('L05','2022-02-28','R01'),
    ('L06','2022-02-27','R02'),
    ('L07','2022-02-28','R02'),
    ('L08','2022-03-01','R02'),
    ('L09','2022-03-02','R02'),
    ('L10','2022-07-01','R06'),
    ('L11','2022-07-27','R07'),
    ('L12','2022-11-01','R09'),
    ('L13','2022-12-25','R10')
insert into DeliveryDetail
values
    ('L01','P05',1),
    ('L02','P06',1),
    ('L03','P13',1),
    ('L04','P29',1),
    ('L05','P31',1),
    ('L06','P01',1),
    ('L07','P14',1),
    ('L08','P16',1),
    ('L09','P17',1),
    ('L10','P21',1),
    ('L11','P23',1),
    ('L12','P25',1),
    ('L13','P26',1)


select * 
from Product
where categoryID='C02'


select customerName
from customer A, orders B
where A.customerID=B.customerID
    and orderDate >= '2022-02-01' and orderDate <='2022-06-01'


select A.customerID, customerName, customerAddress
from customer A, orders B
where A.customerID=B.customerID
    and date_part('year',orderDate)='2022'

select A.productid
from product A, OrderDetail B
where A.productid=B.productid
    and orderID = 'R01'

select *
from product A, OrderDetail B
where A.productid=B.productid
    and orderID = 'R01'

select A.*
from product A, OrderDetail B, orders C
where A.productid=b.productid
    and B.orderID=C.orderID
    and orderDate ='2022-05-31'

select orderID, sum(OrderQuantity)
from OrderDetail
group by orderID

select A.orderID, sum(OrderQuantity)
from OrderDetail A, orders B
where A.orderID=B.orderID
    and date_part('day',orderDate)='15'
group by A.orderID

select date_part('quarter',orderDate), sum(OrderQuantity*unitprice)
from product A, orders B, OrderDetail C
where A.productid=C.productid
    and B.orderID=C.orderID
    and date_part('year',orderDate)='2022'
group by date_part('quarter',orderDate)

select orderid
from OrderDetail A,product B
where 	A.productid=B.productid
	and categoryid='C01'
	and not exists
	(
		select *
		from category
		where categoryID not in (
								select categoryID
								from OrderDetail A,product B
								where 	A.productid=B.productid 
								)
	)

select distinct date_part('quarter', orderDate)
from orders A,OrderDetail B,product C
where A.orderID=B.orderID
    and B.productid=C.ProductID
    and not exists
    (
        select *
        from product
        where categoryID='C01'
        and productid not in (
                                select productid
                                from OrderDetail B,product C
                                where B.productid=C.productid
                                )
    )
   
alter table category
alter column categoryName
set not null

alter table product
alter column productname
set not null

alter table product
alter column unitprice
set not null

alter table product
alter column categoryID
set not null

alter table customer
alter column customerName
set not null

alter table customer
alter column customerAddress
set not null

alter table orders
alter column orderDate
set not null

alter table orders
alter column RequiredDate
set not null

alter table orders
alter column customerID
set not null

alter table OrderDetail
alter column OrderQuantity
set not null

alter table Delivery
alter column DeliveryDate
set not null

alter table Delivery
alter column orderID
set not null

alter table DeliveryDetail
alter column DeliveryQuantity
set not null

alter table product
add constraint KTunitprice
	check(unitprice > 0)
	
alter table orders
add constraint KTorderdate
	check(orderdate < RequiredDate)

alter table orderdetail
add constraint KTorderquantity
	check(orderquantity>0)