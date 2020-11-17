//#pragma once
//#define SFML_NO_DEPRECATED_WARNINGS
//#include<SFML/Graphics.hpp>
//#include<iostream>
//#include"Player.h"
//#include"Enemy.h"
//#include"Projectile.h"
//#include"Random.h"
//#include"Wall.h"
//#include"HitboxComponent.h"
//#include"TextDisplay.h"
//#include"PickupItem.h"
//#include"Collider.h"
//#include"ViewPlayer.h"
//
//using namespace std;
//using namespace sf;
//
//class FirstLevel
//{
//public:
//	FirstLevel(Font font); 
//	void enemyUpdate();
//	void collideUpdate();
//	void attackBox();
//	void shootBox();
//	void deleteAll();
//	void Draw(RenderWindow& window);
//	void Drawbox(RenderWindow& window);
//	int counter = 0;
//	int counter2 = 0;
//	int counter3 = 0;
//	int zombieKill = 0;
//	int GlockBullet = 0;
//	int SMGBullet = 0;
//	int ShotgunBullet = 0;
//
//	int MaxGlockBullet = 80;
//	int MaxSMGBullet = 100;
//	int MaxShotgunBullet = 50;
//	bool crowb = true;
//	bool pickupCrowbar = false;
//	float deltaTime = 0.0f; 
//	
//	Clock clock1;
//	Clock clock2;
//	Clock clock3;
//
//	//Clock
//	Time elapsed1 = clock1.getElapsedTime();
//	Time elapsed2 = clock2.getElapsedTime();
//	Time elapsed3 = clock3.getElapsedTime();
//
//	Texture playerTexture, boxTexture, enemyTexture, bulletTexture, GlockTexture, SMGTexture, ShotgunTexture, map1, potionHeal, crowbar, sewer;
//
//	//map object
//	RectangleShape map;
//
//	//font
//	Font font, fonthpzombie;
//	
//	//music
//	Music music1;
//	Music zombie1;
//
//	//textdisplay
//	vector<TextDisplay>::const_iterator iterText;
//	vector<TextDisplay> textDisplayArray;
//
//	TextDisplay* textDisplay1;
//
//	//projectile
//	vector<Projectile>::const_iterator iterBullet;
//	vector<Projectile> projectileArray;
//
//	Projectile projectile1;
//	Projectile projectile2;
//	Projectile projectile3;
//
//	//Sound
//	SoundBuffer bufferShot;
//	Sound soundShot;
//
//	//sound effects
//	SoundBuffer bufferShotgun;
//	Sound soundShotgun;
//
//	//sound effects
//	SoundBuffer bufferBox;
//	Sound soundBox;
//
//	//sound effects
//	SoundBuffer bufferHeal;
//	Sound soundHeal;
//
//	//sound effects
//	SoundBuffer bufferZombie;
//	Sound soundZombie;
//
//	//sound effects
//	SoundBuffer bufferPlayer;
//	Sound soundPlayer;
//
//	//wall Vector Array
//	Wall* wallMap10;
//	Wall* wallMap11;
//	Wall* wallMap12;
//	Wall* wallMap13;
//	Wall* wallMap14;
//	Wall* wallMap15;
//	Wall* wallMap16;
//	Wall* wallMap17;
//	Wall* wallMap18;
//	vector<Wall>::const_iterator iterWall;
//	vector<Wall> Wallmap1Array;
//
//	//enemy
//	Enemy* enemy1;
//	vector<Enemy>::const_iterator iterEnemy;
//	vector<Enemy> enemyArray;
//
//	//random
//	Random* random;
//
//	//item
//	PickupItem *BoxG, *BoxSM, *BoxSh, *Glock, *SMG, *Shotgun, *PotionHeal, *Crowbar, *Sewer;
//	vector<PickupItem>::const_iterator iterGlock;
//	vector<PickupItem> GlockArray;
//	vector<PickupItem>::const_iterator iterSMG;
//	vector<PickupItem> SMGArray;
//	vector<PickupItem>::const_iterator iterShotgun;
//	vector<PickupItem> ShotgunArray;
//	vector<PickupItem>::const_iterator iterBoxG;
//	vector<PickupItem> BoxGArray;
//	vector<PickupItem>::const_iterator iterBoxSM;
//	vector<PickupItem> BoxSMArray;
//	vector<PickupItem>::const_iterator iterBoxSh;
//	vector<PickupItem> BoxShArray;
//	vector<PickupItem>::const_iterator iterPoHeal;
//	vector<PickupItem> PotionHealArray;
//	vector<PickupItem>::const_iterator iterCrow;
//	vector<PickupItem> CrowbarArray;
//
//	//Player
//	Player* player;
//
//	//view
//	ViewPlayer* view;
//
//};
//
