#include"Path.h"
using namespace std;

int main()
{
	Path origin("edge_voxel/chair_y.txt");
	Transform straighten(origin);
	straighten.recurrent();



	int a;cin>>a;
	return 0;
}