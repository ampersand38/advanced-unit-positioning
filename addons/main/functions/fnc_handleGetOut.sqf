#include "script_component.hpp"
/*
 * Author: Ampersand
 * Checks if given unit can tandem jump with cargo in the aircraft
 *
 * Arguments:
 * 0: Player <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_unit] call aup_main_fnc_handleGetOut;
 *
 * Public: No
 */

params ["_vehicle"];

deleteVehicle _vehicle;
