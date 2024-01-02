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

	void SetIKA();

	map<string, shared_ptr<Card>> GetAllCard() { return _allCard; }


private:
	map<string, shared_ptr<Card>>_allCard;
};

