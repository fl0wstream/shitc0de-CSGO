#pragma once

#include "color.h"

class CRender
{
public:

	void DrawF(int X, int Y, CColor Color, int Font, bool Center, char* _Input, ...)
	{
		/* set up buffer */
		char Buffer[1024] = { '\0' };

		/* set up varargs*/
		va_list Args;

		va_start(Args, _Input);
		vsprintf_s(Buffer, _Input, Args);
		va_end(Args);

		size_t Size = strlen(Buffer) + 1;

		/* set up widebuffer*/
		wchar_t* WideBuffer = new wchar_t[Size];

		/* char -> wchar */
		mbstowcs_s(0, WideBuffer, Size, Buffer, Size - 1);

		/* check center */
		int Width = 0, Height = 0;

		if (Center)
		{
			Interfaces.Surface->GetTextSize(Font, WideBuffer, Width, Height);
		}

		/* call and draw*/
		Interfaces.Surface->DrawSetTextColor(Color);
		Interfaces.Surface->DrawSetTextFont(Font);
		Interfaces.Surface->DrawSetTextPos(X - (Width * .5), Y);
		Interfaces.Surface->DrawPrintText(WideBuffer, wcslen(WideBuffer), 0);
	}

	void DrawRect(int X, int Y, int W, int H, CColor Color)
	{
		Interfaces.Surface->SetDrawColor(Color);
		Interfaces.Surface->DrawOutlinedRect(X, Y, X + W, Y + H);
	}

	void DrawFilledRect(int X, int Y, int W, int H, CColor Color)
	{
		Interfaces.Surface->SetDrawColor(Color);
		Interfaces.Surface->DrawFilledRect(X, Y, X + W, Y + H);
	}

	void DrawInlineRect(int X, int Y, int W, int H, CColor Color)
	{
		DrawRect(X, Y, W, H, Color);
		DrawRect(X + 1, Y + 1, W - 2, H - 2, CColor(0, 0, 0, 255));
		DrawRect(X - 1, Y - 1, W + 2, H + 2, CColor(0, 0, 0, 255));
	}

	void DrawShadowText(int X, int Y, CColor Color, int Font, bool Center, char* _Input, ...) 
	{
		DrawF(X + 1, Y + 1, CColor(0, 0, 0, 150), Font, Center, _Input);
		DrawF(X, Y, Color, Font, Center, _Input);
	}

}; CRender;

CRender * g_pRender;