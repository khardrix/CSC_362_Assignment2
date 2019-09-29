#include "Football.h"


// This function gets one line of input from the football file currently being read, about individual games (one line of input per game)
void getInput(FILE* fp, char* htn, int* hto, int* htd, int* hts, int* hth, int* hfa, char* vtn, int* vto, int* vtd, int* vts, int* vtr) {
	fscanf(fp, "%s %d %d %d %d %d %s %d %d %d %d", htn, hto, htd, hts, hth, hfa, vtn, vto, vtd, vts, vtr);
}


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


// function used to print a summary of all the football games this program was used to predict the results for.
	// This function calculates the percentage of games that home teams are predicted to win and 
		// display that percentage (to 2 decimal places) along with the total number of games this program tried to predict
void printSummary(int totalGames, int homeWins) {
	double homeWinPercentage = (((double)homeWins / totalGames) * 100);
	printf("\nOf %d games, %.2f%% were won by the home team \n\n\n\n", totalGames, homeWinPercentage);
}