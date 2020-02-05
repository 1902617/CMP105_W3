#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	horiz = true;				// Checks what direction the ball is going on horizontal plane, true = right.
	vert = true;				// Checks what direction the ball is going in the vertical plane, true = up.
	windowSize = window->getSize();

	proCircle.setRadius(10);
	circleOrigin.x = proCircle.getRadius();
	circleOrigin.y = proCircle.getRadius();
	proCircle.setOrigin(circleOrigin);
	proCircle.setFillColor(sf::Color::Blue);
	proCircle.setOutlineThickness(1);
	proCircle.setOutlineColor(sf::Color::Red);
	proCircle.setPosition(20, 300);
	speed = 200.f;

	playCircle.setRadius(50);
	circleOrigin.x = playCircle.getRadius();
	circleOrigin.y = playCircle.getRadius();
	playCircle.setOrigin(circleOrigin);
	playCircle.setFillColor(sf::Color::Green);
	playCircle.setPosition(300, 300);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	if (proCircle.getPosition().x >= (windowSize.x - proCircle.getRadius()))
		horiz = false;
	
	if (proCircle.getPosition().x <= (0 + proCircle.getRadius()))
		horiz = true;

	if (proCircle.getPosition().y >= (windowSize.y - proCircle.getRadius()))
		vert = false;

	if (proCircle.getPosition().y <= (0 + proCircle.getRadius()))
		vert = true;


	if (horiz)
		proCircle.move(speed * dt, 0);
	else
		proCircle.move(-speed * dt, 0);

	if (vert)
		proCircle.move(0, speed * dt);
	else
		proCircle.move(0, -speed * dt);
	
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(proCircle);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}