class CfgVehicles
{
    class StaticWeapon;
    class aup_cargo_base: StaticWeapon
    {
        _generalMacro = "aup_cargo_base";
        author = "Ampersand";
        scope = 1;

        model = QPATHTOF(data\leanOut.p3d);
        //picture = "\A3\Static_F\HMG_02\Data\UI\icon_HMG_02_ca.paa";
        //UiPicture = "\A3\Static_F\HMG_02\Data\UI\icon_HMG_02_ca.paa";

        displayName = "Holding";
        transportSoldier = 1;
        cargoAction[] = {"passenger_boat_holdleft2"};
        cargoPreciseGetInOut[] = {1};
    	cargoProxyIndexes[] = {1};
    	memoryPointsGetInCargo = "pos cargo";
    	memoryPointsGetInCargoDir = "pos cargo dir";
    	memoryPointsGetInCargoPrecise[] = {"pos cargo"};

        class UserActions {};
    };
    class aup_cargoTurret_base: aup_cargo_base
    {
        _generalMacro = "aup_cargoTurret_base";
        author = "Ampersand";
        scope = 1;

        class CargoTurret;
        class Turrets;
    };



    class aup_leanOut: aup_cargoTurret_base
    {
        _generalMacro = "aup_leanOut";
        author = "Ampersand";
        scope = 1;
        displayName = "Leaning";

        class Turrets: Turrets
        {
            class CargoTurret_01: CargoTurret
            {
                gunnerAction = "passenger_flatground_4_vehicle_passenger_stand_1";
                gunnerInAction = "passenger_flatground_4_vehicle_passenger_stand_1";
                memoryPointsGetInGunner = "pos cargo";
                memoryPointsGetInGunnerDir = "pos cargo dir";
        		memoryPointsGetInGunnerPrecise = "pos cargo";
    			preciseGetInOut = 1;
                gunnerName = "Leaning";
                proxyIndex = 1;
                isPersonTurret = 2;        /// enables a person to get into the turret from outside
                maxElev = 45;
                minElev = -45;
                maxTurn = 95;
                minTurn = -95;
            };
        };
    };
};
