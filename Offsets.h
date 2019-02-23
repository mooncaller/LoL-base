#pragma once
#define TARGET_GAMEVERSION "Version 9.4.264.1140 [PUBLIC]"
/*

version 9.3
		float currentGold; //0x1C94
		DWORD* BuffManager; //0x2288
		DWORD BuffEnd; //0x228C
		int32_t SpellBook; //0x2A40
		class SpellInfo* SpellQ; //0x2F58
		class SpellInfo* SpellW; //0x2F5C
		class SpellInfo* SpellE; //0x2F60
		class SpellInfo* SpellR; //0x2F64
		class SpellInfo* SpellD; //0x2F68
		class SpellInfo* SpellF; //0x2F6C
		class SpellInfo* Slot1; //0x2F70
		class SpellInfo* Slot2; //0x2F74
		class SpellInfo* Slot3; //0x2F78
		class SpellInfo* Slot4; //0x2F7C
		class SpellInfo* Slot5; //0x2F80
		class SpellInfo* Slot6; //0x2F84
		class SpellInfo* Slot7; //0x2F88
		class SpellInfo* Recall; //0x2F8C
		String championName; //0x3380
		int32_t level; //0x4BBC

			#define fnIssueOrder 0x1B9E60
	#define fnAttackDelay 0x59B980
	#define fnAttackCastDelay 0x59B8A0
	#define fnGetBoundingRadius 0x1EC6D0
	#define fnCastSpell 0x594740
	#define fnDrawCircle 0x58B200
	#define fnIsObjHero 0x227780
	#define fnIsObjTurret 0x227950
	#define fnIsObjAlive 0x1DBAD0
	#define fnIsObjMinion 0x2277C0
	#define fnIsObjTargetable 0x221960

	#define oRenderer 0x2EDC604
	#define oLocalPlayer 0x2EC1870
	#define oObjectManager 0x2EC0510
	#define oUnderMouseObject 0x2268524
	#define oHUDInstance 0x1618248
	#define oGameTime 0x2EBCBF0
*/
#define oPrintChat 0x5DA690
#define oDrawCircle 0x598C00
#define oBaseDrawPosition 0x1B2DA0
#define oWorldToScreen 0x7D3E20
#define oUnderMouseObject 0x22D4B84
#define oIsAlive 0x1E08C0
#define oIsInhib 0x224B50
#define oIsNexus 0x224C50
#define oIsTroy 0x224F90
#define oIsTurret 0x224EA0
#define oIsBaron 0x214630
#define oIsDragon 0x213900
#define oIsMinion 0x224D10
#define oIsHero 0x224CD0
#define oIsMissile 0x224D30
#define oIsTargetable 0x21DB90
#define oIssueOrder 0x1BC3D0
#define oGetAttackDelay 0x5A8CD0
#define oGetAttackCastDelay 0x5A8BF0
#define oGetBasicAttack 0x1B1D30
#define oGetSpellState 0x596370
#define oCastSpell 0x5A1DC0
#define oUpdateChargeableSpell 0x5A47A0
#define oChatClientPtr 0x1681D6C
#define oLocalPlayer 0x2F2F4F8
#define oObjManager 0x2F2EF60
#define oHudInstance 0x16843C8
#define oRenderer 0x2F4BFB4
#define oZoomClass 0x2F2B414
#define oGameTime 0x2F2B5F0
#define oGameVersion 0x2F39620



#define oScreenWidth 0x18
#define oScreenHeight 0x1C
#define oViewMatrix 0x64
#define oProjection 0xA4


#define XorKey 0xEFEE81C4
#define oObjIndex 0x20
#define oObjTeam 0x4C
#define oObjName 0x88
#define oObjNetworkID 0x110
#define oObjSourceIndex 0x2CC
#define oObjPos 0x260
#define oObjTargetID 0x318
#define oObjVisibility 0x420
#define oObjHealth 0xF7C
#define oObjMaxHealth 0xF8C
#define oObjMana 0x044C
#define oObjMaxMana 0x45C
#define oObjArmor 0x1448
#define oObjBaseAtk 0x1420
#define oObjBonusAtk 0x13A0
#define oObjBaseMagic 0x1450
#define oObjBonusMagic 0x1454
#define oObjMoveSpeed 0x1460
#define oObjAtkRange 0x1468
#define oObjBuffMgr 0x2290
#define oObjSpellBook 0x2A88
#define oObjChampionName 0x24F0
#define oObjLevel 0x4BCC
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