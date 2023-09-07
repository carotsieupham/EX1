create database QLDDH;
use QLDDH;
create table Category 
( 
    CategoryID char(3) primary key, 
    CategoryName varchar(30) );

create table  Product 
( 
    ProductID  char(3) primary key, 
    ProductName varchar(30), 
    UnitPrice real, 
    CategoryID char(3),
    foreign key (CategoryID) references Category(CategoryID));

create table Customer 
(   CustomerID char(3) primary key , 
    CustomerName varchar(30), 
    CustomerAddress varchar(30) );

create table Orders 
(   OrderID char(3) primary key, 
    OrderDate date, 
    RequiredDate date, 
    CustomerID char(3),
    foreign key (CustomerID) references Customer(CustomerID)
);

create table OrderDetail ( 
    OrderID char(3) , 
    ProductID char (3), 
    OrderQuantity int,
    primary key(OrderID,ProductID),
    foreign key (OrderID) references Orders(OrderID),
    foreign key (ProductID) references Product(ProductID)

    );

create table Delivery ( 
    DeliveryID char(3) primary key, 
    DeliveryDate date, 
    OrderID char(3),
    foreign key (OrderID) references Orders(OrderID)
    );

create table DeliveryDetail ( 
	DeliveryID char(3), 
	ProductID char(3), 
	DeliveryQuantity int,
	primary key(DeliveryID,ProductID),
    foreign key (ProductID) references Product(ProductID),
    foreign key (DeliveryID) references Delivery(DeliveryID)
    );
insert into Category
values
('C01','Nuoc giai khat'),
('C02','Thuc an'),
('C03','Do dien tu'),
('C04','Do noi that'),
('C05','Do thoi trang');

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
    ('P30','quan jean',50,'C05');

insert into Customer
values
('M01','Tran Minh Tri','Binh Thanh'),
('M02','Nguyen Minh Triet','Binh Tan'),
('M03','John Pham','Quan 7'),
('M04','Ho Luc','Go Vap'),
('M05','Tran Van Quoc Bao','Binh Thanh'),
('M06','Dang Nguyen Yen Nhi','Thu Duc'),
('M07','Tran Gia Bao','Binh Thanh'),
('M08','Do Hoang Truong','Quan 12'),
('M09','Nguyen Minh Thu','Quan 1'),
('M10','Do Khanh Linh','Quan 2'),
('M11','Nguyen Van Sang','Quan 5'),
('M12','Bui Minh Hieu','Binh Thanh');

insert into Orders
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
    ('R10','2022-12-19','2022-12-25','M11');

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
    ('R10','P21',2);


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
    ('L13','2022-12-25','R10');


