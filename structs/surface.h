#include "color.h"

class CSurface
{
public:

	void SetDrawColor(int r, int g, int b, int a)
	{
		typedef void(__thiscall* Fn)(void*, int, int, int, int);
		return ((Fn)VMT.GetFunction(this, indexes::SetDrawColor))(this, r, g, b, a);
	}

	void SetDrawColor(CColor color)
	{
		typedef void(__thiscall* Fn)(void*, CColor);
		return ((Fn)VMT.GetFunction(this, 14))(this, color);
	}

	void DrawFilledRect( int x, int y, int x2, int y2 )
	{
		typedef void(__thiscall* Fn)(void*, int, int, int, int);
		return ((Fn)VMT.GetFunction(this, indexes::DrawFilledRect))(this, x, y, x2, y2);
	}

	void DrawOutlinedRect( int x, int y, int x2, int y2 )
	{
		typedef void(__thiscall* Fn)(void*, int, int, int, int);
		return ((Fn)VMT.GetFunction(this, indexes::DrawOutlinedRect))(this, x, y, x2, y2);
	}

	bool GetTextSize(int Font, const wchar_t* _Input, int& Wide, int& Tall)
	{
		typedef bool(__thiscall* Fn)(void*, int, const wchar_t*, int&, int&);
		return ((Fn)VMT.GetFunction(this, 79))(this, Font, _Input, Wide, Tall);
	}

	void DrawLine( int x, int y, int x2, int y2 )
	{
		typedef void(__thiscall* Fn)(void*, int, int, int, int);
		return ((Fn)VMT.GetFunction(this, indexes::DrawLine))(this, x, y, x2, y2);
	}

	unsigned int SCreateFont()
	{
		typedef unsigned int(__thiscall* Fn)(void*);
		return ((Fn)VMT.GetFunction(this, indexes::SCreateFont))(this);
	}
	
	bool SetFontGlyphSet(unsigned int font, const char *windowsFontName, int tall, int weight, int blur, int scanlines, int flags, int nRangeMin = 0, int nRangeMax = 0)
	{
		typedef bool(__thiscall* Fn)(void*, unsigned int, const char*, int, int, int, int, int, int, int);
		return ((Fn)VMT.GetFunction(this, indexes::SetFontGlyphSet))(this, font, windowsFontName, tall, weight, blur, scanlines, flags, nRangeMin, nRangeMax);
	}
	void DrawSetTextFont(unsigned int Font)
	{
		typedef void(__thiscall* Fn)(void*, unsigned int);
		return ((Fn)VMT.GetFunction(this, indexes::DrawSetTextFont))(this, Font);
	}

	void DrawSetTextColor(int r, int g, int b, int a)
	{
		typedef void(__thiscall* Fn)(void*, int, int, int, int);
		return ((Fn)VMT.GetFunction(this, indexes::DrawSetTextColor))(this, r, g, b, a);
	}

	void DrawSetTextPos( int x, int y )
	{
		typedef void(__thiscall* Fn)(void*, int, int);
		return ((Fn)VMT.GetFunction(this, indexes::DrawSetTextPos))(this, x, y);
	}

	void DrawPrintText(const wchar_t* Text, int Len, int DrawType = 0)
	{
		typedef void(__thiscall* Fn)(void*, wchar_t const*, int, int);
		return ((Fn)VMT.GetFunction(this, indexes::DrawPrintText))(this, Text, Len, DrawType);
	}

	void DrawSetTextColor(CColor Color)
	{
		typedef void(__thiscall* Fn)(void*, CColor);
		return ((Fn)VMT.GetFunction(this, 24))(this, Color);
	}

};
enum EFontFlags
{
	FONTFLAG_NONE,
	FONTFLAG_ITALIC = 0x001,
	FONTFLAG_UNDERLINE = 0x002,
	FONTFLAG_STRIKEOUT = 0x004,
	FONTFLAG_SYMBOL = 0x008,
	FONTFLAG_ANTIALIAS = 0x010,
	FONTFLAG_GAUSSIANBLUR = 0x020,
	FONTFLAG_ROTARY = 0x040,
	FONTFLAG_DROPSHADOW = 0x080,
	FONTFLAG_ADDITIVE = 0x100,
	FONTFLAG_OUTLINE = 0x200,
	FONTFLAG_CUSTOM = 0x400,
	FONTFLAG_BITMAP = 0x800,
};