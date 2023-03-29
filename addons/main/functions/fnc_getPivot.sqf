#include "script_component.hpp"
/*
 * Author: Ampersand
 * Returns the position of the weapon deployment pivot of the player's weapon.
 *
 * Arguments:
 * 0: Player <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_unit] call aup_main_fnc_getPivot;
 *
 * Public: No
 */

private _player = call CBA_fnc_currentUnit;

_w = primaryWeapon _player;
//update weapon info upon weapon switch
if (_w != _player getVariable ["aup_lastWeapon", "?"]) then {
    _cfg = configFile >> "CfgWeapons" >> _w;
    _m = getText(_cfg >> "model");
    //if (_m select [0,1] == "\") then {_m = _m select [1]};
    _o = createSimpleObject [_m, [0,0,0], true];
    _off = _o selectionPosition [getText(_cfg >> "deployedPivot"), "memory"];
    _off = _off apply {[_x]};
    deleteVehicle _o;
    _player setVariable ["offset", _off];
    _player setVariable ["last_weapon", _w];
    _player setVariable ["proxy", "proxy:\a3\characters_f\proxies\weapon.001"];
};

_offset = _player getVariable ["offset", []];
_proxy = _player getVariable ["proxy", ""];
// using LOD resolution 1 (and lod index 0). This is not always reliable
// you should manually check allLODs and find the most suitable LOD (smallest res LOD usually has the best accuracy, but it might be slow too)
_player selectionVectorDirAndUp [_proxy, 1] params ["_vy", "_vz"];
_pos = selectionPosition [_player, _proxy, 0];

_vx = _vy vectorCrossProduct _vz;

_mat = matrixTranspose [_vx, _vy, _vz];
_pos vectorAdd flatten(_mat matrixMultiply _offset)
