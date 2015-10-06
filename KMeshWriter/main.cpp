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
		inf.seekg(0, inf.end);
		unsigned long long bytes = inf.tellg();
		inf.seekg(0, inf.beg);
		std::stringstream ss;
		std::string st;
		st.resize(bytes);
		inf.read(&st[0], bytes);

		char* buffer = &st[0];

		for (std::size_t i = 0; i < bytes; i++)
		ss << std::hex << static_cast<int>(buffer[i]);

		auto s = ss.str();
		

		std::ofstream of("mesh.kmesh", std::ofstream::binary);
	

		if (of.good())
		{
			/*std::stringstream s;
			
			
			for (std::size_t byte = 0; byte <ss.str().length(); byte++)
				
				s << std::hex << static_cast<unsigned>(ss.str()[byte]) << std::setfill('0') << std::setw(4);

			
			std::cout << s.str() << std::endl;
			
			for (std::size_t byte = 0; byte < s.str().length(); byte+=4)
			{
				std::string sb = s.str().substr(byte, 2);
				std::cout << static_cast<char>(std::stoul(sb.c_str(),nullptr,16));
			}
			
			int a = 2, b = 4;*/
			//of.write(reinterpret_cast<char*>(&a), sizeof(a));
			//of.write(s.str().c_str(), sizeof(int));
			
			
				of.write(&s[0],s.length());
			
			//of << s.rdbuf();
		}

		of.close();
	}

	inf.close();

	std::ifstream iff("mesh.kmesh", std::ifstream::binary);

	std::stringstream iss, iis;
	std::string sf;
	
	iff.seekg(0, iff.end);
	long l = iff.tellg();
	iff.seekg(0, iff.beg);

	sf.resize(l);
	iff.read(&sf[0], l);
	/*iss  <<  iff.rdbuf();
	iss << std::hex;*/

	iis << static_cast<char>(std::stoul(sf.substr(18, 2), nullptr, 16));
	iis >> vertex[0].x;
	/*for (std::size_t byte = 0; byte < iss.str().length(); byte += 4)
	{*/
		
		//iis << static_cast<char>(std::stoul(iss.str().substr(byte, 2), nullptr, 16));
	/*while (!iff.eof())
		for (std::size_t i = 0; i < sizeof(int)*3; i++)
		{
			std::string sss;
			iff.read(&sss[0], sizeof(int));

		}*/
			
	//}
	/*iis << static_cast<char>(std::stoul(iss.str().substr(0, 4), nullptr, 16));*/
	//iis >> vertex[0].n;

	
	
	
	


	return 0;
}