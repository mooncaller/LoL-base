#pragma once
#define TARGET_GAMEVERSION "Version 9.5.265.6479 [PUBLIC]"
#define oCastSpell 0x5AF790 //0xF9F790
#define oIsTroy 0x226860 //0xC16860
#define oIsMissile 0x226600 //0xC16600
#define oIsNotWall 0x7576A0 //0x11476A0
#define oIsTargetable 0x21F600 //0xC0F600
#define oIsNexus 0x226520 //0xC16520
#define oIsHero 0x2265A0 //0xC165A0
#define oDrawCircle 0x5A7940 //0xF97940
#define oIsDragon 0x215080 //0xC05080
#define oUpdateChargeableSpell 0x5B1F60 //0xFA1F60
#define oIsMinion 0x2265E0 //0xC165E0
#define oIsBaron 0x215C50 //0xC05C50
#define oIsAlive 0x1E2560 //0xBD2560
#define oIsInhib 0x226420 //0xC16420
#define oPrintChat 0x5EA6E0 //0xFDA6E0
#define oGetBasicAttack 0x1B3960 //0xBA3960
#define oIssueOrder 0x1BE3D0 //0xBAE3D0
#define oIsTurret 0x226770 //0xC16770
#define oGetAttackDelay 0x5B8030 //0xFA8030
#define oGetAttackCastDelay 0x5B7F50 //0xB6B8D0
#define oGetSpellState 0x5A5440 //0xF95440

#define oRenderer 0x2F5D88C //0x394D88C
#define oChatClientPtr 0x1692E0C //0x2082E0C
#define oGameVersion 0x2F4AB50 //0x393AB50
#define oObjManager 0x2F3FF78 //0x392FF78
#define oLocalPlayer 0x2F407EC //0x39307EC
#define oGameTime 0x2F3C6E8 //0x392C6E8
#define oZoomClass 0x2F3C4F8 //0x392C4F8
#define oHudInstance 0x1695410 //0x2085410

#define oScreenWidth 0x18
#define oScreenHeight 0x1C
#define oViewMatrix 0x64
#define oProjection 0xA4

#define oObjBuffMgr 0x22A0
#define oObjSpellBook 0x2A98
#define oObjChampionName 0x2500
#define XorKey 0xEFEE81C4
#define oObjIndex 0x20
#define oObjTeam 0x4C
#define oObjName 0x88
#define oObjNetworkID 0x110
#define oObjSourceIndex 0x2D4
#define oObjPos 0x264
#define oObjTargetID 0x320 //not sure, didn't test.
#define oObjVisibility 0x428
#define oObjHealth 0xF84
#define oObjArmor 0x1450
#define oObjBaseAtk 0x1428
#define oObjBonusAtk 0x13A8
#define oObjMoveSpeed 0x1468
#define oObjAtkRange 0x1470
#define oObjCombatType 0x21D0
#define oObjLevel 0x4BAC
#define oObjMaxHealth 0xF94
#define oObjMana 0x454
#define oObjMaxMana 0x464

#define oObjSpellStartPos 0x2E4
#define oObjSpellEndPos 0x2F0

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