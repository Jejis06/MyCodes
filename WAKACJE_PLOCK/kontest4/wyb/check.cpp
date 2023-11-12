#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void printFile(string name){
	std::ifstream f(name);
	if (f.is_open())
		std::cout << f.rdbuf();
}

double timeAndRun(string cmd){
	auto start = high_resolution_clock::now();
	system(cmd.c_str());
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<milliseconds>(stop - start);
	return double(duration.count());
}


string to_compiled(string input) { return '.' + input; }

string to_code(string input) { return input + ".cpp"; }

double maxTimeMs = -1;

string timeWrapper(double duration){
	
	if (maxTimeMs < 0) return "\e[0m";
	string pref = "\e[31m";
	if (duration < maxTimeMs/1.5){
		pref = "\e[33m";
	}
	if (duration <= maxTimeMs/2) {
		pref = "\e[32m";
	}
	return pref;
}

int main(int argc, const char** argv){
	int lbound=1, hbound=100, limit=5;

	if (argc < 2) {
		printf("\n---Insufficient ammount of arguments---\n\n");
		printf("./%s prog_name lbound hbound timeLimit\n\n", argv[0]);
		printf("(required)[prog_name] --> for compilation translates to : prog_name.cpp && prog_namebrut.cpp && prog_namegen.cpp \n");
		printf("(optional)[lbound] --> lower bound for seeds\n");
		printf("(optional)[lbound] --> upper bound for seeds\n");
		printf("(optional)[timeLimit] --> timeLimit for every program\n");
		return 0;
	}
	string wzor = argv[1];
	string brut = wzor + "brut";
	string gen = wzor + "gen";

	if (argc >= 4){
		lbound = atoi(argv[2]);
		hbound = atoi(argv[3]);

	}
	if (argc >= 5){
		limit = atoi(argv[4]);

	}
	if (argc >= 6){
		maxTimeMs = atoi(argv[5]);

	}
	double meanBrut = 0;
	double meanWzor = 0;

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

	printf("\nTESTING------\n");
	printf("BOUNDS : <%d,%d> maxN[%d] maxTime[%d]\n",lbound,hbound,limit,maxTimeMs);
	for (int i=lbound; i<=hbound; i++) {
		string generate = "echo " + to_string(i) + " " + to_string(limit) + " | ./" + to_compiled(gen) + " > test.in";
		system(generate.c_str());

		string brut_out = "./" + to_compiled(brut) + " < test.in > brut.out";
		string wzor_out = "./" + to_compiled(wzor) + " < test.in > wzor.out";

		/* run brut */
		double brutTime = timeAndRun(brut_out);
		/* run wzor */
		double wzorTime = timeAndRun(wzor_out);

		string brutCol = timeWrapper(brutTime);
		string wzorCol = timeWrapper(wzorTime);

		if (system("diff brut.out wzor.out") > 0) {
			system("clear");
			printf("\n\n\e[31mWRONG ON %d for input:\e[0m\n",i);
			printFile("test.in");
			printf("\n\n\n");
			printf("\e[32m-------------brut.out-------------\n");
			printFile("brut.out");
			printf("\e[0m\n\n");
			printf("\e[31m-------------wzor.out-------------\n");
			printFile("wzor.out");
			printf("\n");

			return 0;
		}

		//\e[32m -- green
		//\e[31m --red 
		//\e[0m -- end of color
		//\e[34m
		//\e[35m
		else printf("|  \e[32;1mOK %d\e[0m  | %sbrut: %.2fms\e[0m  \t%swzor: %.2fms\e[0m |\n",i,brutCol.c_str(),brutTime,wzorCol.c_str(),wzorTime);

		meanBrut += brutTime;
		meanWzor += wzorTime;
	}

	printf("\n--------Results-------\n");
	printf("| Mean brut : %.2fms |\n", (meanBrut/(hbound-lbound)));
	printf("| Mean wzor : %.2fms |\n", (meanWzor/(hbound-lbound)));
}




