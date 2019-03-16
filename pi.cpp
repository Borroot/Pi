#include <stdio.h>
#include <iostream>
#include <fstream>
#include <limits.h>
#include <string>
#include <cstdlib>

using namespace std;

const string filename = "/home/borroot/Dropbox/Miscellaneous/Pi/pi.txt";

void ask(int d, int *mistakes){
	cout << "> ";
	int entry;
	cin >> entry;

	if(entry == d){
		return;
	} else {
		cout << "wrong, please try again" << endl;
		(*mistakes)++;
		ask(d, mistakes);
	}
}

int main(int argc, char* argv[]){

	if(argc < 2){
		cout << "Usage: " << argv[0] << " [number of digits]\n";
		exit(1);
	}

	const int LIMIT = (argc != 2 || atoi(argv[1]) == 0)? INT_MAX : atoi(argv[1]);

	ifstream file (filename);
	if(!file.is_open()){
		cout << "file could not be opened" << endl;
		exit(1);
	}

	int count = 0, mistakes = 0;
	char c;
	
	cout << "3." << endl;
	while((c = file.get()) != EOF && count < LIMIT){
		ask((int) (c - '0'), &mistakes);
		count++;
	}
	cout << "correct entries: " << count << endl
		  << "mistakes made:   " << mistakes << endl;

	file.close();

	return 0;
}
