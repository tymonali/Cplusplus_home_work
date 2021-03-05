-- 1. Отделения. (Departments)
-- 2. Заболевания (Diseases)
-- 3. Врачи (Doctors)
-- 4. Обследования (Examinations)
-- 5. Палаты (Wards)
-- 6. Patients (Пациенты)

--~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

insert Patients values
('Иван','Прохоров','1971-02-28','2020-12-17','2021-01-08','+38(098)1236532'),
('Денис','Живчик','1989-10-15','2020-12-18','2021-01-14','+38(095)1111111'),
('Вася','Пупкин','2001-04-16','2020-12-18','2021-01-03','+38(095)1211111'),
('Иванов','Петя','2005-10-18','2020-12-19','2021-01-09','+38(066)1111111'),
('Галя','Доярка','1980-08-23','2020-12-19','2021-01-07','+38(063)1111111'),
('Санта','Клаус','1900-01-01','2020-12-25','2021-01-01','+38(067)1472598'),
('Дросида','Кукуцаполь','1949-05-21','2020-12-25','2021-01-21','+38(098)2221541'),
('Никострат','Пофистал','1959-07-08','2021-01-09','2021-02-09','+38(050)7896521'),
('Епихария','Даздрасмыгда','1961-09-19','2021-01-10','','+38(044)8009562'),
('Цитрамон','Диклофенак','1959-07-08','2021-01-11','2021-01-30','+38(056)2589632');

update Patients set DischargeDate = '2021-02-24' where Id = 9;

insert Doctors values
('Анальгин','+38(056)9212587','1000.0','7500.0','Валерьянов'),
('Ацетил','+38(056)7412358','950.0','7500.0','Салецилов'),
('Темпалгин','+38(043)9513571','900.0','7500.0','Аскорбинин'),
('Димедрол','+38(054)3660347','940.0','7500.0','Пургенов'),
('Айболит','+38(028)1583481','970.0','7500.0','Ветеринаров');

insert Diseases values
('Растяжение ногтя на мизинце левой руки','3'),
('Пнутие левой ягодицы','1'),
('Расстройство внутреннего устройства','2'),
('Кардиогенный отёк мошонки','1'),
('Ушиб всей бабки','3'),
('Анальный невроз','2');

drop table Departments;
insert Departments values
('1','90000.0','1','Терапия'),
('2','85000.0','2','Хирургия'),
('3','87000.0','3','Неврология'),
('4','93000.0','4','Психиатрия'),
('5','91000.0','5','Инфекционное');

insert Wards values
('1','1','Т_1'),
('1','1','Т_2'),
('1','1','Т_3'),
('1','1','Т_4'),
('1','1','Т_5'),

('2','2','Х_1'),
('2','2','Х_2'),
('2','2','Х_3'),
('2','2','Х_4'),
('2','2','Х_5'),

('3','3','Н_1'),
('3','3','Н_2'),
('3','3','Н_3'),
('3','3','Н_4'),
('3','3','Н_5'),

('4','4','ПС_1'),
('4','4','ПС_2'),
('4','4','ПС_3'),
('4','4','ПС_4'),
('4','4','ПС_5'),

('5','5','Ин_1'),
('5','5','Ин_2'),
('5','5','Ин_3'),
('5','5','Ин_4'),
('5','5','Ин_5');

--Создаем таблицу вторичных ключей для связки болезней c пациентами
create table DiseasesPacients
(
[PacientId] int,
[DiseasesId] int
);
-- назначаем вторичные ключи к первичным ключам таблиц
-- Many-to-Many(один пациент может болеть несколькими болезнями, 
-- и одной болезнью может болеть несколько пациентов)
alter table DiseasesPacients add constraint FK_DiseasesPacients_Pacients_id
		foreign key([PacientId]) references Patients ([Id]);
alter table DiseasesPacients add constraint FK_DiseasesPacients_Diseases_id
		foreign key([DiseasesId]) references Diseases ([Id]);

-- Назначаем болячки пациентам
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
						/* -== № 1 ==- */
		-- вывести информацию обо всех пациентах, находя-
		-- щихся в больнице;
--=====================================================================
-- Высвечиваем пациентов по имени и фамилии
select FirstName +' '+ LastName as FullName from Patients;

-- Высвечиваем пациентов с ихними болячками
select [FirstName] +' '+ [LastName] as FullName,[ReceiptDate],
[DischargeDate], [Name] as Diseases
from Patients p, Diseases d, DiseasesPacients dp
where dp.PacientId = p.Id and dp.DiseasesId = d.Id;
--=====================================================================
--=====================================================================
						/* -== № 2 ==- */
		-- показать данные о пациентах, которые лежат в опре-
		-- деленном отделении;
--=====================================================================
-- Расселяем пациентов по палатам:
-- Для этого в таблицу Пациенты(Patients) нужно добавить столбец
-- для вторичного ключа
-- Связь будет One-to-Many, т.к в одной палате может лежать несколько
-- пациентов, а один пациент в нескольких палатах лежать не может
alter table Patients
add [WardsID] int not null default 1;

-- Скажем, что новый столбец - это вторичный ключ для Id Палат
alter table Patients
add constraint FK_Patients_to_Wards_Id			-- даем имя вторичному ключу
foreign key([WardsID]) references Wards([Id]);

-- Назначим больных по палатам по ихним болячкам
-- для этого узнаем какие пациенты чем болеют:
select p.Id, p.FirstName +' '+ p.LastName
as FullName, d.Name as Diseases
from Patients p, Diseases d, DiseasesPacients dp
where dp.PacientId = p.Id 
and dp.DiseasesId = d.Id and d.Id = 6;

-- Болезнью с Id=1, болеют пациенты с Id 1 и 9!
-- поселяем их в палату № 1  и № 2 (там мужик и баба)
update Patients set WardsID = 1  where Id = 1;
update Patients set WardsID = 2  where Id = 9;
-- Добавим во вторую палату еще пациента
update Patients set WardsID = 2  where Id = 5;
update Patients set WardsID = 2  where Id = 7;
update Patients set WardsID = 7  where Id = 2;
update Patients set WardsID = 7  where Id = 8;
update Patients set WardsID = 15  where Id = 3;
update Patients set WardsID = 15  where Id = 4;
update Patients set WardsID = 15  where Id = 10;
update Patients set WardsID = 21  where Id = 6;

-- Теперь проверим кто лежит во второй палате
select p.Id, p.FirstName +' '+ p.LastName
as FullName, w.Name as Ward from Patients p, Wards w where w.Id = p.WardsID and p.WardsID = 2;

-- Узнаем с какими диагнозами лежат пациенты во второй палате
select p.Id, p.FirstName +' '+ p.LastName as FullName,
d.Name as Diseases, w.Name as Ward
from Patients p, Diseases d, Wards w, DiseasesPacients dp
where p.WardsID = 2 and w.Id = p.WardsID and dp.PacientId = p.Id and dp.DiseasesId = d.Id;

-- теперь связываем палаты с отделениями
alter table Wards
add [DepartmentsID] int not null default 1;
alter table Wards
add constraint FK_Wards_To_Departmens_Id
foreign key ([DepartmentsID]) references Departments([Id]);

-- Добавляем связи (в каждом отделении по 5 палат)
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

-- А теперь можно выполнить задание
-- Узнаем, кто лежит в терапии
select p.FirstName +' '+ p.LastName as FullName,
d.Name as NameDep, w.Name as Ward
from Patients p, Wards w, Departments d
where d.Name = 'Терапия' and w.DepartmentsID = d.Id and p.WardsID = w.Id;

--=====================================================================
--=====================================================================
						/* -== № 3 ==- */
			-- получить данные о пациентах, которые лежат в боль-
			-- нице больше месяца, отсортировав их по возраста-
			-- нию даты поступления;
--=====================================================================
-- получить данные о пациентах, которые лежат
-- в больнице больше месяца, отсортировав их 
-- по возрастанию даты поступления
select p.Id, p.FirstName +' '+ p.LastName as FullName,
p.ReceiptDate, p.DischargeDate from Patients p
WHERE DATEDIFF(DAY, ReceiptDate,DischargeDate) >= 31
order by ReceiptDate ASC;
--=====================================================================
--=====================================================================
						/* -== № 4 ==- */
			-- вывести информацию о пациентах, которые были
			-- выписаны в прошлом месяце;
--=====================================================================
select p.FirstName+' '+p.LastName as FullName, p.ReceiptDate, p.DischargeDate from Patients p WHERE
DATEDIFF(MONTH, DischargeDate,getdate()) = 1;
--=====================================================================
--=====================================================================
						/* -== № 5 ==- */
			-- показать информацию о пациентах, которые лежа-
			-- ли в больнице с октября по декабрь прошлого года
			-- в определенном отделении;
--=====================================================================
-- Внесем изменения в таблицу пациентов, что бы появились 
-- такие пациенты, которые лежали в этот период
update Patients set ReceiptDate = '2020-10-07', DischargeDate = '2020-10-30' where Id = 1;
update Patients set ReceiptDate = '2020-10-25', DischargeDate = '2020-11-14' where Id = 2;
update Patients set ReceiptDate = '2020-11-07', DischargeDate = '2020-11-30' where Id = 3;

-- Проверяем:
select p.FirstName +' '+ p.LastName as FullName,
 p.ReceiptDate, p.DischargeDate,
d.Name as NameDep, w.Name as Ward
from Patients p, Departments d, Wards w
where month(ReceiptDate) Between 10 and 12
and d.Name = 'Терапия' and w.DepartmentsID = d.Id and p.WardsID = w.Id;

--=====================================================================
--=====================================================================
						/* -== № 6 ==- */
			-- вывести данные о пациентах, которых лечит опре-
			-- деленный врач с одинаковыми заболеваниями .
--=====================================================================
-- Для выполнения этого задания нужно связать докторов с болезнями
alter table Diseases
add[DoctorsID] int not null default 1;
alter table Diseases
add constraint FK_Diseases_To_Doctors_Id
foreign key ([DoctorsID]) references Doctors([Id]);
-- Обновим таблицу Болезней
update Diseases set DoctorsID = 1 where id = 1;
update Diseases set DoctorsID = 2 where id = 2;
update Diseases set DoctorsID = 3 where id = 3;
update Diseases set DoctorsID = 4 where id = 4;
update Diseases set DoctorsID = 4 where id = 5;
update Diseases set DoctorsID = 5 where id = 6;

-- Проверяем:
-- Из этого скрипта
/*
select [FirstName] +' '+ [LastName] as FullName,[ReceiptDate],
[DischargeDate], [Name] as Diseases
from Patients p, Diseases d, DiseasesPacients dp
where dp.PacientId = p.Id and dp.DiseasesId = d.Id;
*/
-- узнаем, что есть три пациента с одинаковым заболеванием
-- И при помощи следующего скрипта, выводим этих пациентов
-- и дохтера, который их лечит:
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