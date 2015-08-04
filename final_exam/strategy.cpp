#include "ski_area.h"
#include "strategy.h"
#include <vector>

//direction
const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };

Pos Strategy_greedy::next(Pos pp)
{
	bool step_left = false;
	Pos p = pp;
	for (int i = 0; i < 4; ++i){
		if (get_ski_area()->get_height(pp.x, pp.y) > get_ski_area()->get_height(pp.x + dx[i], pp.y + dy[i])){
			if ((!step_left) || (get_ski_area()->get_height(pp.x + dx[i], pp.y + dy[i]) > get_ski_area()->get_height(p.x, p.y))){
				p = Pos(pp.x + dx[i], pp.y + dy[i]);
				step_left = true;
			}
		}
	}
	if (!step_left){
		throw NoStep();
	}
	return p;
}

Strategy_dp::Strategy_dp(const Ski_area& ski_area) :Strategy(ski_area)
{
	int r = get_ski_area()->get_r();
	int c = get_ski_area()->get_c();
	memo.resize(r);
	for (int i = 0; i < r; ++i){
		memo[i].resize(c);
		for (int j = 0; j < c; ++j){
			memo[i][j] = NaN;
		}
	}
	for (int i = 0; i < r; ++i){
		for (int j = 0; j < c; ++j){
			f(Pos(i + 1, j + 1));
		}
	}
}

int Strategy_dp::f(Pos p)
{
	if (memo[p.x - 1][p.y - 1] != NaN){
		return memo[p.x - 1][p.y - 1];
	}
	memo[p.x - 1][p.y -1] = 0;
	for (int i = 0; i < 4; ++i){
		if (get_ski_area()->get_height(p.x, p.y) > get_ski_area()->get_height(p.x + dx[i], p.y + dy[i])){
			if (f(Pos(p.x + dx[i], p.y + dy[i])) + 1 > memo[p.x - 1][p.y - 1]){
				memo[p.x - 1][p.y - 1] = f(Pos(p.x + dx[i], p.y + dy[i])) + 1;
			}
		}
	}
	return memo[p.x - 1][p.y - 1];
}
Pos Strategy_dp::next(Pos pp)
{
	bool step_left = false;
	Pos p = pp;
	for (int i = 0; i < 4; ++i){
		if (get_ski_area()->get_height(pp.x, pp.y) > get_ski_area()->get_height(pp.x + dx[i], pp.y + dy[i])){
			if ((!step_left) || (f(Pos(pp.x + dx[i], pp.y + dy[i])) > f(p))){
				p = Pos(pp.x + dx[i], pp.y + dy[i]);
				step_left = true;
			}
		}
	}
	if (!step_left){
		throw NoStep();
	}
	return p;
}