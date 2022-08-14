
## 基本规则：
- 每条命令以 ; \g \G, 其中一个结束
- 关键字不能被缩写也不能分行
- 字符串 日期时间 类型的数据使用单引号 '' 包裹
- 列的别名尽量使用双引号 "" 包裹

## 建议规范
- SQL关键字，函数名，绑定变量等都大写 
- 数据库名，表明，表别名，字段名，字段别名等都小写

## 注释符号
- \# 单行注释
- -- 单行注释，必须和注释文件直接有空格间隔
- /* 块注释 */

## 查看所有的数据库

```
show databases;
```

## 创建自己的数据库
```
create database dbtest; // dbtest 不能与已经存在的数据库重名
```

## 使用自己的数据库

```
use dbtest; // 
```

- 说明：如果没有使用use语句，后面针对数据库的操作也没有加“数据名”的限定，那么会报“ERROR 1046
(3D000): No database selected”（没有选择数据库）

- 使用完 use 语句之后，如果接下来的 SQL 都是针对该数据库操作的，那就不用重复use了，如果要针对另一个数据库操作，那么要重新use


## 查看某个库的所有表格

```
show tables; // 要求前面有use语句
show tables from dbtest;
```

## 创建新的表格

- 说明：如果是最后一个字段，后面不用加逗号，因为逗号的作用是分割每个字段

```
create table 表名称(
字段名 数据类型,
字段名 数据类型
);

e.g
// 创建学生表
// 当使用 use dbtest; 时， 创建的 student 表属于 dbtest 数据库
create table student(
id int,
name varchar(20) //说名字最长不超过20个字符
);

```

## 查看一个表的数据

```
select * from 数据库表名称;

#查看 student表 的数据
select * from student;

```

## 往表中添加一条记录

```
insert into 表名称 values(值列表);

#添加两条记录到 student表中
insert into student values(1,'张三');
insert into student values(2,'李四');
```

## 查看表的创建信息

```
show create table 表名称;

#查看student表的详细创建信息
show create table student;
```

## 查看数据库的创建信息

```
show create database 数据库名;

#查看 dbtest 数据库的详细创建信息
show create database dbtest;
```

## 删除表格

```
drop table 表名称;

#删除学生表
drop table student;

```

## 删除数据库

```
drop database 数据库名;

#删除 dbtest 数据库
drop database dbtest;
```