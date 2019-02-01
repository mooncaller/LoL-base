#pragma once

#include "Vector.h"
#include "Utils.h"
#include "CObject.h"
#include "Engine.h"
#include <d3dx9.h>
#pragma once

class LinePrediction
{
public:

	static struct LineInfo_t
	{
		SpellData*data;
	};

	LinePrediction()
	{

	}

	
	float Length(Vector&vec)
	{
		return (float)sqrt((vec.X * vec.X) + (vec.Y * vec.Y) + (vec.Z * vec.Z));
	}

	void Normalize(Vector&vec)
	{
		float length = Length(vec);
		if (length != 0)
		{
			float inv = 1.0f / length;
			vec.X *= inv;
			vec.Y *= inv;
			vec.Z *= inv;
		}
	}

	Vector Calculate(CObject * target, float range, float missilespeed, float casttime);

	Vector Predict(CObject * target, float range, float missilespeed, float casttime);

	~LinePrediction()
	{
	}

private:


};

class CirclePrediction
{
public:



	float Length(Vector&vec)
	{
		return (float)sqrt((vec.X * vec.X) + (vec.Y * vec.Y) + (vec.Z * vec.Z));
	}

	void Normalize(Vector&vec)
	{
		float length = Length(vec);
		if (length != 0)
		{
			float inv = 1.0f / length;
			vec.X *= inv;
			vec.Y *= inv;
			vec.Z *= inv;
		}
	}

	Vector Calculate(CObject * target, float range, float missilespeed, float radius, float casttime);

	CirclePrediction()
	{
	}

	~CirclePrediction()
	{
	}

private:




};

class Prediction
{


public:
	Prediction();
	~Prediction();

	Prediction(LinePrediction* pred)
	{
		LinePred = pred;
	}
	Prediction(CirclePrediction* pred)
	{
		CircPred = pred;
	}

	enum CollisionType
	{
		Minion
	};
	bool BoundBox(D3DXVECTOR2 cursorPos, D3DXVECTOR2 Pos, D3DXVECTOR2 Size)
	{
		return Pos.x >= cursorPos.x - Size.x && Pos.x <= cursorPos.x + Size.x && Pos.y >= cursorPos.y - Size.y && Pos.y <= cursorPos.y + Size.y /*sol*/ &&  cursorPos.x >= Pos.x /*üst*/ && cursorPos.y >= Pos.y;
	}
	bool PointInLineSegment(D3DXVECTOR2 segmentStart, D3DXVECTOR2 segmentEnd, D3DXVECTOR2 point)
	{

		auto crossproduct = (point.y - segmentStart.y) * (segmentEnd.x - segmentStart.x) - (point.x - segmentStart.x) * (segmentEnd.y - segmentStart.y);
		if (abs(crossproduct) > 2)
		{
			return false;
		}

		auto dotproduct = (point.x - segmentStart.x) * (segmentEnd.x - segmentStart.x) + (point.y - segmentStart.y) * (segmentEnd.y - segmentStart.y);
		if (dotproduct < 0)
		{
			return false;
		}

		auto squaredlengthba = (segmentEnd.x - segmentStart.x) * (segmentEnd.x - segmentStart.x) + (segmentEnd.y - segmentStart.y) * (segmentEnd.y - segmentStart.y);
		if (dotproduct > squaredlengthba)
		{
			return false;
		}

		return true;
	}
	bool PointOnLineSegment(D3DXVECTOR2 pt1, D3DXVECTOR2 pt2, D3DXVECTOR2 pt, double epsilon = 0.001)
	{
		if (pt.x - std::fmax(pt1.x, pt2.x) > epsilon ||
			std::fmin(pt1.x, pt2.x) - pt.x > epsilon ||
			pt.y - std::fmax(pt1.y, pt2.y) > epsilon ||
			std::fmin(pt1.y, pt2.y) - pt.y > epsilon)
			return false;

		if (abs(pt2.x - pt1.x) < epsilon)
			return abs(pt1.x - pt.x) < epsilon || abs(pt2.x - pt.x) < epsilon;
		if (abs(pt2.y - pt1.y) < epsilon)
			return abs(pt1.y - pt.y) < epsilon || abs(pt2.y - pt.y) < epsilon;

		double x = pt1.x + (pt.y - pt1.y) * (pt2.x - pt1.x) / (pt2.y - pt1.y);
		double y = pt1.y + (pt.x - pt1.x) * (pt2.y - pt1.y) / (pt2.x - pt1.x);

		return abs(pt.x - x) < epsilon || abs(pt.y - y) < epsilon;
	}


	std::vector<CObject*> getEnemyMinions() {
		std::vector<CObject*> objets;
		if (ObjManager) {
			for (int i = 0; i < 10000; i++) {

				CObject* obj = Engine::GetObjectByID(i);
				if (obj) {
					if (obj->IsMinion()) {
						if (obj->IsAlive() && obj->IsVisible() && obj->GetTeam() != me->GetTeam() && obj->IsTargetable() && obj->GetMaxHealth() < 15000.0f) {
							objets.push_back(obj);
						}
					}

				}
			}
		}
		return objets;
	};


	bool IsCollisioned(CollisionType type, Vector vec, float radius)
	{
		Engine* engine = new Engine();
		D3DXVECTOR3 vecto;

		vecto.x = vec.X;
		vecto.y = vec.Y;
		vecto.z = vec.Z;

		auto local = me;
		switch (type)
		{
		case Minion:
		{
			for (CObject*minion : getEnemyMinions())
			{


				auto base = (CObject*)minion;
				auto basecord = base->GetPos();//LinePred->Calculate(base);


	
				D3DXVECTOR2 pt1, pt2, pt;
				D3DXVECTOR3 basePos;

				basePos.x = basecord.X;
				basePos.y = basecord.Y;
				basePos.z = basecord.Z;

				pt = engine->WorldToScreen(basePos);

				D3DXVECTOR3 pos;

				pos.x = local->GetPos().X;
				pos.y = local->GetPos().Y;
				pos.z = local->GetPos().Z;
				pt1 = engine->WorldToScreen(pos);
				pt2 = engine->WorldToScreen(vecto);
#ifdef linepred
				render.DrawLine(pt.x, pt.y, pt2.x, pt2.y, 10, D3DCOLOR_ARGB(255, 255, 20, 147));
				render.DrawLine(pt2.x, pt2.y, pt1.x, pt1.y, 10, D3DCOLOR_ARGB(255, 255, 165, 0));
#endif

				if (PointOnLineSegment(D3DXVECTOR2(pt1.x, pt1.y), D3DXVECTOR2(pt2.x, pt2.y), D3DXVECTOR2(pt.x, pt.y), radius))
				{
					Console.print("Nom %s \n", base->GetName());
					Console.print("Point depart %f %f \n", pt1.x, pt1.y);
					Console.print("Point fin %f %f \n", pt2.x, pt2.y);
					Console.print("Point dessus %f %f \n", pt.x, pt.y);
					return true;
				}



			}
			break;
		}
		}

		return false;
	}

	LinePrediction* LinePred;
	CirclePrediction* CircPred;
};
