// Hunt the Wumpus - originally written in BASIC by Gregory Yob in 1973
// File Name: huntTheWumpus
// Programmer: Josh Guerra
// Last Modified: Dec 2, 2015

#include "myHeader.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void main() {
	bool
		instrLoaded = false,
		statsLoaded = false;

	int const 
		SIZE_STATS = 3,			// most stats are grouped into arr[3] with other similar stats
		SIZE_TITLE = 4,
		SIZE_INSTR = 38;		// num of lines in instructions.txt

	int gamesPld,
		moveCounter,
		whoWon[SIZE_STATS],
		posPlayer = 1,
		posWumpus = 6,
		posBat1 = 3,
		posBat2 = 10,
		posPit1 = 13,
		posPit2 = 16;

	double
		winPct[SIZE_STATS],
		numMvs[SIZE_STATS];		// will display some stats as ints

	string
		mapFilename = "map.txt",
		instrFilename = "instructions.txt",
		statsFilename = "stats.txt",
		instrArray[SIZE_INSTR],
		titleArr[SIZE_TITLE] = {
			"\t\t    CIT-120 Capstone Project    ",
			"\t\t          by J. Guerra          ",
			"\t\t        Hunt the Wumpus!        ",
			"\t\tOriginally by Gregory Yob (1973)" 
		};

	ifstream
		ifsInstr,
		ifsStats;

	ofstream
		ofsStats;

	system("color 2f");		// set console color: 2 (green background), f (white text)

	// ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ //

	while (true) {
		printStringArr(titleArr, SIZE_TITLE);

		cout << endl << endl;
		printMenu();
		cout << "\n\nPlease make a selection: ";

		switch (getIntInRange(1, 4)) {
			case 1:			// instructions
				if (!instrLoaded) {
					cout << "\n Loading statistics...";
					
					ifsInstr.open(instrFilename);
					loadStringArrayFromFile(instrArray, SIZE_INSTR, ifsInstr, instrLoaded);
					ifsInstr.close();

					cout << "Done loading statistics";
				}

				system("cls");
				printStringArr(instrArray, SIZE_INSTR);
				cout << endl << endl;
				break;
			case 2:			// Stats
				if (!statsLoaded) {
					ifsStats.open(statsFilename);
					loadStats(gamesPld, whoWon, winPct, numMvs, SIZE_STATS, ifsStats, statsLoaded);
					ifsStats.close();
				}

				printStats(gamesPld, whoWon, winPct, numMvs, SIZE_STATS);
				cout << endl << endl;
				break;
			case 3:			// Play
				cout
					<< "\n\tPlease finish each game."
					<< "\n\tStatistics will be automatically updated after each game."
					<< "\n\tYou may view statistics in main menu or in \"stats.txt\""
					<< endl;

				if (!instrLoaded) {
					cout << "\n\tLoading statistics...";

					ifsInstr.open(instrFilename);
					loadStringArrayFromFile(instrArray, SIZE_INSTR, ifsInstr, instrLoaded);
					ifsInstr.close();

					cout << "\n\tDone loading statistics\n";
				}

				system("pause");
				system("cls");
				startHunt(posPlayer, posWumpus, posBat1, posBat2, posPit1, posPit2, moveCounter);
				break;
			case 4:			// EXIT
				cout << "\nThank you for using my program.\n\n";
				system("pause");
				exit(0);
		}

		system("pause");
		system("cls");
	}
}