#pragma once
#include <SFML/Graphics.hpp> 
#include "const.h"

using namespace sf;

struct Pendulum {
	CircleShape upCog, downCog;
	ConvexShape base, cargo, leftPartArrow, rightPartArrow;
	float rotation = 35, rotGearUp = 0, rotGearDown = 29;
	float speed = -0.001;
	float acceleration = -0.0005;
	bool downhill = true;

	void InitElementsOfPendulum()
	{
		InitCog(upCog, downCog);
		InitPendulum();
		upCog.setRotation(rotGearUp);
		downCog.setRotation(rotGearDown);
	}

	void InitCog(CircleShape &upCog, CircleShape &downCog) {
		upCog.setRadius(150);
		upCog.setPosition(220, 160);
		upCog.setOrigin(150, 150);
		downCog.setRadius(150);
		downCog.setPosition(330, 370);
		downCog.setOrigin(150, 150);
	}

	void InitPendulum()
	{
		base.setPointCount(4);
		base.setPoint(0, Vector2f(120, 0));
		base.setPoint(1, Vector2f(130, 300));
		base.setPoint(2, Vector2f(120, 320));
		base.setPoint(3, Vector2f(110, 300));
		PositionConvex(base);

		cargo.setPointCount(4);
		cargo.setPoint(0, sf::Vector2f(120, 315));
		cargo.setPoint(1, sf::Vector2f(130, 340));
		cargo.setPoint(2, sf::Vector2f(120, 380));
		cargo.setPoint(3, sf::Vector2f(110, 340));
		PositionConvex(cargo);
		cargo.setFillColor(Color::Yellow);

		leftPartArrow.setPointCount(3);
		leftPartArrow.setPoint(0, Vector2f(40, 60));
		leftPartArrow.setPoint(1, Vector2f(120, 0));
		leftPartArrow.setPoint(2, Vector2f(120, 30));
		PositionConvex(leftPartArrow);

		rightPartArrow.setPointCount(3);
		rightPartArrow.setPoint(0, Vector2f(200, 60));
		rightPartArrow.setPoint(1, Vector2f(120, 0));
		rightPartArrow.setPoint(2, Vector2f(120, 30));
		PositionConvex(rightPartArrow);
	}

	void PositionConvex(ConvexShape &convex)
	{
		convex.setPosition(INITAL_POSITION_PENDULUM.x, INITAL_POSITION_PENDULUM.y);
		convex.setFillColor(Color::Yellow);
		convex.setOrigin(120, 0);
	}

	void Update()
	{
		CalculationSpeed();
		UpdateRotation();
	}

	void CalculationSpeed()
	{
		if (int(speed * 1000) == 0)
		{
			speed = acceleration * 2;
			downhill = true;
		}
		if (int(rotation) == 0 && downhill)
		{
			speed += acceleration * 10;
			acceleration = -acceleration;
			downhill = false;
		}
		rotGearUp -= acceleration * 100;
		rotGearDown += acceleration * 100;
		speed += acceleration;
		rotation += speed;
	}

	void UpdateRotation()
	{
		base.setRotation(rotation);
		cargo.setRotation(rotation);
		leftPartArrow.setRotation(rotation);
		rightPartArrow.setRotation(rotation);
		upCog.setRotation(rotation);
		downCog.setRotation(-rotation);
	}

}pendulum;