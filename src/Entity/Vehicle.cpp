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
#include "Vehicle.h"

#include "Core/Module.h"

Vehicle::Vehicle( PVOID luaUserdata ) :
	Element( luaUserdata )
{
}

Vehicle::Vehicle( int model, const Vector3& position, const Vector3& rotation, const string& numberplate, bool direction, int variant1, int variant2 ) :
	Element( nullptr )
{
	float x = position.X;
	float y = position.Y;
	float z = position.Z;

	float rx = rotation.X;
	float ry = rotation.Y;
	float rz = rotation.Z;

	this->LuaUserdata = Lua::Bindings::CreateVehicle( LuaVM, model, x, y, z, rx, ry, rz, numberplate.c_str(), direction, variant1, variant2 );
}

Vehicle::~Vehicle()
{
}

string Vehicle::GetType() const
{
	string value;

	Lua::Bindings::GetVehicleType( LuaVM, LuaUserdata, value );

	return value;
}

bool Vehicle::GetVariant( uchar& variant, uchar& variant2 ) const
{
	return Lua::Bindings::GetVehicleVariant( LuaVM, LuaUserdata, variant, variant2 );
}

VehicleColor Vehicle::GetColor() const
{
	VehicleColor value;

	Lua::Bindings::GetVehicleColor( LuaVM, LuaUserdata, value );

	return value;
}

bool Vehicle::GetLandingGearDown() const
{
	bool value;

	Lua::Bindings::GetVehicleLandingGearDown( LuaVM, LuaUserdata, value );

	return value;
}

uchar Vehicle::GetMaxPassengers() const
{
	uchar value;

	Lua::Bindings::GetVehicleMaxPassengers( LuaVM, LuaUserdata, value );

	return value;
}

string Vehicle::GetName() const
{
	string value;

	Lua::Bindings::GetVehicleName( LuaVM, LuaUserdata, value );

	return value;
}

Ped* Vehicle::GetOccupant( uint seat ) const
{
	return this->ElementManager->FindOrCreate< Ped* >( Lua::Bindings::GetVehicleOccupant( LuaVM, LuaUserdata, seat ) );
}

vector< Ped* > Vehicle::GetOccupants() const
{
	vector< Ped* > list;

	for( const auto& arg : Lua::Bindings::GetVehicleOccupants( LuaVM, LuaUserdata ) )
	{
		if( arg.GetType() == LuaType::LightUserdata )
		{
			Ped* ped = this->ElementManager->FindOrCreate< Ped* >( arg.GetLightUserData() );

			if( ped != nullptr )
			{
				list.push_back( ped );
			}
		}
	}

	return list;
}

Element* Vehicle::GetController() const
{
	return this->ElementManager->FindOrCreate< Element* >( Lua::Bindings::GetVehicleController( LuaVM, LuaUserdata ) );
}

bool Vehicle::GetSirensOn() const
{
	bool value;

	Lua::Bindings::GetVehicleSirensOn( LuaVM, LuaUserdata, value );

	return value;
}

Vector3 Vehicle::GetTurnVelocity() const
{
	Vector3 value;

	Lua::Bindings::GetVehicleTurnVelocity( LuaVM, LuaUserdata, value );

	return value;
}

Vector2 Vehicle::GetTurretPosition() const
{
	Vector2 value;

	Lua::Bindings::GetVehicleTurretPosition( LuaVM, LuaUserdata, value );

	return value;
}

bool Vehicle::IsLocked() const
{
	bool value;

	Lua::Bindings::IsVehicleLocked( LuaVM, LuaUserdata, value );

	return value;
}

ushort Vehicle::GetUpgradeOnSlot( uchar slot ) const
{
	ushort value;

	Lua::Bindings::GetVehicleUpgradeOnSlot( LuaVM, LuaUserdata, slot, value );

	return value;
}

vector< uint > Vehicle::GetUpgrades() const
{
	vector< uint > list;

	for( const auto& arg : Lua::Bindings::GetVehicleUpgrades( LuaVM, LuaUserdata ) )
	{
		uint value = (uint)arg.GetNumber();

		list.push_back( value );
	}

	return list;
}

vector< uint > Vehicle::GetCompatibleUpgrades() const
{
	vector< uint > list;

	for( const auto& arg : Lua::Bindings::GetVehicleCompatibleUpgrades( LuaVM, LuaUserdata ) )
	{
		uint value = (uint)arg.GetNumber();

		list.push_back( value );
	}

	return list;
}

uchar Vehicle::GetDoorState( uchar door ) const
{
	uchar value;

	Lua::Bindings::GetVehicleDoorState( LuaVM, LuaUserdata, door, value );

	return value;
}

VehicleWheelsState Vehicle::GetWheelStates() const
{
	VehicleWheelsState value;

	Lua::Bindings::GetVehicleWheelStates( LuaVM, LuaUserdata, value.FrontLeft, value.RearLeft, value.FrontRight, value.RearRight );

	return value;
}

uchar Vehicle::GetLightState( uchar light ) const
{
	uchar value;

	Lua::Bindings::GetVehicleLightState( LuaVM, LuaUserdata, light, value );

	return value;
}

uchar Vehicle::GetPanelState( uchar panel ) const
{
	uchar value;

	Lua::Bindings::GetVehiclePanelState( LuaVM, LuaUserdata, panel, value );

	return value;
}

uchar Vehicle::GetOverrideLights() const
{
	uchar value;

	Lua::Bindings::GetVehicleOverrideLights( LuaVM, LuaUserdata, value );

	return value;
}

Vehicle* Vehicle::GetTowedByVehicle() const
{
	return this->ElementManager->FindOrCreate< Vehicle* >( Lua::Bindings::GetVehicleTowedByVehicle( LuaVM, LuaUserdata ) );
}

Vehicle* Vehicle::GetTowingVehicle() const
{
	return this->ElementManager->FindOrCreate< Vehicle* >( Lua::Bindings::GetVehicleTowingVehicle( LuaVM, LuaUserdata ) );
}

uchar Vehicle::GetPaintjob() const
{
	uchar value;

	Lua::Bindings::GetVehiclePaintjob( LuaVM, LuaUserdata, value );

	return value;
}

string Vehicle::GetPlateText() const
{
	char* value = new char[ VEHICLE_PLATE_TEXT_LENGTH ];

	Lua::Bindings::GetVehiclePlateText( LuaVM, LuaUserdata, value );

	string result( value );

	delete [] value;

	return result;
}

bool Vehicle::IsDamageProof() const
{
	bool value;

	Lua::Bindings::IsVehicleDamageProof( LuaVM, LuaUserdata, value );

	return value;
}

bool Vehicle::IsFuelTankExplodable() const
{
	bool value;

	Lua::Bindings::IsVehicleFuelTankExplodable( LuaVM, LuaUserdata, value );

	return value;
}

bool Vehicle::IsFrozen() const
{
	bool value;

	Lua::Bindings::IsVehicleFrozen( LuaVM, LuaUserdata, value );

	return value;
}

bool Vehicle::IsOnGround() const
{
	bool value;

	Lua::Bindings::IsVehicleOnGround( LuaVM, LuaUserdata, value );

	return value;
}

bool Vehicle::GetEngineState() const
{
	bool value;

	Lua::Bindings::GetVehicleEngineState( LuaVM, LuaUserdata, value );

	return value;
}

bool Vehicle::IsTrainDerailed() const
{
	bool value;

	Lua::Bindings::IsTrainDerailed( LuaVM, LuaUserdata, value );

	return value;
}

bool Vehicle::IsTrainDerailable() const
{
	bool value;

	Lua::Bindings::IsTrainDerailable( LuaVM, LuaUserdata, value );

	return value;
}

bool Vehicle::GetTrainDirection() const
{
	bool value;

	Lua::Bindings::GetTrainDirection( LuaVM, LuaUserdata, value );

	return value;
}

float Vehicle::GetTrainSpeed() const
{
	float value;

	Lua::Bindings::GetTrainSpeed( LuaVM, LuaUserdata, value );

	return value;
}

bool Vehicle::IsBlown() const
{
	return Lua::Bindings::IsVehicleBlown( LuaVM, LuaUserdata );
}

Color Vehicle::GetHeadLightColor() const
{
	Color value;

	Lua::Bindings::GetVehicleHeadLightColor( LuaVM, LuaUserdata, value );

	return value;
}

float Vehicle::GetDoorOpenRatio( uchar door ) const
{
	float value;

	Lua::Bindings::GetVehicleDoorOpenRatio( LuaVM, LuaUserdata, door, value );

	return value;
}

bool Vehicle::IsTaxiLightOn() const
{
	bool value;

	Lua::Bindings::IsVehicleTaxiLightOn( LuaVM, LuaUserdata, value );

	return value;
}

bool Vehicle::Fix()
{
	return Lua::Bindings::FixVehicle( LuaVM, LuaUserdata );
}

bool Vehicle::Blow( bool explode )
{
	return Lua::Bindings::BlowVehicle( LuaVM, LuaUserdata, explode );
}

bool Vehicle::SetTurnVelocity( const Vector3& velocity )
{
	return Lua::Bindings::SetVehicleTurnVelocity( LuaVM, LuaUserdata, velocity.X, velocity.Y, velocity.Z );
}

bool Vehicle::SetColor( const VehicleColor& color )
{
	Color c1 = color.GetRGBColor( 0 );
	Color c2 = color.GetRGBColor( 1 );
	Color c3 = color.GetRGBColor( 2 );
	Color c4 = color.GetRGBColor( 3 );

	return Lua::Bindings::SetVehicleColor( LuaVM, LuaUserdata, c1.R, c1.G, c1.B, c2.R, c2.G, c2.B, c3.R, c3.G, c3.B, c4.R, c4.G, c4.B );
}

bool Vehicle::SetLandingGearDown( bool landingGearDown )
{
	return Lua::Bindings::SetVehicleLandingGearDown( LuaVM, LuaUserdata, landingGearDown );
}

bool Vehicle::SetLocked( bool locked )
{
	return Lua::Bindings::SetVehicleLocked( LuaVM, LuaUserdata, locked );
}

bool Vehicle::SetDoorsUndamageable( bool undamageable )
{
	return Lua::Bindings::SetVehicleDoorsUndamageable( LuaVM, LuaUserdata, undamageable );
}

bool Vehicle::SetSirensOn( bool on )
{
	return Lua::Bindings::SetVehicleSirensOn( LuaVM, LuaUserdata, on );
}

bool Vehicle::SetTaxiLightOn( bool on )
{
	return Lua::Bindings::SetVehicleTaxiLightOn( LuaVM, LuaUserdata, on );
}

bool Vehicle::AddUpgrade( ushort upgrade )
{
	return Lua::Bindings::AddVehicleUpgrade( LuaVM, LuaUserdata, upgrade );
}

bool Vehicle::RemoveUpgrade( ushort upgrade )
{
	return Lua::Bindings::RemoveVehicleUpgrade( LuaVM, LuaUserdata, upgrade );
}

bool Vehicle::SetDoorState( uchar door, uchar state )
{
	return Lua::Bindings::SetVehicleDoorState( LuaVM, LuaUserdata, door, state );
}

bool Vehicle::SetWheelStates( const VehicleWheelsState& states )
{
	return Lua::Bindings::SetVehicleWheelStates( LuaVM, LuaUserdata, states.FrontLeft, states.RearLeft, states.FrontRight, states.RearRight );
}

bool Vehicle::SetLightState( uchar light, uchar state )
{
	return Lua::Bindings::SetVehicleLightState( LuaVM, LuaUserdata, light, state );
}

bool Vehicle::SetPanelState( uchar panel, uchar state )
{
	return Lua::Bindings::SetVehiclePanelState( LuaVM, LuaUserdata, panel, state );
}

bool Vehicle::SetIdleRespawnDelay( ulong time )
{
	return Lua::Bindings::SetVehicleIdleRespawnDelay( LuaVM, LuaUserdata, time );
}

bool Vehicle::SetRespawnDelay( ulong time )
{
	return Lua::Bindings::SetVehicleRespawnDelay( LuaVM, LuaUserdata, time );
}

bool Vehicle::SetRespawnPosition( const Vector3& position, const Vector3& rotation )
{
	return Lua::Bindings::SetVehicleRespawnPosition( LuaVM, LuaUserdata, position.X, position.Y, position.Z, rotation.X, rotation.Y, rotation.Z );
}

bool Vehicle::ToggleRespawn( bool respawn )
{
	return Lua::Bindings::ToggleVehicleRespawn( LuaVM, LuaUserdata, respawn );
}

bool Vehicle::ResetExplosionTime()
{
	return Lua::Bindings::ResetVehicleExplosionTime( LuaVM, LuaUserdata );
}

bool Vehicle::ResetIdleTime()
{
	return Lua::Bindings::ResetVehicleIdleTime( LuaVM, LuaUserdata );
}

bool Vehicle::Spawn( const Vector3& position, const Vector3& rotation )
{
	return Lua::Bindings::SpawnVehicle( LuaVM, LuaUserdata, position.X, position.Y, position.Z, rotation.X, rotation.Y, rotation.Z );
}

bool Vehicle::Respawn()
{
	return Lua::Bindings::RespawnVehicle( LuaVM, LuaUserdata );
}

bool Vehicle::SetOverrideLights( uchar lights )
{
	return Lua::Bindings::SetVehicleOverrideLights( LuaVM, LuaUserdata, lights );
}

bool Vehicle::AttachTrailer( Vehicle* trailer )
{
	return Lua::Bindings::AttachTrailerToVehicle( LuaVM, LuaUserdata, trailer->GetLuaUserdata() );
}

bool Vehicle::DetachTrailer( Vehicle* trailer )
{
	return Lua::Bindings::DetachTrailerFromVehicle( LuaVM, LuaUserdata, trailer ? trailer->GetLuaUserdata() : nullptr );
}

bool Vehicle::SetEngineState( bool state )
{
	return Lua::Bindings::SetVehicleEngineState( LuaVM, LuaUserdata, state );
}

bool Vehicle::SetDirtLevel( float dirtLevel )
{
	return Lua::Bindings::SetVehicleDirtLevel( LuaVM, LuaUserdata, dirtLevel );
}

bool Vehicle::SetDamageProof( bool damageProof )
{
	return Lua::Bindings::SetVehicleDamageProof( LuaVM, LuaUserdata, damageProof );
}

bool Vehicle::SetPaintjob( uchar paintjob )
{
	return Lua::Bindings::SetVehiclePaintjob( LuaVM, LuaUserdata, paintjob );
}

bool Vehicle::SetFuelTankExplodable( bool explodable )
{
	return Lua::Bindings::SetVehicleFuelTankExplodable( LuaVM, LuaUserdata, explodable );
}

bool Vehicle::SetFrozen( bool frozen )
{
	return Lua::Bindings::SetVehicleFrozen( LuaVM, LuaUserdata, frozen );
}

bool Vehicle::SetTrainDerailed( bool derailed )
{
	return Lua::Bindings::SetTrainDerailed( LuaVM, LuaUserdata, derailed );
}

bool Vehicle::SetTrainDerailable( bool derailable )
{
	return Lua::Bindings::SetTrainDerailable( LuaVM, LuaUserdata, derailable );
}

bool Vehicle::SetTrainDirection( bool direciton )
{
	return Lua::Bindings::SetTrainDirection( LuaVM, LuaUserdata, direciton );
}

bool Vehicle::SetTrainSpeed( float speed )
{
	return Lua::Bindings::SetTrainSpeed( LuaVM, LuaUserdata, speed );
}

bool Vehicle::SetHeadLightColor( const Color& color )
{
	return Lua::Bindings::SetVehicleHeadLightColor( LuaVM, LuaUserdata, color.R, color.G, color.B );
}

bool Vehicle::SetTurretPosition( const Vector2& position )
{
	return Lua::Bindings::SetVehicleTurretPosition( LuaVM, LuaUserdata, position.X, position.Y );
}

bool Vehicle::SetDoorOpenRatio( uchar door, float ratio, ulong time )
{
	return Lua::Bindings::SetVehicleDoorOpenRatio( LuaVM, LuaUserdata, door, ratio, time );
}

bool Vehicle::SetVariant( uchar variant, uchar variant2 )
{
	return Lua::Bindings::SetVehicleVariant( LuaVM, LuaUserdata, variant, variant2 );
}

bool Vehicle::GiveSirens( uchar sirenType, uchar sirenCount, bool flag360, bool checkLosFlag, bool useRandomiserFlag, bool silentFlag )
{
	return Lua::Bindings::GiveVehicleSirens( LuaVM, LuaUserdata, sirenType, sirenCount, flag360, checkLosFlag, useRandomiserFlag, silentFlag );
}

bool Vehicle::RemoveSirens()
{
	return Lua::Bindings::RemoveVehicleSirens( LuaVM, LuaUserdata );
}

bool Vehicle::SetSirens( uchar sirenID, const Vector3& position, const Color& color, float alpha, float minAlpha )
{
	return Lua::Bindings::SetVehicleSirens( LuaVM, LuaUserdata, sirenID, position.X, position.Y, position.Z, color.R, color.G, color.B, alpha, minAlpha );
}

bool Vehicle::SetPlateText( const string& name )
{
	return Lua::Bindings::SetVehiclePlateText( LuaVM, LuaUserdata, name.c_str() );
}
