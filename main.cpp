#include <iostream>
#include <fstream>

using namespace std;

void openFile (string name);
int LoadData (string name, double data[]);
void printData (double data [], int sizz);


int main()
{
    while (true)
{
        char choice;
        string name, nameload;
        double data[300];
        int sizz;
        cout << "1 - Enter a new data set" << endl;
        cout << "2 - Load a data set" << endl;
        cout << "3 - Display a data set" << endl;
        cout << "E - End" << endl;
        cout << "Choose what operation you want : ";
        cin >> choice;
        if (choice == 'E' || choice == 'e')
        {
            return 0;
        }
        if (choice == '1')
        {
            cout << "Enter File Name: ";
            getline(cin, name);
            name += ".txt";
            openFile(name);
        }
        else if (choice == '2')
        {
            cout << "Enter File Name: ";
            getline(cin, nameload);
            nameload += ".txt";
            sizz = LoadData(nameload, data);
            cout << "Data Loaded Successfully!\n";

        }
        else if (choice == '3')
        {
        printData(data,sizz);
        cout << endl ;
        }
}




    return 0;
}

void openFile(string name)
{
    fstream inFile;
    double data;
	inFile.open(name, ios::out);
	if (!inFile)
	{
		cout << name << "could not be opened.\n";
		return;
	}
	else
    {
    cout << "Enter Data.\nWhen finished, enter \'555\' to stop entering data:\n";
	while (true)
	{
	    cin >> data;
        if (data == 555)
            break;
        inFile << data << endl;
	}
	inFile.close();

    }
}

int LoadData (string name, double data[])
{
    ifstream file;
    file.open(name);
    int size = 0;
    while (!file.eof() && !file.fail())
    {
        file >> data [size++];
    }
    file.close();
return size;
}

void printData (double data [], int sizz)
{
    for (int i=0 ; i< sizz ; i++)
    {
        cout << data[i] << " ";
    }
}
