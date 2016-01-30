#pragma once

#include "top.h"

class IClientEntityList
{
public:

	/* pads */
	virtual void PAD0( );
	virtual void PAD1( );
	virtual void PAD2( );

	/* cast to IClientEntity* before using  */
	virtual void* GetClientEntity( int Index );
	virtual void* GetClientEntityFromHandle( void* _Handle );

	virtual int NumberOfEntities( bool NonNetworkable );
	virtual int GetHighestEntityIndex( );
	virtual void SetMaxEntities( int Max );
	virtual void GetMaxEntities( );

}; extern IClientEntityList * ClientEntityList;