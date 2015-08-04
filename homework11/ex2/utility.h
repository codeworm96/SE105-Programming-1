#ifndef UTILITY_H
#define UTILITY_H

//get rid of the marco
#undef max
#undef min

inline int max(int a, int b)
{
	if (a > b){
		return a;
	}
	else{
		return b;
	}
}

inline int min(int a, int b)
{
	if (a > b){
		return b;
	}
	else{
		return a;
	}
}

inline int wraped_next(int ix, int sz)
{
	++ix;
	if (ix == sz){
		return 0;//wrap
	}
	else{
		return ix;
	}
}

#endif //UTILITY_H