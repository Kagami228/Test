#pragma once
#include <string>
#include <iostream>

struct IGameObject
{
	virtual ~IGameObject() {};
};
struct IMovable
{
	virtual ~IMovable() {};
	enum class Direction
	{
		FlY,
		WALK,
		RUN,
		JUMP
	};
	virtual void Move(Direction d) = 0;
};
std::ostream& operator<<(std::ostream& s, IMovable::Direction d) {
	switch (d)
	{
	case IMovable::Direction::FlY:
		return s << "fly";
		break;
	case IMovable::Direction::WALK:
		return s << "walk";
		break;
	case IMovable::Direction::RUN:
		return s << "run";
		break;
	case IMovable::Direction::JUMP:
		return s << "jump";
		break;
	default:
		break;
	}
}
struct ICanDemage
{
	virtual ~ICanDemage() {};
	enum class Damagem
	{
		SHOOT,
		BIT
	};
	virtual void ShootOrBit(Damagem d) = 0;
};

std::ostream& operator<<(std::ostream& s, ICanDemage::Damagem d) {
	switch (d)
	{
	case ICanDemage::Damagem::SHOOT:
		return s << "shoot";
		break;
	case ICanDemage::Damagem::BIT:
		return s << "bit";
		break;
	default:
		break;
	}
}

struct IDamagable
{
	virtual ~IDamagable() {}
	virtual void Damage() = 0;
};

struct ISkinable
{
	struct Skin
	{
		std::string model;
		std::string color;
	};
	virtual ~ISkinable() {}
	virtual std::string ModelName() = 0;
	virtual void ApplySkin(const Skin& s) {
		if (s.model == ModelName()) {
			std::cout << "Apply color for " << ModelName() << std::endl;
		}
	}
};



class Human :public IGameObject,public IMovable, public ICanDemage, public IDamagable, public ISkinable
{
	std::string _name;
public:
	Human(const std::string& name):_name(name){

	}
	void Move(Direction d) override {
		if (d == Direction::RUN || d == Direction::JUMP)
			std::cout << ModelName()<< " " << _name << " move " << d << std::endl;

	}
	void ShootOrBit(Damagem damage) override {
		if (damage == Damagem::SHOOT) {
			std::cout << ModelName() << " " << _name << " can - " << damage << std::endl;
		}
	}
	std::string ModelName() override {
		return "Human";
	}
	void Damage() {
		std::cout << ModelName() << _name << " yes i can receive damage";
	}
};


class Android :public IGameObject,public IMovable, public ICanDemage, public IDamagable, public ISkinable
{
	std::string _name;
public:
	Android(const std::string& name) :_name(name) {

	}

	void Move(Direction d) override {
		if (d == Direction::WALK || d == Direction::FlY)
			std::cout << ModelName() << " " << _name << " move " << d << std::endl;
	}
	void ShootOrBit(Damagem damage) override {
		if (damage == Damagem::SHOOT) {
			std::cout << ModelName() << " " << _name << " can - " << damage << std::endl;
		}
	}
	std::string ModelName() override {
		return "Android";
	}
	void Damage() {
		std::cout << ModelName() << _name << " yes i can receive damage";
	}
};

class Beast :public IGameObject,public IMovable, public ICanDemage, public IDamagable, public ISkinable
{
	std::string _name;
public:
	Beast(const std::string& name) :_name(name) {

	}
	void Move(Direction d) override {
		if (d == Direction::RUN || d == Direction::FlY)
			std::cout << ModelName() << " " << _name << " move " << d << std::endl;
	}
	void ShootOrBit(Damagem damage) override {
		if (damage == Damagem::BIT) {
			std::cout << ModelName() << " " << _name << " can - " << damage << std::endl;
		}
	}
	std::string ModelName() override {
		return "Beast";
	}
	void Damage() {
		std::cout << ModelName() << _name << " yes i can receive damage\n";
	}
};
