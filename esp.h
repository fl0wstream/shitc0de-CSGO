#pragma once
#include "sdk.h"

class CESP
{
public:

	void Draw()
	{
		CBaseEntity* Local = (CBaseEntity*)Interfaces.ClientEntList->GetClientEntity(Interfaces.Engine->GetLocalPlayer());

		for (int i = 0; i < Interfaces.ClientEntList->GetHighestEntityIndex(); ++i)
		{
			CBaseEntity* Entity = (CBaseEntity*)Interfaces.ClientEntList->GetClientEntity(i);

			//PlayerInfo_t* Info = new PlayerInfo_t;

			Vector vScreen, vHead;

			matrix3x4_t mMatrix = Interfaces.Engine->GetMatrix();

			if (!Entity)
				continue;

			if (Entity->IsDormant())
				continue;

			if (Entity == Local)
				continue;

			if (Entity->Health())
			{
				//Interfaces.Engine->GetPlayerInfo(i, Info);

				if (WorldToScreen(Entity->GetAbsOrigin(), vScreen, mMatrix) && WorldToScreen((Entity->GetEyePosition() + Vector(0, 0, 8.f)), vHead, mMatrix))
				{
					CColor Color(255, 255, 255, 255);

					if (Entity->GetTeamNum() != Local->GetTeamNum())
						Color = CColor(255, 0, 0, 255);
					else
						Color = CColor(0, 255, 255, 255);

					//g_pRender->DrawF(vScreen.x, vScreen.y + 4, Color, 8, 1, "- %s -", Info->Name);
					g_pRender->DrawF(vHead.x, vHead.y - 14, Color, 7, 1, "%d", Entity->Health());

					int iHeight = vScreen.y - vHead.y; 
					int iWidth = iHeight / 2.5;
					//double dHealthBar = (iHeight / 100);
					
					//g_pRender->DrawRect((Head.x - iWidth / 2) - 7, Head.y, 6, iHeight, Color);
					//g_pRender->DrawFilledRect((Head.x - iWidth / 2) - 7, Head.y, 6, (iHeight / 100) * Entity->Health(), CColor(0, 255, 0, 150));
					g_pRender->DrawInlineRect(vHead.x - iWidth / 2, vHead.y, iWidth, iHeight, Color); \

					//cout << "Height: " << iHeight << " | HealthBar: " << float(iHeight / 100) << " | Offset: " << float(iHeight / 100) * Entity->Health() << endl;
				}
			}
		}
	}

	__forceinline bool WorldToScreen(Vector In, Vector& Out, matrix3x4_t ViewMatrix)
	{
		Out.x = ViewMatrix[0][0] * In.x + ViewMatrix[0][1] * In.y + ViewMatrix[0][2] * In.z + ViewMatrix[0][3];

		Out.y = ViewMatrix[1][0] * In.x + ViewMatrix[1][1] * In.y + ViewMatrix[1][2] * In.z + ViewMatrix[1][3];

		Out.z = ViewMatrix[3][0] * In.x + ViewMatrix[3][1] * In.y + ViewMatrix[3][2] * In.z + ViewMatrix[3][3];

		if (Out.z < 0.01f)
			return false;

		float Inverse = 1.f / Out.z;

		Out.x *= Inverse;
		Out.y *= Inverse;

		int Width, Height;

		Interfaces.Engine->GetScreenSize(Width, Height);

		auto X = Width / 2;
		auto Y = Height / 2;

		X += 0.5 * Out.x * Width + 0.5;
		Y -= 0.5 * Out.y * Height + 0.5;

		Out.x = X;
		Out.y = Y;

		return true;
	}

};
