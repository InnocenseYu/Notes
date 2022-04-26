## 调试快捷键的使用

- F9 设置断点与取消断点，配合F5可以使程序在想要的位置停止，进而一步步执行下去；在断点处右击可以设置判断条件，满足断点条件后在该位置停止；
- F5 启动调试，如果有设置断点的话，执行完断点前程序并停在断点处，再次按下F5时，将会在程序逻辑上执行下一步，非物理上下一步；
- ctrl+F5, 开始执行程序不调试；
- F10 step over, 逐过程，通常用来处理一个过程，一个过程可以是一次函数调用，或者是一条语句;
- F11 逐语句，就是每次都执行一条语句，但是这个快捷键可以使我们的执行逻辑进入函数内部（这是最长用的）
- F10 F11 F5，不使用F9设置断点也可以直接使用,断点是为了针对个别语句调试方便；

## 调试展示窗口

- call stack(调用堆栈)：展示函数的调用逻辑。main()函数逻辑运行中依次调用的外部函数，然后再次回到main()函数寻找什么函数中定义的main()函数可被当前main()函数使用；
- memory 内存：查看定义变量的存储区中 地址与存储值内容；
- watch 监视：监视变量在程序运行中值的变化；