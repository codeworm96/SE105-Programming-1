#include "Window.h"
#include "GUI.h"
#include <string>

//Botton size
const int GAP = 4;
const int WIDTH = 50;
const int HEIGHT = 40;

//Window size
const int MAXX = 5 * WIDTH + GAP;
const int MAXY = 8 * HEIGHT + GAP;

class CalcGUI :public Graph_lib::Window
{
public:
	CalcGUI(Point tl);//constructor
private:
	bool mode;//immediately calculate open?
	std::string current;//current input
	std::string ans;//last answer
	//row 1
	Graph_lib::Text status;
	Graph_lib::Button bt_mode;
	Graph_lib::Button bt_off;
	//row 2
	Graph_lib::Button bt_backspace;
	Graph_lib::Button bt_clear;
	Graph_lib::Button bt_ans;
	Graph_lib::Button bt_bracket_l;
	Graph_lib::Button bt_bracket_r;
	//operators
	Graph_lib::Button bt_div;
	Graph_lib::Button bt_mul;
	Graph_lib::Button bt_sub;
	Graph_lib::Button bt_add;

	Graph_lib::Button bt_mod;
	Graph_lib::Button bt_fac;
	Graph_lib::Button bt_equ;
	//number input
	Graph_lib::Button bt_num0;
	Graph_lib::Button bt_num1;
	Graph_lib::Button bt_num2;
	Graph_lib::Button bt_num3;
	Graph_lib::Button bt_num4;
	Graph_lib::Button bt_num5;
	Graph_lib::Button bt_num6;
	Graph_lib::Button bt_num7;
	Graph_lib::Button bt_num8;
	Graph_lib::Button bt_num9;
	Graph_lib::Button bt_dot;
	//output
	Graph_lib::Out_box display;//expression
	Graph_lib::Out_box result;//calculate result
	//call backs
	static void cb_mode(Graph_lib::Address, Graph_lib::Address);
	static void cb_off(Graph_lib::Address, Graph_lib::Address);

	static void cb_backspace(Graph_lib::Address, Graph_lib::Address);
	static void cb_clear(Graph_lib::Address, Graph_lib::Address);
	static void cb_ans(Graph_lib::Address, Graph_lib::Address);
	static void cb_bracket_l(Graph_lib::Address, Graph_lib::Address);
	static void cb_bracket_r(Graph_lib::Address, Graph_lib::Address);

	static void cb_div(Graph_lib::Address, Graph_lib::Address);
	static void cb_mul(Graph_lib::Address, Graph_lib::Address);
	static void cb_sub(Graph_lib::Address, Graph_lib::Address);
	static void cb_add(Graph_lib::Address, Graph_lib::Address);
	static void cb_mod(Graph_lib::Address, Graph_lib::Address);
	static void cb_fac(Graph_lib::Address, Graph_lib::Address);
	static void cb_equ(Graph_lib::Address, Graph_lib::Address);

	static void cb_num0(Graph_lib::Address, Graph_lib::Address);
	static void cb_num1(Graph_lib::Address, Graph_lib::Address);
	static void cb_num2(Graph_lib::Address, Graph_lib::Address);
	static void cb_num3(Graph_lib::Address, Graph_lib::Address);
	static void cb_num4(Graph_lib::Address, Graph_lib::Address);
	static void cb_num5(Graph_lib::Address, Graph_lib::Address);
	static void cb_num6(Graph_lib::Address, Graph_lib::Address);
	static void cb_num7(Graph_lib::Address, Graph_lib::Address);
	static void cb_num8(Graph_lib::Address, Graph_lib::Address);
	static void cb_num9(Graph_lib::Address, Graph_lib::Address);
	static void cb_dot(Graph_lib::Address, Graph_lib::Address);

	void toggle_mode();//change mode
	void append(char c);//append a digit
	void append_op(char c);//append a operator
	void append_add_sub(char c);//with special judge to +/-
	void immediate_calc();
	void clear();//clear input
	void backspace();
	void calculate();
	void add_ans();//append ans to input
};