#pragma once;


const string TCHARToString(const TCHAR * str);

bool IsRectCollision(const RECT & re01, const RECT & re02);

bool IsPointCollision(const RECT & re, const POINT & point);

int randomRange(int min, int max);