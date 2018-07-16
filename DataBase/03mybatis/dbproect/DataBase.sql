create table users(
       id int auto_increment primary key ,
       name varchar(20) not null,
       gender varchar(5) not null,
       email varchar(10) not null,
       clsid int not null
       
);

create table classes(
       id int primary key,
       name varchar(10) not null
);



insert into users values(1,'Zhang','F','123@qq.com',1);
insert into users values(null,'LI','M','123@qq.com',2);
insert into users values(null,'TOM','M','123@qq.com',3);
insert into users values(null,'JAY','F','123@qq.com',1);
insert into users values(null,'Andy','M','123@qq.com',2);
insert into users values(null,'james','F','123@qq.com',3);
insert into users values(null,'Kobe','M','123@qq.com',1);
insert into users values(null,'YI','F','123@qq.com',2);
insert into users values(null,'YAO','M','123@qq.com',3);
insert into users values(null,'YIN','F','123@qq.com',1);
commit;

insert into classes values(1,'S1');
insert into classes values(2,'S2');
insert into classes values(3,'Y2');
commit;




