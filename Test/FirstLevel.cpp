//#include "FirstLevel.h"
//
//FirstLevel::FirstLevel(Font font)
//{
//	playerTexture.loadFromFile("Character/mainFemale02.png");
//	enemyTexture.loadFromFile("Character/zombie1-1.png");
//	boxTexture.loadFromFile("Item/box.png");
//	bulletTexture.loadFromFile("Item/bullet.png");
//	GlockTexture.loadFromFile("Item/glock.png");
//	SMGTexture.loadFromFile("Item/smg.png");
//	ShotgunTexture.loadFromFile("Item/shotgun.png");
//	map1.loadFromFile("Map/map1.png");
//	potionHeal.loadFromFile("Item/potionHeal.png");
//	crowbar.loadFromFile("Item/crowbar.png");
//	sewer.loadFromFile("Item/sewer.png");
//	projectile1.bullet.setTexture(&bulletTexture);
//	projectile2.bullet.setTexture(&bulletTexture);
//	projectile3.bullet.setTexture(&bulletTexture);
//
//	//map object
//	map.setTexture(&map1);
//	map.setSize(Vector2f(1450, 2000));
//	map.setPosition(Vector2f(0, 0));
//
//	//font
//	/*font.loadFromFile("Font/ArcadeClassic.ttf");
//	fonthpzombie.loadFromFile("Font/DisposableDroidBB.ttf");*/
//	this->font = font;
//
//	//music
//	music1.openFromFile("Sound/onthestreet3.wav");
//	music1.play();
//	music1.setLoop(true);
//	zombie1.openFromFile("Sound/zombie.wav");
//	zombie1.play();
//	zombie1.setLoop(true);
//
//	//sound
//	bufferShot.loadFromFile("Sound/fireglock.wav");
//	soundShot.setBuffer(bufferShot);
//	bufferShotgun.loadFromFile("Sound/fireshotgun.wav");
//	soundShotgun.setBuffer(bufferShotgun);
//	bufferBox.loadFromFile("Sound/boxattacked.wav");
//	soundBox.setBuffer(bufferBox);
//	bufferHeal.loadFromFile("Sound/heal.wav");
//	soundHeal.setBuffer(bufferHeal);
//	bufferZombie.loadFromFile("Sound/zombieattacked.wav");
//	soundZombie.setBuffer(bufferZombie);
//	bufferPlayer.loadFromFile("Sound/playerattacked.wav");
//	soundPlayer.setBuffer(bufferPlayer);
//
//	//wall
//	wallMap10 = new Wall(Vector2f(58, 222), Vector2f(150, 1547));
//	wallMap11 = new Wall(Vector2f(405, 112), Vector2f(957.5, 168));
//	wallMap12 = new Wall(Vector2f(410, 530), Vector2f(205, 655));
//	wallMap13 = new Wall(Vector2f(462, 530), Vector2f(871, 653));
//	wallMap14 = new Wall(Vector2f(282, 167), Vector2f(262, 1242.5));
//	wallMap15 = new Wall(Vector2f(1110, 430), Vector2f(721, 1547));
//	wallMap16 = new Wall(Vector2f(232, 201), Vector2f(522, 1224.5));
//	wallMap17 = new Wall(Vector2f(58, 222), Vector2f(1073, 1214));
//	wallMap18 = new Wall(Vector2f(290, 166), Vector2f(783, 1242));
//	Wallmap1Array.push_back(*wallMap10);
//	Wallmap1Array.push_back(*wallMap11);
//	Wallmap1Array.push_back(*wallMap12);
//	Wallmap1Array.push_back(*wallMap13);
//	Wallmap1Array.push_back(*wallMap14);
//	Wallmap1Array.push_back(*wallMap14);
//	Wallmap1Array.push_back(*wallMap15);
//	Wallmap1Array.push_back(*wallMap16);
//	Wallmap1Array.push_back(*wallMap17);
//	Wallmap1Array.push_back(*wallMap18);
//
//	//textdisplay
//	//textDisplay1->text.setFont(this->font);
//	//textDisplay1->text.setColor(Color::Red);
//
//	//enemy
//	enemy1 = new Enemy(&enemyTexture, Vector2u(3, 5), 0.15f, 50.0f);
//	enemy1->text.setFont(fonthpzombie);
//	enemy1->text.setCharacterSize(15);
//	enemy1->text.setColor(Color::Red);
//
//	//random spawn enemy zone1
//	counter = 0;
//	while (counter < 10)
//	{
//		int boxX[10] = { 0 }, boxY[10] = { 0 };
//		int tempx, tempy, po = 0;
//		tempx = random->generateRandom(0, 1414);
//		tempy = random->generateRandom(950, 1950);
//		for (int i = 0; i < 10; i++)
//		{
//			if (tempx == boxX[i] && tempy == boxY[i])
//			{
//				po = 1;
//			}
//			if (tempx > 100 && tempx < 1283 && tempy>1089 && tempy < 1750)
//			{
//				po = 1;
//			}
//		}
//		if (po == 0) {
//			boxX[counter] = tempx;
//			boxY[counter] = tempy;
//			enemy1->enemy.setPosition(tempx, tempy);
//			enemyArray.push_back(*enemy1);
//
//			counter++;
//
//		}
//	}
//	//random spawn enemy zone2
//	counter = 0;
//	while (counter < 5)
//	{
//		int boxX[15] = { 0 }, boxY[15] = { 0 };
//		int tempx, tempy, po = 0;
//		tempx = random->generateRandom(460, 1414);
//		tempy = random->generateRandom(235, 943);
//		for (int i = 0; i < 10; i++)
//		{
//			if (tempx == boxX[i] && tempy == boxY[i])
//			{
//				po = 1;
//			}
//			if (tempx > 551 && tempx < 1116 && tempy>300 && tempy < 957)
//			{
//				po = 1;
//			}
//		}
//		if (po == 0) {
//			boxX[counter] = tempx;
//			boxY[counter] = tempy;
//			enemy1->enemy.setPosition(tempx, tempy);
//			enemyArray.push_back(*enemy1);
//
//			counter++;
//
//		}
//	}
//	
//	//item
//	BoxG = new PickupItem(&boxTexture, Vector2f(60, 60), Vector2f(60, 30), 0, 0, Vector2f(0, 0));
//	BoxSM = new PickupItem(&boxTexture, Vector2f(60, 60), Vector2f(60, 30), 0, 0, Vector2f(0, 0));
//	BoxSh = new PickupItem(&boxTexture, Vector2f(60, 60), Vector2f(60, 30), 0, 0, Vector2f(0, 0));
//	Glock = new PickupItem(&GlockTexture, Vector2f(30, 22), Vector2f(0, 0), 0, 0, Vector2f(0, 0));
//	SMG = new PickupItem(&SMGTexture, Vector2f(35, 22), Vector2f(0, 0), 0, 0, Vector2f(0, 0));
//	Shotgun = new PickupItem(&ShotgunTexture, Vector2f(40, 18), Vector2f(0, 0), 0, 0, Vector2f(0, 0));
//	PotionHeal = new PickupItem(&potionHeal, Vector2f(18, 26), Vector2f(0, 0), 0, 0, Vector2f(0, 0));
//	Crowbar = new PickupItem(&crowbar, Vector2f(40, 18), Vector2f(0, 0), 0, 0, Vector2f(0, 0));
//	Sewer = new PickupItem(&sewer, Vector2f(50, 50), Vector2f(0, 0), 0, 0, Vector2f(0, 0)); 
//	Sewer->item.setPosition(Vector2f(1250, 320));
//
//	//random spawn Glock box zone1
//	counter = 0;
//	while (counter < 1)
//	{
//		int boxX[7] = { 0 }, boxY[7] = { 0 };
//		int tempx, tempy, po = 0;
//		tempx = random->generateRandom(0, 1414);
//		tempy = random->generateRandom(950, 1950);
//		for (int i = 0; i < 10; i++)
//		{
//			if (tempx == boxX[i] && tempy == boxY[i])
//			{
//				po = 1;
//			}
//			if (tempx > 100 && tempx < 1283 && tempy>1089 && tempy < 1750)
//			{
//				po = 1;
//			}
//		}
//		if (po == 0) {
//			boxX[counter] = tempx;
//			boxY[counter] = tempy;
//			BoxG->setPosition(Vector2f(boxX[counter], boxY[counter]));
//			Glock->item.setPosition(boxX[counter] + 15, boxY[counter] + 20);
//			BoxGArray.push_back(*BoxG);
//			GlockArray.push_back(*Glock);
//			counter++;
//		}
//	}
//	//random spawn SMG box zone1
//	counter = 0;
//	while (counter < 1)
//	{
//		int boxX[7] = { 0 }, boxY[7] = { 0 };
//		int tempx, tempy, po = 0;
//		tempx = random->generateRandom(0, 1414);
//		tempy = random->generateRandom(950, 1950);
//		for (int i = 0; i < 10; i++)
//		{
//			if (tempx == boxX[i] && tempy == boxY[i])
//			{
//				po = 1;
//			}
//			if (tempx > 100 && tempx < 1283 && tempy>1089 && tempy < 1750)
//			{
//				po = 1;
//			}
//		}
//		if (po == 0) {
//			boxX[counter] = tempx;
//			boxY[counter] = tempy;
//			BoxSM->setPosition(Vector2f(boxX[counter], boxY[counter]));
//			SMG->item.setPosition(boxX[counter] + 15, boxY[counter] + 20);
//			BoxSMArray.push_back(*BoxSM);
//			SMGArray.push_back(*SMG);
//			counter++;
//		}
//	}
//	//random spawn Shotgun box zone1
//	counter = 0;
//	while (counter < 1)
//	{
//		int boxX[7] = { 0 }, boxY[7] = { 0 };
//		int tempx, tempy, po = 0;
//		tempx = random->generateRandom(0, 1414);
//		tempy = random->generateRandom(950, 1950);
//		for (int i = 0; i < 10; i++)
//		{
//			if (tempx == boxX[i] && tempy == boxY[i])
//			{
//				po = 1;
//			}
//			if (tempx > 100 && tempx < 1283 && tempy>1089 && tempy < 1750)
//			{
//				po = 1;
//			}
//		}
//		if (po == 0) {
//			boxX[counter] = tempx;
//			boxY[counter] = tempy;
//			BoxSh->setPosition(Vector2f(boxX[counter], boxY[counter]));
//			Shotgun->item.setPosition(boxX[counter] + 15, boxY[counter] + 20);
//			BoxShArray.push_back(*BoxSh);
//			ShotgunArray.push_back(*Shotgun);
//			counter++;
//		}
//	}
//	//random spawn Glock box zone2
//	counter = 0;
//	while (counter < 1)
//	{
//		int boxX[7] = { 0 }, boxY[7] = { 0 };
//		int tempx, tempy, po = 0;
//		tempx = random->generateRandom(420, 1414);
//		tempy = random->generateRandom(235, 943);
//		for (int i = 0; i < 10; i++)
//		{
//			if (tempx == boxX[i] && tempy == boxY[i])
//			{
//				po = 1;
//			}
//			if (tempx > 551 && tempx < 1116 && tempy>300 && tempy < 957)
//			{
//				po = 1;
//			}
//		}
//		if (po == 0) {
//			boxX[counter] = tempx;
//			boxY[counter] = tempy;
//			BoxG->setPosition(Vector2f(boxX[counter], boxY[counter]));
//			Glock->item.setPosition(boxX[counter] + 15, boxY[counter] + 20);
//			BoxGArray.push_back(*BoxG);
//			GlockArray.push_back(*Glock);
//			counter++;
//		}
//	}
//	//random spawn SMG box zone2
//	counter = 0;
//	while (counter < 1)
//	{
//		int boxX[7] = { 0 }, boxY[7] = { 0 };
//		int tempx, tempy, po = 0;
//		tempx = random->generateRandom(420, 1414);
//		tempy = random->generateRandom(235, 943);
//		for (int i = 0; i < 10; i++)
//		{
//			if (tempx == boxX[i] && tempy == boxY[i])
//			{
//				po = 1;
//			}
//			if (tempx > 551 && tempx < 1116 && tempy>300 && tempy < 957)
//			{
//				po = 1;
//			}
//		}
//		if (po == 0) {
//			boxX[counter] = tempx;
//			boxY[counter] = tempy;
//			BoxSM->setPosition(Vector2f(boxX[counter], boxY[counter]));
//			SMG->item.setPosition(boxX[counter] + 15, boxY[counter] + 20);
//			BoxSMArray.push_back(*BoxSM);
//			SMGArray.push_back(*SMG);
//			counter++;
//		}
//	}
//	//random spawn Shotgun box zone2
//	counter = 0;
//	while (counter < 1)
//	{
//		int boxX[7] = { 0 }, boxY[7] = { 0 };
//		int tempx, tempy, po = 0;
//		tempx = random->generateRandom(420, 1414);
//		tempy = random->generateRandom(235, 943);
//		for (int i = 0; i < 10; i++)
//		{
//			if (tempx == boxX[i] && tempy == boxY[i])
//			{
//				po = 1;
//			}
//			if (tempx > 551 && tempx < 1116 && tempy>300 && tempy < 957)
//			{
//				po = 1;
//			}
//		}
//		if (po == 0) {
//			boxX[counter] = tempx;
//			boxY[counter] = tempy;
//			BoxSh->setPosition(Vector2f(boxX[counter], boxY[counter]));
//			Shotgun->item.setPosition(boxX[counter] + 15, boxY[counter] + 20);
//			BoxShArray.push_back(*BoxSh);
//			ShotgunArray.push_back(*Shotgun);
//			counter++;
//		}
//	}
//
//}
//
//void FirstLevel::enemyUpdate()
//{
//	enemy1->UpdateMovement(deltaTime, player->GetPosition(), player->GetSize());
//}
//
//void FirstLevel::collideUpdate()
//{
//	//player collide hitboxmap 
//	counter = 0;
//	for (iterWall = Wallmap1Array.begin(); iterWall != Wallmap1Array.end(); iterWall++)
//	{
//		Wallmap1Array[counter].GetCollider().CheckCollision(player->GetCollider(), 1.0f);
//		counter++;
//	}
//
//	//enemy collide hitboxmap
//	counter = 0;
//	for (iterEnemy = enemyArray.begin(); iterEnemy != enemyArray.end(); iterEnemy++)
//	{
//		counter2 = 0;
//		for (iterWall = Wallmap1Array.begin(); iterWall != Wallmap1Array.end(); iterWall++)
//		{
//			if (enemyArray[counter].enemy.getGlobalBounds().intersects(Wallmap1Array[counter2].wall.getGlobalBounds()))
//			{
//				if (enemyArray[counter].face == 0) //left
//				{
//					enemyArray[counter].canMoveL = false;
//					enemyArray[counter].enemy.move(2, 0);
//				}
//				if (enemyArray[counter].face == 1) //right
//				{
//					enemyArray[counter].canMoveR = false;
//					enemyArray[counter].enemy.move(-2, 0);
//				}
//				if (enemyArray[counter].face == 2) //up
//				{
//					enemyArray[counter].canMoveUp = false;
//					enemyArray[counter].enemy.move(0, 2);
//				}
//				if (enemyArray[counter].face == 3) //down
//				{
//					enemyArray[counter].canMoveDown = false;
//					enemyArray[counter].enemy.move(0, -2);
//				}
//				break;
//			}
//			counter2++;
//		}
//		counter++;
//	}
//
//	//player collide box
//	counter = 0;
//	for (iterBoxG = BoxGArray.begin(); iterBoxG != BoxGArray.end(); iterBoxG++)
//	{
//		if (player->hitboxPlayer->hitbox.getGlobalBounds().intersects(BoxGArray[counter].item.getGlobalBounds()))
//		{
//			if (player->getFace() == 0)
//			{
//				player->canMoveL = false;
//				player->body.move(2, 0);
//			}
//			if (player->getFace() == 1)
//			{
//				player->canMoveR = false;
//				player->body.move(-2, 0);
//			}
//			if (player->getFace() == 2)
//			{
//				player->canMoveUp = false;
//				player->body.move(0, 2);
//			}
//			if (player->getFace() == 3)
//			{
//				player->canMoveDown = false;
//				player->body.move(0, -2);
//			}
//		}
//
//		counter++;
//	}
//	counter = 0;
//	for (iterBoxSM = BoxSMArray.begin(); iterBoxSM != BoxSMArray.end(); iterBoxSM++)
//	{
//		if (player->hitboxPlayer->hitbox.getGlobalBounds().intersects(BoxSMArray[counter].item.getGlobalBounds()))
//		{
//			if (player->getFace() == 0)
//			{
//				player->canMoveL = false;
//				player->body.move(2, 0);
//			}
//			if (player->getFace() == 1)
//			{
//				player->canMoveR = false;
//				player->body.move(-2, 0);
//			}
//			if (player->getFace() == 2)
//			{
//				player->canMoveUp = false;
//				player->body.move(0, 2);
//			}
//			if (player->getFace() == 3)
//			{
//				player->canMoveDown = false;
//				player->body.move(0, -2);
//			}
//		}
//
//		counter++;
//	}
//	counter = 0;
//	for (iterBoxSh = BoxShArray.begin(); iterBoxSh != BoxShArray.end(); iterBoxSh++)
//	{
//		if (player->hitboxPlayer->hitbox.getGlobalBounds().intersects(BoxShArray[counter].item.getGlobalBounds()))
//		{
//			if (player->getFace() == 0)
//			{
//				player->canMoveL = false;
//				player->body.move(2, 0);
//			}
//			if (player->getFace() == 1)
//			{
//				player->canMoveR = false;
//				player->body.move(-2, 0);
//			}
//			if (player->getFace() == 2)
//			{
//				player->canMoveUp = false;
//				player->body.move(0, 2);
//			}
//			if (player->getFace() == 3)
//			{
//				player->canMoveDown = false;
//				player->body.move(0, -2);
//			}
//		}
//
//		counter++;
//	}
//	//enemy collide box
//	counter = 0;
//	for (iterEnemy = enemyArray.begin(); iterEnemy != enemyArray.end(); iterEnemy++)
//	{
//		counter2 = 0;
//		for (iterBoxG = BoxGArray.begin(); iterBoxG != BoxGArray.end(); iterBoxG++)
//		{
//			if (enemyArray[counter].enemy.getGlobalBounds().intersects(BoxGArray[counter2].hitboxBox.hitbox.getGlobalBounds()))
//			{
//				if (enemyArray[counter].face == 0) //left
//				{
//					enemyArray[counter].canMoveL = false;
//					enemyArray[counter].enemy.move(2, 0);
//				}
//				if (enemyArray[counter].face == 1) //right
//				{
//					enemyArray[counter].canMoveR = false;
//					enemyArray[counter].enemy.move(-2, 0);
//				}
//				if (enemyArray[counter].face == 2) //up
//				{
//					enemyArray[counter].canMoveUp = false;
//					enemyArray[counter].enemy.move(0, 2);
//				}
//				if (enemyArray[counter].face == 3) //down
//				{
//					enemyArray[counter].canMoveDown = false;
//					enemyArray[counter].enemy.move(0, -2);
//				}
//				break;
//			}
//			else
//			{
//				enemyArray[counter].canMoveL = true;
//				enemyArray[counter].canMoveR = true;
//				enemyArray[counter].canMoveUp = true;
//				enemyArray[counter].canMoveDown = true;
//			}
//			counter2++;
//		}
//		counter++;
//	}
//
//	counter = 0;
//	for (iterEnemy = enemyArray.begin(); iterEnemy != enemyArray.end(); iterEnemy++)
//	{
//		counter2 = 0;
//		for (iterBoxSM = BoxSMArray.begin(); iterBoxSM != BoxSMArray.end(); iterBoxSM++)
//		{
//			if (enemyArray[counter].enemy.getGlobalBounds().intersects(BoxSMArray[counter2].hitboxBox.hitbox.getGlobalBounds()))
//			{
//				if (enemyArray[counter].face == 0) //left
//				{
//					enemyArray[counter].canMoveL = false;
//					enemyArray[counter].enemy.move(2, 0);
//				}
//				if (enemyArray[counter].face == 1) //right
//				{
//					enemyArray[counter].canMoveR = false;
//					enemyArray[counter].enemy.move(-2, 0);
//				}
//				if (enemyArray[counter].face == 2) //up
//				{
//					enemyArray[counter].canMoveUp = false;
//					enemyArray[counter].enemy.move(0, 2);
//				}
//				if (enemyArray[counter].face == 3) //down
//				{
//					enemyArray[counter].canMoveDown = false;
//					enemyArray[counter].enemy.move(0, -2);
//				}
//				break;
//			}
//			counter2++;
//		}
//		counter++;
//	}
//
//	counter = 0;
//	for (iterEnemy = enemyArray.begin(); iterEnemy != enemyArray.end(); iterEnemy++)
//	{
//		counter2 = 0;
//		for (iterBoxSh = BoxShArray.begin(); iterBoxSh != BoxShArray.end(); iterBoxSh++)
//		{
//			if (enemyArray[counter].enemy.getGlobalBounds().intersects(BoxShArray[counter2].hitboxBox.hitbox.getGlobalBounds()))
//			{
//				if (enemyArray[counter].face == 0) //left
//				{
//					enemyArray[counter].canMoveL = false;
//					enemyArray[counter].enemy.move(2, 0);
//				}
//				if (enemyArray[counter].face == 1) //right
//				{
//					enemyArray[counter].canMoveR = false;
//					enemyArray[counter].enemy.move(-2, 0);
//				}
//				if (enemyArray[counter].face == 2) //up
//				{
//					enemyArray[counter].canMoveUp = false;
//					enemyArray[counter].enemy.move(0, 2);
//				}
//				if (enemyArray[counter].face == 3) //down
//				{
//					enemyArray[counter].canMoveDown = false;
//					enemyArray[counter].enemy.move(0, -2);
//				}
//				break;
//			}
//			counter2++;
//		}
//		counter++;
//	}
//
//	//player collide item
//	counter = 0;
//	for (iterGlock = GlockArray.begin(); iterGlock != GlockArray.end(); iterGlock++)
//	{
//		if (player->hitboxPlayer->hitbox.getGlobalBounds().intersects(GlockArray[counter].item.getGlobalBounds()))
//		{
//			GlockArray[counter].destroy = true;
//			soundHeal.play();
//			player->isGlock = true;
//			GlockBullet = 80;
//		}
//		counter++;
//	}
//
//	counter = 0;
//	for (iterSMG = SMGArray.begin(); iterSMG != SMGArray.end(); iterSMG++)
//	{
//		if (player->hitboxPlayer->hitbox.getGlobalBounds().intersects(SMGArray[counter].item.getGlobalBounds()))
//		{
//			SMGArray[counter].destroy = true;
//			soundHeal.play();
//			player->isSMG = true;
//			SMGBullet = 100;
//		}
//
//		counter++;
//	}
//
//	counter = 0;
//	for (iterShotgun = ShotgunArray.begin(); iterShotgun != ShotgunArray.end(); iterShotgun++)
//	{
//		if (player->hitboxPlayer->hitbox.getGlobalBounds().intersects(ShotgunArray[counter].item.getGlobalBounds()))
//		{
//			ShotgunArray[counter].destroy = true;
//			soundHeal.play();
//			player->isShotgun = true;
//			ShotgunBullet = 50;
//		}
//
//		counter++;
//	}
//
//	counter = 0;
//	for (iterPoHeal = PotionHealArray.begin(); iterPoHeal != PotionHealArray.end(); iterPoHeal++)
//	{
//		if (player->hitboxPlayer->hitbox.getGlobalBounds().intersects(PotionHealArray[counter].item.getGlobalBounds()))
//		{
//			if (player->hp > 0) {
//				PotionHealArray[counter].destroy = true;
//				soundHeal.play();
//				if (player->hp >= 80) {
//					player->hp = 100;
//					view->boxX = 150;
//				}
//				else {
//					player->hp += 20;
//					view->boxX += 30;
//				}
//			}
//		}
//
//		counter++;
//	}
//
//	//player collide crowbar
//	counter = 0;
//	for (iterCrow = CrowbarArray.begin(); iterCrow != CrowbarArray.end(); iterCrow++)
//	{
//		if (player->hitboxPlayer->hitbox.getGlobalBounds().intersects(CrowbarArray[counter].item.getGlobalBounds()))
//		{
//			CrowbarArray[counter].destroy = true;
//			soundHeal.play();
//		}
//
//		counter++;
//	}
//	
//	//Enemy collide player
//	if (elapsed2.asSeconds() >= 0.5)
//	{
//		clock2.restart();
//		counter = 0;
//		for (iterEnemy = enemyArray.begin(); iterEnemy != enemyArray.end(); iterEnemy++)
//		{
//			if (player->hitboxPlayer->hitbox.getGlobalBounds().intersects(enemyArray[counter].enemy.getGlobalBounds()))
//			{
//				if (player->hp > 0) {
//					textDisplay1->text.setString("2");
//					textDisplay1->text.setPosition(player->body.getPosition().x - 10, player->body.getPosition().y - 45);
//					textDisplayArray.push_back(*textDisplay1);
//					player->hp -= enemyArray[counter].attackDamage;
//					view->boxX -= 3;
//					if (player->face == 0) {
//						player->body.move(2, 0);
//					}
//					else if (player->face == 1) {
//						player->body.move(-2, 0);
//					}
//					else if (player->face == 2) {
//						player->body.move(0, 2);
//					}
//					else if (player->face == 3) {
//						player->body.move(0, -2);
//					}
//					soundPlayer.play();
//				}
//			}
//			counter++;
//		}
//	}
//
//}
//
//void FirstLevel::attackBox()
//{
//	if (elapsed3.asSeconds() >= 0.3)
//	{
//		clock3.restart();
//		counter = 0;
//		for (iterBoxG = BoxGArray.begin(); iterBoxG != BoxGArray.end(); iterBoxG++)
//		{
//			if (Keyboard::isKeyPressed(Keyboard::Space)) {
//				if (player->getWeapon() == 1 && (player->hitboxPlayerSwordleft->hitbox.getGlobalBounds().intersects(BoxGArray[counter].item.getGlobalBounds()) && player->getFace() == 0
//					|| player->hitboxPlayerSwordRight->hitbox.getGlobalBounds().intersects(BoxGArray[counter].item.getGlobalBounds()) && player->getFace() == 1
//					|| player->hitboxPlayerSwordUp->hitbox.getGlobalBounds().intersects(BoxGArray[counter].item.getGlobalBounds()) && player->getFace() == 2
//					|| player->hitboxPlayerSwordDown->hitbox.getGlobalBounds().intersects(BoxGArray[counter].item.getGlobalBounds()) && player->getFace() == 3))
//				{
//					textDisplay1->text.setString("1");
//					textDisplay1->text.setPosition(BoxGArray[counter].item.getPosition().x + 50, BoxGArray[counter].item.getPosition().y - 50);
//					textDisplayArray.push_back(*textDisplay1);
//
//					BoxGArray[counter].hpBox -= player->attackSword;
//					soundBox.play();
//				}
//			}
//			if (BoxGArray[counter].hpBox <= 0)
//			{
//				BoxGArray[counter].destroy = true;
//			}
//			counter++;
//		}
//	}
//	if (elapsed3.asSeconds() >= 0.3)
//	{
//		clock3.restart();
//		counter = 0;
//		for (iterBoxSM = BoxSMArray.begin(); iterBoxSM != BoxSMArray.end(); iterBoxSM++)
//		{
//			if (Keyboard::isKeyPressed(Keyboard::Space)) {
//				if (player->getWeapon() == 1 && (player->hitboxPlayerSwordleft->hitbox.getGlobalBounds().intersects(BoxSMArray[counter].item.getGlobalBounds()) && player->getFace() == 0
//					|| player->hitboxPlayerSwordRight->hitbox.getGlobalBounds().intersects(BoxSMArray[counter].item.getGlobalBounds()) && player->getFace() == 1
//					|| player->hitboxPlayerSwordUp->hitbox.getGlobalBounds().intersects(BoxSMArray[counter].item.getGlobalBounds()) && player->getFace() == 2
//					|| player->hitboxPlayerSwordDown->hitbox.getGlobalBounds().intersects(BoxSMArray[counter].item.getGlobalBounds()) && player->getFace() == 3))
//				{
//					textDisplay1->text.setString("1");
//					textDisplay1->text.setPosition(BoxSMArray[counter].item.getPosition().x - 10, BoxSMArray[counter].item.getPosition().y - 45);
//					textDisplayArray.push_back(*textDisplay1);
//
//					BoxSMArray[counter].hpBox -= player->attackSword;
//					soundBox.play();
//				}
//			}
//			if (BoxSMArray[counter].hpBox <= 0)
//			{
//				BoxSMArray[counter].destroy = true;
//			}
//			counter++;
//		}
//	}
//	if (elapsed3.asSeconds() >= 0.3)
//	{
//		clock3.restart();
//		counter = 0;
//		for (iterBoxSh = BoxShArray.begin(); iterBoxSh != BoxShArray.end(); iterBoxSh++)
//		{
//			if (Keyboard::isKeyPressed(Keyboard::Space)) {
//				if (player->getWeapon() == 1 && (player->hitboxPlayerSwordleft->hitbox.getGlobalBounds().intersects(BoxShArray[counter].item.getGlobalBounds()) && player->getFace() == 0
//					|| player->hitboxPlayerSwordRight->hitbox.getGlobalBounds().intersects(BoxShArray[counter].item.getGlobalBounds()) && player->getFace() == 1
//					|| player->hitboxPlayerSwordUp->hitbox.getGlobalBounds().intersects(BoxShArray[counter].item.getGlobalBounds()) && player->getFace() == 2
//					|| player->hitboxPlayerSwordDown->hitbox.getGlobalBounds().intersects(BoxShArray[counter].item.getGlobalBounds()) && player->getFace() == 3))
//				{
//					textDisplay1->text.setString("1");
//					textDisplay1->text.setPosition(BoxShArray[counter].item.getPosition().x - 10, BoxShArray[counter].item.getPosition().y - 45);
//					textDisplayArray.push_back(*textDisplay1);
//
//					BoxShArray[counter].hpBox -= player->attackSword;
//					soundBox.play();
//				}
//			}
//			if (BoxShArray[counter].hpBox <= 0)
//			{
//				BoxShArray[counter].destroy = true;
//			}
//			counter++;
//		}
//	}
//}
//
//void FirstLevel::shootBox()
//{
//	counter = 0;
//	for (iterBullet = projectileArray.begin(); iterBullet != projectileArray.end(); iterBullet++)
//	{
//		counter2 = 0;
//		for (iterBoxG = BoxGArray.begin(); iterBoxG != BoxGArray.end(); iterBoxG++)
//		{
//			if (projectileArray[counter].bullet.getGlobalBounds().intersects(BoxGArray[counter2].item.getGlobalBounds()))
//			{
//				projectileArray[counter].destroy = true;
//
//				textDisplay1->text.setString(to_string(projectileArray[counter].gunAttackDamage));
//				textDisplay1->text.setPosition(BoxGArray[counter2].item.getPosition().x - 10, BoxGArray[counter2].item.getPosition().y - 45);
//				textDisplayArray.push_back(*textDisplay1);
//
//				BoxGArray[counter2].hpBox--;
//				soundBox.play();
//
//				if (BoxGArray[counter2].hpBox <= 0)
//				{
//					BoxGArray[counter2].destroy = true;
//				}
//			}
//			counter2++;
//		}
//		counter++;
//	}
//	counter = 0;
//	for (iterBullet = projectileArray.begin(); iterBullet != projectileArray.end(); iterBullet++)
//	{
//		counter2 = 0;
//		for (iterBoxSM = BoxSMArray.begin(); iterBoxSM != BoxSMArray.end(); iterBoxSM++)
//		{
//			if (projectileArray[counter].bullet.getGlobalBounds().intersects(BoxSMArray[counter2].item.getGlobalBounds()))
//			{
//				projectileArray[counter].destroy = true;
//
//				textDisplay1->text.setString(to_string(projectileArray[counter].gunAttackDamage));
//				textDisplay1->text.setPosition(BoxSMArray[counter2].item.getPosition().x - 10, BoxSMArray[counter2].item.getPosition().y - 45);
//				textDisplayArray.push_back(*textDisplay1);
//
//				BoxSMArray[counter2].hpBox--;
//				soundBox.play();
//
//				if (BoxSMArray[counter2].hpBox <= 0)
//				{
//					BoxSMArray[counter2].destroy = true;
//				}
//			}
//			counter2++;
//		}
//		counter++;
//	}
//	counter = 0;
//	for (iterBullet = projectileArray.begin(); iterBullet != projectileArray.end(); iterBullet++)
//	{
//		counter2 = 0;
//		for (iterBoxSh = BoxShArray.begin(); iterBoxSh != BoxShArray.end(); iterBoxSh++)
//		{
//			if (projectileArray[counter].bullet.getGlobalBounds().intersects(BoxShArray[counter2].item.getGlobalBounds()))
//			{
//				projectileArray[counter].destroy = true;
//
//				textDisplay1->text.setString(to_string(projectileArray[counter].gunAttackDamage));
//				textDisplay1->text.setPosition(BoxShArray[counter2].item.getPosition().x - 10, BoxShArray[counter2].item.getPosition().y - 45);
//				textDisplayArray.push_back(*textDisplay1);
//
//				BoxShArray[counter2].hpBox--;
//				soundBox.play();
//
//				if (BoxShArray[counter2].hpBox <= 0)
//				{
//					BoxShArray[counter2].destroy = true;
//				}
//			}
//			counter2++;
//		}
//		counter++;
//	}
//}
//
//void FirstLevel::deleteAll()
//{
//	//delete crowbar
//	counter = 0;
//	for (iterCrow = CrowbarArray.begin(); iterCrow != CrowbarArray.end(); iterCrow++)
//	{
//		if (CrowbarArray[counter].destroy == true)
//		{
//			CrowbarArray.erase(iterCrow);
//			pickupCrowbar = true;
//			break;
//		}
//		counter++;
//	}
//
//	// Delete dead enemy
//	counter = 0;
//	for (iterEnemy = enemyArray.begin(); iterEnemy != enemyArray.end(); iterEnemy++)
//	{
//		if (enemyArray[counter].alive == false)
//		{
//			if (random->generateRandom(1, 5) == 1) {
//				PotionHeal->item.setPosition(enemyArray[counter].enemy.getPosition());
//				PotionHealArray.push_back(*PotionHeal);
//			}
//			enemyArray.erase(iterEnemy);
//			zombieKill++;
//			printf("%d", zombieKill);
//			break;
//		}
//		counter++;
//	}
//	if (zombieKill >= 15)
//	{
//		//spawn crowber
//		if (crowb == true) {
//			printf("pp");
//			int CrowX, CrowY, cro = 0;
//			CrowX = random->generateRandom(0, 1414);
//			CrowY = random->generateRandom(950, 1950);
//			if (CrowX > 100 && CrowX < 1283 && CrowY > 1089 && CrowY < 1750)
//			{
//				cro = 1;
//			}
//			if (cro == 0) {
//				Crowbar->setPosition(Vector2f(CrowX, CrowY));
//				CrowbarArray.push_back(*Crowbar);
//				crowb = false;
//			}
//		}
//		zombie1.setLoop(false);
//		zombie1.stop();
//	}
//	//delete item
//	counter = 0;
//	for (iterGlock = GlockArray.begin(); iterGlock != GlockArray.end(); iterGlock++)
//	{
//		if (GlockArray[counter].destroy == true)
//		{
//			GlockArray.erase(iterGlock);
//			break;
//		}
//
//		counter++;
//	}
//	counter = 0;
//	for (iterSMG = SMGArray.begin(); iterSMG != SMGArray.end(); iterSMG++)
//	{
//		if (SMGArray[counter].destroy == true)
//		{
//			SMGArray.erase(iterSMG);
//			break;
//		}
//
//		counter++;
//	}
//	counter = 0;
//	for (iterShotgun = ShotgunArray.begin(); iterShotgun != ShotgunArray.end(); iterShotgun++)
//	{
//		if (ShotgunArray[counter].destroy == true)
//		{
//			ShotgunArray.erase(iterShotgun);
//			break;
//		}
//
//		counter++;
//	}
//	counter = 0;
//	for (iterPoHeal = PotionHealArray.begin(); iterPoHeal != PotionHealArray.end(); iterPoHeal++)
//	{
//		if (PotionHealArray[counter].destroy == true)
//		{
//			PotionHealArray.erase(iterPoHeal);
//			break;
//		}
//
//		counter++;
//	}
//
//	//delete box
//	counter = 0;
//	for (iterBoxG = BoxGArray.begin(); iterBoxG != BoxGArray.end(); iterBoxG++)
//	{
//		if (BoxGArray[counter].destroy == true)
//		{
//			BoxGArray.erase(iterBoxG);
//			if (player->getFace() == 0)
//			{
//				player->canMoveL = true;
//				player->body.move(1, 0);
//			}
//			if (player->getFace() == 1)
//			{
//				player->canMoveR = true;
//				player->body.move(-1, 0);
//			}
//			if (player->getFace() == 2)
//			{
//				player->canMoveUp = true;
//				player->body.move(0, 1);
//			}
//			if (player->getFace() == 3)
//			{
//				player->canMoveDown = true;
//				player->body.move(0, -1);
//			}
//			break;
//		}
//		counter++;
//	}
//	counter = 0;
//	for (iterBoxSM = BoxSMArray.begin(); iterBoxSM != BoxSMArray.end(); iterBoxSM++)
//	{
//		if (BoxSMArray[counter].destroy == true)
//		{
//			BoxSMArray.erase(iterBoxSM);
//			if (player->getFace() == 0)
//			{
//				player->canMoveL = true;
//				player->body.move(1, 0);
//			}
//			if (player->getFace() == 1)
//			{
//				player->canMoveR = true;
//				player->body.move(-1, 0);
//			}
//			if (player->getFace() == 2)
//			{
//				player->canMoveUp = true;
//				player->body.move(0, 1);
//			}
//			if (player->getFace() == 3)
//			{
//				player->canMoveDown = true;
//				player->body.move(0, -1);
//			}
//			break;
//		}
//		counter++;
//	}
//	counter = 0;
//	for (iterBoxSh = BoxShArray.begin(); iterBoxSh != BoxShArray.end(); iterBoxSh++)
//	{
//		if (BoxShArray[counter].destroy == true)
//		{
//			BoxShArray.erase(iterBoxSh);
//			if (player->getFace() == 0)
//			{
//				player->canMoveL = true;
//				player->body.move(1, 0);
//			}
//			if (player->getFace() == 1)
//			{
//				player->canMoveR = true;
//				player->body.move(-1, 0);
//			}
//			if (player->getFace() == 2)
//			{
//				player->canMoveUp = true;
//				player->body.move(0, 1);
//			}
//			if (player->getFace() == 3)
//			{
//				player->canMoveDown = true;
//				player->body.move(0, -1);
//			}
//			break;
//		}
//		counter++;
//	}
//
//}
//
//void FirstLevel::Draw(RenderWindow& window)
//{
//	//draw map
//	window.draw(map);
//
//	//draw sewer
//	window.draw(Sewer->item);
//	if (pickupCrowbar == true && player->hitboxPlayer->hitbox.getGlobalBounds().intersects(Sewer->item.getGlobalBounds()))
//	{
//		player->body.setPosition(150, 300);
//	}
//
//	//draw item
//	counter = 0;
//	for (iterGlock = GlockArray.begin(); iterGlock != GlockArray.end(); iterGlock++)
//	{
//		GlockArray[counter].Update();
//		window.draw(GlockArray[counter].item);
//
//		counter++;
//	}
//	counter = 0;
//	for (iterSMG = SMGArray.begin(); iterSMG != SMGArray.end(); iterSMG++)
//	{
//		SMGArray[counter].Update();
//		window.draw(SMGArray[counter].item);
//
//		counter++;
//	}
//	counter = 0;
//	for (iterShotgun = ShotgunArray.begin(); iterShotgun != ShotgunArray.end(); iterShotgun++)
//	{
//		ShotgunArray[counter].Update();
//		window.draw(ShotgunArray[counter].item);
//
//		counter++;
//	}
//	counter = 0;
//	for (iterPoHeal = PotionHealArray.begin(); iterPoHeal != PotionHealArray.end(); iterPoHeal++)
//	{
//		PotionHealArray[counter].Update();
//		window.draw(PotionHealArray[counter].item);
//
//		counter++;
//	}
//	counter = 0;
//	for (iterCrow = CrowbarArray.begin(); iterCrow != CrowbarArray.end(); iterCrow++)
//	{
//		window.draw(CrowbarArray[counter].item);
//
//		counter++;
//	}
//}
//
//void FirstLevel::Drawbox(RenderWindow& window)
//{
//	//draw box
//	counter = 0;
//	for (iterBoxG = BoxGArray.begin(); iterBoxG != BoxGArray.end(); iterBoxG++)
//	{
//		if (player->GetPosition().y > BoxGArray[counter].GetPosition().y)
//		{
//			BoxGArray[counter].Draw(window);
//		}
//		counter++;
//	}
//
//	counter = 0;
//	for (iterBoxSM = BoxSMArray.begin(); iterBoxSM != BoxSMArray.end(); iterBoxSM++)
//	{
//		if (player->GetPosition().y > BoxSMArray[counter].GetPosition().y)
//		{
//			BoxSMArray[counter].Draw(window);
//		}
//		counter++;
//	}
//
//	counter = 0;
//	for (iterBoxSh = BoxShArray.begin(); iterBoxSh != BoxShArray.end(); iterBoxSh++)
//	{
//		if (player->GetPosition().y > BoxShArray[counter].GetPosition().y)
//		{
//			BoxShArray[counter].Draw(window);
//		}
//		counter++;
//	}
//}
