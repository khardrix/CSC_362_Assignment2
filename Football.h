#define _CRT_SECURE_NO_WARNINGS
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

double computePredictionValue1(int, int);
double computePredictionValue2(int, int);
double computePredictionValue3(int, int);
double computePredictionValue4(int, int, int);
double computePredictionValue5(int, int, int, int, int, int);

void compute(int, int, int, int, int, int, int, int, int, double *, double *, double *, double *, double *);

int getScore(double, double, double, double, double);

void printOutput(int, char*, char*);

void update(int, int *, int *);

void printSummary(int, int);
/* -------------------------------------------- END OF FUNCTION PROTOTYPES ------------------------------------------ */