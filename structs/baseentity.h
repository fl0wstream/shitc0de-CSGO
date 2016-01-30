class CBaseEntity
{
public:
	float Friction()
	{
		return *reinterpret_cast<float*>((DWORD)this + 0x0140);
	}
	int GetTeamNum()
	{
		return *reinterpret_cast<int*>((DWORD)this + 0xF0);
	}
	Vector Velocity()
	{
		return *reinterpret_cast<Vector*>((DWORD)this + 0x0110);
	}

	int Health()
	{
		return *(int*)(this + 0xFC);
	}

	int Index()
	{
		void* networkable = (void*)(this + 0x8);
		typedef int(__thiscall* OriginalFn)(void*);
		return ((OriginalFn)VMT.GetFunction(networkable, 9))(networkable);
		//return *(int*)(this + 64);
	}

	int GetFlags()
	{
		return *reinterpret_cast<int*>((DWORD)this + 0x0100);
	}

	Vector GetEyePosition()
	{
		Vector vecViewOffset = *reinterpret_cast<Vector*>((DWORD)this + 0x0104);
		return GetAbsOrigin() + vecViewOffset;
	}

	Vector& GetAbsOrigin()
	{
		typedef Vector& (__thiscall* OriginalFn)(void*);
		return ((OriginalFn)VMT.GetFunction(this, 10))(this);
	}

	Vector& GetAbsAngles()
	{
		typedef Vector& (__thiscall* OriginalFn)(void*);
		return ((OriginalFn)VMT.GetFunction(this, 11))(this);
	}

	void* GetClientClass()
	{
		void* Networkable = (void*)(this + 0x8);
		typedef void* (__thiscall* OriginalFn)(void*);
		return ((OriginalFn)VMT.GetFunction(Networkable, 2))(Networkable);
	}
	
	bool IsDormant()
	{
		return *reinterpret_cast<bool*>((DWORD)this + 0xE9);
	}

	float MaxSpeed()
	{
		return *reinterpret_cast<float*>((DWORD)this + 0x160C);
	}

	bool isAlive()
	{
		BYTE lifestate = *(BYTE*)((DWORD)this + 0x025B);
		return (lifestate == 0);
	}

	int GetIndex()
	{
		void* networkable = (void*)(this + 0x8);
		typedef int(__thiscall* OriginalFn)(PVOID);
		return ((OriginalFn)VMT.GetFunction(networkable, 9))(networkable);
	}

	bool SetupBones(VMatrix *pBoneToWorldOut, int nMaxBones, int boneMask, float currentTime)
	{
		void *pRenderable = (void*)(this + 0x4);
		typedef bool(__thiscall* OriginalFn)(PVOID, VMatrix*, int, int, float);
		return ((OriginalFn)VMT.GetFunction(pRenderable, 16))(pRenderable, pBoneToWorldOut, nMaxBones, boneMask, currentTime);
	}

	void* GetModel()
	{
		void *pRenderable = (void*)(this + 0x4);
		typedef void*(__thiscall* OriginalFn)(PVOID);
		return VMT.getvfunc<OriginalFn>(pRenderable, 9)(pRenderable);
	}

	int InCross()
	{
		return *(int*)(this + 0xA940);
	}

};