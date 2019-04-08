# attack-area
In this demo, you will learn how to plot with visual C++ and how to make and use DLL. This demo is not depend on MFC,but on console program.
## DLL
### Basic knowledge about DLL
动态链接库(DLL，Dynamic Link Library)是在程序执行时，被动态地装载运行以完成一些通用功能的代码集合。它也是**可执行文件**，但不能像exe文件一样直接运行，而是**为其他可执行文件提供共享代码的库**。另外一种提供共享代码的方式是静态链接库，两者的区别是使用方法不同。
<br>源程序要形成可执行文件要经过编译（Compile）和链接（Link）两个阶段。库文件的使用在链接阶段。如果采用静态链接库方式，库文件（lib）中的指令被直接包含在最终生成的exe文件中。如果使用动态链接库，库文件（dll）不必被包含在最终的exe文件中，可执行文件在执行时可以动态地引用和卸载该DLL文件。另外静态链接库中不能再包含其他lib或DLL，但是动态链接库中可以包含。
<br>此处应插入一流程图解释说明静态链接库和动态链接库的区别
### Characteristic of DLL
* DLL扩展了应用程序的特性
* DLL的编写与具体的编程语言及编译器无关
* DLL的使用有助于节省内存
* 有助于资源的共享
* 有助于隐藏细节，保护技术机密
### Classify
* Non-MFC DLL(非MFC动态链接库)
<br>不采用MFC类库结构，导出的函数为标准的C接口。能被非MFC或MFC编写的应用程序调用。
* MFC Regular DLL(MFC规则动态库)
<br>
