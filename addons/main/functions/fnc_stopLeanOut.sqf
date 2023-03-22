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
 * [_unit] call mfp_main_fnc_stopLeanOut;
 *
 * Public: No
 */

params ["_unit"];

private _helper = _unit getVariable [QGVAR(helper)];