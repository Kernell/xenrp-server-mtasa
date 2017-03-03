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

class Vehicle;

#ifndef __VEHICLE_H
#define __VEHICLE_H

#define VEHICLE_PLATE_TEXT_LENGTH 8

#include "Element.h"
#include "SharedUtil/VehicleColor.h"
#include "SharedUtil/VehicleWheelsState.h"

class Vehicle : public Element
{
public:
	                                    Vehicle                         ( PVOID luaUserdata );
	                                    Vehicle                         ( int model, const Vector3& position, const Vector3& rotation, const string& numberplate, bool direction = false, int variant1 = 255, int variant2 = 255 );
	virtual                             ~Vehicle                        ();

	virtual string                      GetType                         () const;
	virtual bool                        GetVariant                      ( uchar& variant, uchar& variant2 ) const;
	virtual VehicleColor                GetColor	                    () const;
///	virtual ushort                      GetModelFromName                ( const string& name ) const;
	virtual bool                        GetLandingGearDown		        () const;
	virtual uchar                       GetMaxPassengers                () const;
	virtual string                      GetName                         () const;
///	virtual string                      GetNameFromModel                ( ushort model ) const;
	virtual Ped*                        GetOccupant                     ( uint seat ) const;
	virtual vector< Ped* >              GetOccupants                    () const;
	virtual Element*                    GetController                   () const;
	virtual bool						GetSirensOn                     () const;
	virtual Vector3                     GetTurnVelocity                 () const;
	virtual Vector2                     GetTurretPosition               () const;
	virtual bool						IsLocked                        () const;
///	virtual ArgumentsVector		        GetsOfType                      ( uint model ) const;       
	virtual ushort                      GetUpgradeOnSlot                ( uchar slot ) const;
	virtual vector< uint >              GetUpgrades                     () const;
///	virtual string                      GetUpgradeSlotName              ( uchar slot ) const;
///	virtual string                      GetUpgradeSlotName              ( ushort upgrade ) const;
	virtual vector< uint >              GetCompatibleUpgrades           () const;
	virtual uchar                       GetDoorState                    ( uchar door ) const;
	virtual VehicleWheelsState          GetWheelStates                  () const;
	virtual uchar                       GetLightState                   ( uchar light ) const;
	virtual uchar                       GetPanelState                   ( uchar panel ) const;
	virtual uchar                       GetOverrideLights               () const;
	virtual Vehicle*                    GetTowedByVehicle               () const;
	virtual Vehicle*                    GetTowingVehicle                () const;
	virtual uchar                       GetPaintjob                     () const;
	virtual string                      GetPlateText                    () const;
	virtual bool                        IsDamageProof                   () const;
	virtual bool                        IsFuelTankExplodable            () const;
	virtual bool                        IsFrozen                        () const;
	virtual bool                        IsOnGround                      () const;
	virtual bool                        GetEngineState                  () const;
	virtual bool                        IsTrainDerailed                 () const;
	virtual bool                        IsTrainDerailable               () const;
	virtual bool                        GetTrainDirection               () const;
	virtual float                       GetTrainSpeed                   () const;
	virtual bool                        IsBlown                         () const;
	virtual Color                       GetHeadLightColor               () const;
	virtual float                       GetDoorOpenRatio                ( uchar door ) const;
	virtual bool                        IsTaxiLightOn                   () const;
///	virtual bool                        GetVehicleSirens                ();
///	virtual bool                        GetVehicleSirenParams           ();

	virtual bool                        Fix                             ();
	virtual bool                        Blow                            ( bool explode );
	virtual bool                        SetTurnVelocity                 ( const Vector3& velocity );
	virtual bool                        SetColor                        ( const VehicleColor& color );
	virtual bool                        SetLandingGearDown              ( bool landingGearDown );
	virtual bool                        SetLocked                       ( bool locked );
	virtual bool                        SetDoorsUndamageable            ( bool undamageable );
	virtual bool                        SetSirensOn                     ( bool on );
	virtual bool                        SetTaxiLightOn                  ( bool on );
	virtual bool                        AddUpgrade                      ( ushort upgrade );
	virtual bool                        RemoveUpgrade                   ( ushort upgrade );
	virtual bool                        SetDoorState                    ( uchar door, uchar state );
	virtual bool                        SetWheelStates                  ( const VehicleWheelsState& states );
	virtual bool                        SetLightState                   ( uchar light, uchar state );
	virtual bool                        SetPanelState                   ( uchar panel, uchar state );
	virtual bool                        SetIdleRespawnDelay             ( ulong time );
	virtual bool                        SetRespawnDelay                 ( ulong time );
	virtual bool                        SetRespawnPosition              ( const Vector3& position, const Vector3& rotation );
	virtual bool                        ToggleRespawn                   ( bool respawn );
	virtual bool                        ResetExplosionTime              ();
	virtual bool                        ResetIdleTime                   ();
	virtual bool                        Spawn                           ( const Vector3& position, const Vector3& rotation );
	virtual bool                        Respawn                         ();
	virtual bool                        SetOverrideLights               ( uchar lights );
	virtual bool                        AttachTrailer                   ( Vehicle* trailer );
	virtual bool                        DetachTrailer                   ( Vehicle* trailer = nullptr );
	virtual bool                        SetEngineState                  ( bool state );
	virtual bool                        SetDirtLevel                    ( float dirtLevel );
	virtual bool                        SetDamageProof                  ( bool damageProof );
	virtual bool                        SetPaintjob                     ( uchar paintjob );
	virtual bool                        SetFuelTankExplodable           ( bool explodable );
	virtual bool                        SetFrozen                       ( bool frozen );
	virtual bool                        SetTrainDerailed                ( bool derailed );
	virtual bool                        SetTrainDerailable              ( bool derailable );
	virtual bool                        SetTrainDirection               ( bool direciton );
	virtual bool                        SetTrainSpeed                   ( float speed );
	virtual bool                        SetHeadLightColor               ( const Color& color );
	virtual bool                        SetTurretPosition               ( const Vector2& position );
	virtual bool                        SetDoorOpenRatio                ( uchar door, float ratio, ulong time = 0 );
	virtual bool                        SetVariant                      ( uchar variant, uchar variant2 );
	virtual bool                        GiveSirens                      ( uchar sirenType, uchar sirenCount, bool flag360 = false, bool checkLosFlag = true, bool useRandomiserFlag = true, bool silentFlag = false );
	virtual bool                        RemoveSirens                    ();
	virtual bool                        SetSirens                       ( uchar sirenID, const Vector3& position, const Color& color, float alpha = 255, float minAlpha = 0.0 );
	virtual bool                        SetPlateText                    ( const string& name );
};

#endif