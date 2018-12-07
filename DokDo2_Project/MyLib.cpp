#include "DXUT.h"
#include "MyLib.h"

const string TCHARToString(const TCHAR * str)
{
	int len = wcslen(str);
	int clen = len * 2 + 1;

	char * _str = new char[clen];

	wcstombs(_str, str, clen);

	string t = _str;

	delete[] _str;
	_str = nullptr;

	return t;
}

bool IsRectCollision(const RECT & re01, const RECT & re02)
{
	if ((re01.left < re02.right) && (re01.right > re02.left) && (re01.top < re02.bottom) && (re01.bottom > re02.top))
		return true;

	return false;
}

bool IsPointCollision(const RECT & re, const POINT & point)
{
	if ((re.left < point.x && re.right > point.x) && (re.top < point.y && re.bottom > point.y))
		return true;

	return false;
}

int randomRange(int min, int max)
{
	if (max == 0)
		return -1;
	return (int)(rand() % (max - min + 1) + min);

}
