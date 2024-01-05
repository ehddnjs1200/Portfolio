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

	if (card->GetType() == Card::Type::Attack)
	{
		switch (stoi(temp))
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		case 13:
			break;
		case 14:
			break;
		case 15:
			break;
		case 16:
			break;
		case 17:
			break;
		case 18:
			break;
		case 19:
			break;
		case 20:
			break;
		case 21:
			break;
		case 22:
			break;
		case 23:
			break;
		case 24:
			break;
		case 25:
			break;
		case 26:
			break;
		case 27:
			break;
		case 28:
			break;
		case 29:
			break;
		case 30:
			break;
		case 31:
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
