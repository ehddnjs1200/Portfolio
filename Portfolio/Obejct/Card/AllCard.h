#pragma once
class AllCard
{
public:
	AllCard();
	~AllCard();

    struct FileInfo {
        wstring filePath;
        int fileNumber;  // 파일명에서 추출한 숫자
    };

    void ListFilesInFolder(const wstring& folderPath, vector<FileInfo>& filePaths);

	map<string, shared_ptr<Card>> SetIKA();

	map<string, shared_ptr<Card>> GetAllCard() { return _allCard; }

    shared_ptr<Card> GetCard(const string& key) {
        auto it = _allCard.find(key);
        if (it != _allCard.end()) {
            return it->second;
        }
        return nullptr;
    }

public:
	map<string, shared_ptr<Card>>_allCard;
};

