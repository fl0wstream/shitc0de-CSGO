#pragma once

#include "sdk.h"

class CColor
{
public:

	unsigned char _RGBA[4];

	CColor(int R, int G, int B, int A)
	{
		_RGBA[0] = (unsigned char)R;
		_RGBA[1] = (unsigned char)G;
		_RGBA[2] = (unsigned char)B;
		_RGBA[3] = (unsigned char)A;
	}
};