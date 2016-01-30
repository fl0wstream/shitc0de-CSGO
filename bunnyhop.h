#pragma once
#include "sdk.h"

class CBunnyhop {
public:
	void CreateMove(CUserCmd* cmd) 
	{
		CBaseEntity* me = Interfaces.ClientEntList->GetClientEntity(Interfaces.Engine->GetLocalPlayer());

		if (cmd->buttons & IN_JUMP && !(me->GetFlags() & FL_ONGROUND))
			cmd->buttons &= ~IN_JUMP;
	}
};