#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "level.hpp"

using namespace sf;

class Entity {
	protected:
		double test;
		std::vector<Object> obj;
		double CurrentFrame;
		double x, y;
		double prevX, prevY;
		double w, h;
		double dx, dy;
		Sprite Hero_Sprite;

		std::vector<Texture> Texture_Anim_n;
		std::vector<Texture> Texture_Anim_ne;
		std::vector<Texture> Texture_Anim_e;
		std::vector<Texture> Texture_Anim_se;
		std::vector<Texture> Texture_Anim_s;
		std::vector<Texture> Texture_Anim_sw;
		std::vector<Texture> Texture_Anim_w;
		std::vector<Texture> Texture_Anim_nw;
	public:
		Entity(){};


		FloatRect getRect() {
			return FloatRect(x, y, w, h);
		}
		FloatRect getRect(double x1,double y1) {
			return FloatRect(x+x1, y+y1, w, h);
		}
		//~Entity();
};
