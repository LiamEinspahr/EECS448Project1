#include <iostream>
#include <string>
#include "Executive.h"

using namespace std;

int main(){

	string horizontal_bar = "-----------------------------------------------------------------------\n";
	string battleship_text = " 		            BATTLESHIP          			  \n";

	for (int i = 0; i < 3; i++) cout << endl;
	cout << horizontal_bar;
	for (int i = 1; i <= 1; i++) cout << endl;
	cout << battleship_text;
	for (int i = 1; i <= 1; i++) cout << endl;
	cout << horizontal_bar;
	for (int i = 0; i < 3; i++) cout << endl;

	Executive exec;
	exec.run();

	return(0);
}
