#pragma once
class AllCard
{
public:
	AllCard();
	~AllCard();

    struct FileInfo {
        wstring filePath;
        int fileNumber;  // ���ϸ��� ������ ����
    };

    void ListFilesInFolder(const wstring& folderPath, vector<FileInfo>& filePaths);

	void SetIKA();

	map<string, shared_ptr<Card>> GetAllCard() { return _allCard; }


private:
	map<string, shared_ptr<Card>>_allCard;
};

