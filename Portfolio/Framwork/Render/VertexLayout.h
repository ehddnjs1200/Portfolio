#pragma once
// Á¤Á¡

struct Vertex
{
    XMFLOAT3 pos;

    Vertex()
        : pos(0,0,0)
        {}
    Vertex(float x, float y)
        : pos(x,y,0)
        {}
};

struct VertexUV
{
    XMFLOAT3 pos; // x, y ,z(0)
    XMFLOAT2 uv; // x,y

    VertexUV()
        : pos(0,0,0)
        , uv(0,0)
        {}
    VertexUV(float x, float y, float u , float v)
        : pos(x,y,0)
        , uv(u,v)
        {}

};