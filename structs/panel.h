class CPanel
{
public:
	const char* GetName( unsigned int Panel )
	{
		typedef const char*(__thiscall* Fn)(void*, unsigned int);
		return ((Fn)VMT.GetFunction(this, 36))(this, Panel );
	}

};