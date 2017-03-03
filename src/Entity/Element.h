/*********************************************************
*
*  Copyright © 2017, Xen Roleplay. 
*
*  All Rights Reserved.
*
*  Redistribution and use in source and binary forms,
*  with or without modification,
*  is permitted only for authors.
*
*********************************************************/

class Element;

#ifndef __ELEMENT_H
#define __ELEMENT_H

#include "Lua/LuaArgument.h"
#include "Lua/LuaArguments.h"
#include "Math/Vector2.h"
#include "Math/Vector3.h"
#include "SharedUtil/Color.h"

class Ped;
class Player;
class Account;
class ColShape;
class Team;
class Vehicle;

class ElementManager;

using namespace SharedUtil;

class Element
{
protected:
	unsigned long long                          ID;

public:
												Element                     ( PVOID luaUserdata );
	virtual                                     ~Element                    ();

	virtual void                                DoPulse                     ();
	virtual void                                Save                        () const;

	inline ElementManager*                      GetElementManager           () const                  { return this->ElementManager; }
	inline PVOID                                GetLuaUserdata              () const                  { return this->LuaUserdata; }
	unsigned long long                          GetID                       () const                  { return this->ID; }

public:
	virtual void                                Destroy                     ();
	virtual Element*                            Clone                       ( const Math::Vector3& vecPosition, bool cloneChildren ) const;
	virtual bool                                IsValid                     () const;

	virtual Element*                            GetChild                    ( int index ) const;
	virtual int                                 GetChildrenCount            () const;

	virtual string				                GetElementID                () const;
	virtual LuaArgument			                GetData                     ( const string& key, bool inherit = true ) const;
	virtual LuaArguments		                GetAllData                  () const;
	virtual Element*                            GetParent                   () const;
	virtual Math::Vector3			            GetPosition                 () const;
	virtual Math::Vector3			            GetRotation                 () const;
	virtual Math::Vector3			            GetVelocity                 () const;
	virtual uchar					            GetInterior                 () const;
	virtual bool					            IsWithinColShape            () const;
	virtual bool					            IsWithinMarker              () const;
	virtual ushort                              GetDimension                () const;
	virtual string                              GetZoneName                 ( bool citiesOnly = false ) const;
	virtual bool					            IsAttached                  () const;
	virtual Element*                            GetAttachedTo               () const;
	virtual ColShape*                           GetColShape                 () const;
	virtual uchar                               GetAlpha                    () const;
	virtual bool					            IsDoubleSided               () const;
	virtual float					            GetHealth                   () const;
	virtual ushort					            GetModel                    () const;
	virtual bool					            IsInWater                   () const;
	virtual bool					            GetAttachedOffsets          ( Math::Vector3& position, Math::Vector3& rotation ) const;
	virtual Player*                             GetSyncer                   () const;
	virtual bool					            GetCollisionsEnabled        () const;
	virtual bool					            IsFrozen                    () const;
	virtual Element*                            GetLowLod                   () const;
	virtual bool					            IsLowLod                    () const;

	virtual bool                                SetElementID                ( const string& id );
	virtual bool                                SetData                     ( const string& key, const LuaArgument& var );
	virtual bool                                ClearVisibleTo              ();
	virtual bool                                RemoveData                  ( const string& key );
	virtual bool                                SetParent                   ( Element* target );
	virtual bool                                SetPosition                 ( const Math::Vector3& position, bool warp = true );
	virtual bool                                SetRotation                 ( const Math::Vector3& rotation, const char* rotationOrder = "default", bool newWay = false );
	virtual bool                                SetVelocity                 ( const Math::Vector3& velocity );
	virtual bool                                SetVisibleTo                ( Element* target, bool visible );
	virtual bool                                SetInterior                 ( int interior );
	virtual bool                                SetDimension                ( int dimension );
	virtual bool                                Attach                      ( Element* target, const Math::Vector3& vecPosition, const Math::Vector3& vecRotation );
	virtual bool                                Detach                      ( Element* target = nullptr );
	virtual bool                                SetAlpha                    ( int alpha );
	virtual bool                                SetDoubleSided              ( bool doubleSided );
	virtual bool                                SetHealth                   ( float health );
	virtual bool                                SetModel                    ( int model );
	virtual bool                                SetAttachedOffsets          ( const Math::Vector3& vecPosition, const Math::Vector3& vecRotation );
	virtual bool                                SetSyncer                   ( Player* player );
	virtual bool                                SetCollisionsEnabled        ( bool enabled );
	virtual bool                                SetFrozen                   ( bool frozen );
	virtual bool                                SetLowLod                   ( bool enabled );

protected:
	PVOID                                       LuaUserdata;
	lua_State*                                  LuaVM;
	ElementManager*                             ElementManager;
};

#endif
