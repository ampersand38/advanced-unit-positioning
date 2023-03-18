#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"cba_main"};
        author = "Ampersand";
        authors[] = {"Ampersand"};
        authorUrl = "https://github.com/ampersand38/mout-fighting-positions";
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"

class CfgVehicles {
    class StaticBase;
    class mfp_leanOut: StaticBase {
        author = "Ampersand";
        _generalMacro = mfp_leanOut;
        scope = 1;
    };
};
