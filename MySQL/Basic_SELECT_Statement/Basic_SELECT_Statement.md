
## SQL 语句分类

### DDL(data definition language) 数据定义语言

```
CREATE 
ALTER
DROP
RENAME
TRUNCATE
```

### DML(data manipulation language) 数据操作语言

```
INSERT
DELETE
SELECT
UPDATE
```

### DCL(data control language) 数据控制语言

```
COMMIT
ROLLBACK
SAVEPOINT
GRANT
REVOKE
```

## SELECT 语句

```
# 定义：
SELECT 标识选择哪些列
FROM 标识从哪个表中选择

SELECT 字段1, 字段2, 字段3 ...
FROM 标识从哪个表中选择

# 选择全部列
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