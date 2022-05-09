## 一些特殊案例

### 程序死循环
- 变量越区操作，导致不可控
- ![变量存储区规划1](../Storage&Variable/stack.png)
- ![变量存储区规划2](../Storage&Variable/stack0.png)
- [栈区的使用](../Storage&Variable/storage&variable.md/#栈区的使用)

### 辗转相除法 (欧几里得算法)
- 求最大公约数 (Greatest common factor/divisor，GCF/GCD)
  - 关于两个数 a b 最大公约数的求法，不需要比较 a b 大小
  - 小数除以大数，商为零，余数是自己
- 求最小公倍数 (Least Common Multiple), LCM(a,b)= (a*b)/HCD(a,b)