#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <pthread.h>


#define DATABASEFILE     "database.txt"
#define SORTDATABASEFILE "sortDataBase.txt"


class Worker {

	private:
		std:: string   name;
		      int       age;
		      double salary;

	public:
		void doWork (std:: ofstream & outFile);
		Worker ();
		Worker (std:: ifstream & inFile);
		void show ();
		~Worker ();
};


int amountOfStrings (std:: ifstream & inFile, std:: string name);
void startInitialize (std:: vector <Worker> & worker, int amount, std:: ifstream & inFile);
void * treatment (void * worker);


int main (void) {

	std:: ofstream outFile;
	outFile.open (SORTDATABASEFILE, std:: ios_base:: out);

	std:: ifstream inFile;
	int amountStrings = amountOfStrings (inFile, DATABASEFILE);
	inFile.open (DATABASEFILE);


	std:: vector<Worker> worker (amountStrings);
	startInitialize (worker, amountStrings, inFile);

	pthread_t thread[amountStrings];

	int i = 0;
	for (i = 0; i < amountStrings; i++) {

		try {

			pthread_create (&thread[i], NULL, treatment, &worker[i]);
		}

		catch (const std:: exception & ex) {

			std:: cout << ex.what () << std:: endl;
		}
	}

	for (i = 0; i < amountStrings; i++)
		pthread_join (thread[i], NULL); 


	return 0;
}


void * treatment (void * worker) {

	std:: ofstream outFile;
	outFile.open (SORTDATABASEFILE, std:: ios_base:: out | std:: ios_base:: app);

	Worker * currentWorker = (Worker * ) worker;
	currentWorker->doWork (outFile);
}


int amountOfStrings (std:: ifstream & inFile, std:: string name) {

	inFile.open (name);

	int amountEndl =    0;
	char ch        = '\0';

	while (!inFile.eof()) {

		inFile.get (ch);

		if (ch == '\n')
			amountEndl++;
	}

	inFile.close ();

	return amountEndl + 1;
}


void Worker:: doWork (std:: ofstream & outFile) {

	salary--;

	outFile << std:: left << std:: setw (10) 
	        << name       << std:: setw (10) 
		    << age        << std:: setw (10) 
			<< salary     << std:: endl;
}


void Worker:: show () {

	std:: cout << "name: "   << name   << std:: endl;
	std:: cout << "age: "    << age    << std:: endl;
	std:: cout << "salary: " << salary << std:: endl;
	std:: cout <<                         std:: endl;
}


void startInitialize (std:: vector <Worker> & worker, int amount, std:: ifstream & inFile) {

	int i = 0;
	for (i = 0; i < amount; i++)
		worker[i] = Worker (inFile);

}


Worker:: Worker () {

	name   = "";
	age    =  0;
	salary =  0;
}


Worker:: Worker (std:: ifstream & inFile) {

	if (!inFile.eof()) {

		if (!inFile.is_open ())
			std:: cout << "File wasn't opened." << std:: endl;

		inFile >> name >> age >> salary;

		if (salary >= 100)
			throw std:: invalid_argument ("salary > 100");
	}
}


Worker:: ~Worker () {

	std:: cout << "Worker: closed " << name << std:: endl;
}





