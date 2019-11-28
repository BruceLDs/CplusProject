#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//void testFile()
//{
//	/*char* filename = "test.txt";
//	fopen(filename, "r");
//	fgetc, fgets, fread, fclose;
//	fputc, fputs, fwrite*/
//
//	
//	int a = 100;
//	char c = 'a';
//	ofstream fout("test.txt");
//	fout << a << endl;
//	fout << c << endl;
//	fout.close();
//	ifstream fin("test.txt");
//	int ia;
//	char ic;
//	fin >> ia;  // atoi
//	fin >> ic;
//	fout.close();
//	//fin.get(c);
//	//fin.getline();
//
//	
//
//}
struct ServerInfo
{
	char ip[100];
	int port;
};

class config
{
public:
	config(string filename = "config")
		:_binaryFile(filename + ".cfg")
		, _textFile(filename + ".txt")
	{}
	void ReadText(ServerInfo& info)
	{
		ifstream fin(_textFile.c_str());
		fin >> info.ip;
		fin >> info.port;
		fin.close();
	}

	void WriteText(const ServerInfo& info)
	{
		ofstream fout(_textFile.c_str());
		fout << info.ip;
		fout << info.port << endl;
		fout.close();
	}

	void ReadBin(ServerInfo& info)
	{
		ifstream fin(_binaryFile.c_str());
		fin.read((char*)&info, sizeof(ServerInfo));
		fin.close();
	}

	void WriteBin(const ServerInfo& info)
	{
		ofstream fout(_binaryFile.c_str());
		fout.write((char*)&info, sizeof(ServerInfo));
		fout.close();
	}
private:
	string _binaryFile;
	string _textFile;
};

void testFile2()
{
	ServerInfo info;
	config cfg;

	strcpy(info.ip, "192.168.1.1");
	info.port = 3066;

	cfg.WriteText(info);
	cfg.WriteBin(info);

	ServerInfo info2;
	ServerInfo info3;
	cfg.ReadBin(info2);
	cfg.ReadText(info3);

}

int main()
{
	/*int a;
	char c;
	scanf("%d", &a);
	scanf("%c", &c);
	cin >> a;
	cin >> c;
	cout << a ;
	cerr << a;
	clog << a;*/
	//testFile();
	testFile2();
}