## goto 语句

### 最常用法
- 终止程序在某些深度嵌套的结构的处理过程，多层循环这种情况使用break是达不到目的

```C
for(...)
    for(...)
    {
        for(...)
        {
            if(disaster)
            goto error;
        }
    }
    …
error:
    if(disaster)
        // 处理错误情况
```