#include "framework.h"
#include "HealthBar.h"

HealthBar::HealthBar(int maxHp, int Hp,int barWidth)
    :_maxHp(maxHp), _Hp(Hp), _barWidth(barWidth)
{
    Init();
    Setting();
}

HealthBar::~HealthBar()
{

}

void HealthBar::Update()
{
    _back->Update();
    _HpBar->Update();
    for (int i = 0; i < _maxHp; i++)
    {
        _Image[i]->Update();
    }
}

void HealthBar::Render()
{
    _back->Render();
    _HpBar->Render();
    for (int i = 0; i < _maxHp; i++)
    {
        _Image[i]->Render();
    }
}

void HealthBar::DrawBar()
{
    int filledWidth = (int)((double)_Hp / _maxHp * _barWidth);
    string bar = "[";
    for (int i = 0; i < _barWidth; ++i) {
        if (i < filledWidth)
            bar += "=";
        else
            bar += " ";
    }
    bar += "]";
    cout << "hp: " << bar << endl;
}

void HealthBar::DecreaseHp(int amount)
{
    _Hp -= amount;
    if (_Hp < 0)
        _Hp = 0;
}

void HealthBar::IncreaseHp(int amount)
{
    _Hp += amount;
    if (_Hp > _maxHp)
        _Hp = _maxHp;
}

void HealthBar::PlusMaxHp(int amount)
{
    _maxHp += amount;
}

void HealthBar::Init()
{
    _back = make_shared<Quad>(L"backHp.png");
    //_HpBar = make_shared<RectCollider>();
    _HpBar = make_shared<RectCollider>(_back->GetTextureSize());
    

    for (int i = 0; i < _maxHp; i++)
    {
        shared_ptr<Quad> _Images = make_shared<Quad>(L"hp.png", static_cast<float>(_maxHp));
        _Image.emplace_back(_Images);
    }
}

void HealthBar::Setting()
{
    _back->GetTransForm()->SetPos(Vector2(CenterX - 240, CenterY - 100));
    _back->GetTransForm()->GetScale() *= 0.09f;
    _HpBar->SetParent(_back->GetTransForm());

    Vector2 pos = _back->GetTransForm()->GetPos();
    Vector2 scale = _back->GetTransForm()->GetScale();
    scale *= 1226;

    float left_x = pos.x - (scale.x);
    float right_x = pos.x + (scale.x);

    float a = right_x - left_x;
    float _Interval = a / static_cast<float>(_maxHp);

    for (int i = 0; i < _maxHp; i++)
    {
        _Image[i]->GetTransForm()->SetPos(Vector2(left_x + (_Interval * i), CenterY - 100));
        _Image[i]->GetTransForm()->GetScale() *= 0.09f;
    }
}
