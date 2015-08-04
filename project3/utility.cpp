#include  "utility.h"
#include <stdexcept>

namespace math
{
	int factorial(int n)
	{
		if (n < 0){
			throw std::runtime_error("invalid factorial");
		}
		long long product = 1;
		int res = 1;
		for (int i = 1; i <= n; ++i){
			product *= i;
			res = product;
			if (res != product){
				throw std::runtime_error("too large factorial");
			}
		}
		res = product;
		return res;
	}
}
