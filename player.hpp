#pragma once
#include "entity.hpp"
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Player : public Entity {
	private:
		int countTest;
		double rotation;
		double distance;

		vector<Texture> Gen_Vec(const string& str,int count);
		double calculate_angle(const Vector2f &vec);
		void move(const Vector2f &pos, float &time);
		bool checkCollision(double x, double y);
	public:
		Player(Level& lvl,double x,double y,int h,int w);
		void Draw(sf::RenderWindow &window,View viev);
		void update(const Vector2f &pos,float &time);
		double getPlayerCoordinateX();
		double getPlayerCoordinatrY();
		//~Player();
};

Player::Player(Level& lvl,double z,double d,int h1,int w1) {
	prevX = x = z;
	prevY = y = d;
	w = w1;
	h = h1;
	obj = lvl.GetAllObjects();


	Texture_Anim_e = Gen_Vec("image/run_e/running_e000", 8);
	Texture_Anim_s = Gen_Vec("image/run_s/running s000", 8);
	Texture_Anim_n = Gen_Vec("image/run_n/running n000", 8);
	Texture_Anim_w = Gen_Vec("image/run_w/running w000", 8);
	Texture_Anim_se = Gen_Vec("image/run_se/running se000", 8);
	Texture_Anim_sw = Gen_Vec("image/run_sw/running sw000", 8);
	Texture_Anim_ne = Gen_Vec("image/run_ne/running ne000", 8);
	Texture_Anim_nw = Gen_Vec("image/run_nw/running nw000", 8);

	Hero_Sprite.setTexture(Texture_Anim_e[0]);
	Hero_Sprite.setPosition(x,y);

}
vector<Texture> Player::Gen_Vec(const string& str,int count) {
	Texture Hero_Texture;
	vector<Texture> vec;
	for (unsigned i = 0; i < count; ++i) {
		Hero_Texture.loadFromFile(str + to_string(i) + ".psd");
		vec.push_back(Hero_Texture);
	}
	return vec;
}

void Player::Draw(sf::RenderWindow &window,View view) {
	Hero_Sprite.setOrigin(48,48);
	view.setCenter(x+50,y+50);
	window.setView(view);
	window.draw(Hero_Sprite);
}

double Player::calculate_angle(const Vector2f &vec) {
	dx = vec.x - x;
	dy = vec.y - y;
	return (atan2(dy, dx)) * 180 / 3.14159265;
}
bool Player::checkCollision(double x,double y) {
	for (int i = 0; i < obj.size(); i++)
		if (getRect(x,y).intersects(obj[i].rect) && obj[i].name != "Player")
			return true;

	return false;
}
void Player::move(const Vector2f &pos, float &time) {
	rotation = calculate_angle(pos);
	distance = sqrt((pos.x - x)*(pos.x - x) + (pos.y - y)*(pos.y - y));
	if (distance > 0)
		if (!checkCollision(0.1*time*(pos.x - x) / distance, 0.1*time*(pos.y - y) / distance))
			Hero_Sprite.move(0.1*time*(pos.x - x) / distance, 0.1*time*(pos.y - y) / distance);
		else
			Hero_Sprite.setPosition(Hero_Sprite.getPosition().x, Hero_Sprite.getPosition().y);

}

void Player::update(const Vector2f &pos,float &time) {

	move(pos, time);

	CurrentFrame +=0.03*time;
	if (CurrentFrame > test) {
		test = CurrentFrame;
	}
	if (CurrentFrame > 14) CurrentFrame = 0;

		if (rotation < 22.5 && rotation > -22.5) {
			Hero_Sprite.setTexture(Texture_Anim_e[CurrentFrame/2]);
		}
		if (rotation >= 22.5 && rotation <= 67.5) {
			Hero_Sprite.setTexture(Texture_Anim_se[CurrentFrame/2]);
		}
		if (rotation > 67.5 && rotation < 112.5) {
			Hero_Sprite.setTexture(Texture_Anim_s[CurrentFrame/2]);
		}
		if (rotation >= 112.5 && rotation <= 157.5) {
			Hero_Sprite.setTexture(Texture_Anim_sw[CurrentFrame/2]);
		}
		if (rotation > 157.5 && rotation > -157.5) {
			Hero_Sprite.setTexture(Texture_Anim_w[CurrentFrame/2]);
		}
		if (rotation <= -112.5 && rotation >= -157.5) {
			Hero_Sprite.setTexture(Texture_Anim_nw[CurrentFrame/2]);
		}
		if (rotation < -67.5 && rotation > -112.5) {
			Hero_Sprite.setTexture(Texture_Anim_n[CurrentFrame/2]);
		}
		if (rotation >= -67.5 && rotation <= -22.5) {
			Hero_Sprite.setTexture(Texture_Anim_ne[CurrentFrame/2]);
		}


	x = Hero_Sprite.getPosition().x;
	y = Hero_Sprite.getPosition().y;
}

double Player::getPlayerCoordinateX() {
	return x;
}
double Player::getPlayerCoordinatrY() {
	return y;
}
