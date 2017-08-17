#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline bool exists(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

string numberConvert(int i)
{
	string result = to_string(i);
	//0001
	if (i < 10)
	{
		result = "000" + to_string(i); //000x
	}
	else if (i < 100)
	{
		result = "00" + to_string(i); //00xx
	}
	else if (i < 1000)
	{
		result = "0" + to_string(i); //0xxx 
	}

	return result;
}

int main()
{
	string path = "C:\\Users\\xbrosseau\\Downloads\\TEMP\\UTRA TEMP\\saint-jean 2017 - Copie\\";
	int indice = 0;

	for (int i = 2000; i <= 6000; ++i)//-1658
	{
		const string file_path_old = path + "IMG_" + numberConvert(i) + ".JPG";
		const string file_path_new = path + "IMG_" + numberConvert(i- 1658) + ".JPG";
		if (exists(path + "IMG_" + numberConvert(i) + ".JPG"))
		{
			indice++;
			cout << file_path_old << " | " << indice << endl;
			///////////
			int result;
			char newname[] = "newname.txt";
			result = rename(file_path_old.c_str(), file_path_new.c_str());
			if (result == 0)
				cout << "File successfully renamed"<<endl;
			else
				cout << "Error renaming file"<<endl;
			///////////

		}
		else
		{
			//cout << file_path << " existe pas"<<endl;
		}
	}

}
