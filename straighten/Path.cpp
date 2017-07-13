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
	for(int i=0;i < _data.size();i++)
	{
		_data[i].print();
	}
}

void Path::save(const char* filename)
{
	ofstream fout(filename);
	for(int i=0;i<_data.size();i++)
	{
		fout<<_data[i].x<<" "<<_data[i].y<<" "<<_data[i].z<<endl;
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
	len = origin.len();
	//variable
	head[1] = 0;
	head[0] = -1;
	recurrent_z = origin[0].z;
}

void Transform::recurrent()
{
	while(recurrent_z>1)
		recurrent_once();
}

void Transform::recurrent_once()
{
	cout<<"head 1"<<endl;
	recurrent_half(1);
	cout<<"head 0"<<endl;
	recurrent_half(0);
	head[1]++;
	head[0]--;
	recurrent_z--;
}

void Transform::recurrent_half(const int head_rank)
{
	int delta;
	if(head_rank == 1) 
		delta = 1;
	else 
		delta = -1;
	Path new_path = _data[_data.size()-1];
	Voxel voxel_delta = new_path[head[head_rank]+delta] - new_path[head[head_rank]];
	int rotate_len = 0;
	while(1)
	{
		if((new_path[head[head_rank]+delta] - new_path[head[head_rank]]) == voxel_delta && voxel_delta.z == 0)
		{
			//new_path[head[head_rank]].print();
			rotate_len++;
			head[head_rank] = head[head_rank]+delta;
		}
		else
		{
			//new_path[head[head_rank]].print();
			cout<<rotate_len<<endl;
			rotate(head_rank, rotate_len);
			voxel_delta = new_path[head[head_rank]+delta] - new_path[head[head_rank]];
			rotate_len = 0;
			if(voxel_delta.z != 0)
				break;
		}
	}
}

void Transform::rotate(const int head_rank, int rotate_len)
{
}