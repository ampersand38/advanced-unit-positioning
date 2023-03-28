#include "script_component.hpp"

if (!hasInterface) exitWith {};

addUserActionEventHandler ["AdjustUp", "Activate", {call FUNC(inputStopMove)}];
