#pragma once
#include "sdk.h"

class CTriggerbot {
public:
	void CreateMove(CUserCmd* cmd) {
		CBaseEntity* local = (CBaseEntity*)Interfaces.ClientEntList->GetClientEntity(Interfaces.Engine->GetLocalPlayer());

		if (GetAsyncKeyState(VK_MENU))
		{
			int cross = local->InCross();
			if (cross > 0 && cross <= 64)
			{
				CBaseEntity* target = (CBaseEntity*)Interfaces.ClientEntList->GetClientEntity(cross);
				if (!target->IsDormant() && target->GetTeamNum() != local->GetTeamNum())
				{
					cmd->buttons |= IN_ATTACK;
				}
			}
		}
	}
};