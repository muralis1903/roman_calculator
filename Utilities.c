#include "utilities.h"

void Test_Begin();
void Test_Complete();
void Test_compare_int(int, int);
void Test_compare_string(char*, char*);

static int Test_Cases_Passed = 0;
static int Test_Cases_Failed = 0;
static int Total_Test_Cases = 0;
static int tests_pass = 0;
static int tests_fail = 0;
static float testnum = 1;

/* -------------------------------------------------------------------------
** function: Test_Begin()
** Description: This function is the entry point into tests.
** Return: None
** Arguments: None
**
** -------------------------------------------------------------------------*/
void Test_Begin(){
	
	printf("\n\n*********************************\n");
	printf("Starting tests. \n");
	printf("*********************************\n\n");
	
	Test_Cases_Passed = 0;
	Test_Cases_Failed = 0;
	Total_Test_Cases = 0;
	tests_fail = 0;
	tests_pass = 0;
	testnum = 1.0;
	
	FILE *f = fopen("roman_calculator.txt", "w");
	if (f == NULL)
	{
	    printf("Error opening file!\n");
	    exit(1);
	}

	fprintf(f, "\n\n*********************************\n");
	fprintf(f, "Starting tests..... \n");
	fprintf(f, "*********************************\n\n");
	
	fclose(f);	
}

/* -------------------------------------------------------------------------
** function: Test_Complete()
** Description: This function is the end point in tests.
** Return: None
** Arguments: None
**
** -------------------------------------------------------------------------*/
void Test_Complete() {
	
	printf("\n*********************************\n");
	printf("Total Test Cases  : %d\n", Total_Test_Cases);
	printf("Tests Cases Passed: %d\n", Test_Cases_Passed);
	printf("Tests Cases Failed: %d\n", Test_Cases_Failed);
	printf("*********************************\n\n");
	
	FILE *f = fopen("roman_calculator.txt", "a");
	if (f == NULL)
	{
	    printf("Error opening file!\n");
	    exit(1);
	}

    fprintf(f, "\n*********************************\n");
	fprintf(f, "Total Test Cases  : %d\n", Total_Test_Cases);
	fprintf(f, "Tests Cases Passed: %d\n", Test_Cases_Passed);
	fprintf(f, "Tests Cases Failed: %d\n", Test_Cases_Failed);
	fprintf(f, "*********************************\n\n");

	fclose(f);
}

/* -------------------------------------------------------------------------
** function: Test_compare_int()
** Description: This function compares two integers and increments Tests_Passed
**    variable by 1 if integers are equal else increments Test_Cases_Failed.
** Return: None
** Arguments: int, int
**
** -------------------------------------------------------------------------*/
void Test_compare_int(int Actual, int Expected) {
	
	FILE *f = fopen("roman_calculator.txt", "a");
	if (f == NULL)
	{
	    printf("Error opening file!\n");
	    exit(1);
	}

	if (Actual == Expected) {
        tests_pass++;
        printf("\n Test Pass \n");
        fprintf(f, "\n Test Pass \n");
  	
    }
    else {

		tests_fail++;
		printf("\n Test Fail \n");
		printf("Actual value:%2d, Expected Value:%2d",Actual, Expected);
		fprintf(f, "\n Test Fail \n");
		fprintf(f, "Actual value:%2d, Expected Value:%2d",Actual, Expected);
      	
    }
    
   	fclose(f);
}

/* -------------------------------------------------------------------------
** function: Test_compare_string()
** Description: This function compares two strings and increments Tests_Passed
**    variable by 1 if strings are same else increments Test_Cases_Failed.
** Return: None
** Arguments: char, char
**
** -------------------------------------------------------------------------*/
void Test_compare_string(char* ActualString, char* ExpectedString) {
	int cmp = strcmp(ActualString, ExpectedString);
    
	FILE *f = fopen("roman_calculator.txt", "a");
	if (f == NULL)
	{
	    printf("Error opening file!\n");
	    exit(1);
	}
		
    if(cmp == 0) {

        tests_pass++;
        printf("\n Test Pass \n"); 
		fprintf(f, "\n Test Pass \n");      	
    }
    else {

		tests_fail++;
		printf("\n Test Fail \n");
		printf("Actual String: %2s, Expected String: %2s",ActualString, ExpectedString);
		fprintf(f, "\n Test Fail \n");
		fprintf(f, "Actual String: %2s, Expected String: %2s",ActualString, ExpectedString);     	
    }
    
   	fclose(f);	
}
/* -------------------------------------------------------------------------
** function: test_header()
** Description: This function compares two strings and increments Tests_Passed
**    variable by 1 if strings are same else increments Test_Cases_Failed.
** Return: None
** Arguments: char, char
**
** -------------------------------------------------------------------------*/
void test_header(int tc, char* input) {

	printf("\n*********************************\n");
	printf("Test Case Number %d : \n\n", tc);
	printf("%s", input)	;
	
	FILE *f = fopen("roman_calculator.txt", "a");
	if (f == NULL)
	{
	    printf("Error opening file!\n");
	    exit(1);
	}
	
	fprintf(f, "\n*********************************\n");
	fprintf(f, "Test Case Number %d : \n\n", tc);
	fprintf(f, "%s", input)	;	
	    
   	fclose(f);
}
/* -------------------------------------------------------------------------
** function: Test_case_complete()
** Description: This function captures the numbers for each test case.
** Return: None
** Arguments: None
**
** -------------------------------------------------------------------------*/
void Test_case_complete() {
	
	Total_Test_Cases++;
	
	if (tests_fail > 0) {
		Test_Cases_Failed++;
	}
	else {
	
		Test_Cases_Passed++;	
	}	
}
