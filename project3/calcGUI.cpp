#include "calcGUI.h"
#include "calc.h"
#include <sstream>
#include <stdexcept>
#include <cctype>

CalcGUI::CalcGUI(Point tl)
	:Window(tl, MAXX, MAXY, "Calculator"),
	//last row
	bt_num0(Point(GAP, y_max() - HEIGHT), WIDTH * 2 - GAP, HEIGHT - GAP, "0", cb_num0),
	bt_dot(Point(GAP + WIDTH * 2, y_max() - HEIGHT), WIDTH - GAP, HEIGHT - GAP, ".", cb_dot),
	bt_add(Point(GAP + WIDTH * 3, y_max() - HEIGHT), WIDTH - GAP, HEIGHT - GAP, "+", cb_add),
	bt_equ(Point(GAP + WIDTH * 4, y_max() - HEIGHT * 2), WIDTH - GAP, HEIGHT * 2 - GAP, "=", cb_equ),
	//row 5
	bt_num1(Point(GAP, y_max() - HEIGHT * 2), WIDTH - GAP, HEIGHT - GAP, "1", cb_num1),
	bt_num2(Point(GAP + WIDTH, y_max() - HEIGHT * 2), WIDTH - GAP, HEIGHT - GAP, "2", cb_num2),
	bt_num3(Point(GAP + WIDTH * 2, y_max() - HEIGHT * 2), WIDTH - GAP, HEIGHT - GAP, "3", cb_num3),
	bt_sub(Point(GAP + WIDTH * 3, y_max() - HEIGHT * 2), WIDTH - GAP, HEIGHT - GAP, "-", cb_sub),
	//row 4
	bt_num4(Point(GAP, y_max() - HEIGHT * 3), WIDTH - GAP, HEIGHT - GAP, "4", cb_num4),
	bt_num5(Point(GAP + WIDTH, y_max() - HEIGHT * 3), WIDTH - GAP, HEIGHT - GAP, "5", cb_num5),
	bt_num6(Point(GAP + WIDTH * 2, y_max() - HEIGHT * 3), WIDTH - GAP, HEIGHT - GAP, "6", cb_num6),
	bt_mul(Point(GAP + WIDTH * 3, y_max() - HEIGHT * 3), WIDTH - GAP, HEIGHT - GAP, "*", cb_mul),
	bt_fac(Point(GAP + WIDTH * 4, y_max() - HEIGHT * 3), WIDTH - GAP, HEIGHT - GAP, "!", cb_fac),
	//row 3
	bt_num7(Point(GAP, y_max() - HEIGHT * 4), WIDTH - GAP, HEIGHT - GAP, "7", cb_num7),
	bt_num8(Point(GAP + WIDTH, y_max() - HEIGHT * 4), WIDTH - GAP, HEIGHT - GAP, "8", cb_num8),
	bt_num9(Point(GAP + WIDTH * 2, y_max() - HEIGHT * 4), WIDTH - GAP, HEIGHT - GAP, "9", cb_num9),
	bt_div(Point(GAP + WIDTH * 3, y_max() - HEIGHT * 4), WIDTH - GAP, HEIGHT - GAP, "/", cb_div),
	bt_mod(Point(GAP + WIDTH * 4, y_max() - HEIGHT * 4), WIDTH - GAP, HEIGHT - GAP, "%", cb_mod),
	//row2
	bt_backspace(Point(GAP, y_max() - HEIGHT * 5), WIDTH - GAP, HEIGHT - GAP, "<-", cb_backspace),
	bt_clear(Point(GAP + WIDTH, y_max() - HEIGHT * 5), WIDTH - GAP, HEIGHT - GAP, "clear", cb_clear),
	bt_ans(Point(GAP + WIDTH * 2, y_max() - HEIGHT * 5), WIDTH - GAP, HEIGHT - GAP, "Ans", cb_ans),
	bt_bracket_l(Point(GAP + WIDTH * 3, y_max() - HEIGHT * 5), WIDTH - GAP, HEIGHT - GAP, "(", cb_bracket_l),
	bt_bracket_r(Point(GAP + WIDTH * 4, y_max() - HEIGHT * 5), WIDTH - GAP, HEIGHT - GAP, ")", cb_bracket_r),
	//row 1
	bt_mode(Point(GAP, y_max() - HEIGHT * 6), WIDTH - GAP, HEIGHT - GAP, "Mode", cb_mode),
	bt_off(Point(GAP + WIDTH * 4, y_max() - HEIGHT * 6), WIDTH - GAP, HEIGHT - GAP, "OFF", cb_off),

	display(Point(GAP, GAP), x_max() - 2 * GAP, y_max() - HEIGHT * 7 - GAP, ""),//display expression
	result(Point(GAP, GAP + HEIGHT), x_max() - 2 * GAP, y_max() - HEIGHT * 7 - GAP, ""),//calculate result
	status(Point(GAP * 3 + WIDTH, y_max() - HEIGHT * 6 + GAP * 6), "normal")//mode
{
	//attach widgets
	attach(bt_mode);
	attach(bt_off);
	attach(bt_backspace);
	attach(bt_clear);
	attach(bt_ans);
	attach(bt_bracket_l);
	attach(bt_bracket_r);

	attach(bt_num7);
	attach(bt_num8);
	attach(bt_num9);
	attach(bt_div);
	attach(bt_mod);

	attach(bt_num4);
	attach(bt_num5);
	attach(bt_num6);
	attach(bt_mul);
	attach(bt_fac);

	attach(bt_num1);
	attach(bt_num2);
	attach(bt_num3);
	attach(bt_sub);

	attach(bt_num0);
	attach(bt_dot);
	attach(bt_add);
	attach(bt_equ);

	attach(display);
	attach(result);
	attach(status);

	//default settings
	mode = false;
	current = "";
	ans = "0";
}

void CalcGUI::cb_mode(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).toggle_mode();//mode change
}

void CalcGUI::cb_off(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).hide();//quit
}

void CalcGUI::cb_backspace(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).backspace();
}

void CalcGUI::cb_clear(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).clear();
}

void CalcGUI::cb_ans(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).add_ans();
}

//brackets
void CalcGUI::cb_bracket_l(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).append('(');
}

void CalcGUI::cb_bracket_r(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).append(')');
}

//operators
void CalcGUI::cb_div(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).append_op('/');
}
void CalcGUI::cb_mul(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).append_op('*');
}

void CalcGUI::cb_sub(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).append_add_sub('-');
}
void CalcGUI::cb_add(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).append_add_sub('+');
}
void CalcGUI::cb_mod(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).append_op('%');
}
void CalcGUI::cb_fac(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).append_op('!');
}
void CalcGUI::cb_equ(Graph_lib::Address, Graph_lib::Address pw)//=
{
	Graph_lib::reference_to<CalcGUI>(pw).calculate();
}

//digits input
void CalcGUI::cb_num0(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).append('0');
}

void CalcGUI::cb_num1(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).append('1');
}

void CalcGUI::cb_num2(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).append('2');
}
void CalcGUI::cb_num3(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).append('3');
}

void CalcGUI::cb_num4(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).append('4');
}

void CalcGUI::cb_num5(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).append('5');
}

void CalcGUI::cb_num6(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).append('6');
}

void CalcGUI::cb_num7(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).append('7');
}

void CalcGUI::cb_num8(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).append('8');
}

void CalcGUI::cb_num9(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).append('9');
}

void CalcGUI::cb_dot(Graph_lib::Address, Graph_lib::Address pw)
{
	Graph_lib::reference_to<CalcGUI>(pw).append('.');
}

void CalcGUI::toggle_mode()
{
	mode = !mode;//switch mode
	current = "";//clear input
	result.put("");//clear result
	if (mode){
		//no bracket
		bt_bracket_l.hide();
		bt_bracket_r.hide();

		status.set_label("immediate");
	}
	else{
		//show bracket
		bt_bracket_l.show();
		bt_bracket_r.show();

		status.set_label("normal");
	}
	//update
	display.put(current);
	redraw();
}

void CalcGUI::append(char c)
{
	current += c;
	//update
	display.put(current);
	result.put("");//clear result
	redraw();
}

void CalcGUI::immediate_calc()
{
	if (mode){//only when immediately calculate on
		Calculator calc(current);
		double res = calc.eval();
		//convert to string
		std::ostringstream oss;
		oss.precision(8);
		oss << res;
		current = oss.str();
	}
}

void CalcGUI::append_op(char c)
try{
	immediate_calc();

	current += c;
	//update
	display.put(current);
	result.put("");//clear result
	redraw();
}
//show error
catch(std::runtime_error& e){
	display.put(current);
	result.put(std::string("Error: ") + e.what());
	redraw();
	current = "";
}

void CalcGUI::append_add_sub(char c)
try{
	if ((!current.empty()) && (isdigit(current[current.size() - 1]) || (current[current.size() - 1] == '!'))){
		immediate_calc();
	}

	current += c;
	//update
	display.put(current);
	result.put("");//clear result
	redraw();
}
//show error
catch (std::runtime_error& e){
	display.put(current);
	result.put(std::string("Error: ") + e.what());
	redraw();
	current = "";
}

void CalcGUI::clear()
{
	current = "";
	//update
	display.put(current);
	result.put("");//clear result
	redraw();
}

void CalcGUI::backspace()
{
	current = current.substr(0, current.size() - 1);
	//update
	display.put(current);
	result.put("");//clear result
	redraw();
}

void CalcGUI::calculate()
try{
	Calculator calc(current);
	double res = calc.eval();
	//convert to string
	std::ostringstream oss;
	oss.precision(8);
	oss << res;
	ans = oss.str();

	result.put(ans);
	redraw();
	current = "";
}
//show error
catch (std::runtime_error& e){
	display.put(current);
	result.put(std::string("Error: ") + e.what());
	redraw();
	current = "";
}

void CalcGUI::add_ans()
{
	current += ans;
	//update
	display.put(current);
	result.put("");//clear result
	redraw();
}
