//#pragma once
//#define SFML_NO_DEPRECATED_WARNINGS
//#include<SFML/Graphics.hpp>
//#include<iostream>
//#include"Player.h"
//#include"Enemy.h"
//#include"Enemy3.h"
//#include"Projectile.h"
//#include"Random.h"
//#include"Wall.h"
//#include"HitboxComponent.h"
//#include"TextDisplay.h"
//#include"PickupItem.h"
//#include"Collider.h"
//#include"ViewPlayer.h"
//#include"MenuBG.h"
//#include"Button.h"
//#include"Textbox.h"
//#include"Pause.h"
//#include"Chatbox.h"
//#include"Wall2.h"
//#include"Wall3.h"
//#include"Wall4.h"
//#include"GenBar.h"
//
//#include<iostream>
//#include<ctime>
//#include<cstdlib>
//#include<fstream>
//#include<vector>
//#include<stack>
//#include<map>
//
//#include"SFML\System.hpp"
//#include"SFML\Window.hpp"
//#include"SFML\Graphics.hpp"
//#include"SFML\Audio.hpp"
//#include"SFML\Network.hpp"
//
//using namespace sf;
//using namespace std;
//
//class GameState
//{
//public:
//	GameState();
//
//	RenderWindow* window; 
//	Texture E, keyTexture, map2Texture, map3Texture, map4Texture, map5Texture, playerTexture, boxTexture, enemyTexture, enemy2Texture, enemy3Texture, enemy4Texture, bulletTexture, GlockTexture, SMGTexture, ShotgunTexture, map1, potionHeal, crowbar, sewer, background;
//	Clock clock1;
//	Clock clock2;
//	Clock clock3;
//	Clock clock4;
//
//	int level = 1;
//	int menulevel = 1;
//	int gen = 0;
//	int maxgen = 6;
//	int counter = 0;
//	int counter2 = 0;
//	int counter3 = 0;
//	int zombieKill = 0;
//	int num, ran;
//	int MaxZombie = 15;
//	bool crowb = true;
//	bool pickupCrowbar = false;
//	bool pause = false;
//	bool chat = true;
//	int chatbox = 0;
//	float gen1size = 0, gen2size = 0, gen3size = 0, gen4size = 0, gen5size = 0, gen6size = 0;
//	bool gen1fixed = false, gen2fixed = false, gen3fixed = false, gen4fixed = false, gen5fixed = false, gen6fixed = false;
//	bool keycard = false;
//	bool menustate = true;
//
//	int GlockBullet = 0;
//	int SMGBullet = 0;
//	int ShotgunBullet = 0;
//
//	int MaxGlockBullet = 80;
//	int MaxSMGBullet = 100;
//	int MaxShotgunBullet = 50;
//
//	void Update();
//};
//
