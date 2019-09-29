#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include "Football.h"
#include <FootballComputation.c>
#include <Football_IO.c>

/*******************************************************************************************************************************************
 *******************************************************************************************************************************************
 *****     Class: CSC-362-001             Semester: Fall 2019             Professor: Richard Fox             Student: Ryan Huffman     *****
 *****_________________________________________________________________________________________________________________________________*****
 *****                                        Programming Assignment #2: Predict Football Games                                        *****
 *****---------------------------------------------------------------------------------------------------------------------------------*****
 *****      This program is used to predict the outcome of football games for which the teams and strengths are stored in a File.      *****
 *****                                                                                                                                 *****
 *****                                    Each line of the Input File has 11 pieces of information:                                    *****
 *****                     1.) Home Team's City (as well as name if more than one team from that particular city)                      *****
 *****                                2.) Home Team Offense (rating of 1 - 10, with 10 being the best)                                 *****
 *****                                3.) Home Team Defense (rating of 1 - 10, with 10 being the best)                                 *****
 *****                             4.) Home Team Special Teams (rating of 1 - 10, with 10 being the best)                              *****
 *****                             5.) Home Team Home Strength (rating of 1 - 10, with 10 being the best)                              *****
 *****                          6.) Home Team Home Field Advantage (rating of 1 - 10, with 10 being the best)                          *****
 *****                    7.) Visiting Team's City (as well as name if more than one team from that particular city)                   *****
 *****                              8.) Visiting Team Offense (rating of 1 - 10, with 10 being the best)                               *****
 *****                              9.) Visiting Team Defense (rating of 1 - 10, with 10 being the best)                               *****
 *****                          10.) Visiting Team Special Teams (rating of 1 - 10, with 10 being the best)                            *****
 *****                          11.) Visiting Team Road Strength (rating of 1 - 10, with 10 being the best)                            *****
 *****---------------------------------------------------------------------------------------------------------------------------------*****
 *****                                     This program is separated into four separate Files:                                         *****
 *****                         A.) This File with the main function and include statement for the Header File                          *****
 *****          B.) A Header File that contains all function prototypes, Constants and all include statements for C libraries          *****
 *****                                      C.) A File containing all computational functions                                          *****
 *****                      D.) A File containing all I/O functions, as well as the summary(...){...} function                         *****
 *****---------------------------------------------------------------------------------------------------------------------------------*****
 *****  This program uses a while loop to loop through every line of the Input File, exiting the loop once the EOF has been reached.   *****    
 *****   Every repetition of the while loop reads in one line of input from the Input file, assigning values to respective variables   *****
 *****       and calling functions to make the needed computations to predict the final score and winner of each football game.        *****
 *****                                                                                                                                 *****
 *****                After the while loop ends and each individual game has been predicted and output to the terminal,                *****
 *****   this program will print to the terminal a summary report that includes the total number of games this session has predicted   *****
 *****                       and the percentage of those games that the Home Team has been predicted to win.                           *****
 *****---------------------------------------------------------------------------------------------------------------------------------*****
 *****                      To perform all the tasks listed above, this program needs the following functions:                         *****
 *****                      1.) main() - Where the program starts executing and where all method calls are made                        *****
 *****           2.) getInput(...) - Get the input from the Input File and assign the values to their respective variables             *****
 *****    3.) computeProtectionValue1(...) - (optional) Compute the value for  predictor1 to be used with the compute(...) function    *****
 *****    4.) computeProtectionValue2(...) - (optional) Compute the value for  predictor2 to be used with the compute(...) function    *****
 *****    5.) computeProtectionValue3(...) - (optional) Compute the value for  predictor3 to be used with the compute(...) function    *****
 *****    6.) computeProtectionValue4(...) - (optional) Compute the value for  predictor4 to be used with the compute(...) function    *****
 *****    7.) computeProtectionValue5(...) - (optional) Compute the value for  predictor5 to be used with the compute(...) function    *****
 *****                          8.) compute(...) - Compute the values needed for the getScore(...) function                            *****
 *****      9.) getScore(...) - Calculate the score differential. Which is used to predict the game winner and score differntial       *****
 *****                    10.) printOutput(...) - Print the winner and score differential for each individual game                     *****
 *****    11.) update(...) - Increment to the total number of games predicted and if the number of Home Team wins (if Home Team won)   *****
 *****                    12.) printSummary(...) - Print to the terminal the total number of games predicted and                       *****
 *****                                             the percentage of games Home Teams are predicted to win                             ***** 
 *******************************************************************************************************************************************
 *******************************************************************************************************************************************/


int main() {
	
	/* ----------------------------------------------------- VARIABLE DECLARATIONS ------------------------------------------------------ */
	// Character Pointer variables to store the file names
	char* fileName1 = "football1.txt";
	char* fileName2 = "football2.txt";

	// Character Array variables to store the home and visiting teams' names
	char homeTeamName[21], visitingTeamName[21];

	// int variables to store strength values for the home and visiting team
	int htOffense, htDefense, htSpecialTeams, htHomeSTR, htHomeADV, vtOffense, vtDefense, vtSpecialTeams, vtRoadSTR;

	// File Pointer variables 
	FILE* fileInput1;
	FILE* fileInput2;

	// double variables to store predictor values to be used in predicting who will win games
	double predictor1, predictor2, predictor3, predictor4, predictor5;

	// int variable to store the score differential
	int differential;

	// int counter variables to store the total number of games predicted and the number of predicted home team wins
	int totalGames = 0;
	int homeWins = 0;
	/* ------------------------------------------------- END OF VARIABLE DECLARATIONS --------------------------------------------------- */

	// opening the files in read mode and assigning them to the file pointer variables
	fileInput1 = fopen(("%c", fileName1), "r");
	fileInput2 = fopen(("%c", fileName2), "r");


	// if statement to check if the file pointer variable fileInput1 is equal to NULL
	if (fileInput1 == NULL) {
		// print to the terminal that the file could not be found
		printf("Could not find file");
		// return 1 to indicate that an error has occured
		return 1;
	}


	// if statement to check if the file pointer variable fileInput2 is equal to NULL
	if (fileInput2 == NULL) {
		// print to the terminal that the file could not be found
		printf("Could not find file 2");
		// return 1 to indicate that an error has occured
		return 1;
	}


	/* -------------------------------------------- WHILE LOOP TO LOOP THROUGH FILE UNTIL EOF ------------------------------------------- */
	// infinite while loop that will only exit when the EOF (End Of File) 
		// of the file is reached
	while (!feof(fileInput1)) {
		// Call the getInput(...){...} function to read in a single line of input from the specified file and 
			// store variables in appropriate variables
		getInput(fileInput1, homeTeamName, &htOffense, &htDefense, &htSpecialTeams, &htHomeSTR, &htHomeADV,
			visitingTeamName, &vtOffense, &vtDefense, &vtSpecialTeams, &vtRoadSTR);

		// Call the compute(...){...} function to compute the values needed to calculate the score differntial and 
			// therefore, also winner of each individual football game using the getScore(...){...} function below
		compute(htOffense, htDefense, htSpecialTeams, htHomeSTR, htHomeADV, vtOffense, vtDefense, vtSpecialTeams, vtRoadSTR, 
			&predictor1, &predictor2, &predictor3, &predictor4, &predictor5);

		// Call the getScore(...){...} function to calculate the score differential and 
			// store that value in the int variable, differential
		differential = getScore(predictor1, predictor2, predictor3, predictor4, predictor5);

		// Call the printOutput(...){...} function to print out the results of the prediction for the particular game
			// this while loop is currently looking at to the terminal
		printOutput(differential, homeTeamName, visitingTeamName);

		// Call the update(...){...} function to increment the total number of games predicted and 
			// depending on the results of the prediction, increment the number of home teams predicted to win
		update(differential, &totalGames, &homeWins);
	}
	/* ----------------------------------------- END OF WHILE LOOP TO LOOP THROUGH FILE UNTIL EOF --------------------------------------- */

	// Call the printSummary method to print the final line of output (total number of games predicted and 
		// the percentage of those games the home team is predicted to win)
	printSummary(totalGames, homeWins);

	// close both files
	fclose(fileInput1);
	fclose(fileInput2);

	// Exit the program and return 0 if no errors occurred 
	return 0;
}

/*
// This function gets one line of input from the football file currently being read, about individual games (one line of input per game)
void getInput(FILE* fp, char* htn, int* hto, int* htd, int* hts, int* hth, int* hfa, char* vtn, int* vto, int* vtd, int* vts, int* vtr) {
	fscanf(fp, "%s %d %d %d %d %d %s %d %d %d %d", htn, hto, htd, hts, hth, hfa, vtn, vto, vtd, vts, vtr);
}
*/
/*
// function for use in conjunction with the compute(...){...} function. 
	// This function calculates the value of the double variable, predictor1
double computePredictionValue1(int htOffense, int vtDefense) {
	return ((htOffense * OFFENSIVE_FACTOR) - vtDefense);
}


// function for use in conjunction with the compute(...){...} function. 
	// This function calculates the value of the double variable, predictor2
double computePredictionValue2(int htDefense, int vtOffense) {
	return ((htDefense + 2) - (vtOffense * OFFENSIVE_FACTOR));
}


// function for use in conjunction with the compute(...){...} function. 
	// This function calculates the value of the double variable, predictor3
double computePredictionValue3(int htSpecialTeams, int vtSpecialTeams) {
	return ((htSpecialTeams * SPECIAL_TEAMS_FACTOR) - vtSpecialTeams);
}


// function for use in conjunction with the compute(...){...} function. 
	// This function calculates the value of the double variable, predictor4
double computePredictionValue4(int htHomeSTR, int htHomeADV, int vtSpecialTeams) {
	return (htHomeSTR + (htHomeADV * HOME_FIELD_ADVANTAGE) - vtSpecialTeams);
}


// function for use in conjunction with the compute(...){...} function. 
	// This function calculates the value of the double variable, predictor5
double computePredictionValue5(int htOffense, int htDefense, int htHomeSTR, int vtOffense, int vtDefense, int vtRoadSTR) {
	return ((htOffense * htDefense * htHomeSTR * OVERALL_FACTOR) - (vtOffense * vtDefense * vtRoadSTR));
}


// function used in conjunction with the getScore(...){...} function to help predict the winner of the game in question and
	// the score differntial of said game.
		// This function takes all the strengths of both teams playing a game of football and calculates values to be used
			// by the getScore(...){...} function to predict the winner of the respective game, based upon the values assigned
			// to the strengths of each team and the weights given to each strength field and respective formulas
void compute(int htOffense, int htDefense, int htSpecialTeams, int htHomeSTR, int htHomeADV, int vtOffense, int vtDefense, int vtSpecialTeams, int vtRoadSTR, double* predictor1, double* predictor2, double* predictor3, double* predictor4, double* predictor5) {
	*predictor1 = computePredictionValue1(htOffense, vtDefense);
	*predictor2 = computePredictionValue2(htDefense, vtOffense);
	*predictor3 = computePredictionValue3(htSpecialTeams, vtSpecialTeams);
	*predictor4 = computePredictionValue4(htHomeSTR, htHomeADV, vtSpecialTeams);
	*predictor5 = computePredictionValue5(htOffense, htDefense, htHomeSTR, vtOffense, vtDefense, vtRoadSTR);
}


// function used to predict the winner of the football game and the score differential of that game.
	// Negative result = visiting team won by the absolute value of the calculated int
	// Positive result = home team won by the absolute value of the calculated int
int getScore(double predictor1, double predictor2, double predictor3, double predictor4, double predictor5) {
	double difference = ((predictor1 * OFFENSIVE_WORTH) + (predictor2 * DEFENSIVE_WORTH) + (predictor3 * SPECIAL_WORTH) + (predictor4 * HOME_WORTH) + (predictor5 * OVERALL_WORTH));
	return (int)difference;
}
*/
/*
// function used to print to the terminal the name of both teams, which team won and the amount of points the winning team won by
	// Example output: "Cincinnati beat Buffalo by 3"
void printOutput(int differential, char* homeTeamName, char* visitingTeamName) {
	// if statement that checks if the two teams had a tie (score differential of 0)
		// if there was a tie between the two teams, the home team is given the win by 1 (one) point
	if (differential == 0) {
		printf("%s beat %s by 1 \n", homeTeamName, visitingTeamName);
	}
	// else if statement that checks if the score differential was greater than 0 (zero)
		// In this case, the home team won by a score differential equal to the int variable, differential
	else if (differential > 0) {
		printf("%s beat %s by %d \n", homeTeamName, visitingTeamName, differential);
	}
	// else statement that executes if the score differential was a negative number
		// In this case, the visiting team won by the absolute value of the int variable, differential
	else {
		printf("%s beat %s by %d \n", visitingTeamName, homeTeamName, abs(differential));
	}
}
*/
/*
// function used to update the total number of games predicted and if the home team is predicted to win,
	// update the number of home teams predicted to win
void update(int differential, int* totalGames, int* homeWins) {
	// Increment the int counter variable, totalGames
	*totalGames = *totalGames + 1;

	// if statement that checks if the value of the calculated int variable, differential, is positive.
		// If that is the case, increment the value of the int counter variable, homeWins
	if (differential >= 0) {
		*homeWins = *homeWins + 1;
	}
}
*/
/*
// function used to print a summary of all the football games this program was used to predict the results for.
	// This function calculates the percentage of games that home teams are predicted to win and 
		// display that percentage (to 2 decimal places) along with the total number of games this program tried to predict
void printSummary(int totalGames, int homeWins) {
	double homeWinPercentage = (((double)homeWins / totalGames) * 100);
	printf("\nOf %d games, %.2f%% were won by the home team \n\n\n\n", totalGames, homeWinPercentage);
}
*/


/*
Output:
Output from football1.txt:

Cincinnati beat Buffalo by 3
Philadelphia beat Detroit by 10
New_England beat NY_Jets by 3
Minnesota beat Oakland by 6
Kansas_City beat Baltimore by 3
Dallas beat Miami by 7
Atlanta beat Indianapolis by 1
Carolina beat Arizona by 5
Tampa_Bay beat NY_Giants by 13
LA_Chargers beat Houston by 6
New_Orleans beat Seattle by 1
Pittsburgh beat San_Francisco by 10
LA_Rams beat Cleveland by 5

Of 13 games, 53.85% were won by the home team



Output from football2.txt:

Miss_State beat Kansas_St by 14
West_Virginia beat NC_State by 15
Cincinnati beat Miami_OH by 21
Penn_St beat Pitt by 6
Ohio_St beat Indiana by 26
Alabama beat South_Carolina by 31
USC beat BYU by 3
UCF beat Stanford by 13
Iowa beat Iowa_St by 5
Michigan_St beat Arizona_St by 5
Kentucky beat Florida by 1
Clemson beat Syracuse by 13
Purdue beat TCU by 4
Oklahoma beat UCLA by 10

Of 14 games, 57.14% were won by the home team
*/