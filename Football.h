#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>

/* ---------------------------------------------- CONSTANT DECLARATIONS --------------------------------------------- */
#define OFFENSIVE_FACTOR 1.15
#define SPECIAL_TEAMS_FACTOR 1.22
#define HOME_FIELD_ADVANTAGE 1.2
#define OVERALL_FACTOR 1.15
#define OFFENSIVE_WORTH 0.30
#define DEFENSIVE_WORTH 0.24
#define SPECIAL_WORTH 0.17
#define HOME_WORTH 0.11
#define OVERALL_WORTH 0.13
/* ------------------------------------------- END OF CONSTANT DECLARATIONS ----------------------------------------- */


/* ----------------------------------------------- FUNCTION PROTOTYPES ---------------------------------------------- */
// Used to read in each line of input from specified file and assign values to their respective variables
void getInput(FILE*, char*, int*, int*, int*, int*, int*, char*, int*, int*, int*, int*);

// Used to calculate the value of the double variable, predictor1, which is called in the compute(...){...} function 
double computePredictionValue1(int, int);
// Used to calculate the value of the double variable, predictor2, which is called in the compute(...){...} function
double computePredictionValue2(int, int);
// Used to calculate the value of the double variable, predictor3, which is called in the compute(...){...} function
double computePredictionValue3(int, int);
// Used to calculate the value of the double variable, predictor4, which is called in the compute(...){...} function
double computePredictionValue4(int, int, int);
// Used to calculate the value of the double variable, predictor5, which is called in the compute(...){...} function
double computePredictionValue5(int, int, int, int, int, int);
// Used to calculate all the values of the double variables, [predictor1, predictor2 ... predictor5]
void compute(int, int, int, int, int, int, int, int, int, double *, double *, double *, double *, double *);

// Used to calculate the predicted score differential of a football game 
int getScore(double, double, double, double, double);

// Used to print the predicted outcome of an individual football game
void printOutput(int, char*, char*);

// Used to update the int counter variable, totalGames. Also update homeWins, if the home team won
void update(int, int *, int *);

// Used to print a summary of all the football games predicted with the specific input file.
void printSummary(int, int);
/* -------------------------------------------- END OF FUNCTION PROTOTYPES ------------------------------------------ */