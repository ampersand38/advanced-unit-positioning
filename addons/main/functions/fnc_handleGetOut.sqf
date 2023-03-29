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

params ["_vehicle", "_role", "_unit", "_turret"];

deleteVehicle _vehicle;
if (lifeState _unit != "INCAPACITATED") then {
    _unit switchMove "";
};
