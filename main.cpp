#include "sdk.h"

typedef void(__cdecl *MsgFn)(char const* pMsg, va_list);
void __cdecl Msg(char const* msg, ...)
{
	static MsgFn oMsg = (MsgFn)GetProcAddress(GetModuleHandle("tier0.dll"), "Msg");
	char buffer[989];
	va_list list;
	va_start(list, msg);
	vsprintf(buffer, msg, list);
	va_end(list);
	oMsg(buffer, list);
}
void SetupIndexes()
{
	using namespace indexes;
	//Engine
	GetScreenSize = 5;
	GetPlayerInfo = 8;
	GetLocalPlayer = 12;
	ClientCmd = 108;
	SetViewAngles = 19;
	GetViewAngles = 18;
	WorldToScreenMatrix = 37;

	//ClientEntList
	GetClientEntity = 3;
	GetHighestEntityIndex = 8;
	GetClientEntityFromHandle = 7;

	//Surface
	SetDrawColor = 15;
	DrawFilledRect = 16;
	DrawOutlinedRect = 18;
	DrawLine = 19;
	SCreateFont = 71;
	SetFontGlyphSet = 72;
	DrawSetTextFont = 23;
	DrawSetTextColor = 25;
	DrawSetTextPos = 26;
	DrawPrintText = 28;

	//ModelInfo
	GetStudioModel = 29;
}
void StartCheat()
{
	SetupIndexes();
	Interfaces.Engine->ClientCmd("clear");

	Msg("shitc0de hook initialized\n");
	Msg("==========================\n");
	Hooks.Hook();
}