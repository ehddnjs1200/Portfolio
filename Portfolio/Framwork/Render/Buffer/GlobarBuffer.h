#pragma once

class MatrixBuffer : public ConstantBuffer
{
public:
	struct Data
	{
	// 4 * 4
		XMMATRIX _matrix;
	};
private:
	Data _data;

public:
	MatrixBuffer()
		: ConstantBuffer(&_data, sizeof(Data))
	{
		_data._matrix = XMMatrixIdentity(); // ���� ��ĸ����
		// 1 0 0 0
		// 0 1 0 0
		// 0 0 1 0
		// 0 0 0 1

		// �������(�׵����), �����, ��ġ���, �����

		// vector2 ������ ��(����), ������ ����(����)
		// �຤�Ϳ� ������ ���� ����(��Į��), �����Ϳ� �຤���� ���� ����
	}
	virtual ~MatrixBuffer() {}
	
	void Set(XMMATRIX value)
	{
		_data._matrix = XMMatrixTranspose(value); // WVP �Ǵ� SRT
	}


};

class ColorBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		XMFLOAT4 color;
	};

	Data _data;

public:
	ColorBuffer()
		: ConstantBuffer(&_data, sizeof(Data))
	{
		_data.color = {1,1,1,1}; // ������
	}

	void SetColor(XMFLOAT4 color) { _data.color = color; }
};

class FrameBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		XMFLOAT2 maxFrame;
		XMFLOAT2 curFrame;
	} _data;

	FrameBuffer()
		: ConstantBuffer(&_data, sizeof(Data))
	{
		_data.maxFrame = {1.0f, 1.0f};
		_data.curFrame = {0.0f, 0.0f};
	}
};

class ActionBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		XMFLOAT2 size;
		XMFLOAT2 startPos;
		XMFLOAT2 maxSize;
		XMFLOAT2 padding; // 16����Ʈ�� ������ ��ŭ �Ѱ������
	} _data;

	ActionBuffer()
		: ConstantBuffer(&_data, sizeof(Data))
	{
		_data.size = {1.0f,1.0f};
		_data.startPos = {0.0f,0.0f};
		_data.maxSize = {1.0f,1.0f};
	};
};

class FilterBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		int LR = 0;
		int TB = 0;
		int value2 = 0;
		int value3 = 0;
	} _data;

	FilterBuffer()
		: ConstantBuffer(&_data, sizeof(_data))
	{}
};