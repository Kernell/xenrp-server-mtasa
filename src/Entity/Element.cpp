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

#include "StdInc.h"
#include "Element.h"

#include "Core/Module.h"
#include "Manager/ElementManager.h"

extern Module* g_Module;

Element::Element( PVOID luaUserdata ) :
	LuaUserdata( luaUserdata ),
	ID( NULL )
{
	this->LuaVM          = g_Module->GetLua();
	this->ElementManager = g_Module->GetElementManager();

	this->ElementManager->AddToList( this );
}

Element::~Element()
{
	this->ElementManager->RemoveFromList( this );

	this->Destroy();

	this->LuaUserdata    = nullptr;
	this->ElementManager = nullptr;
	this->LuaVM          = nullptr;
}

void Element::DoPulse()
{
}

void Element::Save() const
{
}

void Element::Destroy()
{
	Lua::Bindings::DestroyElement( LuaVM, LuaUserdata );
}

Element* Element::Clone( const Math::Vector3& vecPosition, bool cloneChildren ) const
{
	return this->ElementManager->FindOrCreate( Lua::Bindings::CloneElement( LuaVM, LuaUserdata, vecPosition, cloneChildren ) );
}

bool Element::IsValid() const
{
	return Lua::Bindings::IsElement( LuaVM, LuaUserdata );
}

Element* Element::GetChild( int index ) const
{
	return this->ElementManager->FindOrCreate( Lua::Bindings::GetElementChild( LuaVM, LuaUserdata, index ) );
}

int Element::GetChildrenCount() const
{
	return Lua::Bindings::GetElementChildrenCount( LuaVM, LuaUserdata );
}

string Element::GetElementID() const
{
	return Lua::Bindings::GetElementID( LuaVM, LuaUserdata );
}

LuaArgument Element::GetData( const string& key, bool inherit ) const
{
	return Lua::Bindings::GetElementData( LuaVM, LuaUserdata, key, inherit );
}

LuaArguments Element::GetAllData() const
{
	return Lua::Bindings::GetAllElementData( LuaVM, LuaUserdata );
}

Element* Element::GetParent() const
{
	return this->ElementManager->FindOrCreate( Lua::Bindings::GetElementParent( LuaVM, LuaUserdata ) );
}

Math::Vector3 Element::GetPosition() const
{
	Math::Vector3 value;

	Lua::Bindings::GetElementPosition( LuaVM, LuaUserdata, value );

	return value;
}

Math::Vector3 Element::GetRotation() const
{
	Math::Vector3 value;

	Lua::Bindings::GetElementRotation( LuaVM, LuaUserdata, value );

	return value;
}

Math::Vector3 Element::GetVelocity() const
{
	Math::Vector3 value;

	Lua::Bindings::GetElementVelocity( LuaVM, LuaUserdata, value );

	return value;
}

uchar Element::GetInterior() const
{
	uchar value = 0;

	Lua::Bindings::GetElementInterior( LuaVM, LuaUserdata, value );

	return value;
}

bool Element::IsWithinColShape() const
{
	bool value = false;

	Lua::Bindings::IsElementWithinColShape( LuaVM, LuaUserdata, value );

	return value;
}

bool Element::IsWithinMarker() const
{
	bool value = false;

	Lua::Bindings::IsElementWithinMarker( LuaVM, LuaUserdata, value );

	return value;
}

ushort Element::GetDimension() const
{
	ushort value = 0;

	Lua::Bindings::GetElementDimension( LuaVM, LuaUserdata, value );

	return value;
}

string Element::GetZoneName( bool citiesOnly ) const
{
	string value;

	Lua::Bindings::GetElementZoneName( LuaVM, LuaUserdata, value, citiesOnly );

	return value;
}

bool Element::IsAttached() const
{
	return Lua::Bindings::IsElementAttached( LuaVM, LuaUserdata );
}

Element* Element::GetAttachedTo() const
{
	return this->ElementManager->FindOrCreate( Lua::Bindings::GetElementAttachedTo( LuaVM, LuaUserdata ) );
}

ColShape* Element::GetColShape() const
{
	return this->ElementManager->FindOrCreate< ColShape* >( Lua::Bindings::GetElementColShape( LuaVM, LuaUserdata ) );
}

uchar Element::GetAlpha() const
{
	uchar value = 0;

	Lua::Bindings::GetElementAlpha( LuaVM, LuaUserdata, value );

	return value;
}

bool Element::IsDoubleSided() const
{
	bool value = false;

	Lua::Bindings::IsElementDoubleSided( LuaVM, LuaUserdata, value );

	return value;
}

float Element::GetHealth() const
{
	float value = 0.0f;

	Lua::Bindings::GetElementHealth( LuaVM, LuaUserdata, value );

	return value;
}

ushort Element::GetModel() const
{
	ushort value = 0;

	Lua::Bindings::GetElementModel( LuaVM, LuaUserdata, value );

	return value;
}

bool Element::IsInWater() const
{
	bool value = false;

	Lua::Bindings::IsElementInWater( LuaVM, LuaUserdata, value );

	return value;
}

bool Element::GetAttachedOffsets( Math::Vector3& position, Math::Vector3& rotation ) const
{
	return Lua::Bindings::GetElementAttachedOffsets( LuaVM, LuaUserdata, position, rotation );
}

Player* Element::GetSyncer() const
{
	return this->ElementManager->FindOrCreate< Player* >( Lua::Bindings::GetElementSyncer( LuaVM, LuaUserdata ) );
}

bool Element::GetCollisionsEnabled() const
{
	return Lua::Bindings::GetElementCollisionsEnabled( LuaVM, LuaUserdata );
}

bool Element::IsFrozen() const
{
	bool value = false;

	Lua::Bindings::IsElementFrozen( LuaVM, LuaUserdata, value );

	return value;
}

Element* Element::GetLowLod() const
{
	PVOID value;

	if( !Lua::Bindings::GetLowLodElement( LuaVM, LuaUserdata, value ) )
		return nullptr;

	return this->ElementManager->FindOrCreate( value );
}

bool Element::IsLowLod() const
{
	bool value = false;

	Lua::Bindings::IsElementLowLod( LuaVM, LuaUserdata, value );

	return value;
}

bool Element::SetElementID( const string& id )
{
	return Lua::Bindings::SetElementID( LuaVM, LuaUserdata, id );
}

bool Element::SetData( const string& key, const LuaArgument& var )
{
	return Lua::Bindings::SetElementData( LuaVM, LuaUserdata, key, var );
}

bool Element::ClearVisibleTo()
{
	return Lua::Bindings::ClearElementVisibleTo( LuaVM, LuaUserdata );
}

bool Element::RemoveData( const string& key )
{
	return Lua::Bindings::RemoveElementData( LuaVM, LuaUserdata, key );
}

bool Element::SetParent( Element* target )
{
	return Lua::Bindings::SetElementParent( LuaVM, LuaUserdata, target->GetLuaUserdata() );
}

bool Element::SetPosition( const Math::Vector3& position, bool warp )
{
	return Lua::Bindings::SetElementPosition( LuaVM, LuaUserdata, position, warp );
}

bool Element::SetRotation( const Math::Vector3& rotation, const char* rotationOrder, bool newWay )
{
	return Lua::Bindings::SetElementRotation( LuaVM, LuaUserdata, rotation, rotationOrder, newWay );
}

bool Element::SetVelocity( const Math::Vector3& velocity )
{
	return Lua::Bindings::SetElementVelocity( LuaVM, LuaUserdata, velocity );
}

bool Element::SetVisibleTo( Element* target, bool visible )
{
	return Lua::Bindings::SetElementVisibleTo( LuaVM, LuaUserdata, target, visible );
}

bool Element::SetInterior( int interior )
{
	return Lua::Bindings::SetElementInterior( LuaVM, LuaUserdata, interior );
}

bool Element::SetDimension( int dimension )
{
	return Lua::Bindings::SetElementDimension( LuaVM, LuaUserdata, dimension );
}

bool Element::Attach( Element* target, const Math::Vector3& vecPosition, const Math::Vector3& vecRotation )
{
	return Lua::Bindings::AttachElements( LuaVM, LuaUserdata, target->GetLuaUserdata(), vecPosition, vecRotation );
}

bool Element::Detach( Element* target )
{
	return Lua::Bindings::DetachElements( LuaVM, LuaUserdata, target ? target->GetLuaUserdata() : nullptr );
}

bool Element::SetAlpha( int alpha )
{
	return Lua::Bindings::SetElementAlpha( LuaVM, LuaUserdata, alpha );
}

bool Element::SetDoubleSided( bool doubleSided )
{
	return Lua::Bindings::SetElementDoubleSided( LuaVM, LuaUserdata, doubleSided );
}

bool Element::SetHealth( float health )
{
	return Lua::Bindings::SetElementHealth( LuaVM, LuaUserdata, health );
}

bool Element::SetModel( int model )
{
	return Lua::Bindings::SetElementModel( LuaVM, LuaUserdata, model );
}

bool Element::SetAttachedOffsets( const Math::Vector3& position, const Math::Vector3& rotation )
{
	return Lua::Bindings::SetElementAttachedOffsets( LuaVM, LuaUserdata, position, rotation );
}

bool Element::SetSyncer( Player* player )
{
	return Lua::Bindings::SetElementSyncer( LuaVM, LuaUserdata, player->GetLuaUserdata() );
}

bool Element::SetCollisionsEnabled( bool enabled )
{
	return Lua::Bindings::SetElementCollisionsEnabled( LuaVM, LuaUserdata, enabled );
}

bool Element::SetFrozen( bool frozen )
{
	return Lua::Bindings::SetElementFrozen( LuaVM, LuaUserdata, frozen );
}

bool Element::SetLowLod( bool enabled )
{
	return Lua::Bindings::SetLowLodElement( LuaVM, LuaUserdata, enabled );
}

bool Element::OutputChatBox( const string& text, uchar red, uchar green, uchar blue, bool colorCoded )
{
	return Lua::Bindings::OutputChatBox( LuaVM, text.c_str(), LuaUserdata, red, green, blue, colorCoded );
}

bool Element::OutputChatBox( const string& text, const Color& color, bool colorCoded )
{
	return Lua::Bindings::OutputChatBox( LuaVM, text.c_str(), LuaUserdata, color.R, color.G, color.B, colorCoded );
}

bool Element::OutputConsole( const string& text )
{
	return Lua::Bindings::OutputConsole( LuaVM, text.c_str(), LuaUserdata );
}
