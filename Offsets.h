#pragma once
#define TARGET_GAMEVERSION "Version 9.2.260.6714 [PUBLIC]"

#define oPrintChat 0x5C9570
#define oGetAttackDelay 0x597D10
#define oGetAttackCastDelay 0x597C30
#define oDrawCircle 0x587920
#define oBaseDrawPosition 0x1B3E70
#define oIsAlive 0x1DFA40
#define oIsInhib 0x227830
#define oIsNexus 0x227930
#define oIsTroy 0x227C70
#define oIsTurret 0x227B80
#define oIsBaron 0x215CE0
#define oIsDragon 0x215090
#define oIsMinion 0x2279F0
#define oIsHero 0x2279B0
#define oIsMissile 0x227A10
#define oIsTargetable 0x221CE0
#define oIssueOrder 0x1BCEE0
#define oGetSpellState 0x585080
#define oCastSpell 0x590D20
#define oUpdateChargeableSpell 0x593790


#define oLocalPlayer 0x2E996BC
#define oObjManager 0x2E99120
#define oGameTime 0x2E957C8
#define oGameVersion 0x2EA2EC0
#define oZoomClass 0x2E955E4
#define oChatClientPtr 0x15EE7B0
#define oHudInstance 0x15F0E48

#define oRenderer 0x2EB51D4
#define oScreenWidth 0x18
#define oScreenHeight 0x1C
#define oViewMatrix 0x64
#define oProjection 0xA4


#define XorKey 0xEFEE81C4
#define oObjIndex 0x20
#define oObjTeam 0x4C
#define oObjName 0x88
#define oObjNetworkID 0x110
#define oObjPos 0x260
#define oObjTargetID 0x318
#define oObjVisibility 0x420
#define oObjHealth 0xF7C
#define oObjArmor 0x1448
#define oObjBaseAtk 0x1420
#define oObjBonusAtk 0x13A0
#define oObjMoveSpeed 0x1460
#define oObjAtkRange 0x1468
#define oObjBuffMgr 0x2260
#define oObjSpellBook 0x29F8
#define oObjChampionName 0x2460
#define oObjLevel 0x4BBC
#define oObjHealthRegen 0x1A08
#define oObjManaRegen 0x1B68 

//Missile

#define missileStartPos 0x2E4
#define missileEndPos 0x2F0

//Buff

#define O_BUFFMGR_BUFFNAME 0x8
#define O_BUFFMGR_STARTTIME 0xC
#define O_BUFFMGR_ENDTIME 0x10
#define O_BUFFMGR_flBUFFCOUNT 0x2C
#define O_BUFFMGR_iBUFFCOUNT 0x70

//AI MGR

#define O_AIMGR_TARGETPOS 0x10
#define O_AIMGR_ISMOVING 0x198
#define O_AIMGR_ISDASHING 0x1E8
#define O_AIMGR_NAVBEGIN 0x1BC //NOT VERIFIED
#define O_AIMGR_NAVEND 0x1C0 //NOT VERIFIED
#define O_AIMGR_HASNAVPATH 0x19C //NOT VERIFIED
#define O_AIMGR_CURRENTPOS 0x2BC //NOT VERIFIED
#define O_AIMGR_VELOCITY 0x2C8 //NOT VERIFIED