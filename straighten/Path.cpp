#include "Path.h"


Path::Path(const char* filename)
{
	ifstream fin(filename);
	int x,y,z;
	while(fin>>x)
	{
		fin>>y>>z;
		_data.push_back(Voxel(x,y,z));
	}
}


Path::~Path(void)
{
}


void Path::print()
{
	for(int i=0;i<_data.size();i++)
	{
		_data[i].print();
	}
}

Voxel& Path::operator[](int k)
{
	if(k>=0)
		return _data[k];
	else
		return _data[_data.size()+k];
}

Transform::Transform(Path origin)
{
	_data.push_back(origin);
}