//#include "ski_area.h"
//#include "strategy.h"
//#include <iostream>
//using namespace std;
//
//int main()
//try{
//	Ski_area sa("C:\\SkiResort.txt");
//	cout << sa.get_r() << sa.get_c();
//	for (int i = 0; i <= sa.get_r() + 1; ++i){
//		for (int j = 0; j <= sa.get_c() + 1; ++j){
//			cout << sa.get_height(i, j) << ' ';
//		}
//		cout << endl;
//	}
//	cout << endl;
//	Pos p(3, 3);
//	Strategy* st = new Strategy_dp(sa);
//	try{
//		while (true){
//			cout << p.x << ' ' << p.y << endl;
//			p = st->next(p);
//		}
//	}
//	catch (Strategy::NoStep){
//		cout << "end" << endl;
//	}
//	cin.get();
//}
//catch (...){
//	cerr << "some error" << endl;
//	cin.get();
//	return 1;
//}