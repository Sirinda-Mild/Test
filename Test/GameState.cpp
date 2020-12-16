//#include "GameState.h"
//
//GameState::GameState()
//{
//	window = new RenderWindow (VideoMode(1366, 768), "Walking Dead", Style::Fullscreen);
//	window->setFramerateLimit(60); 
//	playerTexture.loadFromFile("Character/mainFemale02.png");
//	enemyTexture.loadFromFile("Character/zombie1-1.png");
//	enemy2Texture.loadFromFile("Character/zombie2.png");
//	enemy3Texture.loadFromFile("Character/zombie3.png");
//	enemy4Texture.loadFromFile("Character/zombie4.png");
//	boxTexture.loadFromFile("Item/box.png");
//	bulletTexture.loadFromFile("Item/bullet.png");
//	GlockTexture.loadFromFile("Item/glock.png");
//	SMGTexture.loadFromFile("Item/smg.png");
//	ShotgunTexture.loadFromFile("Item/shotgun.png");
//	map1.loadFromFile("Map/map1.png");
//	map2Texture.loadFromFile("Map/mapsewer2.png");
//	map3Texture.loadFromFile("Map/umbrella1stfloor.png");
//	map4Texture.loadFromFile("Map/umbrella3rdfloor.png");
//	map5Texture.loadFromFile("Map/map5.png");
//	potionHeal.loadFromFile("Item/potionHeal.png");
//	crowbar.loadFromFile("Item/crowbar.png");
//	sewer.loadFromFile("Item/sewer.png");
//	keyTexture.loadFromFile("Item/keycard.png");
//	E.loadFromFile("Button/E.png");
//	if (!background.loadFromFile("Menu/mainmenu8.png")) {
//		printf("error");
//	}
//}
//
//void GameState::Update()
//{
//}
