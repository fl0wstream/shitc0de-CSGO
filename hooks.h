#pragma once
#include "sdk.h"
#include "esp.h"
#include "triggerbot.h"
#include "bunnyhop.h"

CESP * pESP;
CTriggerbot * pTriggerbot;
CBunnyhop * pBunnyhop;

typedef void(__stdcall* CreateMoveFn)(int, float, bool);
CreateMoveFn oCreateMove;
void __stdcall hkCreateMove(int sequence_number, float input_sample_frametime, bool active)
{
	oCreateMove(sequence_number, input_sample_frametime, active);

	CUserCmd* cmdlist = *(CUserCmd**)((DWORD)Interfaces.Input + 0xEC);
	CUserCmd* cmd = &cmdlist[sequence_number % 150];

	if (!Interfaces.ClientEntList->GetClientEntity(Interfaces.Engine->GetLocalPlayer()))
		return;

	pTriggerbot->CreateMove(cmd);
	pBunnyhop->CreateMove(cmd);

	CVerifiedUserCmd* verifiedlist = *(CVerifiedUserCmd**)((DWORD)Interfaces.Input + 0xF0);
	CVerifiedUserCmd* verified = &verifiedlist[sequence_number % 150];

	verified->m_cmd = *cmd;
	verified->m_crc = gCRC.CRC32_ProcessSingleBuffer(cmd, sizeof(cmd));
}

typedef void(__thiscall *PaintTraverseFn)(void*, unsigned int, bool, bool);
PaintTraverseFn oPaintTraverse;
void __stdcall hkPaintTraverse(int VGUIPanel, bool ForceRepaint, bool AllowForce)
{
	oPaintTraverse(Interfaces.Panel, VGUIPanel, ForceRepaint, AllowForce);

	const char* szName = Interfaces.Panel->GetName(VGUIPanel);

	/* right panel */
	if (szName[0] == 'F' && szName[5] == 'O')
	{
		int iScreenWidth;
		int iScreenHeight;

		Interfaces.Engine->GetScreenSize(iScreenWidth, iScreenHeight);

		g_pRender->DrawShadowText(iScreenWidth - 130, 5, CColor(225, 45, 45, 255), 7, 0, "[ shitc0dehook v0.1 ]");

		if (Interfaces.Engine->IsConnected() && Interfaces.Engine->IsInGame())
		{
			pESP->Draw();
		}
	}
}

class CHooks
{
public:
	void Hook()
	{
		CVMTHookManager* ClientHook = new CVMTHookManager(Interfaces.Client);
		oCreateMove = (CreateMoveFn)ClientHook->HookFunction(21, hkCreateMove);
		ClientHook->HookTable(true);

		CVMTHookManager* PaintHook = new CVMTHookManager(Interfaces.Panel);
		oPaintTraverse = (PaintTraverseFn)PaintHook->HookFunction(41, hkPaintTraverse);
		PaintHook->HookTable(true);
	}
};
CHooks Hooks;