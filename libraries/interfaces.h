class CInterfaces
{
public:
	CEngine *Engine;
	CClient *Client;
	CInput *Input;
	CClientEntityList *ClientEntList;
	CModelInfo *ModelInfo;
	CPanel* Panel;
	CSurface* Surface;
	CTrace* Trace;
	CGlobalVarsBase* Globals;

	void GetInterfaces()
	{
		Engine = (CEngine*)GetPointer("engine.dll", "VEngineClient");
		Trace = (CTrace*)GetPointer("engine.dll", "EngineTraceClient");
		Client = (CClient*)GetPointer("client.dll", "VClient");
		ClientEntList = (CClientEntityList*)GetPointer("client.dll", "VClientEntityList");
		ModelInfo = (CModelInfo*)GetPointer("engine.dll","VModelInfoClient");
		Panel = (CPanel*)GetPointer("vgui2.dll","VGUI_Panel");
		Surface = (CSurface*)GetPointer("vguimatsurface", "VGUI_Surface");
		Input = *(CInput**)((*(DWORD**)Client)[15] + 0x1);
		PDWORD pdwClient = (PDWORD)*(PDWORD)Client;

		DWORD dwInitAddr = (DWORD)(pdwClient[0]);

		for (DWORD dwIter = 0; dwIter <= 0xFF; dwIter++)
		{
			if (*(PBYTE)(dwInitAddr + dwIter) == 0xA3)
			{
				Globals = (CGlobalVarsBase*)*(PDWORD)*(PDWORD)(dwInitAddr + dwIter + 1);
				printf("Globals Found: 0x%X || 0x%X\n", (DWORD)Globals, ((DWORD)Globals - (DWORD)GetModuleHandle("client.dll")));
				break;
			}
		}
		printf("Input Found: 0x%X\n", (DWORD)Input);
	}

	void* GetPointer(const char* Module, const char* InterfaceName)
	{
		void* Interface = NULL;
		char PossibleInterfaceName[1024];

		CreateInterfaceFn CreateInterface = (CreateInterfaceFn)GetProcAddress(GetModuleHandleA(Module), "CreateInterface");
		for (int i = 1; i < 100; i++)
		{
			sprintf(PossibleInterfaceName, "%s0%i", InterfaceName, i);
			Interface = (void*)CreateInterface(PossibleInterfaceName, NULL);
			if (Interface != NULL)
			{
				printf("%s Found: 0x%X\n", PossibleInterfaceName, (DWORD)Interface);
				break;
			}
			sprintf(PossibleInterfaceName, "%s00%i", InterfaceName, i);
			Interface = (void*)CreateInterface(PossibleInterfaceName, NULL);
			if (Interface != NULL)
			{
				printf("%s Found: 0x%X\n", PossibleInterfaceName, (DWORD)Interface);				
				break;
			}
		}

		return Interface;
	}
}; CInterfaces Interfaces;