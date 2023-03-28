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
 * [_unit] call aup_main_fnc_inputStopMove;
 *
 * Public: No
 */

private _player = call CBA_fnc_currentUnit;

if !(isWeaponDeployed [_player, false]) exitWith {};

private _p1 = call FUNC(getPivot) vectorAdd [0, 0, 0.5];
private _p2 = _p1 vectorAdd [0, 0, -1];

private _intersections = lineIntersectsSurfaces [_p1, _p2, _player];
if (_intersections isEqualTo []) exitWith {};

_intersections select 0 params ["_intersectPos"];

private _helper = "aup_leanOut" createVehicle [0, 0, 0];
private _dir = vectorDir _player;
_helper setVectorDir _dir;
_helper setPosASL (_intersectPos vectorAdd (_dir vectorMultiply -0.95));

helper = _helper;
intersectPos = _intersectPos;

[{
    params ["_player"];
    !isWeaponDeployed _player
}, {
    params ["_player", "_helper"];
    _player moveInCargo _helper;
}, [_player, _helper]] call CBA_fnc_waitUntilAndExecute;
