class Extended_PreStart_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preStart));
    };
};

class Extended_PreInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_preInit));
    };
};

class Extended_PostInit_EventHandlers {
    class ADDON {
        init = QUOTE(call COMPILE_FILE(XEH_postInit));
    };
};

class Extended_GetOut_EventHandlers {
    class aup_cargo_base {
        getOut = QUOTE(call FUNC(handleGetOut););
    };
    class aup_cargoTurret_base: aup_cargo_base {};
};
