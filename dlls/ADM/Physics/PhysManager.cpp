#include "Base/ExtDLL.h"
#include "Util.h"
#include "Base/CBase.h"

#include "PhysManager.h"
#include "../shared/ADM/Physics/PhysicsWorld.h"

LINK_ENTITY_TO_CLASS( phys_manager, CPhysManager );

void CPhysManager::Spawn()
{
	pev->solid = SOLID_NOT;
	pev->movetype = MOVETYPE_NONE;

//	pev->flags |= FL_ALWAYSTHINK;

	pev->nextthink = gpGlobals->time + 1.5f;
}

void CPhysManager::Think()
{
	g_Physics.StepSimulation( 1.f / 64.f, 16 );
	pev->nextthink = gpGlobals->time + 1.f / 60.f;
}
