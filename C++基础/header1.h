#pragma  once
//namespace 命名空间名称  {}
//命名空间作用域
//命名空间： 解决命名冲突
namespace header1
{
	int global = 100;
	//嵌套定义
	namespace internal
	{
		int var = 10;
	}

	void fun2()
	{

	}
}

namespace header1
{
	int var2;
	void fun3()
	{

	}
}



