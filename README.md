# attack-area
In this demo, Firstly, you will learn how to plot with visual C++ . This is simple since only two functions are used. Secondly, the process of attack area formula push down is a little complex, however the code is simple. So in many situations, we need make DLL to protect the core idea. Then you will learn how to make and use DLL. This demo is not depend on MFC,but on console program. At last, I note some about the algorithm of attack area.  This concept is about Air-to Air missile.
<br>This is the second time I wirte study notes on github. The details are oversimplified and I know little as a primary. But I will try to record as detailedly as I can. Just for study. Just for improvement. Just for fun.
[DLL](##DLL)
[GDI绘图](##GDI绘图)
[attack area](##attack area)
## DLL
### Basic knowledge about DLL
动态链接库(DLL，Dynamic Link Library)是在程序执行时，被动态地装载运行以完成一些通用功能的代码集合。它也是**可执行文件**，但不能像exe文件一样直接运行，而是**为其他可执行文件提供共享代码的库**。另外一种提供共享代码的方式是静态链接库，两者的区别是使用方法不同。
<br>
<br>源程序要形成可执行文件要经过编译（Compile）和链接（Link）两个阶段。库文件的使用在链接阶段。如果采用静态链接库方式，库文件（lib）中的指令被直接包含在最终生成的exe文件中。如果使用动态链接库，库文件（dll）不必被包含在最终的exe文件中，可执行文件在执行时可以动态地引用和卸载该DLL文件。另外静态链接库中不能再包含其他lib或DLL，但是动态链接库中可以包含。
<br>
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
<br>采用MFC类库编写，源文件中包含一个继承自CWinApp的类，但没有消息循环。可以分为静态链接到MFC库的规则DLL和动态链接倒MFC库的规则DLL。不能导出MFC类及其派生类。
* MFC Extension DLL(MFC扩展DLL)
<br>只能被用MFC类库所写的应用程序调用。支持C++接口，即可以导出定义其内的类。
### 导出函数
DLL中的函数可以分为两种：导出函数和DLL内的函数。其中前者可以被应用程序调用，而后者只能在DLL程序中使用。DLL中导出函数的声明有两种：
* 在定义函数时**使用_declspec(dllexport)关键字**
* 创建**模块定义文件(.def)**，把导出函数名加入模块定义文件中。
<br>
<br>本此demo中使用第一种方法；
<br>针对于第二种方法：
<br>
```
; demoDll.def:导出DLL函数。在.def文件中，注释以;开始
LIBRARY "demoDll"  //动态链接库库名
DISCRIPTION "实现一个Win32动态库"
EXPORTS
      myplot @1   //导出函数名，@1表示指定函数序列号
```
<br>
### DLL调用
两种调用方式：显式链接和隐式链接
* **显式链接：**利用代码显示加载DLL，编译器不需要知道关于DLL的任何信息，比较灵活；
* **隐式链接：**通过编译器提供给应用程序和关于DLL的名称DLL函数的链接地址，不需显式加载，方法简单，但缺少灵活性；
<br>
* 显式链接
过程如下：
<br>LoadLibrary->GetProcAddress->FreeLibray
<br>加载->获取DLL函数地址->释放
<br>示例代码如下：
```
//UseWinerDll.cpp
#include "iostream.h"
#include <stdio.h>
#include "Windows.h"
typedef float (*TheCalculate)(float,float,int); //宏定义calculate函数指针类型
int main()
{
  HINSTANCE hdll;  //DLL句柄
  TheCalculate calfunc;  //函数指针
  hdll=LoadLibrary("..\\debug\\Win32DLL.dll");
  if(hdll!=NULL)
  {
    calfunc=(TheCalculate)GetProcAddress(hdll,"calculate");
  }
  float x,y;
  int type;
  cout<<"Please input x to compute:\n";
  cin>>x;
  cout<<"Please input y to compute:\n";
  cin>>y;
  cout<<"Please input opreation type(0:add 1:sub 2:mul 3:div):\n";
  cin>>type;
  float result=calfunc(x,y,type);
  FreeLibrary(hdll);
  cout<<"The compute result is:\n"<<result<<endl;
  return 0;
}
```
<br>
* 隐式链接
```
#pragma comment(lib,"Win32dll.lib")
extern _declspec(dllimport) float calculate(float x,float y,int type);
```
<br>
## GDI绘图
利用MoveToEx()和LineTo()函数。需要注意的是屏幕坐标定义方式。
<br>如果单从函数图像绘制角度来讲，matlab才是更好的工具，而且作为数学专业的我，对此更为熟悉。对于任何函数，只消两三行代码就可以画出完美的函数图像。如果想用C++调用的话，可以利用matlab生成动态库（mcc -W cpplib:LibFileName -T link:lib fileName.m）。但是工作中，就要按领导要求来做了，作为尝试和学习，也挺好的。
<br>
## attack area
