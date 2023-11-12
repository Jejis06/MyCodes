#include <iostream>
#include <fstream>

using namespace std;

void printFile(string name){
	std::ifstream f(name);

	if (f.is_open())
		std::cout << f.rdbuf();
}

string wzor = "arborysta";
string brut = "arborystabrut";
string gen = "arborystagen";

/* arborystabrut.cpp
arborysta.cpp
arborystagen.cpp
check.cpp
makefile
t.arborysta
*/

string to_compiled(string input) { return '.' + input; }

string to_code(string input) { return input + ".cpp"; }

int main(int argc, const char** argv){
	int lbound=1, hbound=100, limit=5;
	if (argc == 3){
		lbound = atoi(argv[1]);
		hbound = atoi(argv[2]);

	}
	if (argc == 4){
		lbound = atoi(argv[1]);
		hbound = atoi(argv[2]);
		limit = atoi(argv[3]);

	}

	cout << "COMPILING-------\n";
	string compile1 = "g++ -o " + to_compiled(brut) + ' ' + to_code(brut);
	string compile2 = "g++ -o " + to_compiled(gen) + ' ' + to_code(gen);
	string compile3 = "g++ -o " + to_compiled(wzor) + ' ' + to_code(wzor);
	cout << compile1 << endl;
	system(compile1.c_str());
	cout << compile2 << endl;
	system(compile2.c_str());
	cout << compile3 << endl;
	system(compile3.c_str());

	printf("TESTING------\n");
	printf("BOUNDS : <%d,%d> max[%d]\n",lbound,hbound,limit);
	for (int i=lbound; i<=hbound; i++) {
		string generate = "echo " + to_string(i) + " " + to_string(limit) + " | ./" + to_compiled(gen) + " > test.in";
		system(generate.c_str());

		string brut_out = "./" + to_compiled(brut) + " < test.in > brut.out";
		string wzor_out = "./" + to_compiled(wzor) + " < test.in > wzor.out";

		system(brut_out.c_str());
		system(wzor_out.c_str());


		if (system("diff brut.out wzor.out") > 0) {
			printf("\n\nWRONG ON %d for input:\n",i);
			printFile("test.in");
			return 0;
		}

		else cout << "OK " << i << "\n"; 
	}
}



