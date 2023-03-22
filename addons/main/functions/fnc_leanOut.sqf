#include "script_component.hpp"
/*
 * Author: Ampersand
 * Start leaning out.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [player] call aup_main_fnc_leanOut
 *
 * Public: No
 */

params ["_unit"];

private _helper = "aup_leanOut" createVehicle [0, 0, 0];
