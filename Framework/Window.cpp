#include "StdAfx.h"
#include "Level.h"

#include "DebugRenderer.h"

#include "ClientEngine.h"
#include "EventManager.h"
#include "TaskManager.h"

using namespace std;

Test::Test()
{
	pause = false;
	lost = false;

	ClientEngine *pCE = globals::pE;

	sf::Vector2u wS = pCE->pW->getSize();
	sf::Vector2i winSize(wS.x, wS.y);
	backgroundTexture.loadFromFile("data\\background.png");
	backgroundTexture.setRepeated(true);
	background.setTexture(&backgroundTexture);
	background.setOrigin((float)backgroundTexture.getSize().x / 2.f, (float)backgroundTexture.getSize().y / 2.f);
	//if(background.getSize().x < winSize.x)
	background.setSize(sf::Vector2f((float)backgroundTexture.getSize().x, (float)backgroundTexture.getSize().y));

	background.setScale(0.1f, 0.1f);
	//background.setPosition(0.f, 0.f);

	sf::View view = pCE->pW->getView();
	view.setCenter(0.f, 0.f);
	pCE->pW->setView(view);

	b2Vec2 gravity;
	gravity.Set(0.0f, -20.f);
	m_world = new b2World(gravity);

	DD = new DebugDraw(*pCE->pW);
	m_world->SetDebugDraw(DD);
	DD->SetFlags(b2Draw::e_shapeBit);//b2DebugDraw::e_shapeBit);
}

Test::~Test()
{
	// Cleaning everything...
	for(auto ed : events)	globals::pEM->removeEvent(ed);
	for(auto td : tasks)	globals::pTM->removeTask(td);
	for(auto p : players)	delete p;
	for(auto t : terrain)	delete t;
	for(auto p : particles)	delete p;
	for(auto b : bodies)	delete b;

	delete DD;

	delete m_world;
	m_world = NULL;
}

class QueryCallback : public b2QueryCallback
{
public:
	QueryCallback(const b2Vec2& point)
	{
		m_point = point;
		m_fixture = NULL;
	}

	bool ReportFixture(b2Fixture* fixture)
	{
		b2Body* body = fixture->GetBody();
		if (body->GetType() == b2_dynamicBody)
		{
			bool inside = fixture->TestPoint(m_point);
			if (inside)
			{
				m_fixture = fixture;

				// We are done, terminate the query.
				return false;
			}
		}

		// Continue the query.
		return true;
	}

	b2Vec2 m_point;
	b2Fixture* m_fixture;
};

void Test::Step(float32 frameTime)
{
	//int velocityIterations = 8, positionIterations = 3;
	int velocityIterations = 5, positionIterations = 2;
	m_world->Step(frameTime, velocityIterations, positionIterations);

	/*
	for(auto terr : terrain)
		terr->updateDrawable();
	*/
	for(auto body : bodies)
		body->updateDrawable();
	for(Character *character : players)
		character->tick();
}

sf::Vector2f Test::GetMousePos(const sf::RenderWindow& App) const
{
	// get the local mouse position (relatively to a window)
	sf::Vector2i mousePos(sf::Mouse::getPosition(App));
	return App.mapPixelToCoords(mousePos);
}

void Test::Render(sf::RenderWindow *pRW)
{
	pRW->draw(background);

	sf::Transform transform;
	// Temporary commented -1.f for scale because of using box2d debugdraw
	transform.scale(1.f, /**/-/**/1.f); // Box2d runs in cartesian coordinate system (so we have to flip y-axis)
	if(!sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		for(auto it : terrain)
			it->draw(pRW, transform);
		for(auto it : bodies)
			it->draw(pRW, transform);
		for(auto it : particles)
			it->draw(pRW, transform);
		for(Character *c : players)
			c->draw(pRW, transform);
	}
	m_world->DrawDebugData();

	/**/
	;;;;;;;
	/*/
	;;;;;;;
	/**/
}