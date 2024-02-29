#include "framework.h"
#include "Character.h"

void Character::SetPos(Vector2 pos, float scale)
{
	_character->GetTransForm()->GetPos() = pos;
	_character->GetTransForm()->GetScale() *= scale;
}

void Character::GetDemage(int demage)
{
	_hp -= demage;
	_hpBar->DecreaseHp(demage);
}

void Character::Heling(int value)
{
	_hp += value;
	_hpBar->IncreaseHp(value);
}
