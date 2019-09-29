#include "Football.h"


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