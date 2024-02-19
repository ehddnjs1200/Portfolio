#pragma once


static void UsingCard(shared_ptr<Card> card,shared_ptr<Ironclad> player,shared_ptr<Character> monster)
{
	size_t t;
	string result;
	size_t startPos;
	size_t endPos;
	wstring temp;
	wstring file;
	int demage = 0;
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
		startPos = t + wcslen(L"Ironclad/Skill/"); // "Ironclad/Skill/" 다음 위치
		endPos = file.find(L".png", startPos); // ".png" 위치
		temp = file.substr(startPos, endPos - startPos);

		result = WstringToString(temp);
	}

	if ((t = card->GetFile().find(L"Ironclad/Power/", 0)) != wstring::npos)
	{
		file = card->GetFile();
		startPos = t + wcslen(L"Ironclad/Power/"); // "Ironclad/Power/" 다음 위치
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
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 6;
			else
				_attack = 9;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage =((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 1:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
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
				demage =  (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage =  ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage =  ((_attack + player->GetForce()) * 0.75);
			else
				demage =  _attack;
			
			monster->SetVulnerable(monster->GetVulnerable() + _vulnerable);

		}
			break;
		case 2:
		{
			if (player->GetCost()< card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 6;
			else
				_attack = 8;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage =  (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage =  ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage =  ((_attack + player->GetForce()) * 0.75);
			else
				demage =  _attack;
		}
			break;
		case 3:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = player->GetShield();
			else
				_attack = player->GetShield();

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage =  (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage =  ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage =  ((_attack + player->GetForce()) * 0.75);
			else
				demage =  _attack;
		}
			break;
		case 4:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 14;
			else
				_attack = 18;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 5:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 8;
			else
				_attack = 11;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 6:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
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
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 7:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 8:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 14 + player->GetForce()*3;
			else
				_attack = 14 + player->GetForce()*5;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = ((_attack * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = (_attack * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = (_attack * 0.75);
			else
				demage = _attack;
		}
			break;
		case 9:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 5;
			else
				_attack = 7;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;

		}
			break;
		case 10:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 11:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 12:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 13:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 14:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 15:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 16:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 17:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 18:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 19:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 20:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 21:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 22:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 23:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 24:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 25:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 26:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 27:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 28:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 29:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 30:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
		}
			break;
		case 31:
		{
			if (player->GetCost() < card->GetCost())
			{
				card->SetChoice();
				break;
			}
			player->UsingCost(card->GetCost());
			if (card->GetUg() == 0)
				_attack = 9;
			else
				_attack = 12;

			if (monster->GetVulnerable() > 0 && player->GetWeaken() > 0)
				demage = (((_attack + player->GetForce()) * 1.5f) * 0.75);
			else if (monster->GetVulnerable() > 0)
				demage = ((_attack + player->GetForce()) * 1.5f);
			else if (player->GetWeaken() > 0)
				demage = ((_attack + player->GetForce()) * 0.75);
			else
				demage = _attack;
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
	


	monster->GetDemage(demage);
}
