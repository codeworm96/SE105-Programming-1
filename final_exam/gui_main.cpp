#include "Window.h"
#include "GUI.h"
#include <string>
#include "gui_main.h"

MainGUI::MainGUI(Point tl)
	:Window(tl, MAXX, MAXY, "SkiArea"),
	l1(Point(0, HEIGHT), "distance:"),
	outd(Point(WIDTH, 0), WIDTH, HEIGHT, ""),
	l2(Point(WIDTH * 2, HEIGHT), "start x:"),
	inx(Point(WIDTH * 3, 0), WIDTH, HEIGHT, ""),
	l3(Point(WIDTH * 4, HEIGHT), "start y:"),
	iny(Point(WIDTH * 5, 0), WIDTH, HEIGHT, ""),
	next1(Point(WIDTH * 6, 0), WIDTH, HEIGHT, "Next1", cb_next1),
	next2(Point(WIDTH * 7, 0), WIDTH, HEIGHT, "Next2", cb_next2),
	ski_area("C:\\SkiResort.txt"),
	sa_gui(Point(100,100),ski_area,50,50),
	sx(0),
	sy(0),
	cx(0),
	cy(0),
	strategy1(new Strategy_greedy(ski_area)),
	strategy2(new Strategy_dp(ski_area))
{
	attach(l1);
	attach(l2);
	attach(l3);
	attach(outd);
	attach(inx);
	attach(iny);
	attach(next1);
	attach(next2);
	attach(sa_gui);
}

void MainGUI::next(Strategy* s)
{
	if (sx != inx.get_int() || sy != iny.get_int()){
		sx = inx.get_int();
		sy = iny.get_int();
		cx = sx;
		cy = sy;
		d = 0;
		sa_gui.set_comment(Pos(sx, sy), "*");
		sa_gui.set_hl(Pos(sx, sy), true);
	}
	else{
		try{
			sa_gui.set_hl(Pos(cx, cy), false);
			Pos p = s->next(Pos(cx, cy));
			cx = p.x;
			cy = p.y;
			++d;
			ostringstream oss;
			oss << d;
			sa_gui.set_comment(Pos(cx, cy), oss.str());
			sa_gui.set_hl(Pos(cx, cy), true);
			outd.put(oss.str());
		}
		catch (Strategy::NoStep){

		}
	}
	redraw();
}