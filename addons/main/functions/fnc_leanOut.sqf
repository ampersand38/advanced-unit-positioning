#include "script_component.hpp"
/*
 * Author: Ampersand
 * Start leaning out.
 *
 * Arguments:
 * None
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [] call aup_main_fnc_leanOut
 *
 * Public: No
 */

private _player = call CBA_fnc_currentUnit;

if !(isWeaponDeployed [_player, false]) exitWith {};

private _pivot = call FUNC(getPivot);

/*
private _p1 = (_player modelToWorldVisualWorld _pivot) vectorAdd [0, 0, 0.5];
private _p2 = _p1 vectorAdd [0, 0, -1];

private _intersections = lineIntersectsSurfaces [_p1, _p2, _player];
if (_intersections isEqualTo []) exitWith {};

_intersections select 0 params ["_intersectPos"];
*/

private _helper = "aup_leanOut" createVehicle [0, 0, 0];
private _dir = vectorDir _player;
private _up = vectorUp _player;
_helper setVectorDirAndUp [_dir, _up];
//_helper setPosASL _intersectPos;
_helper setPosASL (_player modelToWorldVisualWorld _pivot);

_pivot params ["_x", "_y", "_z"];
_helper animateSource ["Fw", -0.25, true];
_helper animateSource ["Up", -_z, true];

_player addEventHandler ["HandleDamage", {
    params ["_unit", "_selection", "_damage", "_source", "_projectile", "_hitIndex", "_instigator", "_hitPoint", "_directHit"];
    if (vehicle _unit isKindOf "aup_cargoTurret_base") then {
        if (lifeState _unit == "INCAPACITATED") then {
            _unit removeEventHandler [_thisEvent, _thisEventHandler];
            moveOut _unit;
        };
    } else {
        _unit removeEventHandler [_thisEvent, _thisEventHandler];
    };
}];

[{
    params ["_player"];
    !isWeaponDeployed _player
}, {
    params ["_player", "_helper"];
    _player moveInCargo _helper;
}, [_player, _helper]] call CBA_fnc_waitUntilAndExecute;
