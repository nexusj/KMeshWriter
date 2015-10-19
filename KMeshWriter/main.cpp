#include <sal.h>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <fstream>
#include <sstream>

struct type
{
	float x, y, z;
}vertex[3];
int main(_In_ int _Argc, _In_reads_(_Argc) _Pre_z_ char ** _Argv)
{
	std::ifstream inf("mesh.txt", std::ifstream::binary);

	if (inf.good())
	{
		
		std::ofstream of("mesh.kmesh", std::ofstream::binary);
	

		if (of.good())
		{
			int x = 0;
			inf >> x;
			of.write(reinterpret_cast<char*>(&x), sizeof(int));

			float f = 0;

			while (inf >> f)
				of.write(reinterpret_cast<char*>(&f), sizeof(float));
		}

		of.close();
	}

	inf.close();

	std::ifstream iff("mesh.kmesh", std::ifstream::binary);

	int n = 0;
	iff.read(reinterpret_cast<char*>(&n), sizeof(int));
	
	iff.read(reinterpret_cast<char*>(&vertex[0]), sizeof(type)*3);
	
	
	
	


	return 0;
}