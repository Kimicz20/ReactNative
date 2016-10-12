/*
* 辅助参数类
*用于重写 输入输出重定向 以及两个缓冲区参数
*/
#ifndef SupportClass_class
#define SupportClass_class

#include "Parameter.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>

const int MAXPATHLEN = 100;

class SupportClass
{
  
 public:
  //参数类: 包括两个缓冲区参数
  Parameter supParam;
  
  //插桩路径保存
  string testPath[MAXPATHLEN];
  int index;
  string showPath();
  void cleanPath();

  //输入输出重定向
  const void operator << ( const std::string& ) const;
  const void operator >> ( std::string& ) const;
   void operator >> ( int& ) ;
  const void operator >> ( bool& ) const;
};
#endif
