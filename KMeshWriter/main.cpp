#include <sal.h>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <fstream>
#include <sstream>

struct type
{
	int n;
	float x, y, z;
}vertex[3];
int main(_In_ int _Argc, _In_reads_(_Argc) _Pre_z_ char ** _Argv)
{
	std::ifstream inf("mesh.txt", std::ifstream::in);

	if (inf.good())
	{
		unsigned long long bytes;
		std::stringstream ss;
		ss << inf.rdbuf();
		

		std::ofstream of("mesh.kmesh", std::ofstream::binary);
	

		if (of.good())
		{
			std::stringstream s;
			
			for (std::size_t byte = 0; byte <ss.str().length(); byte++)
				
				s << std::hex << static_cast<unsigned>(ss.str()[byte]) << std::setfill('0') << std::setw(4);
			
			std::cout << s.str() << std::endl;
			
			for (std::size_t byte = 0; byte < s.str().length(); byte+=4)
			{
				std::string sb = s.str().substr(byte, 2);
				std::cout << static_cast<char>(std::stoul(sb.c_str(),nullptr,16));
			}
			
			int a = 2, b = 4;
			//of.write(reinterpret_cast<char*>(&a), sizeof(a));
			//of.write(s.str().c_str(), sizeof(int));
			
			/*for (std::size_t byte = 0; byte < s.str().length(); byte++)
				of.write(s.str().c_str(), sizeof(float));*/
			
			of << s.rdbuf();
		}

		of.close();
	}

	inf.close();

	std::ifstream iff("mesh.kmesh", std::ifstream::binary);

	std::stringstream iss, iis;

	
	/*iss  <<  iff.rdbuf();
	iss << std::hex;*/
	/*for (std::size_t byte = 0; byte < iss.str().length(); byte += 4)
	{*/
		
		//iis << static_cast<char>(std::stoul(iss.str().substr(byte, 2), nullptr, 16));
	while (!iff.eof())
		for (std::size_t i = 0; i < sizeof(int)*3; i++)
		{
			std::string sss;
			iff.read(&sss[0], sizeof(int));

		}
			
	//}
	/*iis << static_cast<char>(std::stoul(iss.str().substr(0, 4), nullptr, 16));*/
	//iis >> vertex[0].n;

	
	
	
	


	return 0;
}