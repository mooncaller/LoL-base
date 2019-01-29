#pragma once
#include <time.h>
#include "stdafx.h"
#include "guicon.h"
#include "Engine.h"
#include "Hooks.h"
#include "detours.h"
#include "Missile.h"
#include <vector>
#include <iostream>
#include <map>
using namespace std;
class Orbwalker
{
public:


	CObjectManager* ObjManager;

	std::vector<CObject*> getAttackableUnitInRange() {
		std::vector<CObject*> objets;
		if (ObjManager) {
			for (int i = 0; i < 10000; i++) {
				CObject* obj = Engine::GetObjectByID(i);
				if (obj) {
					if (obj->IsHero() || obj->IsMinion() || obj->IsTurret() || obj->IsNexus()) {
						if (obj->IsAlive() && obj->IsVisible() && obj->GetTeam() != me->GetTeam() && obj->GetHealth()>2) {
							if (me->GetPos().DistTo(obj->GetPos()) < me->GetAttackRange() + me->GetBoundingRadius() + obj->GetBoundingRadius()) {
								objets.push_back(obj);
							}
						}
					}
				}
			}
		}
		return objets;
	};

	double ClickerDelay = 0.1;
	float movetimer = 0;
	float attacktimer = 0;

	void ResetMoveTimer()
	{
		movetimer = Engine::GetGameTime();
	};
	void ResetAttackTimer()
	{
		attacktimer = Engine::GetGameTime();
	};

	double CalcAttackDelay()
	{
		return (Engine::GetGameTime() - attacktimer);
	};
	double CalcAttackTime()
	{
		return Functions.GetAttackDelay(me);
	};
	double CalcAttackCast()
	{
		return Functions.GetAttackCastDelay(me);

	};
	bool AttackReady()
	{
		if (CalcAttackDelay() > CalcAttackTime())
		{
			return true;
		}
		else {
			return false;
		}
	};


	std::vector<Missile*> GetMissile() {
		std::vector<Missile*> objets;
		if (ObjManager) {
			for (int i = 0; i < 10000; i++) {
				CObject* obj = Engine::GetObjectByID(i);
				
				if (obj) {
					if (Functions.IsMissile(obj)) {
						//Console.print("%s", obj->GetName());
						objets.push_back((Missile*)obj);
					}
				}
			}
		}
		return objets;
	}

	bool isLastHittable(CObject* minion) {
		float adMultiplier = 0.0f;
		float armor = minion->GetArmor();

		if (armor > 0)
			adMultiplier = 100 / (100 + armor);
		else
			adMultiplier = 2 - (100 / (100 - armor));

		return (minion->GetHealth() - (adMultiplier*me->GetTotalAttackDamage()) <= 0);
	};

	bool KSable(CObject* minion, float damage, int type) {
		if (type == 1) {
			float adMultiplier = 0.0f;
			float armor = minion->GetArmor();

			if (armor > 0)
				adMultiplier = 100 / (100 + armor);
			else
				adMultiplier = 2 - (100 / (100 - armor));

			return (minion->GetHealth() - damage <= 0);
		}
		else {
			float adMultiplier = 0.0f;
			float armor = 100.0f;

			if (armor > 0)
				adMultiplier = 100 / (100 + armor);
			else
				adMultiplier = 2 - (100 / (100 - armor));

			return (minion->GetHealth() - damage <= 0);
		}
	}

	std::vector<CObject*> GetHeroes() {
		std::vector<CObject*> objets;
		for (CObject* obj : getAttackableUnitInRange()) {
			if (Functions.IsHero(obj)) {
				objets.push_back(obj);
			}
		}
		return objets;
	};

	float getReductedPriority(CObject* target) {
		std::map<string, int> Priorities;
		Priorities["Aatrox"] = 2;
		Priorities["Ahri"] = 4;
		Priorities["Akali"] = 3;
		Priorities["Alistar"] = 1;
		Priorities["Amumu"] = 1;
		Priorities["Anivia"] = 4;
		Priorities["Annie"] = 4;
		Priorities["Ashe"] = 4;
		Priorities["AurelionSol"] = 4;
		Priorities["Azir"] = 4;
		Priorities["Bard"] = 1;
		Priorities["Blitzcrank"] = 1;
		Priorities["Brand"] = 4;
		Priorities["Braum"] = 1;
		Priorities["Caitlyn"] = 4;
		Priorities["Cassiopeia"] = 4;
		Priorities["Chogath"] = 2;
		Priorities["Corki"] = 4;
		Priorities["Darius"] = 2;
		Priorities["Diana"] = 3;
		Priorities["Draven"] = 4;
		Priorities["DrMundo"] = 1;
		Priorities["Ekko"] = 4;
		Priorities["Elise"] = 2;
		Priorities["Evelynn"] = 2;
		Priorities["Ezreal"] = 4;
		Priorities["Fiddlesticks"] = 3;
		Priorities["Fiora"] = 3;
		Priorities["Fizz"] = 3;
		Priorities["Galio"] = 2;
		Priorities["Gangplank"] = 2;
		Priorities["Garen"] = 1;
		Priorities["Gnar"] = 1;
		Priorities["Gragas"] = 2;
		Priorities["Graves"] = 4;
		Priorities["Hecarim"] = 1;
		Priorities["Heimerdinger"] = 3;
		Priorities["Illaoi"] = 2;
		Priorities["Irelia"] = 2;
		Priorities["Ivern"] = 2;
		Priorities["Janna"] = 1;
		Priorities["JarvanIV"] = 1;
		Priorities["Jax"] = 2;
		Priorities["Jayce"] = 3;
		Priorities["Jhin"] = 4;
		Priorities["Jinx"] = 4;
		Priorities["Kalista"] = 4;
		Priorities["Karma"] = 4;
		Priorities["Karthus"] = 4;
		Priorities["Kassadin"] = 3;
		Priorities["Katarina"] = 4;
		Priorities["Kayle"] = 3;
		Priorities["Kennen"] = 4;
		Priorities["Khazix"] = 3;
		Priorities["Kindred"] = 4;
		Priorities["Kled"] = 2;
		Priorities["KogMaw"] = 4;
		Priorities["Leblanc"] = 4;
		Priorities["LeeSin"] = 2;
		Priorities["Leona"] = 1;
		Priorities["Lissandra"] = 3;
		Priorities["Lucian"] = 4;
		Priorities["Lulu"] = 1;
		Priorities["Lux"] = 4;
		Priorities["Malphite"] = 1;
		Priorities["Malzahar"] = 4;
		Priorities["Maokai"] = 2;
		Priorities["MasterYi"] = 4;
		Priorities["MissFortune"] = 4;
		Priorities["MonkeyKing"] = 1;
		Priorities["Mordekaiser"] = 3;
		Priorities["Morgana"] = 2;
		Priorities["Nami"] = 1;
		Priorities["Nasus"] = 1;
		Priorities["Nautilus"] = 1;
		Priorities["Nidalee"] = 3;
		Priorities["Nocturne"] = 2;
		Priorities["Nunu"] = 1;
		Priorities["Olaf"] = 1;
		Priorities["Orianna"] = 4;
		Priorities["Pantheon"] = 2;
		Priorities["Poppy"] = 2;
		Priorities["Quinn"] = 4;
		Priorities["Rammus"] = 1;
		Priorities["RekSai"] = 2;
		Priorities["Renekton"] = 1;
		Priorities["Rengar"] = 2;
		Priorities["Riven"] = 3;
		Priorities["Rumble"] = 2;
		Priorities["Ryze"] = 2;
		Priorities["Sejuani"] = 1;
		Priorities["Shaco"] = 3;
		Priorities["Shen"] = 1;
		Priorities["Shyvana"] = 1;
		Priorities["Singed"] = 1;
		Priorities["Sion"] = 1;
		Priorities["Sivir"] = 4;
		Priorities["Skarner"] = 1;
		Priorities["Sona"] = 1;
		Priorities["Soraka"] = 4;
		Priorities["Swain"] = 2;
		Priorities["Syndra"] = 4;
		Priorities["TahmKench"] = 1;
		Priorities["Taliyah"] = 3;
		Priorities["Talon"] = 4;
		Priorities["Taric"] = 1;
		Priorities["Teemo"] = 4;
		Priorities["Thresh"] = 1;
		Priorities["Tristana"] = 4;
		Priorities["Trundle"] = 2;
		Priorities["Tryndamere"] = 2;
		Priorities["TwistedFate"] = 4;
		Priorities["Twitch"] = 4;
		Priorities["Udyr"] = 2;
		Priorities["Urgot"] = 2;
		Priorities["Varus"] = 4;
		Priorities["Vayne"] = 4;
		Priorities["Veigar"] = 4;
		Priorities["Velkoz"] = 4;
		Priorities["Vi"] = 2;
		Priorities["Viktor"] = 4;
		Priorities["Vladimir"] = 3;
		Priorities["Volibear"] = 1;
		Priorities["Warwick"] = 1;
		Priorities["Xerath"] = 4;
		Priorities["XinZhao"] = 2;
		Priorities["Yasuo"] = 3;
		Priorities["Yorick"] = 1;
		Priorities["Zac"] = 1;
		Priorities["Zed"] = 4;
		Priorities["Ziggs"] = 4;
		Priorities["Zilean"] = 3;
		Priorities["Zyra"] = 1;

		if (Priorities[target->GetChampionName()]) {
			if (Priorities[target->GetChampionName()] == 5)
				return 2.5;
			else if (Priorities[target->GetChampionName()] == 4)
				return 2;
			else if(Priorities[target->GetChampionName()] == 3)
				return 1.75;
			else if(Priorities[target->GetChampionName()] == 2)
				return 1.5;
			else if(Priorities[target->GetChampionName()] == 1)
				return 1;
		}
		else {
			return 1;
		}
	}

	float calculateDamage(CObject* from, CObject* to, float rawDamage) {
		return 1;

	}
	CObject* GetTarget(std::vector<CObject*> targets) {
		CObject* selected = nullptr;
		float max = 0;
		if (targets.size() > 0) {
			for (CObject* target : targets) {
				if ((getReductedPriority(target)*calculateDamage(me, target, me->GetTotalAttackDamage()) / target->GetHealth()) > max) {
					//Console.print("Nom: %s \n", target->GetName());
					max = (getReductedPriority(target)*calculateDamage(me, target, me->GetTotalAttackDamage()) / target->GetHealth());
					selected = target;
				}
			}

		}
		return selected;
	};

	bool isPartOf(char* w1, char* w2)
	{
		int i = 0;
		int j = 0;


		while (w1[i] != '\0') {
			if (w1[i] == w2[j])
			{
				int init = i;
				while (w1[i] == w2[j] && w2[j] != '\0')
				{
					j++;
					i++;
				}
				if (w2[j] == '\0') {
					return true;
				}
				j = 0;
			}
			i++;
		}
		return false;
	}

	CObject* GetLastHittableMinion() {
		std::vector<CObject*> objectsInRange = getAttackableUnitInRange();
		for (CObject* minion : objectsInRange) {
			float hPred = minion->GetHealth();
			for (Missile* missile : GetMissile()) {
				if (missile->GetSpellEndPos().DistTo(minion->GetPos()) < 50) {
					if (isPartOf("MinionSiege", missile->GetName())) {
						hPred -= (39.5f + 1.5f * (Engine::GetGameTime() / 90.0f));
					}
					else {
						hPred -= (25.0f + 2 * (Engine::GetGameTime() / 180.0f));
					}
					//Console.print("Hpred: %f \n", hPred);
					
				}
			}

			if (hPred <= 0 || isLastHittable(minion)) {
				return minion;
			}
		}
		return nullptr;
	}

	void Orbwalk(CObject* Target, bool hasTarget)
	{
		if (!hasTarget) {
			Engine::MoveTo(new Vector(Engine::GetMouseWorldPosition()));

		}
		else {
			if (AttackReady() && getAttackableUnitInRange().size() > 0)
			{
					Engine::Attack(Target, 1);
					ResetAttackTimer();
			}
			if (!AttackReady() && getAttackableUnitInRange().size() > 0)
			{
				if (CalcAttackCast() + 0.08f  < CalcAttackDelay())
				{
					//Console.print("AttackDelay: %f |AttackCastDelay: %f | Engine::GetGameTime(): %f\n", CalcAttackCast(), CalcAttackDelay(), CalcAttackCast() + 0.2f);
					Engine::MoveTo(new Vector(Engine::GetMouseWorldPosition()));
					ResetMoveTimer();
				}
			}
			if (getAttackableUnitInRange().size() < 1)
			{
				Engine::MoveTo(new Vector(Engine::GetMouseWorldPosition()));
				ResetMoveTimer();
			}
		}
	};

	void LaneClear() {
		if (GetLastHittableMinion()) {
			Orbwalk(GetLastHittableMinion(), 1);
		}
		else if (GetTarget(GetHeroes())) {
			Orbwalk(GetTarget(GetHeroes()), 1);
		}
		else if (getAttackableUnitInRange().size() > 0) {
						Orbwalk(getAttackableUnitInRange().at(0), 1);
		}
		else {
			Orbwalk(me, 0);
		}
		
	}

	void LastHit() {
		if (GetLastHittableMinion()) {
			Orbwalk(GetLastHittableMinion(), 1);
		}
		else if (GetTarget(GetHeroes())) {
			Orbwalk(GetTarget(GetHeroes()), 1);
		}
		else {
			Orbwalk(me, 0);
		}
	}

	void Combo() {
		if (GetTarget(GetHeroes())) {
			/*if (me->GetSpellBook().GetSpellSlotByID(0)->GetTime() == 0) {
				me->CastSpellTarget(GetTarget(GetHeroes()), 0);
			}*/
			Console.print("%s", me->GetChampionName());
			//TRISTANA COMBO
			if (isPartOf("Tristana", me->GetChampionName())) {
				if (Engine::IsReady(0, me))
					Engine::CastSpellSelf(0);

				if (Engine::IsReady(2, me))
					Engine::CastSpellTargetted(2, GetTarget(GetHeroes()));

				if (GetTarget(GetHeroes())->GetHealth() / GetTarget(GetHeroes())->GetMaxHealth() < 0.1f && (Engine::IsReady(3, me))) {
					if (me->GetSpellBook()->GetSpellSlotByID(3)->GetLevel() == 1 && KSable(GetTarget(GetHeroes()), 300, 0)) {
						Engine::CastSpellTargetted(3, GetTarget(GetHeroes()));
					}
					else if (me->GetSpellBook()->GetSpellSlotByID(3)->GetLevel() == 2 && KSable(GetTarget(GetHeroes()), 400, 0)) {
						Engine::CastSpellTargetted(3, GetTarget(GetHeroes()));
					}
					else if (me->GetSpellBook()->GetSpellSlotByID(3)->GetLevel() == 3 && KSable(GetTarget(GetHeroes()), 500, 0)) {
						Engine::CastSpellTargetted(3, GetTarget(GetHeroes()));
					}
				}
				
			}
			else if (isPartOf("Twitch",me->GetChampionName())) {
				if (Engine::IsReady(1,me))
					Engine::CastSpellPos(1, GetTarget(GetHeroes())->GetPos());
			}
			else if (isPartOf("Vayne", me->GetChampionName())) {
				
			}

			Orbwalk(GetTarget(GetHeroes()), 1);
		}
		else {
			Orbwalk(me, 0);
		}
		
	}

	void Harass() {

	};

};

