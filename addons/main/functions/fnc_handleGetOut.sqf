#include "script_component.hpp"
/*
 * Author: Ampersand
 * Deletes the helper vehicle
 *
 * Arguments:
 * 0: Vehicle <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_vehicle] call aup_main_fnc_handleGetOut;
 *
 * Public: No
 */

#define FALL_THRESHOLD 0.8

params ["_vehicle", "_role", "_unit", "_turret"];

if (lifeState _unit != "INCAPACITATED") then {
    _unit switchMove "";
};

deleteVehicle _vehicle;
