#include "framework.h"
#include "Character.h"

void Character::SetPos(Vector2 pos, float scale)
{
	_character->GetTransForm()->GetPos() = pos;
	_character->GetTransForm()->GetScale() *= scale;
}
