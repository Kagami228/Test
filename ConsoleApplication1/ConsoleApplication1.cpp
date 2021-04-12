#include <iostream>
#include "Person.h"
#include <vector>

void sy(std::string& p) {

}

void reversy(std::string& p) {
	std::string tmp_S = "";
	std::string tmp_S2 = "";

	for (int i = 0; i < p.size(); i++) {
		if (p[i] == ';' or i == p.size() - 1) {
			int l = tmp_S.size();

			for (int j = 0; j < (l) / 2; j++) {
				std::swap(tmp_S[j], tmp_S[l - j - 1]);

			}

			tmp_S2 = tmp_S2 + tmp_S + ";";
			tmp_S = "";
		}
		else {
			tmp_S.push_back(p[i]);
		}
	}
	p = tmp_S2;
}


int main() {
	std::string ss = "First string;Second string;Third string;4th string";
	reversy(ss);
	std::cout << ss << std::endl;
	std::vector<IGameObject*> objects = { new Human("Rodg"), new Human("Julia"),new Android("Oreo"), new Beast("Jinx"),new Beast("Koil") };
	for (auto o : objects) {
		auto movable_object = dynamic_cast<IMovable*>(o);
		if (movable_object != nullptr)
		{
			movable_object->Move(IMovable::Direction::FlY);
			movable_object->Move(IMovable::Direction::JUMP);
			movable_object->Move(IMovable::Direction::RUN);
			movable_object->Move(IMovable::Direction::WALK);
		}
		auto can_damage_object = dynamic_cast<ICanDemage*>(o);
		if (can_damage_object != nullptr)
		{
			can_damage_object->ShootOrBit(ICanDemage::Damagem::BIT);
			can_damage_object->ShootOrBit(ICanDemage::Damagem::SHOOT);
		}
		auto damaggable_object = dynamic_cast<IDamagable*>(o);
		if (damaggable_object != nullptr)
		{
			damaggable_object->Damage();
			damaggable_object->Damage();
		}
	}



	//Human h;
	//ISkinable::Skin s;
	//s.model = "Human";
	//s.color = "red";
	//h.ApplySkin(s);
	//h.Damage();
	//std::string c=h.ModelName();
	//std::cout <<"\n"<< c<<std::endl;
	//h.ShootOrBit(ICanDemage::Damagem::SHOOT);

}