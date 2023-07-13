create table Category 
( 
    CategoryID char(3) primary key, 
    CategoryName varchar(30) )
alter table category
alter column categoryname
set not null
alter table category
add unique(categoryname)
create table  Product 
( 
    ProductID  char(3) primary key, 
    ProductName varchar(30), 
    UnitPrice real, 
    CategoryID char(3))
alter table product
alter column productname
set not null
alter table product
alter column unitprice
set not null
alter table product
alter column categoryid
set not null
alter table product
add unique(productname)
alter table product
add constraint KTunitprice
check(unitprice>0)
create table Invoice ( 
    InvoiceID char(3) primary key, 
    InvoiceDate date, 
    Descriptions varchar(30) 
)
alter table invoice
alter column invoicedate
set not null
alter table invoice
alter column descriptions
set not null
create table InvoiceDetail  
( 
    InvoiceID char (3), 
    ProductID char(3), 
    Quantity int,
    primary key(InvoiceID,ProductID) 
)
alter table invoicedetail
alter column quantity
set not null
alter table invoicedetail
add constraint KTquantity
check(quantity>0)
insert into Category
values
('C01','Nuoc giai khat'),
('C02','Thuc an'),
('C03','Do ve sinh'),
('C04','Vat lieu xay dung'),
('C05','Do dien tu')
insert into Product
values
('P01','Pepsi',10,'C01'),
('P02','Coca',10,'C01'),
('P03','Gach',50,'C04'),
('P04','Tivi',60,'C05'),
('P05','Fanta',5,'C01'),
('P06','Tu lanh',50,'C05'),
('P07','Xi mang',20,'C04'),
('P08','Thep',25,'C04'),
('P09','Xaxi',10,'C01'),
('P10','Ton',20,'C04'),
('P11','May giat',50,'C05'),
('P12','May say',30,'C05'),
('P13','PC',80,'C05'),
('P14','Son',30,'C04'),
('P15','Redbull',10,'C01'),
('P16','Dinh',5,'C04'),
('P17','Cat',10,'C04'),
('P18','Carot',10,'C02'),
('P19','Socola',10,'C02'),
('P20','Ban chai',20,'C03'),
('P21','Xa bong',15,'C03'),
('P22','Thit heo',30,'C02'),
('P23','Dau goi',20,'C03'),
('P24','Thit bo',30,'C02'),
('P25','Dieu hoa',60,'C05'),
('P26','Salad',5,'C02'),
('P27','Sua rua mat',20,'C03'),
('P28','Nuoc loc',5,'C01'),
('P29','Banh',5,'C02'),
('P30','Laptop',30,'C05')
select * from product
insert into Invoice
values
('I01','2023-03-28','Buoi sang'),
('I02','2023-03-28','Buoi chieu'),
('I03','2023-09-24','Buoi trua'),
('I04','2023-09-24','Buoi sang'),
('I05','2023-12-24','Buoi toi'),
('I06','2023-10-25','Buoi sang'),
('I07','2023-08-20','Buoi trua'),
('I08','2022-01-30','Buoi trua'),
('I09','2023-04-01','Buoi trua'),
('I10','2023-05-01','Buoi sang')
delete from invoice
insert into InvoiceDetail  
values
('I01','P02',2),
('I01','P03',1),
('I01','P04',1),
('I02','P01',2),
('I02','P10',2),
('I02','P27',2),
('I02','P29',3),
('I03','P01',1),
('I04','P30',1),
('I04','P11',1),
('I05','P01',1),
('I05','P29',1),
('I06','P22',1),
('I06','P24',2),
('I07','P07',2),
('I07','P08',4),
('I07','P10',5),
('I08','P19',2),
('I08','P15',2),
('I09','P14',4),
('I09','P17',5),
('I09','P16',20),
('I09','P03',5),
('I09','P10',5),
('I10','P30',1),
('I10','P04',2)
5.1. Find products of the category ID = "CO1"
select * from product
where categoryid='C01'
5.2. Find products (ID, name and price) of the category ID = "CO2".
select productid,productname,unitprice from product
where categoryid='C02'
5.3. Find products (*) with unit price from 10 to 50.
select * from product
where unitprice>=10 and unitprice<=50
5.4. Show invoices, it created at date = 2023-04-01
select * from invoice
where invoicedate='2022-04-1'
5.5. Show invoices, it created on year = 2023.
select * from invoice
where Date_part('Year',invoicedate)='2023'
5.6. Find products (ID, name, unit price and quantity), it belong to the invoice at date = 2023-09-24.
select a.productid,productname,unitprice,quantity 
from product a,invoice b,invoicedetail c
where a.productid=c.productid and b.invoiceid = c.invoiceid and invoicedate='2023-09-24'
5.7. Total quantity of each invoice
select invoiceid ,sum(quantity) as tongsp
from invoicedetail
group by invoiceid
5.8. Total quantity of each invoice in date = d.
select a.invoiceid,sum(quantity)
from invoice a,invoicedetail b
where a.invoiceid=b.invoiceid and invoicedate='2023-09-24'
group by a.invoiceid
5.9. Total cost (= quantity times to unit price) of each invoice
select invoiceid ,sum(quantity*unitprice)
from invoicedetail b, product c
where b.productid=c.productid
group by invoiceid
5.9.1 tong gia tri cac hoa don trong tung quy cua nam 2023
select Date_part('quarter',invoicedate) ,sum(quantity*unitprice)
from invoicedetail b, product c ,invoice a
where b.productid=c.productid and a.invoiceid=b.invoiceid and Date_part('Year',invoicedate)='2023'
group by Date_part('quarter',invoicedate)
5.10. With invoices have the largest total quantity
select invoiceid ,sum(quantity) as tongsp
from invoicedetail
group by invoiceid
having sum(quantity) >=all(select sum(quantity)
					 from invoicedetail
					 group by invoiceid)
5.11. In date = d, with invoices have the largest total quantity
select a.invoiceid ,sum(quantity) as tongsp
from invoicedetail a,invoice b
where invoicedate='2023-03-28' and a.invoiceid=b.invoiceid
group by a.invoiceid
having sum(quantity) >=all(select sum(quantity)
					       from invoicedetail a,invoice b
						   where invoicedate='2023-03-28' and a.invoiceid=b.invoiceid
					       group by a.invoiceid)
5.12. With invoices have the largest total cost
select invoiceid ,sum(quantity*unitprice)
from invoicedetail b, product c
where b.productid=c.productid
group by invoiceid
having sum(quantity*unitprice)>=all(select sum(quantity*unitprice)
								    from invoicedetail b, product c
									where b.productid=c.productid
									group by invoiceid)
5.13. In date = d, with invoices have the largest total cost
select a.invoiceid ,sum(quantity*unitprice)
from invoicedetail b, product c ,invoice a
where b.productid=c.productid and a.invoiceid=b.invoiceid and invoicedate='2023-03-28'
group by a.invoiceid
having sum(quantity*unitprice)>=all(select sum(quantity*unitprice)
								    from invoicedetail b, product c ,invoice a
                                    where b.productid=c.productid and a.invoiceid=b.invoiceid and invoicedate='2023-03-28'
									group by a.invoiceid) 
5.14. Find years have the largest total cost.
select date_part('Year',invoicedate),sum(quantity*unitprice)
from product a, invoice b, invoicedetail c
where a.productid=c.productid and b.invoiceid=c.invoiceid
group by date_part('Year',invoicedate)
having sum(quantity*unitprice)>=all(select sum(quantity*unitprice)
							   from product a, invoice b, invoicedetail c
                               where a.productid=c.productid and b.invoiceid=c.invoiceid
							   group by date_part('Year',invoicedate))