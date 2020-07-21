# include "hello_Cpp.h"
# include <string>
using namespace std;

bool isShorter(const string s1, const string s2)
{
	return s1.length() < s2.length();
}