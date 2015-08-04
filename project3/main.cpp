/*本道题目的题号是：1
*要求是：
修改第7章的计算器程序，令它从输入框获取输入，并将结果返回到输出框。
注意：
a)支持你在Project  1中所完成的计算器的所有功能；
b)使计算器支持两种工作模式：一种是输入一个完整表达式，获取计算结果
第二种是进行即时计算
c)提供一系列的计算器按键，使得用户可以输入表达式；
d)计算器应该至少包括两个文本框：输入框代表了用户输入的计算表达式，输出框显示了计算结果。
*/
#include "calcGUI.h"
#include "Point.h"

using namespace Graph_lib;

int main()
{
	CalcGUI calc(Point(100,100));
	return gui_main();
}
