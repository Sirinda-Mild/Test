#define SFML_NO_DEPRECATED_WARNINGS
#include<SFML/Graphics.hpp>
#include<iostream>
#include"Player.h"
#include"Enemy.h"
#include"Enemy3.h"
#include"Projectile.h"
#include"Random.h"
#include"Wall.h"
#include"HitboxComponent.h"
#include"TextDisplay.h"
#include"PickupItem.h"
#include"Collider.h"
#include"ViewPlayer.h"
#include"MenuBG.h"
#include"Button.h"
#include"Textbox.h"
#include"Pause.h"
#include"Chatbox.h"
#include"Wall2.h"
#include"Wall3.h"
#include"GenBar.h"

/*#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<stack>
#include<map>

#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
#include"SFML\Network.hpp"*/


using namespace std;

int main()
{
	srand(time(NULL));
	Clock clock1;
	Clock clock2;
	Clock clock3;
	Clock clock4;

	/*int level = 10;*/
	int level = 10;
	int gen = 0;
	int maxgen = 6;
	int counter = 0;
	int counter2 = 0;
	int counter3 = 0;
	int zombieKill = 0;
	int num, ran;
	int MaxZombie = 15;
	bool crowb = true;
	bool pickupCrowbar = false;
	bool pause = false;
	bool chat = true;
	int chatbox = 0;
	float gen1size = 0, gen2size = 0, gen3size = 0, gen4size = 0, gen5size = 0, gen6size = 0;
	bool gen1fixed = false, gen2fixed = false, gen3fixed = false, gen4fixed = false, gen5fixed = false, gen6fixed = false;

	int GlockBullet = 0;
	int SMGBullet = 0;
	int ShotgunBullet = 0;

	int MaxGlockBullet = 80;
	int MaxSMGBullet = 100;
	int MaxShotgunBullet = 50;

	RenderWindow window(VideoMode(1366, 768), "Walking Dead"/*,Style::Fullscreen*/);
	window.setFramerateLimit(90);

	Texture E, map2Texture, map3Texture, playerTexture, boxTexture, enemyTexture, enemy2Texture, enemy3Texture, bulletTexture, GlockTexture, SMGTexture, ShotgunTexture, map1, potionHeal, crowbar, sewer, background;
	playerTexture.loadFromFile("Character/mainFemale02.png");
	enemyTexture.loadFromFile("Character/zombie1-1.png");
	enemy2Texture.loadFromFile("Character/zombie2.png");
	enemy3Texture.loadFromFile("Character/zombie3.png");
	boxTexture.loadFromFile("Item/box.png");
	bulletTexture.loadFromFile("Item/bullet.png");
	GlockTexture.loadFromFile("Item/glock.png");
	SMGTexture.loadFromFile("Item/smg.png");
	ShotgunTexture.loadFromFile("Item/shotgun.png");
	map1.loadFromFile("Map/map1.png");
	map2Texture.loadFromFile("Map/mapsewer2.png");
	map3Texture.loadFromFile("Map/umbrella1stfloor.png");
	potionHeal.loadFromFile("Item/potionHeal.png");
	crowbar.loadFromFile("Item/crowbar.png");
	sewer.loadFromFile("Item/sewer.png");
	E.loadFromFile("Button/E.png");
	if (!background.loadFromFile("Menu/mainmenu8.png")) {
		printf("error");
	}
	
	//button e
	RectangleShape Ebutton;
	Ebutton.setSize(Vector2f(15, 15));
	Ebutton.setTexture(&E);

	//font
	Font font, fonthpzombie, fontMenu;
	font.loadFromFile("Font/ArcadeClassic.ttf");
	fonthpzombie.loadFromFile("Font/DisposableDroidBB.ttf");
	fontMenu.loadFromFile("Font/menufont.ttf");

	//main menu
	MenuBG mainmenuBG(&background, Vector2u(26, 1), 0.1f);

	Pause pausegame;

	//map object
	RectangleShape map, map2, map3;
	map.setTexture(&map1);
	map.setSize(Vector2f(1450, 2000));
	map.setPosition(Vector2f(0, 0));

	map2.setTexture(&map2Texture);
	map2.setSize(Vector2f(1450, 860));
	map2.setPosition(Vector2f(0, 0));

	map3.setTexture(&map3Texture);
	map3.setSize(Vector2f(800, 1750));
	map3.setPosition(Vector2f(0, 0));

	//view
	ViewPlayer view(Vector2f(0.0f, 0.0f), Vector2f(700, 393));

	//music
	Music musicmain, music1, musicsewer, musicfloor;
	musicmain.openFromFile("Sound/mainmenusound.wav");
	music1.openFromFile("Sound/onthestreet3.wav");
	musicsewer.openFromFile("Sound/inthesewer.wav");
	musicfloor.openFromFile("Sound/inbuilding.wav");
	musicmain.play();
	musicmain.setLoop(true);

	Music zombie1;
	zombie1.openFromFile("Sound/zombie.wav");

	//sound effects
	SoundBuffer bufferShot;
	bufferShot.loadFromFile("Sound/fireglock.wav");
	Sound soundShot;
	soundShot.setBuffer(bufferShot);

	//sound effects
	SoundBuffer bufferShotgun;
	bufferShotgun.loadFromFile("Sound/fireshotgun.wav");
	Sound soundShotgun;
	soundShotgun.setBuffer(bufferShotgun);

	//sound effects
	SoundBuffer bufferBox;
	bufferBox.loadFromFile("Sound/boxattacked.wav");
	Sound soundBox;
	soundBox.setBuffer(bufferBox);

	//sound effects
	SoundBuffer bufferHeal;
	bufferHeal.loadFromFile("Sound/heal.wav");
	Sound soundHeal;
	soundHeal.setBuffer(bufferHeal);

	//sound effects
	SoundBuffer bufferZombie;
	bufferZombie.loadFromFile("Sound/zombieattacked.wav");
	Sound soundZombie;
	soundZombie.setBuffer(bufferZombie);

	//sound effects
	SoundBuffer bufferPlayer;
	bufferPlayer.loadFromFile("Sound/playerattacked.wav");
	Sound soundPlayer;
	soundPlayer.setBuffer(bufferPlayer);

	//sound effects
	SoundBuffer bufferButton;
	bufferButton.loadFromFile("Sound/button.wav");
	Sound soundButton;
	soundButton.setBuffer(bufferButton);

	Player player(&playerTexture, Vector2u(9, 41), 0.15f, 100.0f);

	Random random;

	//wall Vector Array
	Wall wallMap10(Vector2f(58, 222), Vector2f(150, 1547));
	Wall wallMap11(Vector2f(405, 112), Vector2f(957.5, 168));
	Wall wallMap12(Vector2f(410, 530), Vector2f(205, 655));
	Wall wallMap13(Vector2f(462, 530), Vector2f(871, 653));
	Wall wallMap14(Vector2f(282, 167), Vector2f(262, 1242.5));
	Wall wallMap15(Vector2f(1110, 430), Vector2f(721, 1547));
	Wall wallMap16(Vector2f(232, 201), Vector2f(522, 1224.5));
	Wall wallMap17(Vector2f(58, 222), Vector2f(1073, 1214));
	Wall wallMap18(Vector2f(290, 166), Vector2f(783, 1242));

	vector<Wall>::const_iterator iterWall;
	vector<Wall> Wallmap1Array;
	Wallmap1Array.push_back(wallMap10);
	Wallmap1Array.push_back(wallMap11);
	Wallmap1Array.push_back(wallMap12);
	Wallmap1Array.push_back(wallMap13);
	Wallmap1Array.push_back(wallMap14);
	Wallmap1Array.push_back(wallMap14);
	Wallmap1Array.push_back(wallMap15);
	Wallmap1Array.push_back(wallMap16);
	Wallmap1Array.push_back(wallMap17);
	Wallmap1Array.push_back(wallMap18);

	//wall2 Vector Array
	Wall2 wallMap20(Vector2f(473, 558), Vector2f(225, 580));
	Wall2 wallMap21(Vector2f(1450, 80), Vector2f(725, 40));
	Wall2 wallMap22(Vector2f(276, 202), Vector2f(325, 90));
	Wall2 wallMap23(Vector2f(276, 41), Vector2f(325, 305));
	Wall2 wallMap24(Vector2f(90, 253), Vector2f(695, 137));
	Wall2 wallMap25(Vector2f(90, 170), Vector2f(975, 90));
	Wall2 wallMap26(Vector2f(55, 212), Vector2f(1422, 62));
	Wall2 wallMap27(Vector2f(22, 140), Vector2f(475, 470));
	Wall2 wallMap28(Vector2f(120, 140), Vector2f(604, 470));
	Wall2 wallMap29(Vector2f(585, 236), Vector2f(1020, 515));
	Wall2 wallMap210(Vector2f(74, 236), Vector2f(1415, 515));
	Wall2 wallMap211(Vector2f(87, 210), Vector2f(885, 666));

	vector<Wall2>::const_iterator iterWall2;
	vector<Wall2> Wallmap2Array;
	Wallmap2Array.push_back(wallMap20);
	Wallmap2Array.push_back(wallMap21);
	Wallmap2Array.push_back(wallMap22);
	Wallmap2Array.push_back(wallMap23);
	Wallmap2Array.push_back(wallMap24);
	Wallmap2Array.push_back(wallMap24);
	Wallmap2Array.push_back(wallMap25);
	Wallmap2Array.push_back(wallMap26);
	Wallmap2Array.push_back(wallMap27);
	Wallmap2Array.push_back(wallMap28);
	Wallmap2Array.push_back(wallMap29);
	Wallmap2Array.push_back(wallMap210);
	Wallmap2Array.push_back(wallMap211);

	//wall3 Vector Array
	Wall3 wallMap30(Vector2f(800, 134), Vector2f(390, 72));
	Wall3 wallMap31(Vector2f(139, 71), Vector2f(64, 135));
	Wall3 wallMap32(Vector2f(77, 89), Vector2f(224, 128));
	Wall3 wallMap33(Vector2f(52, 286), Vector2f(300, 155));
	Wall3 wallMap34(Vector2f(87, 44), Vector2f(490, 275));
	Wall3 wallMap35(Vector2f(52, 286), Vector2f(545, 155));
	Wall3 wallMap36(Vector2f(124, 66), Vector2f(684, 140));
	Wall3 wallMap37(Vector2f(91, 172), Vector2f(45, 375));
	Wall3 wallMap38(Vector2f(128, 86), Vector2f(292, 415));
	Wall3 wallMap39(Vector2f(128, 86), Vector2f(510, 415));
	Wall3 wallMap310(Vector2f(91, 172), Vector2f(748, 375));
	Wall3 wallMap311(Vector2f(313, 212), Vector2f(155, 643));
	Wall3 wallMap312(Vector2f(224, 68), Vector2f(112, 760));
	Wall3 wallMap313(Vector2f(313, 212), Vector2f(647, 643));
	Wall3 wallMap314(Vector2f(128, 86), Vector2f(595, 750));
	Wall3 wallMap315(Vector2f(89, 77), Vector2f(753, 749));
	Wall3 wallMap316(Vector2f(175, 168), Vector2f(183, 953));
	Wall3 wallMap317(Vector2f(175, 168), Vector2f(618, 953));
	Wall3 wallMap318(Vector2f(313, 212), Vector2f(155, 1219));
	Wall3 wallMap319(Vector2f(224, 68), Vector2f(112, 1332));
	Wall3 wallMap320(Vector2f(313, 212), Vector2f(647, 1218));
	Wall3 wallMap321(Vector2f(128, 86), Vector2f(595, 1328));
	Wall3 wallMap322(Vector2f(89, 77), Vector2f(753, 1320));
	Wall3 wallMap323(Vector2f(175, 168), Vector2f(183, 1525));
	Wall3 wallMap324(Vector2f(175, 168), Vector2f(618, 1525));
	Wall3 wallMap325(Vector2f(313, 60), Vector2f(155, 1720));
	Wall3 wallMap326(Vector2f(313, 60), Vector2f(642, 1720));

	vector<Wall3>::const_iterator iterWall3;
	vector<Wall3> Wallmap3Array;
	Wallmap3Array.push_back(wallMap30);
	Wallmap3Array.push_back(wallMap31);
	Wallmap3Array.push_back(wallMap32);
	Wallmap3Array.push_back(wallMap33);
	Wallmap3Array.push_back(wallMap34);
	Wallmap3Array.push_back(wallMap34);
	Wallmap3Array.push_back(wallMap35);
	Wallmap3Array.push_back(wallMap36);
	Wallmap3Array.push_back(wallMap37);
	Wallmap3Array.push_back(wallMap38);
	Wallmap3Array.push_back(wallMap39);
	Wallmap3Array.push_back(wallMap310);
	Wallmap3Array.push_back(wallMap311);
	Wallmap3Array.push_back(wallMap312);
	Wallmap3Array.push_back(wallMap313);
	Wallmap3Array.push_back(wallMap314);
	Wallmap3Array.push_back(wallMap315);
	Wallmap3Array.push_back(wallMap316);
	Wallmap3Array.push_back(wallMap317);
	Wallmap3Array.push_back(wallMap318);
	Wallmap3Array.push_back(wallMap319);
	Wallmap3Array.push_back(wallMap320);
	Wallmap3Array.push_back(wallMap321);
	Wallmap3Array.push_back(wallMap322);
	Wallmap3Array.push_back(wallMap323);
	Wallmap3Array.push_back(wallMap324);
	Wallmap3Array.push_back(wallMap325);
	Wallmap3Array.push_back(wallMap326);

	//Projectile Vector Array
	vector<Projectile>::const_iterator iterBullet;
	vector<Projectile> projectileArray;

	Projectile projectile1;
	Projectile projectile2;
	Projectile projectile3;
	projectile1.bullet.setTexture(&bulletTexture);
	projectile2.bullet.setTexture(&bulletTexture);
	projectile3.bullet.setTexture(&bulletTexture);

	//Enemy Vector Array
	vector<Enemy>::const_iterator iterEnemy;
	vector<Enemy> enemyArray;

	Enemy enemy1(&enemyTexture, Vector2u(3, 5), 0.15f, 50.0f);
	enemy1.text.setFont(fonthpzombie);
	enemy1.text.setCharacterSize(15);
	enemy1.text.setColor(Color::Red);
	enemy1.text.setOutlineThickness(1.f);
	enemy1.text.setOutlineColor(Color::Black);

	//random spawn enemy zone1
	counter = 0;
	while (counter < 10)
	{
		int boxX[10] = { 0 }, boxY[10] = { 0 };
		int tempx, tempy, po = 0;
		tempx = random.generateRandom(0, 1414);
		tempy = random.generateRandom(950, 1950);
		for (int i = 0; i < 10; i++)
		{
			if (tempx == boxX[i] && tempy == boxY[i])
			{
				po = 1;
			}
			if (tempx > 100 && tempx < 1283 && tempy>1089 && tempy < 1750)
			{
				po = 1;
			}
		}
		if (po == 0) {
			boxX[counter] = tempx;
			boxY[counter] = tempy;
			enemy1.enemy.setPosition(tempx, tempy);
			enemyArray.push_back(enemy1);

			counter++;

		}
	}
	//random spawn enemy zone2
	counter = 0;
	while (counter < 5)
	{
		int boxX[15] = { 0 }, boxY[15] = { 0 };
		int tempx, tempy, po = 0;
		tempx = random.generateRandom(460, 1414);
		tempy = random.generateRandom(290, 943);
		for (int i = 0; i < 10; i++)
		{
			if (tempx == boxX[i] && tempy == boxY[i])
			{
				po = 1;
			}
			if (tempx > 551 && tempx < 1116 && tempy>300 && tempy < 957)
			{
				po = 1;
			}
		}
		if (po == 0) {
			boxX[counter] = tempx;
			boxY[counter] = tempy;
			enemy1.enemy.setPosition(tempx, tempy);
			enemyArray.push_back(enemy1);

			counter++;

		}
	}

	//Enemy2 Vector Array
	vector<Enemy>::const_iterator iterEnemy2;
	vector<Enemy> enemy2Array;

	Enemy enemy2(&enemy2Texture, Vector2u(3, 5), 0.15f, 50.0f);
	enemy2.text.setFont(fonthpzombie);
	enemy2.text.setCharacterSize(15);
	enemy2.text.setColor(Color::Red);
	enemy2.text.setOutlineThickness(1.f);
	enemy2.text.setOutlineColor(Color::Black);

	//random spawn enemy2 zone1
	counter = 0;
	while (counter < 3)
	{
		int boxX[4] = { 0 }, boxY[4] = { 0 };
		int tempx, tempy, po = 0;
		tempx = random.generateRandom(480, 620);
		tempy = random.generateRandom(150, 394);
		for (int i = 0; i < 5; i++)
		{
			if (tempx == boxX[i] && tempy == boxY[i])
			{
				po = 1;
			}
		}
		if (po == 0) {
			boxX[counter] = tempx;
			boxY[counter] = tempy;
			enemy2.enemy.setPosition(tempx, tempy);
			enemy2Array.push_back(enemy2);

			counter++;

		}
	}

	//random spawn enemy2 zone2
	counter = 0;
	while (counter < 3)
	{
		int boxX[4] = { 0 }, boxY[4] = { 0 };
		int tempx, tempy, po = 0;
		tempx = random.generateRandom(753, 1392);
		tempy = random.generateRandom(218, 390);
		for (int i = 0; i < 5; i++)
		{
			if (tempx == boxX[i] && tempy == boxY[i])
			{
				po = 1;
			}
		}
		if (po == 0) {
			boxX[counter] = tempx;
			boxY[counter] = tempy;
			enemy2.enemy.setPosition(tempx, tempy);
			enemy2Array.push_back(enemy2);

			counter++;

		}
	}
	
	//random spawn enemy2 zone3
	counter = 0;
	while (counter < 3)
	{
		int boxX[4] = { 0 }, boxY[4] = { 0 };
		int tempx, tempy, po = 0;
		tempx = random.generateRandom(490, 743);
		tempy = random.generateRandom(615, 850);
		for (int i = 0; i < 5; i++)
		{
			if (tempx == boxX[i] && tempy == boxY[i])
			{
				po = 1;
			}
		}
		if (po == 0) {
			boxX[counter] = tempx;
			boxY[counter] = tempy;
			enemy2.enemy.setPosition(tempx, tempy);
			enemy2Array.push_back(enemy2);

			counter++;

		}
	}

	//random spawn enemy2 zone4
	counter = 0;
	while (counter < 3)
	{
		int boxX[4] = { 0 }, boxY[4] = { 0 };
		int tempx, tempy, po = 0;
		tempx = random.generateRandom(939, 1440);
		tempy = random.generateRandom(684, 857);
		for (int i = 0; i < 5; i++)
		{
			if (tempx == boxX[i] && tempy == boxY[i])
			{
				po = 1;
			}
		}
		if (po == 0) {
			boxX[counter] = tempx;
			boxY[counter] = tempy;
			enemy2.enemy.setPosition(tempx, tempy);
			enemy2Array.push_back(enemy2);

			counter++;

		}
	}

	//Enemy3 Vector Array
	vector<Enemy3>::const_iterator iterEnemy3;
	vector<Enemy3> enemy3Array;

	Enemy3 enemy3(&enemy3Texture, Vector2u(3, 5), 0.15f, 80.0f);
	enemy3.enemy.setSize(Vector2f(60, 70));
	enemy3.text.setFont(fonthpzombie);
	enemy3.text.setCharacterSize(15);
	enemy3.text.setColor(Color::Red);
	enemy3.text.setOutlineThickness(1.f);
	enemy3.text.setOutlineColor(Color::Black);

	//random spawn enemy3 zone1
	counter = 0;
	while (counter < 1)
	{
		int boxX[3] = { 0 }, boxY[3] = { 0 };
		int tempx, tempy, po = 0;
		tempx = random.generateRandom(320, 485);
		tempy = random.generateRandom(546, 1100);
		for (int i = 0; i < 4; i++)
		{
			if (tempx == boxX[i] && tempy == boxY[i])
			{
				po = 1;
			}
		}
		if (po == 0) {
			boxX[counter] = tempx;
			boxY[counter] = tempy;
			enemy3.enemy.setPosition(tempx, tempy);
			enemy3Array.push_back(enemy3);

			counter++;

		}
	}

	//random spawn enemy3 zone2
	counter = 0;
	while (counter < 1)
	{
		int boxX[2] = { 0 }, boxY[2] = { 0 };
		int tempx, tempy, po = 0;
		tempx = random.generateRandom(0, 87);
		tempy = random.generateRandom(840, 1110);
		for (int i = 0; i < 3; i++)
		{
			if (tempx == boxX[i] && tempy == boxY[i])
			{
				po = 1;
			}
		}
		if (po == 0) {
			boxX[counter] = tempx;
			boxY[counter] = tempy;
			enemy3.enemy.setPosition(tempx, tempy);
			enemy3Array.push_back(enemy3);

			counter++;

		}
	}

	//random spawn enemy3 zone3
	counter = 0;
	while (counter < 1)
	{
		int boxX[2] = { 0 }, boxY[2] = { 0 };
		int tempx, tempy, po = 0;
		tempx = random.generateRandom(715, 800);
		tempy = random.generateRandom(840, 1110);
		for (int i = 0; i < 3; i++)
		{
			if (tempx == boxX[i] && tempy == boxY[i])
			{
				po = 1;
			}
		}
		if (po == 0) {
			boxX[counter] = tempx;
			boxY[counter] = tempy;
			enemy3.enemy.setPosition(tempx, tempy);
			enemy3Array.push_back(enemy3);

			counter++;

		}
	}

	//random spawn enemy3 zone4
	counter = 0;
	while (counter < 1)
	{
		int boxX[3] = { 0 }, boxY[3] = { 0 };
		int tempx, tempy, po = 0;
		tempx = random.generateRandom(107, 222);
		tempy = random.generateRandom(220, 537);
		for (int i = 0; i < 4; i++)
		{
			if (tempx == boxX[i] && tempy == boxY[i])
			{
				po = 1;
			}
		}
		if (po == 0) {
			boxX[counter] = tempx;
			boxY[counter] = tempy;
			enemy3.enemy.setPosition(tempx, tempy);
			enemy3Array.push_back(enemy3);

			counter++;

		}
	}

	//random spawn enemy3 zone5
	counter = 0;
	while (counter < 1)
	{
		int boxX[3] = { 0 }, boxY[3] = { 0 };
		int tempx, tempy, po = 0;
		tempx = random.generateRandom(585, 693);
		tempy = random.generateRandom(220, 537);
		for (int i = 0; i < 4; i++)
		{
			if (tempx == boxX[i] && tempy == boxY[i])
			{
				po = 1;
			}
		}
		if (po == 0) {
			boxX[counter] = tempx;
			boxY[counter] = tempy;
			enemy3.enemy.setPosition(tempx, tempy);
			enemy3Array.push_back(enemy3);

			counter++;

		}
	}

	//Text vector array
	vector<TextDisplay>::const_iterator iterText;
	vector<TextDisplay> textDisplayArray;

	TextDisplay textDisplay1;
	textDisplay1.text.setFont(font);
	textDisplay1.text.setColor(Color::Red);

	//hitbox ladder
	HitboxComponent hitboxladder1(0, 0, Vector2f(55, 30), Vector2f(670, 267));
	HitboxComponent hitboxladder2(0, 0, Vector2f(55, 30), Vector2f(852, 84));
	HitboxComponent hitboxladder3(0, 0, Vector2f(55, 30), Vector2f(1128, 84));
	HitboxComponent hitboxladder4(0, 0, Vector2f(55, 30), Vector2f(766, 640));
	HitboxComponent hitboxladder5(0, 0, Vector2f(55, 30), Vector2f(1020, 640));

	//green box
	RectangleShape boxgreen;
	boxgreen.setSize(Vector2f(12, 7));
	boxgreen.setPosition(Vector2f(470, 103));
	boxgreen.setFillColor(Color::Green);

	//hitbox generator
	HitboxComponent hitboxgen1(0, 0, Vector2f(110, 52), Vector2f(240, 435));
	HitboxComponent hitboxgen2(0, 0, Vector2f(110, 52), Vector2f(450, 435));
	HitboxComponent hitboxgen3(0, 0, Vector2f(110, 52), Vector2f(106, 770));
	HitboxComponent hitboxgen4(0, 0, Vector2f(70, 52), Vector2f(583, 770));
	HitboxComponent hitboxgen5(0, 0, Vector2f(110, 52), Vector2f(106, 1345));
	HitboxComponent hitboxgen6(0, 0, Vector2f(70, 52), Vector2f(583, 1345));
	HitboxComponent hitboxdoor(0, 0, Vector2f(70, 54), Vector2f(391, 108));

	//gen fixed
	GenBar gen1(Vector2f(hitboxgen1.hitbox.getPosition().x + 60, hitboxgen1.hitbox.getPosition().y));
	GenBar gen2(Vector2f(hitboxgen2.hitbox.getPosition().x + 60, hitboxgen2.hitbox.getPosition().y));
	GenBar gen3(Vector2f(hitboxgen3.hitbox.getPosition().x + 60, hitboxgen3.hitbox.getPosition().y));
	GenBar gen4(Vector2f(hitboxgen4.hitbox.getPosition().x + 60, hitboxgen4.hitbox.getPosition().y));
	GenBar gen5(Vector2f(hitboxgen5.hitbox.getPosition().x + 60, hitboxgen5.hitbox.getPosition().y));
	GenBar gen6(Vector2f(hitboxgen6.hitbox.getPosition().x + 60, hitboxgen6.hitbox.getPosition().y));
	
	//pickup vector array
	vector<PickupItem>::const_iterator iterGlock;
	vector<PickupItem> GlockArray;
	vector<PickupItem>::const_iterator iterSMG;
	vector<PickupItem> SMGArray;
	vector<PickupItem>::const_iterator iterShotgun;
	vector<PickupItem> ShotgunArray;
	vector<PickupItem>::const_iterator iterBoxG;
	vector<PickupItem> BoxGArray;
	vector<PickupItem>::const_iterator iterBoxSM;
	vector<PickupItem> BoxSMArray;
	vector<PickupItem>::const_iterator iterBoxSh;
	vector<PickupItem> BoxShArray;
	vector<PickupItem>::const_iterator iterPoHeal;
	vector<PickupItem> PotionHealArray;
	vector<PickupItem>::const_iterator iterCrow;
	vector<PickupItem> CrowbarArray;


	PickupItem BoxG(&boxTexture, Vector2f(60, 60), Vector2f(60, 30), 0, 0, Vector2f(0, 0));
	PickupItem BoxSM(&boxTexture, Vector2f(60, 60), Vector2f(60, 30), 0, 0, Vector2f(0, 0));
	PickupItem BoxSh(&boxTexture, Vector2f(60, 60), Vector2f(60, 30), 0, 0, Vector2f(0, 0));
	PickupItem Glock(&GlockTexture, Vector2f(30, 22), Vector2f(0, 0), 0, 0, Vector2f(0, 0));
	PickupItem SMG(&SMGTexture, Vector2f(35, 22), Vector2f(0, 0), 0, 0, Vector2f(0, 0));
	PickupItem Shotgun(&ShotgunTexture, Vector2f(40, 18), Vector2f(0, 0), 0, 0, Vector2f(0, 0));
	PickupItem PotionHeal(&potionHeal, Vector2f(18, 26), Vector2f(0, 0), 0, 0, Vector2f(0, 0));
	PickupItem Crowbar(&crowbar, Vector2f(40, 18), Vector2f(0, 0), 0, 0, Vector2f(0, 0));
	PickupItem Sewer(&sewer, Vector2f(50, 50), Vector2f(0, 0), 0, 0, Vector2f(0, 0));
	Sewer.item.setPosition(Vector2f(1250, 320));

	//random spawn Glock box zone1
	counter = 0;
	while (counter < 1)
	{
		int boxX[7] = { 0 }, boxY[7] = { 0 };
		int tempx, tempy, po = 0;
		tempx = random.generateRandom(0, 1414);
		tempy = random.generateRandom(950, 1950);
		for (int i = 0; i < 10; i++)
		{
			if (tempx == boxX[i] && tempy == boxY[i])
			{
				po = 1;
			}
			if (tempx > 100 && tempx < 1283 && tempy>1089 && tempy < 1750)
			{
				po = 1;
			}
		}
		if (po == 0) {
			boxX[counter] = tempx;
			boxY[counter] = tempy;
			BoxG.setPosition(Vector2f(boxX[counter], boxY[counter]));
			Glock.item.setPosition(boxX[counter] + 15, boxY[counter] + 20);
			BoxGArray.push_back(BoxG);
			GlockArray.push_back(Glock);
			counter++;
		}
	}
	//random spawn SMG box zone1
	counter = 0;
	while (counter < 1)
	{
		int boxX[7] = { 0 }, boxY[7] = { 0 };
		int tempx, tempy, po = 0;
		tempx = random.generateRandom(0, 1414);
		tempy = random.generateRandom(950, 1950);
		for (int i = 0; i < 10; i++)
		{
			if (tempx == boxX[i] && tempy == boxY[i])
			{
				po = 1;
			}
			if (tempx > 100 && tempx < 1283 && tempy>1089 && tempy < 1750)
			{
				po = 1;
			}
		}
		if (po == 0) {
			boxX[counter] = tempx;
			boxY[counter] = tempy;
			BoxSM.setPosition(Vector2f(boxX[counter], boxY[counter]));
			SMG.item.setPosition(boxX[counter] + 15, boxY[counter] + 20);
			BoxSMArray.push_back(BoxSM);
			SMGArray.push_back(SMG);
			counter++;
		}
	}
	//random spawn Shotgun box zone1
	counter = 0;
	while (counter < 1)
	{
		int boxX[7] = { 0 }, boxY[7] = { 0 };
		int tempx, tempy, po = 0;
		tempx = random.generateRandom(0, 1414);
		tempy = random.generateRandom(950, 1950);
		for (int i = 0; i < 10; i++)
		{
			if (tempx == boxX[i] && tempy == boxY[i])
			{
				po = 1;
			}
			if (tempx > 100 && tempx < 1283 && tempy>1089 && tempy < 1750)
			{
				po = 1;
			}
		}
		if (po == 0) {
			boxX[counter] = tempx;
			boxY[counter] = tempy;
			BoxSh.setPosition(Vector2f(boxX[counter], boxY[counter]));
			Shotgun.item.setPosition(boxX[counter] + 15, boxY[counter] + 20);
			BoxShArray.push_back(BoxSh);
			ShotgunArray.push_back(Shotgun);
			counter++;
		}
	}
	//random spawn Glock box zone2
	counter = 0;
	while (counter < 1)
	{
		int boxX[7] = { 0 }, boxY[7] = { 0 };
		int tempx, tempy, po = 0;
		tempx = random.generateRandom(420, 1414);
		tempy = random.generateRandom(235, 943);
		for (int i = 0; i < 10; i++)
		{
			if (tempx == boxX[i] && tempy == boxY[i])
			{
				po = 1;
			}
			if (tempx > 551 && tempx < 1116 && tempy>300 && tempy < 957)
			{
				po = 1;
			}
		}
		if (po == 0) {
			boxX[counter] = tempx;
			boxY[counter] = tempy;
			BoxG.setPosition(Vector2f(boxX[counter], boxY[counter]));
			Glock.item.setPosition(boxX[counter] + 15, boxY[counter] + 20);
			BoxGArray.push_back(BoxG);
			GlockArray.push_back(Glock);
			counter++;
		}
	}
	//random spawn SMG box zone2
	counter = 0;
	while (counter < 1)
	{
		int boxX[7] = { 0 }, boxY[7] = { 0 };
		int tempx, tempy, po = 0;
		tempx = random.generateRandom(420, 1414);
		tempy = random.generateRandom(235, 943);
		for (int i = 0; i < 10; i++)
		{
			if (tempx == boxX[i] && tempy == boxY[i])
			{
				po = 1;
			}
			if (tempx > 551 && tempx < 1116 && tempy>300 && tempy < 957)
			{
				po = 1;
			}
		}
		if (po == 0) {
			boxX[counter] = tempx;
			boxY[counter] = tempy;
			BoxSM.setPosition(Vector2f(boxX[counter], boxY[counter]));
			SMG.item.setPosition(boxX[counter] + 15, boxY[counter] + 20);
			BoxSMArray.push_back(BoxSM);
			SMGArray.push_back(SMG);
			counter++;
		}
	}
	//random spawn Shotgun box zone2
	counter = 0;
	while (counter < 1)
	{
		int boxX[7] = { 0 }, boxY[7] = { 0 };
		int tempx, tempy, po = 0;
		tempx = random.generateRandom(420, 1414);
		tempy = random.generateRandom(235, 943);
		for (int i = 0; i < 10; i++)
		{
			if (tempx == boxX[i] && tempy == boxY[i])
			{
				po = 1;
			}
			if (tempx > 551 && tempx < 1116 && tempy>300 && tempy < 957)
			{
				po = 1;
			}
		}
		if (po == 0) {
			boxX[counter] = tempx;
			boxY[counter] = tempy;
			BoxSh.setPosition(Vector2f(boxX[counter], boxY[counter]));
			Shotgun.item.setPosition(boxX[counter] + 15, boxY[counter] + 20);
			BoxShArray.push_back(BoxSh);
			ShotgunArray.push_back(Shotgun);
			counter++;
		}
	}

	//textbox
	Textbox textbox1(50, Color::White, false);
	textbox1.setFont(fonthpzombie);
	textbox1.setPosition(Vector2f(220, 290));
	textbox1.setLimit(true, 16);

	//chatbox
	Chatbox chat1(Vector2f(650, 300), Vector2f(view.view->getSize().x / 2, view.view->getSize().y-40));

	float deltaTime = 0.0f;
	Clock clock;

	num = random.generateRandom(1, 5);

	//game loop
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		Event event;
		Time elapsed4 = clock4.getElapsedTime();
		
		if (Mouse::isButtonPressed(Mouse::Left) && textbox1.textframe.getGlobalBounds().contains(static_cast<sf::Vector2f>(Mouse::getPosition()))) {
			textbox1.setSelected(true);
		}
		else if(Mouse::isButtonPressed(Mouse::Left)){
			textbox1.setSelected(false);
		}

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
			case Event::TextEntered:
				textbox1.typedOn(event);
			}
		}
		//removeja
		if (Keyboard::isKeyPressed(Keyboard::P))
		{
			window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::O))
		{
			player.isGlock = true;
			player.isSMG = true;
			player.isShotgun = true;
			GlockBullet = 100;
			SMGBullet = 150;
			ShotgunBullet = 70;
		}

		if (level == 10) { //main menu
			mainmenuBG.UpdateBG(deltaTime);
			mainmenuBG.UpdateButton(Mouse::getPosition());
			if (mainmenuBG.buttonStory->isPressed() == true) {
				soundButton.play();
				level = 11;
			}
			if (mainmenuBG.buttonHow->isPressed() == true) {
				soundButton.play();
				level = 100;
			}
			if (mainmenuBG.buttonQuit->isPressed() == true) {
				soundButton.play();
				window.close();
			}
			//clear screen
			window.clear();
			mainmenuBG.DrawBG(window);
			mainmenuBG.DrawButton(window);
		}

		if (level == 100) { //how to play
			mainmenuBG.UpdateBG(deltaTime);
			mainmenuBG.UpdateButton4(Mouse::getPosition());

			if (mainmenuBG.buttonBack3->isPressed() == true) {
				soundButton.play();
				level = 10;
			}
			//clear screen
			window.clear();
			mainmenuBG.DrawBG2(window);
		}

		//if (level == 11) { //storymode press
		//	mainmenuBG.UpdateBG(deltaTime);
		//	mainmenuBG.UpdateButton2(Mouse::getPosition());

		//	if (mainmenuBG.buttonNewgame->isPressed() == true) {
		//		soundButton.play();
		//		level = 12;
		//	}
		//	if (mainmenuBG.buttonBack->isPressed() == true) {
		//		soundButton.play();
		//		level = 10;
		//	}

		//	window.clear();
		//	mainmenuBG.DrawBG(window);
		//	mainmenuBG.DrawButton2(window);
		//}

		if (level == 11) { //newgame press
			mainmenuBG.UpdateBG(deltaTime);
			mainmenuBG.UpdateButton3(Mouse::getPosition());
			if (elapsed4.asSeconds() >= 0.1)
			{
				clock4.restart();
				if (mainmenuBG.buttonOK->isPressed() == true) {
					soundButton.play();
					level = 1;
					musicmain.stop();
					music1.play();
					music1.setLoop(true);
					zombie1.play();
					zombie1.setLoop(true);
				}
			}
			if (mainmenuBG.buttonBack2->isPressed() == true) {
				soundButton.play();
				level = 10;
			}
			window.clear();
			mainmenuBG.DrawBG(window);
			mainmenuBG.DrawButton3(window);
			textbox1.drawTo(window);
		}
		//if (pause == true) //pause menu 
		//{
		//	view.view->setSize(Vector2f(window.getSize()));
		//	view.view->setCenter(Vector2f(window.getSize().x / 2.f, window.getSize().y / 2.f));
		//	pausegame.UpdateButton(Mouse::getPosition());
		//	if (pausegame.buttonPlay->isPressed() == true) {
		//		soundButton.play();
		//		level = 1;
		//	}
		//	if (pausegame.buttonHowTP->isPressed() == true) {
		//		soundButton.play();
		//		level = 100;
		//	}
		//	if (pausegame.buttonMenu->isPressed() == true) {
		//		soundButton.play();
		//		level = 10;
		//	}

		//	window.clear();
		//	pausegame.DrawBG(window);
		//	pausegame.DrawButton(window);
		//}

		if (level == 1) { //ok press

			player.Update(deltaTime);

			////pause
			//if ((Keyboard::isKeyPressed(Keyboard::Escape))) {
			//	pause = true;
			//	level = 0;
			//}

			//player view set
			view.viewUpdate(player, map);

			//clear screen
			window.clear();

			view.setView(window);

			//Clock
			Time elapsed1 = clock1.getElapsedTime();
			Time elapsed2 = clock2.getElapsedTime();
			Time elapsed3 = clock3.getElapsedTime();
			
			//player collide edge
			player.playerCollideEdge(map.getSize(), map.getPosition());

			//player collide hitboxmap 
			counter = 0;
			for (iterWall = Wallmap1Array.begin(); iterWall != Wallmap1Array.end(); iterWall++)
			{
				Wallmap1Array[counter].GetCollider().CheckCollision(player.GetCollider(), 1.0f);
				counter++;
			}

			//enemy collide hitboxmap
			counter = 0;
			for (iterEnemy = enemyArray.begin(); iterEnemy != enemyArray.end(); iterEnemy++)
			{
				counter2 = 0;
				for (iterWall = Wallmap1Array.begin(); iterWall != Wallmap1Array.end(); iterWall++)
				{
					if (enemyArray[counter].enemy.getGlobalBounds().intersects(Wallmap1Array[counter2].wall.getGlobalBounds()))
					{
						if (enemyArray[counter].face == 0) //left
						{
							enemyArray[counter].canMoveL = false;
							enemyArray[counter].enemy.move(2, 0);
						}
						if (enemyArray[counter].face == 1) //right
						{
							enemyArray[counter].canMoveR = false;
							enemyArray[counter].enemy.move(-2, 0);
						}
						if (enemyArray[counter].face == 2) //up
						{
							enemyArray[counter].canMoveUp = false;
							enemyArray[counter].enemy.move(0, 2);
						}
						if (enemyArray[counter].face == 3) //down
						{
							enemyArray[counter].canMoveDown = false;
							enemyArray[counter].enemy.move(0, -2);
						}
						break;
					}
					counter2++;
				}
				counter++;
			}

			//player collide box
			counter = 0;
			for (iterBoxG = BoxGArray.begin(); iterBoxG != BoxGArray.end(); iterBoxG++)
			{
				if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(BoxGArray[counter].item.getGlobalBounds()))
				{
					if (player.getFace() == 0)
					{
						player.canMoveL = false;
						player.body.move(2, 0);
					}
					if (player.getFace() == 1)
					{
						player.canMoveR = false;
						player.body.move(-2, 0);
					}
					if (player.getFace() == 2)
					{
						player.canMoveUp = false;
						player.body.move(0, 2);
					}
					if (player.getFace() == 3)
					{
						player.canMoveDown = false;
						player.body.move(0, -2);
					}
				}

				counter++;
			}
			counter = 0;
			for (iterBoxSM = BoxSMArray.begin(); iterBoxSM != BoxSMArray.end(); iterBoxSM++)
			{
				if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(BoxSMArray[counter].item.getGlobalBounds()))
				{
					if (player.getFace() == 0)
					{
						player.canMoveL = false;
						player.body.move(2, 0);
					}
					if (player.getFace() == 1)
					{
						player.canMoveR = false;
						player.body.move(-2, 0);
					}
					if (player.getFace() == 2)
					{
						player.canMoveUp = false;
						player.body.move(0, 2);
					}
					if (player.getFace() == 3)
					{
						player.canMoveDown = false;
						player.body.move(0, -2);
					}
				}

				counter++;
			}
			counter = 0;
			for (iterBoxSh = BoxShArray.begin(); iterBoxSh != BoxShArray.end(); iterBoxSh++)
			{
				if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(BoxShArray[counter].item.getGlobalBounds()))
				{
					if (player.getFace() == 0)
					{
						player.canMoveL = false;
						player.body.move(2, 0);
					}
					if (player.getFace() == 1)
					{
						player.canMoveR = false;
						player.body.move(-2, 0);
					}
					if (player.getFace() == 2)
					{
						player.canMoveUp = false;
						player.body.move(0, 2);
					}
					if (player.getFace() == 3)
					{
						player.canMoveDown = false;
						player.body.move(0, -2);
					}
				}

				counter++;
			}

			//enemy collide box
			counter = 0;
			for (iterEnemy = enemyArray.begin(); iterEnemy != enemyArray.end(); iterEnemy++)
			{
				counter2 = 0;
				for (iterBoxG = BoxGArray.begin(); iterBoxG != BoxGArray.end(); iterBoxG++)
				{
					if (enemyArray[counter].enemy.getGlobalBounds().intersects(BoxGArray[counter2].hitboxBox.hitbox.getGlobalBounds()))
					{
						if (enemyArray[counter].face == 0) //left
						{
							enemyArray[counter].canMoveL = false;
							enemyArray[counter].enemy.move(2, 0);
						}
						if (enemyArray[counter].face == 1) //right
						{
							enemyArray[counter].canMoveR = false;
							enemyArray[counter].enemy.move(-2, 0);
						}
						if (enemyArray[counter].face == 2) //up
						{
							enemyArray[counter].canMoveUp = false;
							enemyArray[counter].enemy.move(0, 2);
						}
						if (enemyArray[counter].face == 3) //down
						{
							enemyArray[counter].canMoveDown = false;
							enemyArray[counter].enemy.move(0, -2);
						}
						break;
					}
					else
					{
						enemyArray[counter].canMoveL = true;
						enemyArray[counter].canMoveR = true;
						enemyArray[counter].canMoveUp = true;
						enemyArray[counter].canMoveDown = true;
					}
					counter2++;
				}
				counter++;
			}

			counter = 0;
			for (iterEnemy = enemyArray.begin(); iterEnemy != enemyArray.end(); iterEnemy++)
			{
				counter2 = 0;
				for (iterBoxSM = BoxSMArray.begin(); iterBoxSM != BoxSMArray.end(); iterBoxSM++)
				{
					if (enemyArray[counter].enemy.getGlobalBounds().intersects(BoxSMArray[counter2].hitboxBox.hitbox.getGlobalBounds()))
					{
						if (enemyArray[counter].face == 0) //left
						{
							enemyArray[counter].canMoveL = false;
							enemyArray[counter].enemy.move(2, 0);
						}
						if (enemyArray[counter].face == 1) //right
						{
							enemyArray[counter].canMoveR = false;
							enemyArray[counter].enemy.move(-2, 0);
						}
						if (enemyArray[counter].face == 2) //up
						{
							enemyArray[counter].canMoveUp = false;
							enemyArray[counter].enemy.move(0, 2);
						}
						if (enemyArray[counter].face == 3) //down
						{
							enemyArray[counter].canMoveDown = false;
							enemyArray[counter].enemy.move(0, -2);
						}
						break;
					}
					counter2++;
				}
				counter++;
			}

			counter = 0;
			for (iterEnemy = enemyArray.begin(); iterEnemy != enemyArray.end(); iterEnemy++)
			{
				counter2 = 0;
				for (iterBoxSh = BoxShArray.begin(); iterBoxSh != BoxShArray.end(); iterBoxSh++)
				{
					if (enemyArray[counter].enemy.getGlobalBounds().intersects(BoxShArray[counter2].hitboxBox.hitbox.getGlobalBounds()))
					{
						if (enemyArray[counter].face == 0) //left
						{
							enemyArray[counter].canMoveL = false;
							enemyArray[counter].enemy.move(2, 0);
						}
						if (enemyArray[counter].face == 1) //right
						{
							enemyArray[counter].canMoveR = false;
							enemyArray[counter].enemy.move(-2, 0);
						}
						if (enemyArray[counter].face == 2) //up
						{
							enemyArray[counter].canMoveUp = false;
							enemyArray[counter].enemy.move(0, 2);
						}
						if (enemyArray[counter].face == 3) //down
						{
							enemyArray[counter].canMoveDown = false;
							enemyArray[counter].enemy.move(0, -2);
						}
						break;
					}
					counter2++;
				}
				counter++;
			}

			//player collide item
			counter = 0;
			for (iterGlock = GlockArray.begin(); iterGlock != GlockArray.end(); iterGlock++)
			{
				if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(GlockArray[counter].item.getGlobalBounds()))
				{
					GlockArray[counter].destroy = true;
					soundHeal.play();
					player.isGlock = true;
					GlockBullet = 80;
				}
				counter++;
			}

			counter = 0;
			for (iterSMG = SMGArray.begin(); iterSMG != SMGArray.end(); iterSMG++)
			{
				if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(SMGArray[counter].item.getGlobalBounds()))
				{
					SMGArray[counter].destroy = true;
					soundHeal.play();
					player.isSMG = true;
					SMGBullet = 100;
				}

				counter++;
			}

			counter = 0;
			for (iterShotgun = ShotgunArray.begin(); iterShotgun != ShotgunArray.end(); iterShotgun++)
			{
				if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(ShotgunArray[counter].item.getGlobalBounds()))
				{
					ShotgunArray[counter].destroy = true;
					soundHeal.play();
					player.isShotgun = true;
					ShotgunBullet = 50;
				}

				counter++;
			}

			counter = 0;
			for (iterPoHeal = PotionHealArray.begin(); iterPoHeal != PotionHealArray.end(); iterPoHeal++)
			{
				if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(PotionHealArray[counter].item.getGlobalBounds()))
				{
					if (player.hp > 0) {
						PotionHealArray[counter].destroy = true;
						soundHeal.play();
						if (player.hp >= 80) {
							player.hp = 100;
							view.boxX = 150;
						}
						else {
							player.hp += 20;
							view.boxX += 30;
						}
					}
				}

				counter++;
			}

			//player collide crowbar
			counter = 0;
			for (iterCrow = CrowbarArray.begin(); iterCrow != CrowbarArray.end(); iterCrow++)
			{
				if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(CrowbarArray[counter].item.getGlobalBounds()))
				{
					CrowbarArray[counter].destroy = true;
					soundHeal.play();
				}

				counter++;
			}

			//Enemy collide player
			if (elapsed2.asSeconds() >= 0.6)
			{
				clock2.restart();
				counter = 0;
				for (iterEnemy = enemyArray.begin(); iterEnemy != enemyArray.end(); iterEnemy++)
				{
					if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(enemyArray[counter].enemy.getGlobalBounds()))
					{
						if (player.hp > 0) {
							textDisplay1.text.setString("2");
							textDisplay1.text.setPosition(player.body.getPosition().x - 10, player.body.getPosition().y - 45);
							textDisplayArray.push_back(textDisplay1);
							player.hp -= enemyArray[counter].enemy1attackDamage;
							view.boxX -= 3;
							/*if (player.face == 0) {
								enemyArray[counter].speed = 15;
								player.body.move(20, 0);
							}
							else if (player.face == 1) {
								enemyArray[counter].speed = 15;
								player.body.move(-20, 0);
							}
							else if (player.face == 2) {
								enemyArray[counter].speed = 15;
								player.body.move(0, 20);
							}
							else if (player.face == 3) {
								enemyArray[counter].speed = 15;
								player.body.move(0, -20);
							}*/
							soundPlayer.play();
						}
					}
					counter++;
				}
			}

			//player slash enemy
			if (elapsed3.asSeconds() >= 0.3)
			{
				clock3.restart();
				counter = 0;
				for (iterEnemy = enemyArray.begin(); iterEnemy != enemyArray.end(); iterEnemy++)
				{
					if (Keyboard::isKeyPressed(Keyboard::Space)) {
						if (player.getWeapon() == 1 && (player.hitboxPlayerSwordleft->hitbox.getGlobalBounds().intersects(enemyArray[counter].enemy.getGlobalBounds()) && player.getFace() == 0
							|| player.hitboxPlayerSwordRight->hitbox.getGlobalBounds().intersects(enemyArray[counter].enemy.getGlobalBounds()) && player.getFace() == 1
							|| player.hitboxPlayerSwordUp->hitbox.getGlobalBounds().intersects(enemyArray[counter].enemy.getGlobalBounds()) && player.getFace() == 2
							|| player.hitboxPlayerSwordDown->hitbox.getGlobalBounds().intersects(enemyArray[counter].enemy.getGlobalBounds()) && player.getFace() == 3))
						{

							enemyArray[counter].enemy1hp -= player.attackSword;
							if (enemyArray[counter].face == 0) {
								enemyArray[counter].enemy.move(20, 0);
							}
							else if (enemyArray[counter].face == 1) {
								enemyArray[counter].enemy.move(-20, 0);
							}
							else if (enemyArray[counter].face == 2) {
								enemyArray[counter].enemy.move(0, 20);
							}
							else if (enemyArray[counter].face == 3) {
								enemyArray[counter].enemy.move(0, -20);
							}
							soundZombie.play();
						}
					}
					if (enemyArray[counter].enemy1hp <= 0)
					{
						enemyArray[counter].alive = false;
					}
					counter++;
				}
			}

			//player slash box
			if (elapsed3.asSeconds() >= 0.3)
			{
				clock3.restart();
				counter = 0;
				for (iterBoxG = BoxGArray.begin(); iterBoxG != BoxGArray.end(); iterBoxG++)
				{
					if (Keyboard::isKeyPressed(Keyboard::Space)) {
						if (player.getWeapon() == 1 && (player.hitboxPlayerSwordleft->hitbox.getGlobalBounds().intersects(BoxGArray[counter].item.getGlobalBounds()) && player.getFace() == 0
							|| player.hitboxPlayerSwordRight->hitbox.getGlobalBounds().intersects(BoxGArray[counter].item.getGlobalBounds()) && player.getFace() == 1
							|| player.hitboxPlayerSwordUp->hitbox.getGlobalBounds().intersects(BoxGArray[counter].item.getGlobalBounds()) && player.getFace() == 2
							|| player.hitboxPlayerSwordDown->hitbox.getGlobalBounds().intersects(BoxGArray[counter].item.getGlobalBounds()) && player.getFace() == 3))
						{
							textDisplay1.text.setString("1");
							textDisplay1.text.setPosition(BoxGArray[counter].item.getPosition().x + 50, BoxGArray[counter].item.getPosition().y - 50);
							textDisplayArray.push_back(textDisplay1);

							BoxGArray[counter].hpBox -= player.attackSword;
							soundBox.play();
						}
					}
					if (BoxGArray[counter].hpBox <= 0)
					{
						BoxGArray[counter].destroy = true;
					}
					counter++;
				}
			}
			if (elapsed3.asSeconds() >= 0.3)
			{
				clock3.restart();
				counter = 0;
				for (iterBoxSM = BoxSMArray.begin(); iterBoxSM != BoxSMArray.end(); iterBoxSM++)
				{
					if (Keyboard::isKeyPressed(Keyboard::Space)) {
						if (player.getWeapon() == 1 && (player.hitboxPlayerSwordleft->hitbox.getGlobalBounds().intersects(BoxSMArray[counter].item.getGlobalBounds()) && player.getFace() == 0
							|| player.hitboxPlayerSwordRight->hitbox.getGlobalBounds().intersects(BoxSMArray[counter].item.getGlobalBounds()) && player.getFace() == 1
							|| player.hitboxPlayerSwordUp->hitbox.getGlobalBounds().intersects(BoxSMArray[counter].item.getGlobalBounds()) && player.getFace() == 2
							|| player.hitboxPlayerSwordDown->hitbox.getGlobalBounds().intersects(BoxSMArray[counter].item.getGlobalBounds()) && player.getFace() == 3))
						{
							textDisplay1.text.setString("1");
							textDisplay1.text.setPosition(BoxSMArray[counter].item.getPosition().x - 10, BoxSMArray[counter].item.getPosition().y - 45);
							textDisplayArray.push_back(textDisplay1);

							BoxSMArray[counter].hpBox -= player.attackSword;
							soundBox.play();
						}
					}
					if (BoxSMArray[counter].hpBox <= 0)
					{
						BoxSMArray[counter].destroy = true;
					}
					counter++;
				}
			}
			if (elapsed3.asSeconds() >= 0.3)
			{
				clock3.restart();
				counter = 0;
				for (iterBoxSh = BoxShArray.begin(); iterBoxSh != BoxShArray.end(); iterBoxSh++)
				{
					if (Keyboard::isKeyPressed(Keyboard::Space)) {
						if (player.getWeapon() == 1 && (player.hitboxPlayerSwordleft->hitbox.getGlobalBounds().intersects(BoxShArray[counter].item.getGlobalBounds()) && player.getFace() == 0
							|| player.hitboxPlayerSwordRight->hitbox.getGlobalBounds().intersects(BoxShArray[counter].item.getGlobalBounds()) && player.getFace() == 1
							|| player.hitboxPlayerSwordUp->hitbox.getGlobalBounds().intersects(BoxShArray[counter].item.getGlobalBounds()) && player.getFace() == 2
							|| player.hitboxPlayerSwordDown->hitbox.getGlobalBounds().intersects(BoxShArray[counter].item.getGlobalBounds()) && player.getFace() == 3))
						{
							textDisplay1.text.setString("1");
							textDisplay1.text.setPosition(BoxShArray[counter].item.getPosition().x - 10, BoxShArray[counter].item.getPosition().y - 45);
							textDisplayArray.push_back(textDisplay1);

							BoxShArray[counter].hpBox -= player.attackSword;
							soundBox.play();
						}
					}
					if (BoxShArray[counter].hpBox <= 0)
					{
						BoxShArray[counter].destroy = true;
					}
					counter++;
				}
			}
			//Projectile Collides with Enemy
			counter = 0;
			for (iterBullet = projectileArray.begin(); iterBullet != projectileArray.end(); iterBullet++)
			{
				counter2 = 0;
				for (iterEnemy = enemyArray.begin(); iterEnemy != enemyArray.end(); iterEnemy++)
				{
					if (projectileArray[counter].bullet.getGlobalBounds().intersects(enemyArray[counter2].enemy.getGlobalBounds()))
					{
						projectileArray[counter].destroy = true;
						if (enemyArray[counter2].face == 0) {
							enemyArray[counter2].enemy.move(10, 0);
						}
						else if (enemyArray[counter2].face == 1) {
							enemyArray[counter2].enemy.move(-10, 0);
						}
						else if (enemyArray[counter2].face == 2) {
							enemyArray[counter2].enemy.move(0, 10);
						}
						else if (enemyArray[counter2].face == 3) {
							enemyArray[counter2].enemy.move(0, -10);
						}
						enemyArray[counter2].enemy1hp--;
						soundZombie.play();

						if (enemyArray[counter2].enemy1hp <= 0)
						{
							enemyArray[counter2].alive = false;
						}
					}
					counter2++;
				}
				counter++;
			}

			//Projectile Collides with Box
			counter = 0;
			for (iterBullet = projectileArray.begin(); iterBullet != projectileArray.end(); iterBullet++)
			{
				counter2 = 0;
				for (iterBoxG = BoxGArray.begin(); iterBoxG != BoxGArray.end(); iterBoxG++)
				{
					if (projectileArray[counter].bullet.getGlobalBounds().intersects(BoxGArray[counter2].item.getGlobalBounds()))
					{
						projectileArray[counter].destroy = true;

						textDisplay1.text.setString(to_string(projectileArray[counter].gunAttackDamage));
						textDisplay1.text.setPosition(BoxGArray[counter2].item.getPosition().x - 10, BoxGArray[counter2].item.getPosition().y - 45);
						textDisplayArray.push_back(textDisplay1);

						BoxGArray[counter2].hpBox--;
						soundBox.play();

						if (BoxGArray[counter2].hpBox <= 0)
						{
							BoxGArray[counter2].destroy = true;
						}
					}
					counter2++;
				}
				counter++;
			}
			counter = 0;
			for (iterBullet = projectileArray.begin(); iterBullet != projectileArray.end(); iterBullet++)
			{
				counter2 = 0;
				for (iterBoxSM = BoxSMArray.begin(); iterBoxSM != BoxSMArray.end(); iterBoxSM++)
				{
					if (projectileArray[counter].bullet.getGlobalBounds().intersects(BoxSMArray[counter2].item.getGlobalBounds()))
					{
						projectileArray[counter].destroy = true;

						textDisplay1.text.setString(to_string(projectileArray[counter].gunAttackDamage));
						textDisplay1.text.setPosition(BoxSMArray[counter2].item.getPosition().x - 10, BoxSMArray[counter2].item.getPosition().y - 45);
						textDisplayArray.push_back(textDisplay1);

						BoxSMArray[counter2].hpBox--;
						soundBox.play();

						if (BoxSMArray[counter2].hpBox <= 0)
						{
							BoxSMArray[counter2].destroy = true;
						}
					}
					counter2++;
				}
				counter++;
			}
			counter = 0;
			for (iterBullet = projectileArray.begin(); iterBullet != projectileArray.end(); iterBullet++)
			{
				counter2 = 0;
				for (iterBoxSh = BoxShArray.begin(); iterBoxSh != BoxShArray.end(); iterBoxSh++)
				{
					if (projectileArray[counter].bullet.getGlobalBounds().intersects(BoxShArray[counter2].item.getGlobalBounds()))
					{
						projectileArray[counter].destroy = true;

						textDisplay1.text.setString(to_string(projectileArray[counter].gunAttackDamage));
						textDisplay1.text.setPosition(BoxShArray[counter2].item.getPosition().x - 10, BoxShArray[counter2].item.getPosition().y - 45);
						textDisplayArray.push_back(textDisplay1);

						BoxShArray[counter2].hpBox--;
						soundBox.play();

						if (BoxShArray[counter2].hpBox <= 0)
						{
							BoxShArray[counter2].destroy = true;
						}
					}
					counter2++;
				}
				counter++;
			}

			//hitbox update
			player.hitboxPlayer->Update(player.GetPosition(), -12.5, -12.5);
			player.hitboxPlayerAll->Update(player.GetPosition(), -12.5, -22.5);
			player.hitboxPlayerSwordleft->Update(player.GetPosition(), -40, -12);
			player.hitboxPlayerSwordRight->Update(player.GetPosition(), 25, -12);
			player.hitboxPlayerSwordUp->Update(player.GetPosition(), 0, -30);
			player.hitboxPlayerSwordDown->Update(player.GetPosition(), 0, 22);

			//delete crowbar
			counter = 0;
			for (iterCrow = CrowbarArray.begin(); iterCrow != CrowbarArray.end(); iterCrow++)
			{
				if (CrowbarArray[counter].destroy == true)
				{
					CrowbarArray.erase(iterCrow);
					pickupCrowbar = true;
					break;
				}
				counter++;
			}

			// Delete dead enemy
			counter = 0;
			for (iterEnemy = enemyArray.begin(); iterEnemy != enemyArray.end(); iterEnemy++)
			{
				if (enemyArray[counter].alive == false)
				{
					if (random.generateRandom(1, 5) == 1) {
						PotionHeal.item.setPosition(enemyArray[counter].enemy.getPosition());
						PotionHealArray.push_back(PotionHeal);
					}
					enemyArray.erase(iterEnemy);
					zombieKill++;
					printf("%d", zombieKill);
					break;
				}
				counter++;
			}
			if (zombieKill >= 15)
			{
				//spawn crowber
				if (crowb == true) {
					printf("pp");
					int CrowX, CrowY, cro = 0;
					CrowX = random.generateRandom(0, 1414);
					CrowY = random.generateRandom(950, 1950);
					if (CrowX > 100 && CrowX < 1283 && CrowY > 1089 && CrowY < 1750)
					{
						cro = 1;
					}
					if (cro == 0) {
						Crowbar.setPosition(Vector2f(CrowX, CrowY));
						CrowbarArray.push_back(Crowbar);
						crowb = false;
					}
				}
				zombie1.setLoop(false);
				zombie1.stop();
			}

			//Delete Projectile
			counter = 0;
			for (iterBullet = projectileArray.begin(); iterBullet != projectileArray.end(); iterBullet++)
			{
				if (projectileArray[counter].destroy == true)
				{
					projectileArray.erase(iterBullet);
					break;
				}
				counter++;
			}

			//delete text
			counter = 0;
			for (iterText = textDisplayArray.begin(); iterText != textDisplayArray.end(); iterText++)
			{
				if (textDisplayArray[counter].destroy == true)
				{
					textDisplayArray.erase(iterText);
					break;
				}
				counter++;
			}

			//delete item
			counter = 0;
			for (iterGlock = GlockArray.begin(); iterGlock != GlockArray.end(); iterGlock++)
			{
				if (GlockArray[counter].destroy == true)
				{
					GlockArray.erase(iterGlock);
					break;
				}

				counter++;
			}
			counter = 0;
			for (iterSMG = SMGArray.begin(); iterSMG != SMGArray.end(); iterSMG++)
			{
				if (SMGArray[counter].destroy == true)
				{
					SMGArray.erase(iterSMG);
					break;
				}

				counter++;
			}
			counter = 0;
			for (iterShotgun = ShotgunArray.begin(); iterShotgun != ShotgunArray.end(); iterShotgun++)
			{
				if (ShotgunArray[counter].destroy == true)
				{
					ShotgunArray.erase(iterShotgun);
					break;
				}

				counter++;
			}
			counter = 0;
			for (iterPoHeal = PotionHealArray.begin(); iterPoHeal != PotionHealArray.end(); iterPoHeal++)
			{
				if (PotionHealArray[counter].destroy == true)
				{
					PotionHealArray.erase(iterPoHeal);
					break;
				}

				counter++;
			}

			//delete box
			counter = 0;
			for (iterBoxG = BoxGArray.begin(); iterBoxG != BoxGArray.end(); iterBoxG++)
			{
				if (BoxGArray[counter].destroy == true)
				{
					BoxGArray.erase(iterBoxG);
					if (player.getFace() == 0)
					{
						player.canMoveL = true;
						player.body.move(1, 0);
					}
					if (player.getFace() == 1)
					{
						player.canMoveR = true;
						player.body.move(-1, 0);
					}
					if (player.getFace() == 2)
					{
						player.canMoveUp = true;
						player.body.move(0, 1);
					}
					if (player.getFace() == 3)
					{
						player.canMoveDown = true;
						player.body.move(0, -1);
					}
					break;
				}
				counter++;
			}
			counter = 0;
			for (iterBoxSM = BoxSMArray.begin(); iterBoxSM != BoxSMArray.end(); iterBoxSM++)
			{
				if (BoxSMArray[counter].destroy == true)
				{
					BoxSMArray.erase(iterBoxSM);
					if (player.getFace() == 0)
					{
						player.canMoveL = true;
						player.body.move(1, 0);
					}
					if (player.getFace() == 1)
					{
						player.canMoveR = true;
						player.body.move(-1, 0);
					}
					if (player.getFace() == 2)
					{
						player.canMoveUp = true;
						player.body.move(0, 1);
					}
					if (player.getFace() == 3)
					{
						player.canMoveDown = true;
						player.body.move(0, -1);
					}
					break;
				}
				counter++;
			}
			counter = 0;
			for (iterBoxSh = BoxShArray.begin(); iterBoxSh != BoxShArray.end(); iterBoxSh++)
			{
				if (BoxShArray[counter].destroy == true)
				{
					BoxShArray.erase(iterBoxSh);
					if (player.getFace() == 0)
					{
						player.canMoveL = true;
						player.body.move(1, 0);
					}
					if (player.getFace() == 1)
					{
						player.canMoveR = true;
						player.body.move(-1, 0);
					}
					if (player.getFace() == 2)
					{
						player.canMoveUp = true;
						player.body.move(0, 1);
					}
					if (player.getFace() == 3)
					{
						player.canMoveDown = true;
						player.body.move(0, -1);
					}
					break;
				}
				counter++;
			}

			//fire projectiles
			if (player.getWeapon() == 2)
			{
				if (elapsed1.asSeconds() >= 0.7)
				{
					clock1.restart();
					if (Keyboard::isKeyPressed(Keyboard::Space))
					{
						soundShot.play();

						if (player.getFace() == 0) //left
						{
							projectile1.bullet.setPosition(player.GetPositionX() - 20, player.GetPositionY() - 12);
						}
						else if (player.getFace() == 1) //right
						{
							projectile1.bullet.setPosition(player.GetPositionX() + 20, player.GetPositionY() - 12);
						}
						else if (player.getFace() == 2) //up
						{
							projectile1.bullet.setPosition(player.GetPositionX() - 10, player.GetPositionY() - 8);
						}
						else if (player.getFace() == 3) //down
						{
							projectile1.bullet.setPosition(player.GetPositionX() + 8, player.GetPositionY() + 8);
						}
						projectile1.direction = player.getFace();
						projectileArray.push_back(projectile1);
						GlockBullet--;
					}
				}
			}
			if (player.getWeapon() == 3)
			{
				if (elapsed1.asSeconds() >= 0.2)
				{
					clock1.restart();
					if (Keyboard::isKeyPressed(Keyboard::Space))
					{
						soundShot.play();

						if (player.getFace() == 0) //left
						{
							projectile1.bullet.setPosition(player.GetPositionX() - 20, player.GetPositionY() + 4);
						}
						else if (player.getFace() == 1) //right
						{
							projectile1.bullet.setPosition(player.GetPositionX() + 20, player.GetPositionY() + 2);
						}
						else if (player.getFace() == 2) //up
						{
							projectile1.bullet.setPosition(player.GetPositionX() + 7, player.GetPositionY() - 8);
						}
						else if (player.getFace() == 3) //down
						{
							projectile1.bullet.setPosition(player.GetPositionX() - 10, player.GetPositionY() + 8);
						}
						projectile1.direction = player.getFace();
						projectileArray.push_back(projectile1);
						SMGBullet--;
					}
				}
			}
			if (player.getWeapon() == 4)
			{
				if (elapsed1.asSeconds() >= 1)
				{
					clock1.restart();
					if (Keyboard::isKeyPressed(Keyboard::Space))
					{
						soundShotgun.play();
						if (player.getFace() == 0) //left
						{
							projectile1.bullet.setPosition(player.GetPositionX() - 25, player.GetPositionY() - 15);
							projectile2.bullet.setPosition(player.GetPositionX() - 25, player.GetPositionY() - 25);
							projectile3.bullet.setPosition(player.GetPositionX() - 25, player.GetPositionY() - 5);
						}
						else if (player.getFace() == 1) //right
						{
							projectile1.bullet.setPosition(player.GetPositionX() + 20, player.GetPositionY() - 12);
							projectile2.bullet.setPosition(player.GetPositionX() + 20, player.GetPositionY() - 22);
							projectile3.bullet.setPosition(player.GetPositionX() + 20, player.GetPositionY() - 2);
						}
						else if (player.getFace() == 2) //up
						{
							projectile1.bullet.setPosition(player.GetPositionX() - 10, player.GetPositionY() - 8);
							projectile2.bullet.setPosition(player.GetPositionX() - 20, player.GetPositionY() - 8);
							projectile3.bullet.setPosition(player.GetPositionX(), player.GetPositionY() - 8);
						}
						else if (player.getFace() == 3) //down
						{
							projectile1.bullet.setPosition(player.GetPositionX() + 8, player.GetPositionY() + 8);
							projectile2.bullet.setPosition(player.GetPositionX() - 2, player.GetPositionY() + 8);
							projectile3.bullet.setPosition(player.GetPositionX() + 18, player.GetPositionY() + 8);
						}
						projectile1.direction = player.getFace();
						projectile2.direction = player.getFace();
						projectile3.direction = player.getFace();
						projectileArray.push_back(projectile1);
						projectileArray.push_back(projectile2);
						projectileArray.push_back(projectile3);
						ShotgunBullet--;
					}
				}
			}
			//delete gun
			if (GlockBullet <= 0) {
				player.isGlock = false;
			}
			if (SMGBullet <= 0) {
				player.isSMG = false;
			}
			if (ShotgunBullet <= 0) {
				player.isShotgun = false;
			}

			//draw map
			window.draw(map);

			//draw sewer
			window.draw(Sewer.item);

			//player collide sewer
			if (pickupCrowbar == true && player.hitboxPlayer->hitbox.getGlobalBounds().intersects(Sewer.item.getGlobalBounds()))
			{
				player.body.setPosition(100, 200);
				chat = true;
				chatbox = 0;
				music1.stop();
				musicsewer.play();
				musicsewer.setLoop(true); 
				counter = 0;
				for (iterGlock = GlockArray.begin(); iterGlock != GlockArray.end(); iterGlock++)
				{
					GlockArray[counter].destroy = true;
					counter++;
				}
				counter = 0;
				for (iterSMG = SMGArray.begin(); iterSMG != SMGArray.end(); iterSMG++)
				{
					SMGArray[counter].destroy = true;
					counter++;
				}
				counter = 0;
				for (iterShotgun = ShotgunArray.begin(); iterShotgun != ShotgunArray.end(); iterShotgun++)
				{
					ShotgunArray[counter].destroy = true;
					counter++;
				}
				counter = 0;
				for (iterPoHeal = PotionHealArray.begin(); iterPoHeal != PotionHealArray.end(); iterPoHeal++)
				{
					PotionHealArray[counter].destroy = true;
					counter++;
				}
				level = 2;

			}

			//draw item
			counter = 0;
			for (iterGlock = GlockArray.begin(); iterGlock != GlockArray.end(); iterGlock++)
			{
				GlockArray[counter].Update();
				window.draw(GlockArray[counter].item);

				counter++;
			}
			counter = 0;
			for (iterSMG = SMGArray.begin(); iterSMG != SMGArray.end(); iterSMG++)
			{
				SMGArray[counter].Update();
				window.draw(SMGArray[counter].item);

				counter++;
			}
			counter = 0;
			for (iterShotgun = ShotgunArray.begin(); iterShotgun != ShotgunArray.end(); iterShotgun++)
			{
				ShotgunArray[counter].Update();
				window.draw(ShotgunArray[counter].item);

				counter++;
			}
			counter = 0;
			for (iterPoHeal = PotionHealArray.begin(); iterPoHeal != PotionHealArray.end(); iterPoHeal++)
			{
				PotionHealArray[counter].Update();
				window.draw(PotionHealArray[counter].item);

				counter++;
			}
			counter = 0;
			for (iterCrow = CrowbarArray.begin(); iterCrow != CrowbarArray.end(); iterCrow++)
			{
				window.draw(CrowbarArray[counter].item);

				counter++;
			}

			//draw projectile
			if (player.getWeapon() == 4) {
				projectile1.bullet.setSize(Vector2f(8, 8));
				projectile2.bullet.setSize(Vector2f(8, 8));
				projectile3.bullet.setSize(Vector2f(8, 8));
				counter = 0;
				for (iterBullet = projectileArray.begin(); iterBullet != projectileArray.end(); iterBullet++)
				{
					projectileArray[counter].Update(); //update projectile
					window.draw(projectileArray[counter].bullet);
					counter++;
				}
			}
			else {
				projectile1.bullet.setSize(Vector2f(6, 6));
				projectile2.bullet.setSize(Vector2f(0, 0));
				projectile3.bullet.setSize(Vector2f(0, 0));
				counter = 0;
				for (iterBullet = projectileArray.begin(); iterBullet != projectileArray.end(); iterBullet++)
				{
					projectileArray[counter].Update(); //update projectile
					window.draw(projectileArray[counter].bullet);

					counter++;
				}
			}

			//draw enemies
			counter = 0;
			for (iterEnemy = enemyArray.begin(); iterEnemy != enemyArray.end(); iterEnemy++)
			{
				if (player.GetPosition().y > enemyArray[counter].GetPosition().y)
				{
					enemyArray[counter].text.setString("HP " + to_string(enemyArray[counter].enemy1hp) + "/" + to_string(enemyArray[counter].enemy1maxhp));
					window.draw(enemyArray[counter].text);

					enemyArray[counter].Update();
					enemyArray[counter].UpdateMovement(deltaTime, player.GetPosition(), player.GetSize());
					window.draw(enemyArray[counter].enemy);
				}
				counter++;
			}

			//draw box
			counter = 0;
			for (iterBoxG = BoxGArray.begin(); iterBoxG != BoxGArray.end(); iterBoxG++)
			{
				if (player.GetPosition().y > BoxGArray[counter].GetPosition().y)
				{
					BoxGArray[counter].Draw(window);
				}
				counter++;
			}

			counter = 0;
			for (iterBoxSM = BoxSMArray.begin(); iterBoxSM != BoxSMArray.end(); iterBoxSM++)
			{
				if (player.GetPosition().y > BoxSMArray[counter].GetPosition().y)
				{
					BoxSMArray[counter].Draw(window);
				}
				counter++;
			}

			counter = 0;
			for (iterBoxSh = BoxShArray.begin(); iterBoxSh != BoxShArray.end(); iterBoxSh++)
			{
				if (player.GetPosition().y > BoxShArray[counter].GetPosition().y)
				{
					BoxShArray[counter].Draw(window);
				}
				counter++;
			}

			//draw player
			player.Draw(window);

			//draw enemies
			counter = 0;
			for (iterEnemy = enemyArray.begin(); iterEnemy != enemyArray.end(); iterEnemy++)
			{
				if (player.GetPosition().y < enemyArray[counter].GetPosition().y)
				{
					enemyArray[counter].text.setString("HP " + to_string(enemyArray[counter].enemy1hp) + "/" + to_string(enemyArray[counter].enemy1maxhp));
					window.draw(enemyArray[counter].text);

					enemyArray[counter].Update();
					enemyArray[counter].UpdateMovement(deltaTime, player.GetPosition(), player.GetSize());
					window.draw(enemyArray[counter].enemy);
				}
				counter++;
			}

			//draw box
			counter = 0;
			for (iterBoxG = BoxGArray.begin(); iterBoxG != BoxGArray.end(); iterBoxG++)
			{
				if (player.GetPosition().y <= BoxGArray[counter].GetPosition().y)
				{
					BoxGArray[counter].Draw(window);
				}
				counter++;
			}
			counter = 0;
			for (iterBoxSM = BoxSMArray.begin(); iterBoxSM != BoxSMArray.end(); iterBoxSM++)
			{
				if (player.GetPosition().y <= BoxSMArray[counter].GetPosition().y)
				{
					BoxSMArray[counter].Draw(window);
				}
				counter++;
			}
			counter = 0;
			for (iterBoxSh = BoxShArray.begin(); iterBoxSh != BoxShArray.end(); iterBoxSh++)
			{
				if (player.GetPosition().y <= BoxShArray[counter].GetPosition().y)
				{
					BoxShArray[counter].Draw(window);
				}
				counter++;
			}

			//draw hitbox
			counter = 0;
			for (iterWall = Wallmap1Array.begin(); iterWall != Wallmap1Array.end(); iterWall++)
			{
				Wallmap1Array[counter].Draw(window);
				counter++;
			}

			//draw text
			counter = 0;
			for (iterText = textDisplayArray.begin(); iterText != textDisplayArray.end(); iterText++)
			{
				textDisplayArray[counter].Update();
				window.draw(textDisplayArray[counter].text);

				counter++;
			}
			//bullet draw
			view.name.setString(textbox1.getText());
			view.glockBullet.setString(to_string(GlockBullet) + "/" + to_string(MaxGlockBullet));
			view.smgBullet.setString(to_string(SMGBullet) + "/" + to_string(MaxSMGBullet));
			view.shotgunBullet.setString(to_string(ShotgunBullet) + "/" + to_string(MaxShotgunBullet));
			view.HP.setString("HP : " + to_string(player.hp) + "/" + to_string(player.maxhp));
			view.one.setString("1");
			view.two.setString("2");
			view.three.setString("3");
			view.four.setString("4");

			//HP Draw
			view.Draw(window);
			if (chat == true) {
				player.canMoveDown = false;
				player.canMoveL = false;
				player.canMoveR = false;
				player.canMoveUp = false;

				if (chatbox == 0) 
				{
					chat1.chat1.setString("Ah... this town. \nWe need that vaccine.");
					chat1.Draw1(window);
					if (elapsed4.asSeconds() >= 0.2)
					{
						clock4.restart();
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							chatbox = 1;
						}
					}
				}
				else if (chatbox == 1)
				{
					chat1.chat1.setString("We have to go into the sewers to get into \nthe basement of the building.");
					chat1.Draw1(window);
					if (elapsed4.asSeconds() >= 0.1)
					{
						clock4.restart();
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							chatbox = 2;
						}
					}
				}
				else if (chatbox == 2)
				{
					chat1.chat1.setString("But...we need to kill all of these zombies first.");
					chat1.Draw1(window);
					if (elapsed4.asSeconds() >= 0.1)
					{
						clock4.restart();
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							player.canMoveDown = true;
							player.canMoveL = true;
							player.canMoveR = true;
							player.canMoveUp = true;
							chat = false;
						}
					}
				}
			}
			if (chat == false) {
				view.task.setString("Task");
				view.task1.setString("Kill Zombies ("+ to_string(zombieKill) + "/" + to_string(MaxZombie) + ")");
				if (zombieKill >= 15) {
					view.task1.setColor(Color::Green);
					view.task2.setString("Find Crowbar");
				}
				if (pickupCrowbar == true) {
					view.task2.setColor(Color::Green);
					view.task3.setString("Find Sewer");
				}
				view.DrawTask(window);
				view.DrawTask1(window);
			}
			if (Keyboard::isKeyPressed(Keyboard::M)) {
				counter = 0;
				for (iterEnemy = enemyArray.begin(); iterEnemy != enemyArray.end(); iterEnemy++)
				{
					enemyArray[counter].alive = false;
					counter++;
				}
				zombieKill = 15;
			}
			if (Keyboard::isKeyPressed(Keyboard::N)) {
				pickupCrowbar = true;
			}
		}
		
		//level2**************************************************************************************************************************
		if (level == 2) { 

			player.Update(deltaTime);

			////pause
			//if ((Keyboard::isKeyPressed(Keyboard::Escape))) {
			//	pause = true;
			//	level = 0;
			//}

			//player view set
			view.viewUpdate(player, map2);

			//clear screen
			window.clear();

			view.setView(window);

			//Clock
			Time elapsed1 = clock1.getElapsedTime();
			Time elapsed2 = clock2.getElapsedTime();
			Time elapsed3 = clock3.getElapsedTime();

			//player collide edge
			player.playerCollideEdge(map2.getSize(), map2.getPosition());

			//player collide hitboxmap 
			counter = 0;
			for (iterWall2 = Wallmap2Array.begin(); iterWall2 != Wallmap2Array.end(); iterWall2++)
			{
				Wallmap2Array[counter].GetCollider().CheckCollision(player.GetCollider(), 1.0f);
				counter++;
			}

			//enemy collide hitboxmap
			counter = 0;
			for (iterEnemy2 = enemy2Array.begin(); iterEnemy2 != enemy2Array.end(); iterEnemy2++)
			{
				counter2 = 0;
				for (iterWall2 = Wallmap2Array.begin(); iterWall2 != Wallmap2Array.end(); iterWall2++)
				{
					if (enemy2Array[counter].enemy.getGlobalBounds().intersects(Wallmap2Array[counter2].wall.getGlobalBounds()))
					{
						if (enemy2Array[counter].face == 0) //left
						{
							enemy2Array[counter].canMoveL = false;
							enemy2Array[counter].enemy.move(2, 0);
						}
						if (enemy2Array[counter].face == 1) //right
						{
							enemy2Array[counter].canMoveR = false;
							enemy2Array[counter].enemy.move(-2, 0);
						}
						if (enemy2Array[counter].face == 2) //up
						{
							enemy2Array[counter].canMoveUp = false;
							enemy2Array[counter].enemy.move(0, 2);
						}
						if (enemy2Array[counter].face == 3) //down
						{
							enemy2Array[counter].canMoveDown = false;
							enemy2Array[counter].enemy.move(0, -2);
						}
						break;
					}
					counter2++;
				}
				counter++;
			}

			//player collide potionheal
			counter = 0;
			for (iterPoHeal = PotionHealArray.begin(); iterPoHeal != PotionHealArray.end(); iterPoHeal++)
			{
				if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(PotionHealArray[counter].item.getGlobalBounds()))
				{
					if (player.hp > 0) {
						PotionHealArray[counter].destroy = true;
						soundHeal.play();
						if (player.hp >= 80) {
							player.hp = 100;
							view.boxX = 150;
						}
						else {
							player.hp += 20;
							view.boxX += 30;
						}
					}
				}

				counter++;
			}

			//fixed when hold SMG can't press E
			//player collide ladder 
			if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxladder1.hitbox.getGlobalBounds())) 
			{
				if (elapsed1.asSeconds() > 0.3) {
					clock1.restart();
					if (Keyboard::isKeyPressed(Keyboard::E)) {
						printf("e");
						if (num == 1) {
							player.body.setPosition(400, 1700);
							chat = true;
							chatbox = 0;
							musicsewer.stop();
							musicfloor.play();
							musicfloor.setLoop(true);
							counter = 0;
							for (iterEnemy2 = enemy2Array.begin(); iterEnemy2 != enemy2Array.end(); iterEnemy2++)
							{
								enemy2Array[counter].alive = false;
								counter++;
							}
							counter = 0;
							for (iterPoHeal = PotionHealArray.begin(); iterPoHeal != PotionHealArray.end(); iterPoHeal++)
							{
								PotionHealArray[counter].destroy = true;
								counter++;
							}
							level = 3;
						}
						else {
							printf("ja");
							textDisplay1.text.setString("Not this way");
							textDisplay1.text.setCharacterSize(15);
							textDisplay1.LifeTime = 25;
							textDisplay1.text.setPosition(hitboxladder1.hitbox.getPosition().x - 10, hitboxladder1.hitbox.getPosition().y - 10);
							textDisplayArray.push_back(textDisplay1);
						}
					}
				}
			}
			if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxladder2.hitbox.getGlobalBounds()))
			{
				if (elapsed1.asSeconds() > 0.3) {
					clock1.restart();
					if (Keyboard::isKeyPressed(Keyboard::E)) {
						if (num == 2) {
							player.body.setPosition(400, 1700);
							chat = true;
							chatbox = 0;
							musicsewer.stop();
							musicfloor.play();
							musicfloor.setLoop(true);
							counter = 0;
							for (iterEnemy2 = enemy2Array.begin(); iterEnemy2 != enemy2Array.end(); iterEnemy2++)
							{
								enemy2Array[counter].alive = false;
								counter++;
							}
							counter = 0;
							for (iterPoHeal = PotionHealArray.begin(); iterPoHeal != PotionHealArray.end(); iterPoHeal++)
							{
								PotionHealArray[counter].destroy = true;
								counter++;
							}
							level = 3;
						}
						else {
							textDisplay1.text.setString("Not this way");
							textDisplay1.text.setCharacterSize(15);
							textDisplay1.LifeTime = 25;
							textDisplay1.text.setPosition(hitboxladder2.hitbox.getPosition().x - 10, hitboxladder2.hitbox.getPosition().y - 10);
							textDisplayArray.push_back(textDisplay1);
						}
					}
				}
			}
			if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxladder3.hitbox.getGlobalBounds()))
			{
				if (elapsed1.asSeconds() > 0.3) {
					clock1.restart();
					if (Keyboard::isKeyPressed(Keyboard::E)) {
						if (num == 3) {
							player.body.setPosition(400, 1700);
							chat = true;
							chatbox = 0;
							musicsewer.stop();
							musicfloor.play();
							musicfloor.setLoop(true);
							counter = 0;
							for (iterEnemy2 = enemy2Array.begin(); iterEnemy2 != enemy2Array.end(); iterEnemy2++)
							{
								enemy2Array[counter].alive = false;
								counter++;
							}
							counter = 0;
							for (iterPoHeal = PotionHealArray.begin(); iterPoHeal != PotionHealArray.end(); iterPoHeal++)
							{
								PotionHealArray[counter].destroy = true;
								counter++;
							}
							level = 3;
						}
						else {
							textDisplay1.text.setString("Not this way");
							textDisplay1.text.setCharacterSize(15);
							textDisplay1.LifeTime = 25;
							textDisplay1.text.setPosition(hitboxladder3.hitbox.getPosition().x - 10, hitboxladder3.hitbox.getPosition().y - 10);
							textDisplayArray.push_back(textDisplay1);
						}
					}
				}
			}
			if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxladder4.hitbox.getGlobalBounds()))
			{
				if (elapsed1.asSeconds() > 0.3) {
					clock1.restart();
					if (Keyboard::isKeyPressed(Keyboard::E)) {
						if (num == 4) {
							player.body.setPosition(400, 1700);
							chat = true;
							chatbox = 0;
							musicsewer.stop();
							musicfloor.play();
							musicfloor.setLoop(true);
							counter = 0;
							for (iterEnemy2 = enemy2Array.begin(); iterEnemy2 != enemy2Array.end(); iterEnemy2++)
							{
								enemy2Array[counter].alive = false;
								counter++;
							}
							counter = 0;
							for (iterPoHeal = PotionHealArray.begin(); iterPoHeal != PotionHealArray.end(); iterPoHeal++)
							{
								PotionHealArray[counter].destroy = true;
								counter++;
							}
							level = 3;
						}
						else {
							textDisplay1.text.setString("Not this way");
							textDisplay1.text.setCharacterSize(15);
							textDisplay1.LifeTime = 25;
							textDisplay1.text.setPosition(hitboxladder4.hitbox.getPosition().x - 10, hitboxladder4.hitbox.getPosition().y - 10);
							textDisplayArray.push_back(textDisplay1);
						}
					}
				}
			}
			if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxladder5.hitbox.getGlobalBounds()))
			{
				if (elapsed1.asSeconds() > 0.3) {
					clock1.restart();
					if (Keyboard::isKeyPressed(Keyboard::E)) {
						if (num == 5) {
							player.body.setPosition(400, 1700);
							chat = true;
							chatbox = 0;
							musicsewer.stop();
							musicfloor.play();
							musicfloor.setLoop(true);
							counter = 0;
							for (iterEnemy2 = enemy2Array.begin(); iterEnemy2 != enemy2Array.end(); iterEnemy2++)
							{
								enemy2Array[counter].alive = false;
								counter++;
							}
							counter = 0;
							for (iterPoHeal = PotionHealArray.begin(); iterPoHeal != PotionHealArray.end(); iterPoHeal++)
							{
								PotionHealArray[counter].destroy = true;
								counter++;
							}
							level = 3;
						}
						else {
							textDisplay1.text.setString("Not this way");
							textDisplay1.text.setCharacterSize(15);
							textDisplay1.LifeTime = 25;
							textDisplay1.text.setPosition(hitboxladder5.hitbox.getPosition().x - 10, hitboxladder5.hitbox.getPosition().y - 10);
							textDisplayArray.push_back(textDisplay1);
						}
					}
				}
			}

			//Enemy collide player
			if (elapsed2.asSeconds() >= 0.6)
			{
				clock2.restart();
				counter = 0;
				for (iterEnemy2 = enemy2Array.begin(); iterEnemy2 != enemy2Array.end(); iterEnemy2++)
				{
					if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(enemy2Array[counter].enemy.getGlobalBounds()))
					{
						if (player.hp > 0) {
							textDisplay1.text.setString(to_string(enemy2Array[counter].enemy2attackDamage));
							textDisplay1.text.setPosition(player.body.getPosition().x - 10, player.body.getPosition().y - 45);
							textDisplayArray.push_back(textDisplay1);
							player.hp -= enemy2Array[counter].enemy2attackDamage;
							view.boxX -= enemy2Array[counter].enemy2attackDamage*1.5;
							/*if (player.face == 0) {
								enemyArray[counter].speed = 15;
								player.body.move(20, 0);
							}
							else if (player.face == 1) {
								enemyArray[counter].speed = 15;
								player.body.move(-20, 0);
							}
							else if (player.face == 2) {
								enemyArray[counter].speed = 15;
								player.body.move(0, 20);
							}
							else if (player.face == 3) {
								enemyArray[counter].speed = 15;
								player.body.move(0, -20);
							}*/
							soundPlayer.play();
						}
					}
					counter++;
				}
			}

			//player slash enemy
			if (elapsed3.asSeconds() >= 0.3)
			{
				clock3.restart();
				counter = 0;
				for (iterEnemy2 = enemy2Array.begin(); iterEnemy2 != enemy2Array.end(); iterEnemy2++)
				{
					if (Keyboard::isKeyPressed(Keyboard::Space)) {
						if (player.getWeapon() == 1 && (player.hitboxPlayerSwordleft->hitbox.getGlobalBounds().intersects(enemy2Array[counter].enemy.getGlobalBounds()) && player.getFace() == 0
							|| player.hitboxPlayerSwordRight->hitbox.getGlobalBounds().intersects(enemy2Array[counter].enemy.getGlobalBounds()) && player.getFace() == 1
							|| player.hitboxPlayerSwordUp->hitbox.getGlobalBounds().intersects(enemy2Array[counter].enemy.getGlobalBounds()) && player.getFace() == 2
							|| player.hitboxPlayerSwordDown->hitbox.getGlobalBounds().intersects(enemy2Array[counter].enemy.getGlobalBounds()) && player.getFace() == 3))
						{

							enemy2Array[counter].enemy2hp -= player.attackSword;
							if (enemy2Array[counter].face == 0) {
								enemy2Array[counter].enemy.move(20, 0);
							}
							else if (enemy2Array[counter].face == 1) {
								enemy2Array[counter].enemy.move(-20, 0);
							}
							else if (enemy2Array[counter].face == 2) {
								enemy2Array[counter].enemy.move(0, 20);
							}
							else if (enemy2Array[counter].face == 3) {
								enemy2Array[counter].enemy.move(0, -20);
							}
							soundZombie.play();
						}
					}
					if (enemy2Array[counter].enemy2hp <= 0)
					{
						enemy2Array[counter].alive = false;
					}
					counter++;
				}
			}

			//Projectile Collides with Enemy
			counter = 0;
			for (iterBullet = projectileArray.begin(); iterBullet != projectileArray.end(); iterBullet++)
			{
				counter2 = 0;
				for (iterEnemy2 = enemy2Array.begin(); iterEnemy2 != enemy2Array.end(); iterEnemy2++)
				{
					if (projectileArray[counter].bullet.getGlobalBounds().intersects(enemy2Array[counter2].enemy.getGlobalBounds()))
					{
						projectileArray[counter].destroy = true;
						if (enemy2Array[counter2].face == 0) {
							enemy2Array[counter2].enemy.move(10, 0);
						}
						else if (enemy2Array[counter2].face == 1) {
							enemy2Array[counter2].enemy.move(-10, 0);
						}
						else if (enemy2Array[counter2].face == 2) {
							enemy2Array[counter2].enemy.move(0, 10);
						}
						else if (enemy2Array[counter2].face == 3) {
							enemy2Array[counter2].enemy.move(0, -10);
						}
						enemy2Array[counter2].enemy2hp--;
						soundZombie.play();

						if (enemy2Array[counter2].enemy2hp <= 0)
						{
							enemy2Array[counter2].alive = false;
						}
					}
					counter2++;
				}
				counter++;
			}

			//hitbox update
			player.hitboxPlayer->Update(player.GetPosition(), -12.5, -12.5);
			player.hitboxPlayerAll->Update(player.GetPosition(), -12.5, -22.5);
			player.hitboxPlayerSwordleft->Update(player.GetPosition(), -40, -12);
			player.hitboxPlayerSwordRight->Update(player.GetPosition(), 25, -12);
			player.hitboxPlayerSwordUp->Update(player.GetPosition(), 0, -30);
			player.hitboxPlayerSwordDown->Update(player.GetPosition(), 0, 22);

			// Delete dead enemy
			counter = 0;
			for (iterEnemy2 = enemy2Array.begin(); iterEnemy2 != enemy2Array.end(); iterEnemy2++)
			{
				if (enemy2Array[counter].alive == false)
				{
					if (random.generateRandom(1, 8) == 1) {
						PotionHeal.item.setPosition(enemy2Array[counter].enemy.getPosition());
						PotionHealArray.push_back(PotionHeal);
					}
					enemy2Array.erase(iterEnemy2);
					break;
				}
				counter++;
			}

			//Delete Projectile
			counter = 0;
			for (iterBullet = projectileArray.begin(); iterBullet != projectileArray.end(); iterBullet++)
			{
				if (projectileArray[counter].destroy == true)
				{
					projectileArray.erase(iterBullet);
					break;
				}
				counter++;
			}

			//delete text
			counter = 0;
			for (iterText = textDisplayArray.begin(); iterText != textDisplayArray.end(); iterText++)
			{
				if (textDisplayArray[counter].destroy == true)
				{
					textDisplayArray.erase(iterText);
					break;
				}
				counter++;
			}

			//delete item
			counter = 0;
			for (iterPoHeal = PotionHealArray.begin(); iterPoHeal != PotionHealArray.end(); iterPoHeal++)
			{
				if (PotionHealArray[counter].destroy == true)
				{
					PotionHealArray.erase(iterPoHeal);
					break;
				}

				counter++;
			}

			//fire projectiles
			if (player.getWeapon() == 2)
			{
				if (elapsed1.asSeconds() >= 0.7)
				{
					clock1.restart();
					if (Keyboard::isKeyPressed(Keyboard::Space))
					{
						soundShot.play();

						if (player.getFace() == 0) //left
						{
							projectile1.bullet.setPosition(player.GetPositionX() - 20, player.GetPositionY() - 12);
						}
						else if (player.getFace() == 1) //right
						{
							projectile1.bullet.setPosition(player.GetPositionX() + 20, player.GetPositionY() - 12);
						}
						else if (player.getFace() == 2) //up
						{
							projectile1.bullet.setPosition(player.GetPositionX() - 10, player.GetPositionY() - 8);
						}
						else if (player.getFace() == 3) //down
						{
							projectile1.bullet.setPosition(player.GetPositionX() + 8, player.GetPositionY() + 8);
						}
						projectile1.direction = player.getFace();
						projectileArray.push_back(projectile1);
						GlockBullet--;
					}
				}
			}
			if (player.getWeapon() == 3)
			{
				if (elapsed1.asSeconds() >= 0.2)
				{
					clock1.restart();
					if (Keyboard::isKeyPressed(Keyboard::Space))
					{
						soundShot.play();

						if (player.getFace() == 0) //left
						{
							projectile1.bullet.setPosition(player.GetPositionX() - 20, player.GetPositionY() + 4);
						}
						else if (player.getFace() == 1) //right
						{
							projectile1.bullet.setPosition(player.GetPositionX() + 20, player.GetPositionY() + 2);
						}
						else if (player.getFace() == 2) //up
						{
							projectile1.bullet.setPosition(player.GetPositionX() + 7, player.GetPositionY() - 8);
						}
						else if (player.getFace() == 3) //down
						{
							projectile1.bullet.setPosition(player.GetPositionX() - 10, player.GetPositionY() + 8);
						}
						projectile1.direction = player.getFace();
						projectileArray.push_back(projectile1);
						SMGBullet--;
					}
				}
			}
			if (player.getWeapon() == 4)
			{
				if (elapsed1.asSeconds() >= 1)
				{
					clock1.restart();
					if (Keyboard::isKeyPressed(Keyboard::Space))
					{
						soundShotgun.play();
						if (player.getFace() == 0) //left
						{
							projectile1.bullet.setPosition(player.GetPositionX() - 25, player.GetPositionY() - 15);
							projectile2.bullet.setPosition(player.GetPositionX() - 25, player.GetPositionY() - 25);
							projectile3.bullet.setPosition(player.GetPositionX() - 25, player.GetPositionY() - 5);
						}
						else if (player.getFace() == 1) //right
						{
							projectile1.bullet.setPosition(player.GetPositionX() + 20, player.GetPositionY() - 12);
							projectile2.bullet.setPosition(player.GetPositionX() + 20, player.GetPositionY() - 22);
							projectile3.bullet.setPosition(player.GetPositionX() + 20, player.GetPositionY() - 2);
						}
						else if (player.getFace() == 2) //up
						{
							projectile1.bullet.setPosition(player.GetPositionX() - 10, player.GetPositionY() - 8);
							projectile2.bullet.setPosition(player.GetPositionX() - 20, player.GetPositionY() - 8);
							projectile3.bullet.setPosition(player.GetPositionX(), player.GetPositionY() - 8);
						}
						else if (player.getFace() == 3) //down
						{
							projectile1.bullet.setPosition(player.GetPositionX() + 8, player.GetPositionY() + 8);
							projectile2.bullet.setPosition(player.GetPositionX() - 2, player.GetPositionY() + 8);
							projectile3.bullet.setPosition(player.GetPositionX() + 18, player.GetPositionY() + 8);
						}
						projectile1.direction = player.getFace();
						projectile2.direction = player.getFace();
						projectile3.direction = player.getFace();
						projectileArray.push_back(projectile1);
						projectileArray.push_back(projectile2);
						projectileArray.push_back(projectile3);
						ShotgunBullet--;
					}
				}
			}
			//delete gun
			if (GlockBullet <= 0) {
				player.isGlock = false;
			}
			if (SMGBullet <= 0) {
				player.isSMG = false;
			}
			if (ShotgunBullet <= 0) {
				player.isShotgun = false;
			}

			//draw map
			window.draw(map2);

			//draw item
			counter = 0;
			for (iterPoHeal = PotionHealArray.begin(); iterPoHeal != PotionHealArray.end(); iterPoHeal++)
			{
				PotionHealArray[counter].Update();
				window.draw(PotionHealArray[counter].item);

				counter++;
			}

			//draw projectile
			if (player.getWeapon() == 4) {
				projectile1.bullet.setSize(Vector2f(8, 8));
				projectile2.bullet.setSize(Vector2f(8, 8));
				projectile3.bullet.setSize(Vector2f(8, 8));
				counter = 0;
				for (iterBullet = projectileArray.begin(); iterBullet != projectileArray.end(); iterBullet++)
				{
					projectileArray[counter].Update(); //update projectile
					window.draw(projectileArray[counter].bullet);
					counter++;
				}
			}
			else {
				projectile1.bullet.setSize(Vector2f(6, 6));
				projectile2.bullet.setSize(Vector2f(0, 0));
				projectile3.bullet.setSize(Vector2f(0, 0));
				counter = 0;
				for (iterBullet = projectileArray.begin(); iterBullet != projectileArray.end(); iterBullet++)
				{
					projectileArray[counter].Update(); //update projectile
					window.draw(projectileArray[counter].bullet);

					counter++;
				}
			}

			//draw enemies
			counter = 0;
			for (iterEnemy2 = enemy2Array.begin(); iterEnemy2 != enemy2Array.end(); iterEnemy2++)
			{
				if (player.GetPosition().y > enemy2Array[counter].GetPosition().y)
				{
					enemy2Array[counter].text.setString("HP " + to_string(enemy2Array[counter].enemy2hp) + "/" + to_string(enemy2Array[counter].enemy2maxhp));
					window.draw(enemy2Array[counter].text);

					enemy2Array[counter].Update();
					enemy2Array[counter].UpdateMovement(deltaTime, player.GetPosition(), player.GetSize());
					window.draw(enemy2Array[counter].enemy);
				}
				counter++;
			}

			//draw player
			player.Draw(window);

			//draw enemies
			counter = 0;
			for (iterEnemy2 = enemy2Array.begin(); iterEnemy2 != enemy2Array.end(); iterEnemy2++)
			{
				if (player.GetPosition().y < enemy2Array[counter].GetPosition().y)
				{
					enemy2Array[counter].text.setString("HP " + to_string(enemy2Array[counter].enemy2hp) + "/" + to_string(enemy2Array[counter].enemy2maxhp));
					window.draw(enemy2Array[counter].text);

					enemy2Array[counter].Update();
					enemy2Array[counter].UpdateMovement(deltaTime, player.GetPosition(), player.GetSize());
					window.draw(enemy2Array[counter].enemy);
				}
				counter++;
			}

			//draw button
			if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxladder1.hitbox.getGlobalBounds())
				||player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxladder2.hitbox.getGlobalBounds())
				|| player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxladder3.hitbox.getGlobalBounds())
				|| player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxladder4.hitbox.getGlobalBounds())
				|| player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxladder5.hitbox.getGlobalBounds()))
			{
				//show e
				Ebutton.setPosition(player.body.getPosition().x + 20, player.body.getPosition().y - 30);
				window.draw(Ebutton);
			}

			//draw hitbox
			counter = 0;
			for (iterWall2 = Wallmap2Array.begin(); iterWall2 != Wallmap2Array.end(); iterWall2++)
			{
				Wallmap2Array[counter].Draw(window);
				counter++;
			}

			//draw hitbox ladder
			hitboxladder1.Draw(window);
			hitboxladder2.Draw(window);
			hitboxladder3.Draw(window);
			hitboxladder4.Draw(window);
			hitboxladder5.Draw(window);

			//draw text
			counter = 0;
			for (iterText = textDisplayArray.begin(); iterText != textDisplayArray.end(); iterText++)
			{
				textDisplayArray[counter].Update();
				window.draw(textDisplayArray[counter].text);

				counter++;
			}

			//bullet draw
			view.name.setString(textbox1.getText());
			view.glockBullet.setString(to_string(GlockBullet) + "/" + to_string(MaxGlockBullet));
			view.smgBullet.setString(to_string(SMGBullet) + "/" + to_string(MaxSMGBullet));
			view.shotgunBullet.setString(to_string(ShotgunBullet) + "/" + to_string(MaxShotgunBullet));
			view.HP.setString("HP : " + to_string(player.hp) + "/" + to_string(player.maxhp));
			view.one.setString("1");
			view.two.setString("2");
			view.three.setString("3");
			view.four.setString("4");

			//HP Draw
			view.Draw(window);
			if (chat == true) 
			{
				player.canMoveDown = false;
				player.canMoveL = false;
				player.canMoveR = false;
				player.canMoveUp = false;

				if (chatbox == 0)
				{
					chat1.chatbox.setPosition(Vector2f(350, 250));
					chat1.chat1.setPosition(Vector2f(chat1.chatbox.getPosition().x - chat1.chatbox.getSize().x / 2 + 60, chat1.chatbox.getPosition().y - 5));
					chat1.chat1.setString("We have to find the right way to go up.");
					chat1.Draw1(window);
					if (elapsed4.asSeconds() >= 0.2)
					{
						clock4.restart();
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							player.canMoveDown = true;
							player.canMoveL = true;
							player.canMoveR = true;
							player.canMoveUp = true;
							chat = false;
						}
					}
				}
			}

			if (chat == false) {
				view.task.setString("Task");
				view.task4.setString("Find the right way");
				view.task2.setString("");
				view.task3.setString("");
				view.task1.setString("");

				view.DrawTask(window);
				view.DrawTask1(window);
			}
		}

		if (level == 3) { //level3 ********************************************************************************************************

			player.Update(deltaTime);

			////pause
			//if ((Keyboard::isKeyPressed(Keyboard::Escape))) {
			//	pause = true;
			//	level = 0;
			//}

			//player view set
			view.viewUpdate(player, map3);

			//clear screen
			window.clear();

			view.setView(window);

			//Clock
			Time elapsed1 = clock1.getElapsedTime();
			Time elapsed2 = clock2.getElapsedTime();
			Time elapsed3 = clock3.getElapsedTime();

			//player collide edge
			player.playerCollideEdge(map3.getSize(), map3.getPosition());

			//player collide hitboxmap 
			counter = 0;
			for (iterWall3 = Wallmap3Array.begin(); iterWall3 != Wallmap3Array.end(); iterWall3++)
			{
				Wallmap3Array[counter].GetCollider().CheckCollision(player.GetCollider(), 1.0f);
				counter++;
			}

			//fixed when hold SMG can't press E
			//player fixed generator
			if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxgen1.hitbox.getGlobalBounds()))
			{
				if (elapsed1.asSeconds() > 0.1) {
					clock1.restart();
					if (gen1fixed == false) {
						if (Keyboard::isKeyPressed(Keyboard::E)) {
							gen1size += 5;
							gen1.Update(Vector2f(gen1size, 7));
							if (gen1size >= 70) {
								gen1size = 70;
								gen += 1;
								gen1fixed = true;
							}
						}
					}
				}
			}
			if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxgen2.hitbox.getGlobalBounds()))
			{
				if (elapsed1.asSeconds() > 0.1) {
					clock1.restart();
					if (gen2fixed == false) {
						if (Keyboard::isKeyPressed(Keyboard::E)) {
							gen2size += 5;
							gen2.Update(Vector2f(gen2size, 7));
							if (gen2size >= 70) {
								gen2size = 70;
								gen += 1;
								gen2fixed = true;
							}
						}
					}
				}
			}
			if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxgen3.hitbox.getGlobalBounds()))
			{
				if (elapsed1.asSeconds() > 0.1) {
					clock1.restart();
					if (gen3fixed == false) {
						if (Keyboard::isKeyPressed(Keyboard::E)) {
							gen3size += 5;
							gen3.Update(Vector2f(gen3size, 7));
							if (gen3size >= 70) {
								gen3size = 70;
								gen += 1;
								gen3fixed = true;
							}
						}
					}
				}
			}
			if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxgen4.hitbox.getGlobalBounds()))
			{
				if (elapsed1.asSeconds() > 0.1) {
					clock1.restart();
					if (gen4fixed == false) {
						if (Keyboard::isKeyPressed(Keyboard::E)) {
							gen4size += 5;
							gen4.Update(Vector2f(gen4size, 7));
							if (gen4size >= 70) {
								gen4size = 70;
								gen += 1;
								gen4fixed = true;
							}
						}
					}
				}
			}
			if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxgen5.hitbox.getGlobalBounds()))
			{
				if (elapsed1.asSeconds() > 0.1) {
					clock1.restart();
					if (gen5fixed == false) {
						if (Keyboard::isKeyPressed(Keyboard::E)) {
							gen5size += 5;
							gen5.Update(Vector2f(gen5size, 7));
							if (gen5size >= 70) {
								gen5size = 70;
								gen += 1;
								gen5fixed = true;
							}
						}
					}
				}
			}
			if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxgen6.hitbox.getGlobalBounds()))
			{
				if (elapsed1.asSeconds() > 0.1) {
					clock1.restart();
					if (gen6fixed == false) {
						if (Keyboard::isKeyPressed(Keyboard::E)) {
							gen6size += 5;
							gen6.Update(Vector2f(gen6size, 7));
							if (gen6size >= 70) {
								gen6size = 70;
								gen += 1;
								gen6fixed = true;
							}
						}
					}
				}
			}

			//enemy collide hitboxmap
			counter = 0;
			for (iterEnemy3 = enemy3Array.begin(); iterEnemy3 != enemy3Array.end(); iterEnemy3++)
			{
				counter2 = 0;
				for (iterWall3 = Wallmap3Array.begin(); iterWall3 != Wallmap3Array.end(); iterWall3++)
				{
					if (enemy3Array[counter].enemy.getGlobalBounds().intersects(Wallmap3Array[counter2].wall.getGlobalBounds()))
					{
						if (enemy3Array[counter].face == 0) //left
						{
							enemy3Array[counter].canMoveL = false;
							enemy3Array[counter].enemy.move(2, 0);
						}
						if (enemy3Array[counter].face == 1) //right
						{
							enemy3Array[counter].canMoveR = false;
							enemy3Array[counter].enemy.move(-2, 0);
						}
						if (enemy3Array[counter].face == 2) //up
						{
							enemy3Array[counter].canMoveUp = false;
							enemy3Array[counter].enemy.move(0, 2);
						}
						if (enemy3Array[counter].face == 3) //down
						{
							enemy3Array[counter].canMoveDown = false;
							enemy3Array[counter].enemy.move(0, -2);
						}
						break;
					}
					counter2++;
				}
				counter++;
			}

			//player collide item
			counter = 0;
			for (iterGlock = GlockArray.begin(); iterGlock != GlockArray.end(); iterGlock++)
			{
				if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(GlockArray[counter].item.getGlobalBounds()))
				{
					GlockArray[counter].destroy = true;
					soundHeal.play();
					player.isGlock = true;
					GlockBullet = 80;
				}
				counter++;
			}

			counter = 0;
			for (iterSMG = SMGArray.begin(); iterSMG != SMGArray.end(); iterSMG++)
			{
				if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(SMGArray[counter].item.getGlobalBounds()))
				{
					SMGArray[counter].destroy = true;
					soundHeal.play();
					player.isSMG = true;
					SMGBullet = 100;
				}

				counter++;
			}

			counter = 0;
			for (iterShotgun = ShotgunArray.begin(); iterShotgun != ShotgunArray.end(); iterShotgun++)
			{
				if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(ShotgunArray[counter].item.getGlobalBounds()))
				{
					ShotgunArray[counter].destroy = true;
					soundHeal.play();
					player.isShotgun = true;
					ShotgunBullet = 50;
				}

				counter++;
			}

			counter = 0;
			for (iterPoHeal = PotionHealArray.begin(); iterPoHeal != PotionHealArray.end(); iterPoHeal++)
			{
				if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(PotionHealArray[counter].item.getGlobalBounds()))
				{
					if (player.hp > 0) {
						PotionHealArray[counter].destroy = true;
						soundHeal.play();
						if (player.hp >= 80) {
							player.hp = 100;
							view.boxX = 150;
						}
						else {
							player.hp += 20;
							view.boxX += 30;
						}
					}
				}

				counter++;
			}

			//Enemy collide player
			if (elapsed2.asSeconds() >= 0.6)
			{
				clock2.restart();
				counter = 0;
				for (iterEnemy3 = enemy3Array.begin(); iterEnemy3 != enemy3Array.end(); iterEnemy3++)
				{
					if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(enemy3Array[counter].enemy.getGlobalBounds()))
					{
						if (player.hp > 0) {
							textDisplay1.text.setString(to_string(enemy3Array[counter].enemy3attackDamage));
							textDisplay1.text.setPosition(player.body.getPosition().x - 10, player.body.getPosition().y - 45);
							textDisplayArray.push_back(textDisplay1);
							player.hp -= enemy3Array[counter].enemy3attackDamage;
							view.boxX -= enemy3Array[counter].enemy3attackDamage*1.5;
							/*if (player.face == 0) {
								enemyArray[counter].speed = 15;
								player.body.move(20, 0);
							}
							else if (player.face == 1) {
								enemyArray[counter].speed = 15;
								player.body.move(-20, 0);
							}
							else if (player.face == 2) {
								enemyArray[counter].speed = 15;
								player.body.move(0, 20);
							}
							else if (player.face == 3) {
								enemyArray[counter].speed = 15;
								player.body.move(0, -20);
							}*/
							soundPlayer.play();
						}
					}
					counter++;
				}
			}

			//player slash enemy
			if (elapsed3.asSeconds() >= 0.3)
			{
				clock3.restart();
				counter = 0;
				for (iterEnemy3 = enemy3Array.begin(); iterEnemy3 != enemy3Array.end(); iterEnemy3++)
				{
					if (Keyboard::isKeyPressed(Keyboard::Space)) {
						if (player.getWeapon() == 1 && (player.hitboxPlayerSwordleft->hitbox.getGlobalBounds().intersects(enemy3Array[counter].enemy.getGlobalBounds()) && player.getFace() == 0
							|| player.hitboxPlayerSwordRight->hitbox.getGlobalBounds().intersects(enemy3Array[counter].enemy.getGlobalBounds()) && player.getFace() == 1
							|| player.hitboxPlayerSwordUp->hitbox.getGlobalBounds().intersects(enemy3Array[counter].enemy.getGlobalBounds()) && player.getFace() == 2
							|| player.hitboxPlayerSwordDown->hitbox.getGlobalBounds().intersects(enemy3Array[counter].enemy.getGlobalBounds()) && player.getFace() == 3))
						{

							enemy3Array[counter].enemy3hp -= player.attackSword;
							if (enemy3Array[counter].face == 0) {
								enemy3Array[counter].enemy.move(20, 0);
							}
							else if (enemy3Array[counter].face == 1) {
								enemy3Array[counter].enemy.move(-20, 0);
							}
							else if (enemy3Array[counter].face == 2) {
								enemy3Array[counter].enemy.move(0, 20);
							}
							else if (enemy3Array[counter].face == 3) {
								enemy3Array[counter].enemy.move(0, -20);
							}
							soundZombie.play();
						}
					}
					if (enemy3Array[counter].enemy3hp <= 0)
					{
						enemy3Array[counter].alive = false;
					}
					counter++;
				}
			}

			//Projectile Collides with Enemy
			counter = 0;
			for (iterBullet = projectileArray.begin(); iterBullet != projectileArray.end(); iterBullet++)
			{
				counter2 = 0;
				for (iterEnemy3 = enemy3Array.begin(); iterEnemy3 != enemy3Array.end(); iterEnemy3++)
				{
					if (projectileArray[counter].bullet.getGlobalBounds().intersects(enemy3Array[counter2].enemy.getGlobalBounds()))
					{
						projectileArray[counter].destroy = true;
						if (enemy3Array[counter2].face == 0) {
							enemy3Array[counter2].enemy.move(20, 0);
						}
						else if (enemy3Array[counter2].face == 1) {
							enemy3Array[counter2].enemy.move(-20, 0);
						}
						else if (enemy3Array[counter2].face == 2) {
							enemy3Array[counter2].enemy.move(0, 20);
						}
						else if (enemy3Array[counter2].face == 3) {
							enemy3Array[counter2].enemy.move(0, -20);
						}
						enemy3Array[counter2].enemy3hp--;
						soundZombie.play();

						if (enemy3Array[counter2].enemy3hp <= 0)
						{
							enemy3Array[counter2].alive = false;
						}
					}
					counter2++;
				}
				counter++;
			}

			//hitbox update
			player.hitboxPlayer->Update(player.GetPosition(), -12.5, -12.5);
			player.hitboxPlayerAll->Update(player.GetPosition(), -12.5, -22.5);
			player.hitboxPlayerSwordleft->Update(player.GetPosition(), -40, -12);
			player.hitboxPlayerSwordRight->Update(player.GetPosition(), 25, -12);
			player.hitboxPlayerSwordUp->Update(player.GetPosition(), 0, -30);
			player.hitboxPlayerSwordDown->Update(player.GetPosition(), 0, 22);

			//Delete dead enemy
			counter = 0;
			for (iterEnemy3 = enemy3Array.begin(); iterEnemy3 != enemy3Array.end(); iterEnemy3++)
			{
				if (enemy3Array[counter].alive == false)
				{
					ran = random.generateRandom(1, 4);
					if (ran == 1) {
						SMG.item.setPosition(enemy3Array[counter].enemy.getPosition());
						SMGArray.push_back(SMG);
						PotionHeal.item.setPosition(enemy3Array[counter].enemy.getPosition().x + 15, enemy3Array[counter].enemy.getPosition().y + 5);
						PotionHealArray.push_back(PotionHeal);
					}
					else if (ran == 2) {
						Glock.item.setPosition(enemy3Array[counter].enemy.getPosition());
						GlockArray.push_back(Glock);
						PotionHeal.item.setPosition(enemy3Array[counter].enemy.getPosition().x + 15, enemy3Array[counter].enemy.getPosition().y + 5);
						PotionHealArray.push_back(PotionHeal);
					}
					else if (ran == 3) {
						SMG.item.setPosition(enemy3Array[counter].enemy.getPosition());
						SMGArray.push_back(SMG);
						Glock.item.setPosition(enemy3Array[counter].enemy.getPosition().x + 15, enemy3Array[counter].enemy.getPosition().y + 5);
						GlockArray.push_back(Glock);
					}
					else if (ran == 4) {
						Shotgun.item.setPosition(enemy3Array[counter].enemy.getPosition());
						ShotgunArray.push_back(Shotgun);
						Glock.item.setPosition(enemy3Array[counter].enemy.getPosition().x + 15, enemy3Array[counter].enemy.getPosition().y + 5);
						GlockArray.push_back(Glock);
					}
					enemy3Array.erase(iterEnemy3);
					break;
				}
				counter++;
			}

			//Delete Projectile
			counter = 0;
			for (iterBullet = projectileArray.begin(); iterBullet != projectileArray.end(); iterBullet++)
			{
				if (projectileArray[counter].destroy == true)
				{
					projectileArray.erase(iterBullet);
					break;
				}
				counter++;
			}

			//delete text
			counter = 0;
			for (iterText = textDisplayArray.begin(); iterText != textDisplayArray.end(); iterText++)
			{
				if (textDisplayArray[counter].destroy == true)
				{
					textDisplayArray.erase(iterText);
					break;
				}
				counter++;
			}

			//delete item
			counter = 0;
			for (iterGlock = GlockArray.begin(); iterGlock != GlockArray.end(); iterGlock++)
			{
				if (GlockArray[counter].destroy == true)
				{
					GlockArray.erase(iterGlock);
					break;
				}

				counter++;
			}
			counter = 0;
			for (iterSMG = SMGArray.begin(); iterSMG != SMGArray.end(); iterSMG++)
			{
				if (SMGArray[counter].destroy == true)
				{
					SMGArray.erase(iterSMG);
					break;
				}

				counter++;
			}
			counter = 0;
			for (iterShotgun = ShotgunArray.begin(); iterShotgun != ShotgunArray.end(); iterShotgun++)
			{
				if (ShotgunArray[counter].destroy == true)
				{
					ShotgunArray.erase(iterShotgun);
					break;
				}

				counter++;
			}
			counter = 0;
			for (iterPoHeal = PotionHealArray.begin(); iterPoHeal != PotionHealArray.end(); iterPoHeal++)
			{
				if (PotionHealArray[counter].destroy == true)
				{
					PotionHealArray.erase(iterPoHeal);
					break;
				}

				counter++;
			}

			//fire projectiles
			if (player.getWeapon() == 2)
			{
				if (elapsed1.asSeconds() >= 0.7)
				{
					clock1.restart();
					if (Keyboard::isKeyPressed(Keyboard::Space))
					{
						soundShot.play();

						if (player.getFace() == 0) //left
						{
							projectile1.bullet.setPosition(player.GetPositionX() - 20, player.GetPositionY() - 12);
						}
						else if (player.getFace() == 1) //right
						{
							projectile1.bullet.setPosition(player.GetPositionX() + 20, player.GetPositionY() - 12);
						}
						else if (player.getFace() == 2) //up
						{
							projectile1.bullet.setPosition(player.GetPositionX() - 10, player.GetPositionY() - 8);
						}
						else if (player.getFace() == 3) //down
						{
							projectile1.bullet.setPosition(player.GetPositionX() + 8, player.GetPositionY() + 8);
						}
						projectile1.direction = player.getFace();
						projectileArray.push_back(projectile1);
						GlockBullet--;
					}
				}
			}
			if (player.getWeapon() == 3)
			{
				if (elapsed1.asSeconds() >= 0.2)
				{
					clock1.restart();
					if (Keyboard::isKeyPressed(Keyboard::Space))
					{
						soundShot.play();

						if (player.getFace() == 0) //left
						{
							projectile1.bullet.setPosition(player.GetPositionX() - 20, player.GetPositionY() + 4);
						}
						else if (player.getFace() == 1) //right
						{
							projectile1.bullet.setPosition(player.GetPositionX() + 20, player.GetPositionY() + 2);
						}
						else if (player.getFace() == 2) //up
						{
							projectile1.bullet.setPosition(player.GetPositionX() + 7, player.GetPositionY() - 8);
						}
						else if (player.getFace() == 3) //down
						{
							projectile1.bullet.setPosition(player.GetPositionX() - 10, player.GetPositionY() + 8);
						}
						projectile1.direction = player.getFace();
						projectileArray.push_back(projectile1);
						SMGBullet--;
					}
				}
			}
			if (player.getWeapon() == 4)
			{
				if (elapsed1.asSeconds() >= 1)
				{
					clock1.restart();
					if (Keyboard::isKeyPressed(Keyboard::Space))
					{
						soundShotgun.play();
						if (player.getFace() == 0) //left
						{
							projectile1.bullet.setPosition(player.GetPositionX() - 25, player.GetPositionY() - 15);
							projectile2.bullet.setPosition(player.GetPositionX() - 25, player.GetPositionY() - 25);
							projectile3.bullet.setPosition(player.GetPositionX() - 25, player.GetPositionY() - 5);
						}
						else if (player.getFace() == 1) //right
						{
							projectile1.bullet.setPosition(player.GetPositionX() + 20, player.GetPositionY() - 12);
							projectile2.bullet.setPosition(player.GetPositionX() + 20, player.GetPositionY() - 22);
							projectile3.bullet.setPosition(player.GetPositionX() + 20, player.GetPositionY() - 2);
						}
						else if (player.getFace() == 2) //up
						{
							projectile1.bullet.setPosition(player.GetPositionX() - 10, player.GetPositionY() - 8);
							projectile2.bullet.setPosition(player.GetPositionX() - 20, player.GetPositionY() - 8);
							projectile3.bullet.setPosition(player.GetPositionX(), player.GetPositionY() - 8);
						}
						else if (player.getFace() == 3) //down
						{
							projectile1.bullet.setPosition(player.GetPositionX() + 8, player.GetPositionY() + 8);
							projectile2.bullet.setPosition(player.GetPositionX() - 2, player.GetPositionY() + 8);
							projectile3.bullet.setPosition(player.GetPositionX() + 18, player.GetPositionY() + 8);
						}
						projectile1.direction = player.getFace();
						projectile2.direction = player.getFace();
						projectile3.direction = player.getFace();
						projectileArray.push_back(projectile1);
						projectileArray.push_back(projectile2);
						projectileArray.push_back(projectile3);
						ShotgunBullet--;
					}
				}
			}
			//delete gun
			if (GlockBullet <= 0) {
				player.isGlock = false;
			}
			if (SMGBullet <= 0) {
				player.isSMG = false;
			}
			if (ShotgunBullet <= 0) {
				player.isShotgun = false;
			}

			//draw map
			window.draw(map3);

			//draw projectile
			if (player.getWeapon() == 4) {
				projectile1.bullet.setSize(Vector2f(8, 8));
				projectile2.bullet.setSize(Vector2f(8, 8));
				projectile3.bullet.setSize(Vector2f(8, 8));
				counter = 0;
				for (iterBullet = projectileArray.begin(); iterBullet != projectileArray.end(); iterBullet++)
				{
					projectileArray[counter].Update(); //update projectile
					window.draw(projectileArray[counter].bullet);
					counter++;
				}
			}
			else {
				projectile1.bullet.setSize(Vector2f(6, 6));
				projectile2.bullet.setSize(Vector2f(0, 0));
				projectile3.bullet.setSize(Vector2f(0, 0));
				counter = 0;
				for (iterBullet = projectileArray.begin(); iterBullet != projectileArray.end(); iterBullet++)
				{
					projectileArray[counter].Update(); //update projectile
					window.draw(projectileArray[counter].bullet);

					counter++;
				}
			}

			//draw enemies
			counter = 0;
			for (iterEnemy3 = enemy3Array.begin(); iterEnemy3 != enemy3Array.end(); iterEnemy3++)
			{
				if (player.GetPosition().y > enemy3Array[counter].GetPosition().y)
				{
					enemy3Array[counter].text.setString("HP " + to_string(enemy3Array[counter].enemy3hp) + "/" + to_string(enemy3Array[counter].enemy3maxhp));
					window.draw(enemy3Array[counter].text);

					enemy3Array[counter].Update();
					enemy3Array[counter].UpdateMovement(deltaTime, player.GetPosition(), player.GetSize());
					window.draw(enemy3Array[counter].enemy);
				}
				counter++;
			}
			
			//draw item
			counter = 0;
			for (iterGlock = GlockArray.begin(); iterGlock != GlockArray.end(); iterGlock++)
			{
				GlockArray[counter].Update();
				window.draw(GlockArray[counter].item);

				counter++;
			}
			counter = 0;
			for (iterSMG = SMGArray.begin(); iterSMG != SMGArray.end(); iterSMG++)
			{
				SMGArray[counter].Update();
				window.draw(SMGArray[counter].item);

				counter++;
			}
			counter = 0;
			for (iterShotgun = ShotgunArray.begin(); iterShotgun != ShotgunArray.end(); iterShotgun++)
			{
				ShotgunArray[counter].Update();
				window.draw(ShotgunArray[counter].item);

				counter++;
			}
			counter = 0;
			for (iterPoHeal = PotionHealArray.begin(); iterPoHeal != PotionHealArray.end(); iterPoHeal++)
			{
				PotionHealArray[counter].Update();
				window.draw(PotionHealArray[counter].item);

				counter++;
			}

			//draw player
			player.Draw(window);

			//draw enemies
			counter = 0;
			for (iterEnemy3 = enemy3Array.begin(); iterEnemy3 != enemy3Array.end(); iterEnemy3++)
			{
				if (player.GetPosition().y < enemy3Array[counter].GetPosition().y)
				{
					enemy3Array[counter].text.setString("HP " + to_string(enemy3Array[counter].enemy3hp) + "/" + to_string(enemy3Array[counter].enemy3maxhp));
					window.draw(enemy3Array[counter].text);

					enemy3Array[counter].Update();
					enemy3Array[counter].UpdateMovement(deltaTime, player.GetPosition(), player.GetSize());
					window.draw(enemy3Array[counter].enemy);
				}
				counter++;
			}

			//draw button
			if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxgen1.hitbox.getGlobalBounds())
				|| player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxgen2.hitbox.getGlobalBounds())
				|| player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxgen3.hitbox.getGlobalBounds())
				|| player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxgen4.hitbox.getGlobalBounds())
				|| player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxgen5.hitbox.getGlobalBounds())
				|| player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxgen6.hitbox.getGlobalBounds()))
			{
				//show e
				Ebutton.setPosition(player.body.getPosition().x + 20, player.body.getPosition().y - 30);
				window.draw(Ebutton);
			}
			if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxgen1.hitbox.getGlobalBounds())) {
				gen1.Draw(window);
			}
			if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxgen2.hitbox.getGlobalBounds())) {
				gen2.Draw(window);
			}
			if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxgen3.hitbox.getGlobalBounds())) {
				gen3.Draw(window);
			}
			if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxgen4.hitbox.getGlobalBounds())) {
				gen4.Draw(window);
			}
			if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxgen5.hitbox.getGlobalBounds())) {
				gen5.Draw(window);
			}
			if (player.hitboxPlayer->hitbox.getGlobalBounds().intersects(hitboxgen6.hitbox.getGlobalBounds())) {
				gen6.Draw(window);
			}
			if (Keyboard::isKeyPressed(Keyboard::B)) {
				gen = 6;
			}

			//draw boxgreen door
			if (gen >= 6) {
				window.draw(boxgreen);
				//if (player.hitboxPlayerAll->hitbox.getGlobalBounds().intersects(hitboxdoor.hitbox.getGlobalBounds())) {
				//	player.body.setPosition(400, 1700);
				//	chat = true;
				//	chatbox = 0;
				//	counter = 0;
				//	for (iterEnemy3 = enemy3Array.begin(); iterEnemy3 != enemy3Array.end(); iterEnemy3++)
				//	{
				//		enemy3Array[counter].alive = false;
				//		counter++;
				//	}
				//	/*level = 4;*/
				//}
			}

			//draw hitbox gen
			hitboxgen1.Draw(window);
			hitboxgen2.Draw(window);
			hitboxgen3.Draw(window);
			hitboxgen4.Draw(window);
			hitboxgen5.Draw(window);
			hitboxgen6.Draw(window);
			hitboxdoor.Draw(window);

			//draw hitbox
			counter = 0;
			for (iterWall3 = Wallmap3Array.begin(); iterWall3 != Wallmap3Array.end(); iterWall3++)
			{
				Wallmap3Array[counter].Draw(window);
				counter++;
			}

			//draw text
			counter = 0;
			for (iterText = textDisplayArray.begin(); iterText != textDisplayArray.end(); iterText++)
			{
				textDisplayArray[counter].Update();
				window.draw(textDisplayArray[counter].text);

				counter++;
			}

			//bullet draw
			view.name.setString(textbox1.getText());
			view.glockBullet.setString(to_string(GlockBullet) + "/" + to_string(MaxGlockBullet));
			view.smgBullet.setString(to_string(SMGBullet) + "/" + to_string(MaxSMGBullet));
			view.shotgunBullet.setString(to_string(ShotgunBullet) + "/" + to_string(MaxShotgunBullet));
			view.HP.setString("HP : " + to_string(player.hp) + "/" + to_string(player.maxhp));
			view.one.setString("1");
			view.two.setString("2");
			view.three.setString("3");
			view.four.setString("4");

			//HP Draw
			view.Draw(window);
			if (chat == true) {
				player.canMoveDown = false;
				player.canMoveL = false;
				player.canMoveR = false;
				player.canMoveUp = false;

				if (chatbox == 0)
				{
					chat1.chatbox.setPosition(Vector2f(400, 1600));
					chat1.chat1.setPosition(Vector2f(chat1.chatbox.getPosition().x - chat1.chatbox.getSize().x / 2 + 60, chat1.chatbox.getPosition().y - 5));
					chat1.chat1.setString("Finally we can come in.");
					chat1.Draw1(window);
					if (elapsed4.asSeconds() >= 0.2)
					{
						clock4.restart();
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							chatbox = 1;
						}
					}
				}
				else if (chatbox == 1)
				{
					chat1.chatbox.setPosition(Vector2f(400, 1600));
					chat1.chat1.setPosition(Vector2f(chat1.chatbox.getPosition().x - chat1.chatbox.getSize().x / 2 + 60, chat1.chatbox.getPosition().y - 5));
					chat1.chat1.setString("We have to repair all of these generators.");
					chat1.Draw1(window);
					if (elapsed4.asSeconds() >= 0.1)
					{
						clock4.restart();
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							chatbox = 2;
						}
					}
				}
				else if (chatbox == 2)
				{
					chat1.chatbox.setPosition(Vector2f(400, 1600));
					chat1.chat1.setPosition(Vector2f(chat1.chatbox.getPosition().x - chat1.chatbox.getSize().x / 2 + 60, chat1.chatbox.getPosition().y - 5));
					chat1.chat1.setString("Watch out for the faster zombies.");
					chat1.Draw1(window);
					if (elapsed4.asSeconds() >= 0.1)
					{
						clock4.restart();
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							player.canMoveDown = true;
							player.canMoveL = true;
							player.canMoveR = true;
							player.canMoveUp = true;
							chat = false;
						}
					}
				}
			}
			if (chat == false) {
				view.task.setString("Task");
				view.task5.setString("Repair the generator (" + to_string(gen) + "/" + to_string(maxgen) + ")");
				view.task4.setString("");
				view.task3.setString("");
				view.task1.setString("");
				if (gen >= 6) {
					view.task5.setColor(Color::Green);
					view.task2.setString("    Find Door");
				}
				else {
					view.task2.setString("");
				}

				view.DrawTask(window);
				view.DrawTask1(window);
			}
		}
		//if (level == 4) {

		//}
		window.display();
	}

	return 0;
}




