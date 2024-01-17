// c++_ex8.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
using namespace std;

/// <summary>
/// 物体の定義
/// </summary>
class Solid
{
public:
	virtual string Getkind() = 0;
	virtual double GetVolume() = 0;
	virtual double GetSurface() = 0;
};

class Package :public Solid
{
public:
	virtual double GetSize() = 0;
};
/// <summary>
/// 箱型
/// </summary>
class Box :public Package
{
private:
	double width;
	double height;
	double depth;

public:
	Box(double width, double height, double depth) :Package()
	{
		this->width = width;
		this->height = height;
		this->depth = depth;
	}
	string Getkind()override
	{
		return "箱";
	}
	double GetVolume()override
	{
		return width * height * depth;
	}
	double GetSurface()override
	{
		return (width * height + height * depth + depth * width) * 2;
	}
	double GetSize()override
	{
		return width + height + depth;
	}
	double GetWidth()
	{
		return this->width;
	}
	double GetHeight()
	{
		return this->height;
	}
	double GetDepth()
	{
		return this->depth;
	}
};

class Cylinder :public Package
{
private:
	double radius;
	double height;
public:
	Cylinder(double radius, double height) :Package()
	{
		this->radius = radius;
		this->height = height;
	}
	string Getkind()override
	{
		return "円柱";
	}
	double GetVolume()override
	{
		return radius * radius * M_PI * height;
	}
	double GetSurface()override
	{
		return radius * M_PI * 2 * (radius + height);
	}
	double GetSize()override
	{
		return radius * 4 + height;
	}
	double GetRadius()
	{
		return this->radius;
	}
	double GetHeight()
	{
		return this->height;
	}
};

class Cone :public Package
{
private:
	double radius;
	double height;
public:
	Cone(double radius, double height) :Package()
	{
		this->radius = radius;
		this->height = height;
	}
	string Getkind()override
	{
		return "円錐";
	}
	double GetVolume()override
	{
		return radius * radius * M_PI * height / 3.0;
	}
	double GetSurface()override
	{
		return M_PI * radius * (radius + sqrt(radius * radius + height * height));
	}
	double GetSize()override
	{
		return radius * 4 + height;
	}
	double GetRadius()
	{
		return this->radius;
	}
	double GetHeight()
	{
		return this->height;
	}
};

class Sphere :public Package
{
private:
	double radius;
public:
	Sphere(double radius) :Package()
	{
		this->radius = radius;
	}
	string Getkind()override
	{
		return "球";
	}
	double GetVolume()override
	{
		return  M_PI * radius * radius * radius * 4 / 3;
	}
	double GetSurface()override
	{
		return M_PI * radius * radius * 4;
	}
	double GetSize()override
	{
		return radius * 6;
	}
	double GetRadius()
	{
		return this->radius;
	}
};

void DisplayVolumeSurface(Solid* solid)
{
	cout << "体積=" << solid->GetVolume() << endl;
	cout << "表面積=" << solid->GetSurface() << endl;
}
int main()
{
	Box box{ 80.0, 120, 0.1 };
	Cylinder cylinder{ 30, 10 };
	Cone cone{ 30, 10 };
	Sphere sphere{ 20 };
	Solid* solids[] = { &box,&cylinder,&cone,&sphere };
	for (Solid* solid : solids)
	{
		cout << solid->Getkind() << "の体積" << solid->GetVolume() << ",表面積" << solid->GetSurface() << endl;
	}

	// それぞれの宅急便のサイズを求める
	cout << "\n宅急便のサイズを求める" << endl;
	Package* packages[] = { &box,&cylinder,&cone,&sphere };
	int kuronekoSize[] = { 60,80,100,120,140,160,180,200 };
	int i;
	double length;

	for (Package* package : packages)
	{
		length = package->GetSize();
		//_countof()で()内の要素数を持ってくる
		for (i = 0; i < _countof(kuronekoSize); i++)
		{
			if (length <= kuronekoSize[i])
			{
				break;
			}
		}
		if (i < _countof(kuronekoSize))
		{
			cout << package->Getkind() << "のサイズは" << kuronekoSize[i] << "サイズです" << endl;
		}
		else
		{
			cout << "この" << package->Getkind() << "は宅急便では送れません" << endl;
		}
	}
}
