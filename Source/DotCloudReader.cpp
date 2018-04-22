#include <iostream>
#include <fstream>
#include <string>
#include "../Header/DotCloudReader.h"

#define PI 3.14159265

using namespace std;

DotList* DotCloudReader::GetDotCloud()
{
	DotList* dots = new DotList;

	string filename;
	cout << "Enter name of file in resource directory: ";
	cin >> filename;
	filename = "Resource\\" + filename;
	ifstream file(filename);

	double x = 0, y = 0, z = 0;
	int red = 0, green = 0, blue = 0;
	char hex;

	//each row start with a "#"
	while (file >> hex)
	{
		file >> x >> y >> z >> red >> green >> blue;
		dots->AddDot(Vector3D(x, y, z, red, green, blue));
	}

	file.close();

	return dots;
}