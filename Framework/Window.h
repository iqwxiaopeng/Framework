#pragma once

#include <vector>

class EventData;
class TaskData;

class Window
{
public:
	Window();
	virtual ~Window();

	std::vector<EventData*> events;
	std::vector<TaskData*> tasks;

	virtual void Step(float32 frameTime);
	virtual void Render(sf::RenderWindow *pRW);

	// Let derived tests know that a joint was destroyed.
	virtual void JointDestroyed(b2Joint* joint) { B2_NOT_USED(joint); }
	// Callbacks for derived classes.
	virtual void BeginContact(b2Contact* contact) { B2_NOT_USED(contact); }
	virtual void EndContact(b2Contact* contact) { B2_NOT_USED(contact); }
	virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold) { B2_NOT_USED(contact); B2_NOT_USED(oldManifold); }
	virtual void PostSolve(const b2Contact* contact, const b2ContactImpulse* impulse) { B2_NOT_USED(contact); B2_NOT_USED(impulse); }
	virtual bool ReportFixture(b2Fixture* fixture) {B2_NOT_USED(fixture); return false;}

	sf::Vector2f GetMousePos(const sf::RenderWindow& App) const;


protected:
	friend class DestructionListener;
	friend class BoundaryListener;
	friend class ContactListener;

	b2Body* m_groundBody;
	b2AABB m_worldAABB;
	b2World* m_world;

	std::vector<Drawable<sf::ConvexShape>*> terrain; // In terrain bodies are sf::ConvexShape for triangles
	std::vector<Body*> bodies;  // Here they are sf::RectangleShape
	std::vector<Body*> particles; // Hm, no idea what type to put in yet
	std::vector<Character*> players;
};