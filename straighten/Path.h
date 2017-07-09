#pragma once

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

struct Voxel
{
	int x;
	int y;
	int z;
	Voxel(int x, int y, int z):x(x), y(y), z(z) {}
	Voxel(){}
	void print(){cout<<x<<" "<<y<<" "<<z<<endl;}
};

class Path
{
	vector<Voxel> _data;
public:
	Path(const char* filename);
	~Path(void);
	//operator
	Voxel& operator[](int k);
	//print
	void print();
};

class Transform
{
	vector<Path> _data;
public:
	Transform(Path origin);
};