#pragma once


static void UsingCard(shared_ptr<Card> card,shared_ptr<Ironclad> player,shared_ptr<Character> monster)
{
	size_t t;
	string result;
	size_t startPos;
	size_t endPos;
	wstring temp;
	wstring file;
	if ((t = card->GetFile().find(L"Ironclad/Attack/", 0)) != wstring::npos)
	{
		file = card->GetFile();
		startPos = t + wcslen(L"Ironclad/Attack/"); // "Ironclad/Attack/" 다음 위치
		endPos = file.find(L".png", startPos); // ".png" 위치
		temp = file.substr(startPos, endPos - startPos);

		result = WstringToString(temp);
	}

	if ((t = card->GetFile().find(L"Ironclad/Skill/", 0)) != wstring::npos)
	{
		file = card->GetFile();
		startPos = t + wcslen(L"Ironclad/Skill/"); // "Ironclad/Attack/" 다음 위치
		endPos = file.find(L".png", startPos); // ".png" 위치
		temp = file.substr(startPos, endPos - startPos);

		result = WstringToString(temp);
	}

	if ((t = card->GetFile().find(L"Ironclad/Power/", 0)) != wstring::npos)
	{
		file = card->GetFile();
		startPos = t + wcslen(L"Ironclad/Power/"); // "Ironclad/Attack/" 다음 위치
		endPos = file.find(L".png", startPos); // ".png" 위치
		temp = file.substr(startPos, endPos - startPos);

		result = WstringToString(temp);
	}

	int _attack;
	int _vulnerable;
	int _weaken;
	if (card->GetType() == Card::Type::Attack)
	{
		switch (stoi(temp))
		{
		case 0: 
		{
			player->SetCost(-card->GetCost()); 
			if (card->GetUg() == 0)
				_attack = 6;
			else
				_attack = 9;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - _attack);
		}
			break;
		case 1:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
			{ 
				_attack = 8;
				_vulnerable = 2;
			}
			else
			{
				_attack = 10;
				_vulnerable = 3;
			}

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - _attack);
			
			monster->SetVulnerable(monster->GetVulnerable() + _vulnerable);

		}
			break;
		case 2:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 6;
			else
				_attack = 8;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - _attack);
		}
			break;
		case 3:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = player->GetShield();
			else
				_attack = player->GetShield();

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - _attack);
		}
			break;
		case 4:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 14;
			else
				_attack = 18;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - _attack);
		}
			break;
		case 5:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 8;
			else
				_attack = 11;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - _attack);
		}
			break;
		case 6:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
			{
				_attack = 12;
				_weaken = 2;
			}
			else
			{
				_attack = 14;
				_weaken = 3;
			}

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - _attack);

			monster->SetWeaken(monster->GetWeaken() + _weaken);
		}
			break;
		case 7:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - _attack);
		}
			break;
		case 8:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 14 + player->GetForce()*3;
			else
				_attack = 14 + player->GetForce()*5;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - (_attack * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (_attack * 0.75));
			else
				monster->SetHp(monster->GetHp() - _attack);
		}
			break;
		case 9:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 5;
			else
				_attack = 7;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - (_attack + player->GetForce()));

		}
			break;
		case 10:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - (6 + player->GetForce()));
		}
			break;
		case 11:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - (6 + player->GetForce()));
		}
			break;
		case 12:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - (6 + player->GetForce()));
		}
			break;
		case 13:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - (6 + player->GetForce()));
		}
			break;
		case 14:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - (6 + player->GetForce()));
		}
			break;
		case 15:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - (6 + player->GetForce()));
		}
			break;
		case 16:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - (6 + player->GetForce()));
		}
			break;
		case 17:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - (6 + player->GetForce()));
		}
			break;
		case 18:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - (6 + player->GetForce()));
		}
			break;
		case 19:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - (6 + player->GetForce()));
		}
			break;
		case 20:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - (6 + player->GetForce()));
		}
			break;
		case 21:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - (6 + player->GetForce()));
		}
			break;
		case 22:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - (6 + player->GetForce()));
		}
			break;
		case 23:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - (6 + player->GetForce()));
		}
			break;
		case 24:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - (6 + player->GetForce()));
		}
			break;
		case 25:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - (6 + player->GetForce()));
		}
			break;
		case 26:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - (6 + player->GetForce()));
		}
			break;
		case 27:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - (6 + player->GetForce()));
		}
			break;
		case 28:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - (6 + player->GetForce()));
		}
			break;
		case 29:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - (6 + player->GetForce()));
		}
			break;
		case 30:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - (6 + player->GetForce()));
		}
			break;
		case 31:
		{
			player->SetCost(-card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - (((_attack + player->GetForce()) * 1.5f) * 0.75));
			else if (monster->GetVulnerable() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 1.5f));
			else if (player->GetWeaken() > 0)
				monster->SetHp(monster->GetHp() - ((_attack + player->GetForce()) * 0.75));
			else
				monster->SetHp(monster->GetHp() - (6 + player->GetForce()));
		}
			break;
		default:
			break;
		}
	}
	if (card->GetType() == Card::Type::Skill)
	{

	}
	if (card->GetType() == Card::Type::Power)
	{

	}
	







}
