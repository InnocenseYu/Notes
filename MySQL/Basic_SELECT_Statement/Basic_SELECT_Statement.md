
## SQL 语句分类

### DDL(data definition language) 数据定义语言

```mysql
CREATE 
ALTER
DROP
RENAME
TRUNCATE
```

### DML(data manipulation language) 数据操作语言

```mysql
INSERT
DELETE
SELECT
UPDATE
```

### DCL(data control language) 数据控制语言

```mysql
COMMIT
ROLLBACK
SAVEPOINT
GRANT
REVOKE
```

## SELECT 语句

- 建议 SELECT 一行，FROM 一行，因为select 语句比较长，排版舒服 

### 使用方式定义
```
SELECT 标识选择哪些列
FROM 标识从哪个表中选择

SELECT 字段1, 字段2, 字段3 ...
FROM 标识从哪个表中选择
```

### 选择全部列
```
SELECT *
FROM 标识从哪个表中选择
```

> 一般情况下，除非需要使用表中所有的字段数据，最好不要使用通配符 '*'。
> 
> 使用通配符虽然可以节省输入查询语句的时间，但是获取不需要的列数据通常会降低查询和所使用的应用程序的效率。
> 
> 通配符的优势是，当不知道所需要的列的名称时，可以通过它获取它们。
> 
> 在生产环境下，不推荐直接使用 SELECT * 进行查询。


### 列的别名
- 方式1，字段名和别名间使用**空格**
- 方式2，字段名和别名间使用**AS**, 全称是 alias
- 方式3，如何别名有空格，防止歧义，标准规定使用 "" 

```mysql
SELECT employee_id emp_id, last_name AS lname, department_id "dp id"
FROM employees;
```

### 去除重复行
- 

```mysql
SELECT DISTINCT department_id
FROM employees;

// 错误演示, 报错
SELECT salary, DISTINCT department_id 
FROM employees;

// 虽然没有报错，但是不建议，操作没有意义
SELECT DISTINCT salary, department_id 
FROM employees;
```

### 空值参与运算

- 空值 - null
- null 不等同与 0 或者 ''
- null 相当于 什么也没有，不知它是啥
- 空值参与运算，结果也是空值

```mysql
SELECT employee_id, salary "月工资"，salary * (1 + commission_pct) * 12 "年工资", commission_pct
FROM employees;
```

### 着重号 ``

- 不是单引号 ''
- 当表名与保留关键字一致时，需要使用着重号包裹

```mysql
SELECT * FROM `order`; 

```

### 查询常数

- 当需要查询的常数不存在与表中时，但是又需要使用它，可以在用 select 查询时使用 单引号'' 包裹，生产一列同列名一样的字段

```mysql
// 李明 18 就是查询常数，不存在于 employees 表格，会生成同名的字段
SELECT '李明', 18, employee_id, last_name
FORM employees;
```

### 显示表的结构

- 不同于 show db; show tables from db; 这里是显示某个具体表格的描述
```mysql
describe employees;
// or
desc employees;

```

### 过滤数据 WHERE

1. 开启 结果集
2. 从中过滤

```mysql
SELECT * 
FROM employees 
WHERE department_id = 90;
```