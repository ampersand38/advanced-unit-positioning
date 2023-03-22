#include "script_component.hpp"
/*
 * Author: Ampersand
 * Checks if given unit can lean out
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * Success <BOOLEAN>
 *
 * Example:
 * [_unit] call mfp_main_fnc_canLeanOut;
 *
 * Public: No
 */

params ["_unit"];

isWeaponDeployed [_unit, false];
