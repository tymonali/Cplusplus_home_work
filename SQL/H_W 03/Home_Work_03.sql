-- 1. ���������. (Departments)
-- 2. ����������� (Diseases)
-- 3. ����� (Doctors)
-- 4. ������������ (Examinations)
-- 5. ������ (Wards)
-- 6. Patients (��������)

--~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

insert Patients values
('����','��������','1971-02-28','2020-12-17','2021-01-08','+38(098)1236532'),
('�����','������','1989-10-15','2020-12-18','2021-01-14','+38(095)1111111'),
('����','������','2001-04-16','2020-12-18','2021-01-03','+38(095)1211111'),
('������','����','2005-10-18','2020-12-19','2021-01-09','+38(066)1111111'),
('����','������','1980-08-23','2020-12-19','2021-01-07','+38(063)1111111'),
('�����','�����','1900-01-01','2020-12-25','2021-01-01','+38(067)1472598'),
('�������','����������','1949-05-21','2020-12-25','2021-01-21','+38(098)2221541'),
('���������','��������','1959-07-08','2021-01-09','2021-02-09','+38(050)7896521'),
('��������','������������','1961-09-19','2021-01-10','','+38(044)8009562'),
('��������','����������','1959-07-08','2021-01-11','2021-01-30','+38(056)2589632');

update Patients set DischargeDate = '2021-02-24' where Id = 9;

insert Doctors values
('��������','+38(056)9212587','1000.0','7500.0','����������'),
('������','+38(056)7412358','950.0','7500.0','���������'),
('���������','+38(043)9513571','900.0','7500.0','����������'),
('��������','+38(054)3660347','940.0','7500.0','��������'),
('�������','+38(028)1583481','970.0','7500.0','�����������');

insert Diseases values
('���������� ����� �� ������� ����� ����','3'),
('������ ����� �������','1'),
('������������ ����������� ����������','2'),
('������������ ��� �������','1'),
('���� ���� �����','3'),
('�������� ������','2');

drop table Departments;
insert Departments values
('1','90000.0','1','�������'),
('2','85000.0','2','��������'),
('3','87000.0','3','����������'),
('4','93000.0','4','����������'),
('5','91000.0','5','������������');

insert Wards values
('1','1','�_1'),
('1','1','�_2'),
('1','1','�_3'),
('1','1','�_4'),
('1','1','�_5'),

('2','2','�_1'),
('2','2','�_2'),
('2','2','�_3'),
('2','2','�_4'),
('2','2','�_5'),

('3','3','�_1'),
('3','3','�_2'),
('3','3','�_3'),
('3','3','�_4'),
('3','3','�_5'),

('4','4','��_1'),
('4','4','��_2'),
('4','4','��_3'),
('4','4','��_4'),
('4','4','��_5'),

('5','5','��_1'),
('5','5','��_2'),
('5','5','��_3'),
('5','5','��_4'),
('5','5','��_5');

--������� ������� ��������� ������ ��� ������ �������� c ����������
create table DiseasesPacients
(
[PacientId] int,
[DiseasesId] int
);
-- ��������� ��������� ����� � ��������� ������ ������
-- Many-to-Many(���� ������� ����� ������ ����������� ���������, 
-- � ����� �������� ����� ������ ��������� ���������)
alter table DiseasesPacients add constraint FK_DiseasesPacients_Pacients_id
		foreign key([PacientId]) references Patients ([Id]);
alter table DiseasesPacients add constraint FK_DiseasesPacients_Diseases_id
		foreign key([DiseasesId]) references Diseases ([Id]);

-- ��������� ������� ���������
insert into DiseasesPacients values
('1','1'),
('2','2'),
('3','3'),
('4','4'),
('5','4'),
('6','5'),
('7','6'),
('8','2'),
('9','1'),
('10','3');

update DiseasesPacients set DiseasesId = 3 where PacientId = 4;
select * from DiseasesPacients;
--=====================================================================
--=====================================================================
						/* -== � 1 ==- */
		-- ������� ���������� ��� ���� ���������, ������-
		-- ����� ���������;
--=====================================================================
-- ����������� ��������� �� ����� � �������
select FirstName +' '+ LastName as FullName from Patients;

-- ����������� ��������� � ������ ���������
select [FirstName] +' '+ [LastName] as FullName,[ReceiptDate],
[DischargeDate], [Name] as Diseases
from Patients p, Diseases d, DiseasesPacients dp
where dp.PacientId = p.Id and dp.DiseasesId = d.Id;
--=====================================================================
--=====================================================================
						/* -== � 2 ==- */
		-- �������� ������ ����������, ������� ����� �����-
		-- �������� ���������;
--=====================================================================
-- ��������� ��������� �� �������:
-- ��� ����� � ������� ��������(Patients) ����� �������� �������
-- ��� ���������� �����
-- ����� ����� One-to-Many, �.� � ����� ������ ����� ������ ���������
-- ���������, � ���� ������� � ���������� ������� ������ �� �����
alter table Patients
add [WardsID] int not null default 1;

-- ������, ��� ����� ������� - ��� ��������� ���� ��� Id �����
alter table Patients
add constraint FK_Patients_to_Wards_Id			-- ���� ��� ���������� �����
foreign key([WardsID]) references Wards([Id]);

-- �������� ������� �� ������� �� ����� ��������
-- ��� ����� ������ ����� �������� ��� ������:
select p.Id, p.FirstName +' '+ p.LastName
as FullName, d.Name as Diseases
from Patients p, Diseases d, DiseasesPacients dp
where dp.PacientId = p.Id 
and dp.DiseasesId = d.Id and d.Id = 6;

-- �������� � Id=1, ������ �������� � Id 1 � 9!
-- �������� �� � ������ � 1  � � 2 (��� ����� � ����)
update Patients set WardsID = 1  where Id = 1;
update Patients set WardsID = 2  where Id = 9;
-- ������� �� ������ ������ ��� ��������
update Patients set WardsID = 2  where Id = 5;
update Patients set WardsID = 2  where Id = 7;
update Patients set WardsID = 7  where Id = 2;
update Patients set WardsID = 7  where Id = 8;
update Patients set WardsID = 15  where Id = 3;
update Patients set WardsID = 15  where Id = 4;
update Patients set WardsID = 15  where Id = 10;
update Patients set WardsID = 21  where Id = 6;

-- ������ �������� ��� ����� �� ������ ������
select p.Id, p.FirstName +' '+ p.LastName
as FullName, w.Name as Ward from Patients p, Wards w where w.Id = p.WardsID and p.WardsID = 2;

-- ������ � ������ ���������� ����� �������� �� ������ ������
select p.Id, p.FirstName +' '+ p.LastName as FullName,
d.Name as Diseases, w.Name as Ward
from Patients p, Diseases d, Wards w, DiseasesPacients dp
where p.WardsID = 2 and w.Id = p.WardsID and dp.PacientId = p.Id and dp.DiseasesId = d.Id;

-- ������ ��������� ������ � �����������
alter table Wards
add [DepartmentsID] int not null default 1;
alter table Wards
add constraint FK_Wards_To_Departmens_Id
foreign key ([DepartmentsID]) references Departments([Id]);

-- ��������� ����� (� ������ ��������� �� 5 �����)
update Wards set DepartmentsID = 1 where id = 1;
update Wards set DepartmentsID = 1 where id = 2;
update Wards set DepartmentsID = 1 where id = 3;
update Wards set DepartmentsID = 1 where id = 4;
update Wards set DepartmentsID = 1 where id = 5;

update Wards set DepartmentsID = 2 where id = 6;
update Wards set DepartmentsID = 2 where id = 7;
update Wards set DepartmentsID = 2 where id = 8;
update Wards set DepartmentsID = 2 where id = 9;
update Wards set DepartmentsID = 2 where id = 10;

update Wards set DepartmentsID = 3 where id = 11;
update Wards set DepartmentsID = 3 where id = 12;
update Wards set DepartmentsID = 3 where id = 13;
update Wards set DepartmentsID = 3 where id = 14;
update Wards set DepartmentsID = 3 where id = 15;

update Wards set DepartmentsID = 4 where id = 16;
update Wards set DepartmentsID = 4 where id = 17;
update Wards set DepartmentsID = 4 where id = 18;
update Wards set DepartmentsID = 4 where id = 19;
update Wards set DepartmentsID = 4 where id = 20;

update Wards set DepartmentsID = 5 where id = 21;
update Wards set DepartmentsID = 5 where id = 22;
update Wards set DepartmentsID = 5 where id = 23;
update Wards set DepartmentsID = 5 where id = 24;
update Wards set DepartmentsID = 5 where id = 25;

-- � ������ ����� ��������� �������
-- ������, ��� ����� � �������
select p.FirstName +' '+ p.LastName as FullName,
d.Name as NameDep, w.Name as Ward
from Patients p, Wards w, Departments d
where d.Name = '�������' and w.DepartmentsID = d.Id and p.WardsID = w.Id;

--=====================================================================
--=====================================================================
						/* -== � 3 ==- */
			-- �������� ������ ����������, ������� ����� �����-
			-- ���� ������ ������, ������������ �� �� ��������-
			-- ��� ���� �����������;
--=====================================================================
-- �������� ������ � ���������, ������� �����
-- � �������� ������ ������, ������������ �� 
-- �� ����������� ���� �����������
select p.Id, p.FirstName +' '+ p.LastName as FullName,
p.ReceiptDate, p.DischargeDate from Patients p
WHERE DATEDIFF(DAY, ReceiptDate,DischargeDate) >= 31
order by ReceiptDate ASC;
--=====================================================================
--=====================================================================
						/* -== � 4 ==- */
			-- ������� ���������� ����������, ������� ����
			-- �������� �������� ������;
--=====================================================================
select p.FirstName+' '+p.LastName as FullName, p.ReceiptDate, p.DischargeDate from Patients p WHERE
DATEDIFF(MONTH, DischargeDate,getdate()) = 1;
--=====================================================================
--=====================================================================
						/* -== � 5 ==- */
			-- �������� ���������� ����������, ������� ����-
			-- �� ��������� �������� �� ������� �������� ����
			-- ������������� ���������;
--=====================================================================
-- ������ ��������� � ������� ���������, ��� �� ��������� 
-- ����� ��������, ������� ������ � ���� ������
update Patients set ReceiptDate = '2020-10-07', DischargeDate = '2020-10-30' where Id = 1;
update Patients set ReceiptDate = '2020-10-25', DischargeDate = '2020-11-14' where Id = 2;
update Patients set ReceiptDate = '2020-11-07', DischargeDate = '2020-11-30' where Id = 3;

-- ���������:
select p.FirstName +' '+ p.LastName as FullName,
 p.ReceiptDate, p.DischargeDate,
d.Name as NameDep, w.Name as Ward
from Patients p, Departments d, Wards w
where month(ReceiptDate) Between 10 and 12
and d.Name = '�������' and w.DepartmentsID = d.Id and p.WardsID = w.Id;

--=====================================================================
--=====================================================================
						/* -== � 6 ==- */
			-- ������� ������ ����������, ������� ����� ����-
			-- �������� ���� ������������ ������������� .
--=====================================================================
-- ��� ���������� ����� ������� ����� ������� �������� � ���������
alter table Diseases
add[DoctorsID] int not null default 1;
alter table Diseases
add constraint FK_Diseases_To_Doctors_Id
foreign key ([DoctorsID]) references Doctors([Id]);
-- ������� ������� ��������
update Diseases set DoctorsID = 1 where id = 1;
update Diseases set DoctorsID = 2 where id = 2;
update Diseases set DoctorsID = 3 where id = 3;
update Diseases set DoctorsID = 4 where id = 4;
update Diseases set DoctorsID = 4 where id = 5;
update Diseases set DoctorsID = 5 where id = 6;

-- ���������:
-- �� ����� �������
/*
select [FirstName] +' '+ [LastName] as FullName,[ReceiptDate],
[DischargeDate], [Name] as Diseases
from Patients p, Diseases d, DiseasesPacients dp
where dp.PacientId = p.Id and dp.DiseasesId = d.Id;
*/
-- ������, ��� ���� ��� �������� � ���������� ������������
-- � ��� ������ ���������� �������, ������� ���� ���������
-- � �������, ������� �� �����:
select p.FirstName +' '+ p.LastName as Patient,
ds.Name as Dissease, d.Name +' '+d.Surname as Doctor
from Patients p, Doctors d, Diseases ds, DiseasesPacients dp
where ds.DoctorsID = d.Id and d.Id = 3 and dp.PacientId = p.Id and dp.DiseasesId = d.Id;

--=====================================================================




select * from Patients;
select * from Doctors;
select * from Diseases;
select * from Departments;
select * from Wards;

--delete from Patients where id = 1;

--drop table Patients;
--drop table Doctors;