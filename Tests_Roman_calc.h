#include"Check_string.h"
#include"Dec_to_roman.h"
#include"Roman_to_dec.h"

extern int Roman_calculator(void);

extern char roman_input1[10];
extern char roman_input2[10];
extern char operator;
extern int converted_dec1;
extern int converted_dec2;
extern int calculated_decimal;

int Test_case_1_0();
/* -------------------------------------------------------------------------
** Test Case: 1.0
** Description: This test checks Roman numerals consist of the following  
**      letters: I, V, X, L, C, D, and M only.
** Return: Integer
** Arguments: None
**
** -------------------------------------------------------------------------*/
int Test_case_1_0(){
	int status = 1;
	roman_input1[1] = "A";
	roman_input2[1] = "I";
	operator = "+";
	
	status = Roman_calculator();
	
	if (status == 0)
	{
		printf("Test failed.");
	}
	else
	{
		printf("Test pass.");
	}
}