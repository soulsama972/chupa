#pragma once
#include "Model.hpp"
#include"Window.hpp"
#include"Math.hpp"
#include<string>
struct TextrueInstanceType
{
	Matrix4x4 matrix;
};
struct TextrueVertex
{
	fVec3 pos;
	fVec2 tex;
};
using IRect = vec4<int>;


class Texture2D : private Model11<TextrueInstanceType>
{
public:
	~Texture2D();
	Texture2D(std::string src);
	void AddInstance(IRect rect);
	void AddInstance(IRect* rect,int len);
	void Draw();

	inline static void Bind(Window* window)
	{
		Texture2D::window = window;
	}

private:
	ID3D11ShaderResourceView* textrue = nullptr;
	ID3D11SamplerState* sampleState = nullptr;
	static Window* window;
};
