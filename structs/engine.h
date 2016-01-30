class CEngine
{
public:

	void GetScreenSize( int& Width, int& Height )
	{
		typedef void( __thiscall* Fn )(void*, int&, int&);
		return ((Fn)VMT.GetFunction(this, indexes::GetScreenSize))(this, Width, Height);
	}

	bool GetPlayerInfo( int Index, PlayerInfo_t* PlayerInfo )
	{
		typedef bool(__thiscall* Fn)(void*, int, PlayerInfo_t*);
		return ((Fn)VMT.GetFunction(this, indexes::GetPlayerInfo))(this, Index, PlayerInfo);
	}

	int GetLocalPlayer()
	{
		typedef int(__thiscall* Fn)(void*);
		return ((Fn)VMT.GetFunction(this, indexes::GetLocalPlayer))(this);
	}

	void ClientCmd( const char* Command )
	{
		typedef void(__thiscall* Fn)(void*, const char*);
		return ((Fn)VMT.GetFunction(this, indexes::ClientCmd))(this, Command);
	}

	void SetViewAngles( Vector& Angles )
	{
		typedef void(__thiscall* Fn)(void*, Vector&);
		return ((Fn)VMT.GetFunction(this, indexes::SetViewAngles))(this, Angles);
	}

	void GetViewAngles(Vector& angle)
	{
		typedef void(__thiscall* Fn)(void*, Vector&);
		return ((Fn)VMT.GetFunction(this, indexes::GetViewAngles))(this,angle);
	}

	VMatrix& WorldToScreenMatrix()
	{
		typedef VMatrix& (__thiscall* Fn)(void*);
		return ((Fn)VMT.GetFunction(this, indexes::WorldToScreenMatrix))(this);
	
	}

	bool IsInGame()
	{
		typedef bool(__thiscall* Fn)(void*);
		return ((Fn)VMT.GetFunction(this, 26))(this);
	}

	bool IsConnected()
	{
		typedef bool(__thiscall* Fn)(void*);
		return ((Fn)VMT.GetFunction(this, 27))(this);
	}

	const matrix3x4_t& GetMatrix()
	{
		typedef const matrix3x4_t& (__thiscall* Fn)(void*);
		return ((Fn)VMT.GetFunction(this, 37))(this);
	}

	bool IsTakingScreenshot(void)
	{
		typedef bool(__thiscall* Fn)(void*);
		return ((Fn)VMT.GetFunction(this, 85))(this);
	}
};