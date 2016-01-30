class CInput
{
public:
	CUserCmd *GetUserCmd(int sqnum)
	{
		typedef CUserCmd*(__thiscall* Fn)(void*, int, int);
		return ((Fn)VMT.GetFunction(this, 8))(this, 0,sqnum);
	}
};