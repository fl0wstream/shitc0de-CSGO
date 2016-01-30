#pragma once

#include "top.h"
#include "vector.h"

class CBaseEntity
{
public:

	bool GetDormant( )
	{
		return *( bool* ) ( this + 0xE9 );
	}

	int GetTeam( )
	{
		return *( int* ) ( this + 0xF0 );
	}

	int GetHealth( )
	{
		return *( int* ) ( this + 0xFC );
	}

	CVector GetOrigin( )
	{
		return *( CVector* ) ( this + 0x134 );
	}

	CVector GetEyePosition( )
	{
		return *( CVector* ) ( this + 0x104 ) + GetOrigin( );
	}

};