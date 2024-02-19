#pragma once
class Quad;

class HealthBar
{
public:
    HealthBar(Vector2 pos,int maxHp, int Hp,int barWidth);
    ~HealthBar();

    void Update();
    void Render();

    void DrawBar();
    void DecreaseHp(int amount);
    void IncreaseHp(int amount);
    void PlusMaxHp(int amount);

    void Init();
    void Setting();

private:
    int _maxHp;
    int _Hp;
    int _barWidth;
    Vector2 _pos;

    vector<shared_ptr<Quad>> _Image;
    shared_ptr<Quad> _back;
    shared_ptr<Collider> _HpBar;

};

