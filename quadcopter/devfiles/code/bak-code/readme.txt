【1】freeRTOSDemo
---来自freeRTOS8.2.1(内含STM32F10x标准库v0.2,无CMSIS)。
---编译环境：IAR EWARM V7.10。

功能：
交替闪烁PB5上连接的LED（0-ON,1-OFF）。


【2】myCrazyflie_1
---来自STM32F10x标准库v3.5.0(内含CMSIS V1.3.0)。
---编译环境：IAR EWARM V7.10。

功能：
交替闪烁PB4和PB5上连接的两个LED（0-ON,1-OFF）。

【3】myCrazyflie_2
---来自STM32F10x标准库v3.5.0(内含CMSIS V1.3.0)。
---编译环境：IAR EWARM V7.10。

功能：
添加了freeRTOS8.2.1.
交替闪烁PB5上连接的LED（0-ON,1-OFF）。

【4】crazyflie-firm
crazyflie工程更改：
- GCC-IAR 7.10;
- freeRTOS 7.4.0->8.2.1;
- stdPeriph_Driver 3.1.2->3.5.0

crazyflie在IAR的debug下，编译没有错误，有34个warning，可以通过J-Link下载，调试。
中断等均正常。
等待来自无线的控制指令。



