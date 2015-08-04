#ifndef STRATEGY_H
#define STRATEGY_H

#include "ski_area.h"
#include <vector>

struct Pos
{
	int x;
	int y;
	Pos(int xx, int yy) :x(xx), y(yy) {}
};

class Strategy
{
public:
	class NoStep{};
	Strategy(const Ski_area& ski_area) :sa(&ski_area){}
	virtual Pos next(Pos pp) = 0;
protected:
	const Ski_area* get_ski_area(){ return sa; }
private:
	const Ski_area* sa;
};

class Strategy_greedy :public Strategy
{
public:
	Strategy_greedy(const Ski_area& ski_area) :Strategy(ski_area){}
	Pos next(Pos pp);
};

class Strategy_dp :public Strategy
{
public:
	Strategy_dp(const Ski_area& ski_area);
	Pos next(Pos pp);
private:
	const int NaN = -1;
	std::vector<std::vector<int> > memo;
	int f(Pos p);
};


#endif //STRATEGY_H