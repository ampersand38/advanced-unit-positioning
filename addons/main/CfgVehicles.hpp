class CfgVehicles
{
    class LandVehicle;
    class StaticWeapon: LandVehicle
    {
        class CargoTurret;
        class EventHandlers;
        class Turrets;
    };

    class aup_cargo_base: StaticWeapon
    {
        _generalMacro = "aup_cargo_base";
        author = "Ampersand";
        scope = 1;
        model = QPATHTOF(data\cargoTurret.p3d);
        //picture = "\A3\Static_F\HMG_02\Data\UI\icon_HMG_02_ca.paa";
        //UiPicture = "\A3\Static_F\HMG_02\Data\UI\icon_HMG_02_ca.paa";

        transportSoldier = 1;
        cargoAction[] = {"passenger_boat_holdleft2"};
        cargoPreciseGetInOut[] = {1};
    	cargoProxyIndexes[] = {1};
    	memoryPointsGetInCargo = "pos cargo";
    	memoryPointsGetInCargoDir = "pos cargo dir";
    	memoryPointsGetInCargoPrecise[] = {"pos cargo"};
        soundAttenuationCargo[] = {0};
        showNVGCargo[] = {1};
        extCameraPosition[] = {0, 0.300000, -3.500000};	// man

        class Turrets {};
        class UserActions {};
    }; // aup_cargo_base

    class aup_holdOn: aup_cargo_base
    {
        _generalMacro = "aup_holdOn";
        displayName = "Holding";
    }; // aup_cargoTurret_base



    class aup_cargoTurret_base: StaticWeapon
    {
        _generalMacro = "aup_cargoTurret_base";
        author = "Ampersand";
        scope = 1;
        model = QPATHTOF(data\cargoTurret.p3d);

        class AnimationSources
        {
            class Up {
                source = "user";
        		animPeriod = 1;
        		initPhase = 0;
            };
            class Fw: Up {};
        };
        class Turrets: Turrets
        {
            class CargoTurret: CargoTurret
            {
        		allowLauncherIn = 1;
        		allowLauncherOut = 1;
                gunnerInAction = "";
                memoryPointsGetInGunner = "pos cargo";
                memoryPointsGetInGunnerDir = "pos cargo dir";
        		memoryPointsGetInGunnerPrecise = "pos cargo";
                forceHideGunner = 1;
    			gunnerGetInAction = "";
    			gunnerGetOutAction = "";
    			preciseGetInOut = 1;
                proxyIndex = 1;
                isPersonTurret = 2;        /// enables a person to get into the turret from outside
                maxElev = 65;
                minElev = -65;
                maxTurn = 95;
                minTurn = -95;
    			ejectDeadGunner = 1;
            };
        };
        class UserActions {};
    }; // aup_cargoTurret_base

    class aup_leanOut: aup_cargoTurret_base
    {
        _generalMacro = "aup_leanOut";
        displayName = "Leaning";

        class Turrets: Turrets
        {
            class CargoTurret: CargoTurret
            {
                gunnerAction = "passenger_flatground_4_vehicle_passenger_stand_1";
                gunnerInAction = "passenger_flatground_4_vehicle_passenger_stand_1";
                gunnerName = "Leaning";
				animationSourceElevation = "Lean";
            };
        }; // Turrets
    }; // aup_leanOut

    class aup_sit_1: aup_cargoTurret_base
    {
        _generalMacro = "aup_sit_1";
        displayName = "Sitting";

        class Turrets: Turrets
        {
            class CargoTurret: CargoTurret
            {
                gunnerAction = "passenger_flatground_1";
                gunnerInAction = "passenger_flatground_1";
            };
        }; // Turrets
    }; // aup_sit_1
    class aup_sit_2: aup_sit_1
    {
        _generalMacro = "aup_sit_2";
        class Turrets: Turrets
        {
            class CargoTurret: CargoTurret
            {
                gunnerAction = "passenger_flatground_2";
                gunnerInAction = "passenger_flatground_2";
            };
        };
    }; // aup_sit_2
    class aup_sit_3: aup_sit_1
    {
        _generalMacro = "aup_sit_3";
        class Turrets: Turrets
        {
            class CargoTurret: CargoTurret
            {
                gunnerAction = "passenger_flatground_3";
                gunnerInAction = "passenger_flatground_3";
            };
        };
    }; // aup_sit_3
    class aup_sit_4: aup_sit_1
    {
        _generalMacro = "aup_sit_4";
        class Turrets: Turrets
        {
            class CargoTurret: CargoTurret
            {
                gunnerAction = "passenger_flatground_4";
                gunnerInAction = "passenger_flatground_4";
            };
        };
    }; // aup_sit_4
}; // CfgVehicles
