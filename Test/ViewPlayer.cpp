#include "ViewPlayer.h"

ViewPlayer::ViewPlayer(Vector2f position, Vector2f size)
{
	font.loadFromFile("Font/ArcadeClassic.ttf");
	fonthpzombie.loadFromFile("Font/DisposableDroidBB.ttf");
	fontMenu.loadFromFile("Font/menufont.ttf");

	view = new View(position, size);
	playerhp.setSize(Vector2f(700, 393));
	playerhp.setOrigin(playerhp.getSize() / 2.f);
	playerhp.setFillColor(Color::Transparent);

	playerpicTexture.loadFromFile("Character/playerhp.png");
	Sword.loadFromFile("Item/sword.png");
	Glock.loadFromFile("Item/glock2.png");
	SMG.loadFromFile("Item/smg2.png");
	Shotgun.loadFromFile("Item/shotgun2.png");

	glockBullet.setFont(fonthpzombie);
	smgBullet.setFont(fonthpzombie);
	shotgunBullet.setFont(fonthpzombie);
	name.setFont(fonthpzombie);
	name.setCharacterSize(17);
	name.setFillColor(Color::White);
	name.setOutlineThickness(1.f);
	name.setOutlineColor(Color::Black);

	//task
	task.setFont(fonthpzombie);
	task.setCharacterSize(27);
	task.setFillColor(Color::White);
	task.setOutlineThickness(1.5f);
	task.setOutlineColor(Color::Black);

	task1.setFont(fonthpzombie);
	task1.setCharacterSize(23);
	task1.setFillColor(Color::White);
	task1.setOutlineThickness(1.5f);
	task1.setOutlineColor(Color::Black);

	task2.setFont(fonthpzombie);
	task2.setCharacterSize(23);
	task2.setFillColor(Color::White);
	task2.setOutlineThickness(1.5f);
	task2.setOutlineColor(Color::Black);

	task3.setFont(fonthpzombie);
	task3.setCharacterSize(23);
	task3.setFillColor(Color::White);
	task3.setOutlineThickness(1.5f);
	task3.setOutlineColor(Color::Black);

	task4.setFont(fonthpzombie);
	task4.setCharacterSize(23);
	task4.setFillColor(Color::White);
	task4.setOutlineThickness(1.5f);
	task4.setOutlineColor(Color::Black);

	task5.setFont(fonthpzombie);
	task5.setCharacterSize(23);
	task5.setFillColor(Color::White);
	task5.setOutlineThickness(1.5f);
	task5.setOutlineColor(Color::Black);

	HP.setFont(fonthpzombie);
	HP.setCharacterSize(17);
	HP.setFillColor(Color::Black);

	one.setFont(fonthpzombie);
	one.setCharacterSize(10);
	one.setFillColor(Color::White);

	two.setFont(fonthpzombie);
	two.setCharacterSize(10);
	two.setFillColor(Color::White);

	three.setFont(fonthpzombie);
	three.setCharacterSize(10);
	three.setFillColor(Color::White);

	four.setFont(fonthpzombie);
	four.setCharacterSize(10);
	four.setFillColor(Color::White);

	glockBullet.setCharacterSize(10);
	glockBullet.setFillColor(Color::Black);

	smgBullet.setCharacterSize(10);
	smgBullet.setFillColor(Color::Black);

	shotgunBullet.setCharacterSize(10);
	shotgunBullet.setFillColor(Color::Black);

	boxSword.setTexture(&Sword);
	boxSword.setOrigin(boxSword.getSize() / 2.f);
	boxSword.setSize(Vector2f(40, 40));
	boxSword.setOutlineThickness(1.5f);
	boxSword.setOutlineColor(Color::Black);

	boxGlock.setTexture(&Glock);
	boxGlock.setOrigin(boxGlock.getSize() / 2.f);
	boxGlock.setSize(Vector2f(40, 40));
	boxGlock.setOutlineThickness(1.5f);
	boxGlock.setOutlineColor(Color::Black);

	boxSMG.setTexture(&SMG);
	boxSMG.setOrigin(boxSMG.getSize() / 2.f);
	boxSMG.setSize(Vector2f(40, 40));
	boxSMG.setOutlineThickness(1.5f);
	boxSMG.setOutlineColor(Color::Black);

	boxShotgun.setTexture(&Shotgun);
	boxShotgun.setOrigin(boxShotgun.getSize() / 2.f);
	boxShotgun.setSize(Vector2f(40, 40));
	boxShotgun.setOutlineThickness(1.5f);
	boxShotgun.setOutlineColor(Color::Black);

	playerpic.setTexture(&playerpicTexture);
	playerpic.setRadius(30.f);
	playerpic.setOutlineThickness(2.f);
	playerpic.setOutlineColor(Color::Black);

	hpboxframe.setSize(Vector2f(150, 15));
	hpboxframe.setFillColor(Color::Transparent);
	hpboxframe.setOutlineThickness(2.5f);
	hpboxframe.setOutlineColor(Color::Black);

	hpbox.setFillColor(Color::Red);
}

void ViewPlayer::viewUpdate(Player player, RectangleShape map)
{
	Vector2f viewSize = view->getSize();
	if (player.GetPosition().x <= viewSize.x / 2 && player.GetPosition().y <= viewSize.y / 2) {
		view->setCenter(viewSize.x / 2, viewSize.y / 2);
		playerhp.setPosition(viewSize.x / 2, viewSize.y / 2);
	}
	else if (player.GetPosition().x <= viewSize.x / 2 && player.GetPosition().y > viewSize.y / 2 && player.GetPosition().y <= map.getSize().y - viewSize.y / 2) {
		view->setCenter(viewSize.x / 2, player.GetPosition().y);
		playerhp.setPosition(viewSize.x / 2, player.GetPosition().y);
	}
	else if (player.GetPosition().x <= viewSize.x / 2 && player.GetPosition().y > map.getSize().y - viewSize.y / 2) {
		view->setCenter(viewSize.x / 2, map.getSize().y - viewSize.y / 2);
		playerhp.setPosition(viewSize.x / 2, map.getSize().y - viewSize.y / 2);
	}
	else if (player.GetPosition().x > viewSize.x / 2 && player.GetPosition().x <= map.getSize().x - viewSize.x / 2 && player.GetPosition().y <= viewSize.y / 2) {
		view->setCenter(player.GetPosition().x, viewSize.y / 2);
		playerhp.setPosition(player.GetPosition().x, viewSize.y / 2);
	}
	else if (player.GetPosition().x > viewSize.x / 2 && player.GetPosition().x <= map.getSize().x - viewSize.x / 2 && player.GetPosition().y > viewSize.y / 2 && player.GetPosition().y <= map.getSize().y - viewSize.y / 2) {
		view->setCenter(player.GetPosition().x, player.GetPosition().y);
		playerhp.setPosition(player.GetPosition().x, player.GetPosition().y);
	}
	else if (player.GetPosition().x > viewSize.x / 2 && player.GetPosition().x <= map.getSize().x - viewSize.x / 2 && player.GetPosition().y > map.getSize().y - viewSize.y / 2) {
		view->setCenter(player.GetPosition().x, map.getSize().y - viewSize.y / 2);
		playerhp.setPosition(player.GetPosition().x, map.getSize().y - viewSize.y / 2);
	}
	else if (player.GetPosition().x > map.getSize().x - viewSize.x / 2 && player.GetPosition().y <= viewSize.y / 2) {
		view->setCenter(map.getSize().x - viewSize.x / 2, viewSize.y / 2);
		playerhp.setPosition(map.getSize().x - viewSize.x / 2, viewSize.y / 2);
	}
	else if (player.GetPosition().x > map.getSize().x - viewSize.x / 2 && player.GetPosition().y > viewSize.y / 2 && player.GetPosition().y <= map.getSize().y - viewSize.y / 2) {
		view->setCenter(map.getSize().x - viewSize.x / 2, player.GetPosition().y);
		playerhp.setPosition(map.getSize().x - viewSize.x / 2, player.GetPosition().y);
	}
	else if (player.GetPosition().x > map.getSize().x - viewSize.x / 2 && player.GetPosition().y > map.getSize().y - viewSize.y / 2) {
		view->setCenter(map.getSize().x - viewSize.x / 2, map.getSize().y - viewSize.y / 2);
		playerhp.setPosition(map.getSize().x - viewSize.x / 2, map.getSize().y - viewSize.y / 2);
	}

}

void ViewPlayer::setView(RenderWindow& window)
{
	window.setView(*view);
}

void ViewPlayer::Draw(RenderWindow& window)
{
	window.draw(playerhp);
	hpbox.setSize(Vector2f(boxX, boxY));
	hpbox.setPosition(playerhp.getPosition().x - view->getSize().x / 2 + 75 , playerhp.getPosition().y - view->getSize().y / 2 + 40);
	hpboxframe.setPosition(playerhp.getPosition().x - view->getSize().x / 2 + 75, playerhp.getPosition().y - view->getSize().y /2 + 40);
	name.setPosition(playerhp.getPosition().x - view->getSize().x / 2 + 75, playerhp.getPosition().y - view->getSize().y / 2 + 15);
	playerpic.setPosition(playerhp.getPosition().x - view->getSize().x / 2 + 10, playerhp.getPosition().y - view->getSize().y / 2 + 10);
	boxSword.setPosition(playerhp.getPosition().x - 82, playerhp.getPosition().y + view->getSize().y / 3 + 20);
	boxGlock.setPosition(playerhp.getPosition().x - 42, playerhp.getPosition().y + view->getSize().y / 3 + 20);
	boxSMG.setPosition(playerhp.getPosition().x, playerhp.getPosition().y + view->getSize().y / 3 + 20);
	boxShotgun.setPosition(playerhp.getPosition().x + 42 , playerhp.getPosition().y + view->getSize().y / 3 + 20);
	glockBullet.setPosition(boxGlock.getPosition().x + 7, boxGlock.getPosition().y + boxGlock.getSize().y / 2 + 8);
	smgBullet.setPosition(boxSMG.getPosition().x + 4, boxSMG.getPosition().y + boxSMG.getSize().y / 2 + 8);
	shotgunBullet.setPosition(boxShotgun.getPosition().x + 7, boxShotgun.getPosition().y + boxShotgun.getSize().y / 2 + 8);
	HP.setPosition(hpboxframe.getPosition().x + 32, hpboxframe.getPosition().y - 5);
	one.setPosition(boxSword.getPosition().x + 3, boxSword.getPosition().y - 3);
	two.setPosition(boxGlock.getPosition().x + 3, boxGlock.getPosition().y - 3);
	three.setPosition(boxSMG.getPosition().x + 3, boxSMG.getPosition().y - 3);
	four.setPosition(boxShotgun.getPosition().x + 3, boxShotgun.getPosition().y - 3);
	window.draw(name);
	window.draw(hpbox);
	window.draw(hpboxframe);
	window.draw(playerpic);
	window.draw(boxSword);
	window.draw(boxGlock);
	window.draw(boxSMG);
	window.draw(boxShotgun);
	window.draw(one);
	window.draw(two);
	window.draw(three);
	window.draw(four);
	window.draw(glockBullet);
	window.draw(smgBullet);
	window.draw(shotgunBullet);
	window.draw(HP);
}

void ViewPlayer::DrawTask(RenderWindow& window)
{
	task.setPosition(playerhp.getPosition().x + view->getSize().x / 2 - 60, playerhp.getPosition().y - view->getSize().y / 2 );
	window.draw(task);
}

void ViewPlayer::DrawTask1(RenderWindow& window)
{
	task1.setPosition(playerhp.getPosition().x + view->getSize().x / 2 - 180, playerhp.getPosition().y - view->getSize().y / 2 + 30);
	task2.setPosition(playerhp.getPosition().x + view->getSize().x / 2 - 132, playerhp.getPosition().y - view->getSize().y / 2 + 55);
	task3.setPosition(playerhp.getPosition().x + view->getSize().x / 2 - 112, playerhp.getPosition().y - view->getSize().y / 2 + 80);
	task4.setPosition(playerhp.getPosition().x + view->getSize().x / 2 - 185, playerhp.getPosition().y - view->getSize().y / 2 + 30);
	task5.setPosition(playerhp.getPosition().x + view->getSize().x / 2 - 267, playerhp.getPosition().y - view->getSize().y / 2 + 30);
	window.draw(task1);
	window.draw(task2);
	window.draw(task3);
	window.draw(task4);
	window.draw(task5);
}
