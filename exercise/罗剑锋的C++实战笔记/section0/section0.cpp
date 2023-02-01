#include "section0.h"

namespace section0
{
	void test() {
		cout << "c++ version = " << __cplusplus << endl;

		cout << "gcc version = " << __VERSION__ << endl;

		cout << "gcc major = " << __GNUC__ << endl;
		cout << "gcc minor = " << __GNUC_MINOR__ << endl;
		cout << "gcc patch = " << __GNUC_PATCHLEVEL__ << endl;

		// check __GLIBCXX__ for macos
#ifndef __GLIBCXX__
#   define __GLIBCXX__ "unkown version,please check or config your gcc path,or your OS not surpport."
#endif

		cout << "libstdc++ = " << __GLIBCXX__ << endl;
	}

	template<int N>
	struct fib
	{
		static const unsigned long long int value = fib<N - 1>::value + fib<N - 2>::value;
	};
	template<>
	struct fib<0>
	{
		static const unsigned long long int value = 1;
	};

	template<>
	struct fib<1>
	{
		static const unsigned long long int value = 1;
	};

	void test2() {
		cout << fib<2>::value << endl;
		cout << fib<3>::value << endl;
		cout << fib<4>::value << endl;
		cout << fib<5>::value << endl;
		cout << fib<6>::value << endl;
		cout << fib<900>::value << endl;
	}

	void main() {
//		test();
		test2();

	}
}
