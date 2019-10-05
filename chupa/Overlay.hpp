#pragma once
#include"Model.hpp"


class Overlay
{
public:
	static LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);

public:
	Overlay(int with, int height);
	~Overlay();
public:
	void InitD3D();
	
	void ClearTargetView(fVec4 color);
	void Draw(bool cleanAfterDraw = true);
	void Render();

public:
	void setScreenSize(fVec2 screensize);

public:
	void InsertLine(fVec2 p1, fVec2 p2, fVec4 color);
	void InsertCircle(fVec2 pos, float rad, fVec4 color,bool filled = true);
	void InsertRect(fVec2 pos, fVec2 size, fVec4 color);
private:
	inline fVec2 GetScale(fVec2 s)
	{
		return fVec2(s.x / screen.x, s.y / screen.y);
	}

	inline fVec2 GetTransalte(fVec2 t,fVec2 c)
	{
		return fVec2((t.x + c.x / 2) * 2 / screen.x - 1, 1 - 2 * (t.y + c.y / 2) / screen.y);
	}
private:
	void InitShapes();
	LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	
public:
	bool rdy = false;
	HWND hwnd = 0;
private:
	fVec2 screen;
	ID3D11Device* dev = nullptr;
	ID3D11DeviceContext* devcon = nullptr;
	IDXGISwapChain* swapChain = nullptr;
	ID3D11RenderTargetView* backBuffer = nullptr;
	Model11<VertexInstance>rect;
	Model11<VertexInstance>line;
	Model11<VertexInstance>circle;
	Model11<VertexInstance>fCircle;

	HINSTANCE hInstance = 0;
	static Overlay* pThis;
};

extern Overlay *overlay;