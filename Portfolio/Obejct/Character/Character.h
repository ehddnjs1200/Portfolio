#pragma once
class Character
{
public:
	Character() {}
	virtual ~Character() {}


	virtual void Update()abstract;
	virtual void Render()abstract;

	void SetPos(Vector2 pos, float scale);
	void SetHp(int value) { _hp = value; }
	void SetShield(int value) { _shield = value; }
	void SetForce(int value) { _force = value; }
	void SetAgility(int value) { _agility = value; }
	void SetWeaken(int value) { _weaken = value; }
	void SetVulnerable(int value) { _vulnerable = value; }

	int GetHp() { return _hp; }
	int GetShield() { return _shield; }
	int GetForce() { return _force; }
	int GetAgility() { return _agility; }
	int GetWeaken() { return _weaken; }
	int GetVulnerable() { return _vulnerable; }

protected:

	shared_ptr<Quad> _character;
	shared_ptr<Collider> _col;
	int _hp = 80;
	int _shield = 0;
	int _force = 0;
	int _agility = 0;
	int _weaken = 0;
	int _vulnerable = 0;
};

