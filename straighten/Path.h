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
	Voxel operator-(Voxel tar){return Voxel(x-tar.x, y-tar.y, z-tar.z);}
	int operator==(Voxel tar){if(tar.x==x && tar.y==y && tar.z==z) return 1;return 0;}
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
	int len(){return _data.size();}
	void save(const char* filename);
};

//recurrent transform
class Transform
{
	vector<Path> _data;
	int len;
	int head[2];
	int recurrent_z;
public:
	Transform(Path origin);
	void recurrent();
	void recurrent_once();
	void recurrent_half(const int head_rank);
	void rotate(const int head_rank, int rotate_len);
};