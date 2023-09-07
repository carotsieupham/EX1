create database QLK;
use QLK;
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
    foreign key (CategoryID) references Category(CategoryID)
    );

create table Warehouse 
(   WarehouseID char(3) primary key, 
    WarehouseAddress varchar(30), 
    CategoryID char(3) ,
	foreign key (CategoryID) references Category(CategoryID)
    );

create table Instock 
(   WarehouseID char(3) , 
    ProductID char(3), 
    Quantity int,
	primary key ( WarehouseID,ProductID),
    foreign key (WarehouseID) references Warehouse(WarehouseID),
    foreign key (ProductID) references Product (ProductID)
);

insert into Category
values
('C01','Nuoc giai khat'),
('C02','Thuc an'),
('C03','Do ve sinh'),
('C04','Vat lieu xay dung'),
('C05','Do dien tu');
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
('P30','Laptop',30,'C05');

insert into Warehouse
values
('W01','TPHCM','C01'),
('W02','Binh Duong','C01'),
('W03','Da Nang','C02'),
('W04','Lam Dong','C02'),
('W05','Bac Ninh','C03'),
('W06','Ha Noi','C04'),
('W07','Hue','C05');
insert into Instock
values
('W01','P01',100),
('W01','P02',50),
('W01','P05',65),
('W01','P15',110),
('W01','P09',0),
('W01','P28',130),
('W02','P09',90),
('W02','P05',85),
('W02','P15',160),
('W02','P01',50),
('W02','P02',100),
('W02','P28',130),
('W03','P18',100),
('W03','P19',200),
('W03','P22',120),
('W03','P24',150),
('W03','P26',160),
('W03','P29',170),
('W04','P18',110),
('W04','P19',210),
('W04','P22',170),
('W04','P24',110),
('W04','P26',120),
('W04','P29',130),
('W05','P20',250),
('W05','P21',400),
('W05','P23',200),
('W05','P27',200),
('W06','P03',200),
('W06','P07',90),
('W06','P08',200),
('W06','P10',1000),
('W06','P14',20),
('W07','P04',500),
('W07','P06',800);

