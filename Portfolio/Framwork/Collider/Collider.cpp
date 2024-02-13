#include "framework.h"
#include "Collider.h"

Collider::Collider()
{
}

Collider::~Collider()
{
}

void Collider::Update()
{
	_transform->Update();
	_colorBuffer->Update();
}

void Collider::Render()
{
	_transform->SetWorldBuffer(0);
	_vertexBuffer->Set(0);
	_colorBuffer->SetPsBuffer(0);

	DEVICE_CONTEXT->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);
	//DEVICE_CONTEXT->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	_vertexShader->Set();
	_pixelShader->Set();

	DEVICE_CONTEXT->Draw(_vertices.size(), 0);
}

bool Collider::IsCollision(shared_ptr<Collider> collider, bool isObb)
{
	if(collider->_type == ColType::CIRCLE)
	{
		//shared_ptr<CircleCollider> circle;
		//circle = dynamic_pointer_cast<CircleCollider>(collider);
		//return IsCollision(circle, isObb);

		return IsCollision(dynamic_pointer_cast<CircleCollider>(collider), isObb);
	}
	if(collider->_type == ColType::RECT)
	{
		//shared_ptr<RectCollider> rect;
		//rect = dynamic_pointer_cast<RectCollider>(collider);
		//return IsCollision(rect, isObb);

		return IsCollision(dynamic_pointer_cast<RectCollider>(collider), isObb);
	}
		
	return false;
}

void Collider::CreateData()
{
	_vertexShader = make_shared<VertexShader>(L"Collider/ColliderVertexShader");
	_pixelShader = make_shared<PixelShader>(L"Collider/ColliderPixelShader");

	UINT stride = sizeof(Vertex);
	_vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), stride, _vertices.size());
	_colorBuffer = make_shared<ColorBuffer>();
	_colorBuffer->SetColor(GREEN);
	//SetGreen();

	_transform = make_shared<Transform>();
}
