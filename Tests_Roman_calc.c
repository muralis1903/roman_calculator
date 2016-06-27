#include "Check_string.h"
#include "Dec_to_roman.h"
#include "Roman_to_dec.h"
#include "utilities.h"

void Test_case_1_0();
void Test_case_2_0();
void Test_case_3_0();
void Test_case_4_0();
void Test_case_5_0();
void Test_case_6_0();
void Test_case_7_0();
void Test_case_8_0();
void Test_case_9_0();
void Test_case_10_0();
void Test_case_11_0();
void Test_case_12_0();
void Test_case_13_0();
void Test_case_14_0();
void Test_case_15_0();

Start_Test(){
	Test_Begin();

	Test_case_1_0();
 	Test_case_2_0();
	Test_case_3_0();
	Test_case_4_0();
	Test_case_5_0();
	Test_case_6_0();
	Test_case_7_0();
	Test_case_8_0();				
	Test_case_9_0();
	Test_case_10_0();
	Test_case_11_0();
 	Test_case_12_0();
	Test_case_13_0();
	Test_case_14_0();
//	Test_case_15_0();
//	Test_case_16_0();
//	Test_case_17_0();
//	Test_case_18_0();				
//	Test_case_19_0();
//	Test_case_20_0();	
	
	Test_Complete();
}

/* -------------------------------------------------------------------------
** Test Case: 1.0
** Description: This test checks Roman numerals consist of the following  
**      letters: I, V, X, L, C, D, and M only.
** Return: Integer
** Arguments: None
**
** -------------------------------------------------------------------------*/
void Test_case_1_0(){
	int tcnum = 1;
	int i = 0;
	int function_return = -1;
	char *roman_chars[] = {"I", "V", "X", "L", "C", "D", "M"};
	int n = sizeof(roman_chars)/sizeof(roman_chars[0]);
	
	test_header(tcnum ,"This test checks if Roman numerals consist of the I, V,\
 X, L, C, D and M only.\n");
	
	for (i=0; i<n; i++){
		function_return = check_string(roman_chars[i]);
		 
		Test_compare_int(function_return, 0);
		
	}
	Test_case_complete();
}

/* -------------------------------------------------------------------------
** Test Case: 2.0
** Description: This test checks Roman numerals does not consist of the following  
**      letters: A, B, E, F, G, H, J, K, N, O, P, Q, R, S, T, U, W, Y and Z.
** Return: Integer
** Arguments: None
**
** -------------------------------------------------------------------------*/
void Test_case_2_0(){
	int tcnum = 2;
	int i = 0;
	int function_return = -1;
	char *non_roman_chars[] = {"A", "B", "E", "F", "G", "H", "J", "K", "N", 
	"O", "P", "Q", "R", "S", "T", "U", "W", "Y", "Z"};
	int n = sizeof(non_roman_chars)/sizeof(non_roman_chars[0]);
	
	test_header(tcnum ,"This test checks if Roman numerals does not consist of \
A, B, E, F, G, H, J, K, N, O, P, Q, R, S, T, U, W, Y and Z.\n");
	
	for (i=0; i<n; i++){
		function_return = check_string(non_roman_chars[i]);
		Test_compare_int(function_return, 1);
	}
	Test_case_complete();
}
/* -------------------------------------------------------------------------
** Test Case: 3.0
** Description: This test checks Roman numerals does not consist of the following  
**      special characters: +, -, ~, !, @, #, $, %, ^, &, *, (, )
** Return: Integer
** Arguments: None
**
** -------------------------------------------------------------------------*/
void Test_case_3_0(){
	int tcnum = 3;
	int i = 0;
	int function_return = -1;
	char *non_roman_chars[] = {"+", "-", "~", "!", "@", "#", "$", "%", "^", "&",
	 "*", "(", ")"};
	int n = sizeof(non_roman_chars)/sizeof(non_roman_chars[0]);
	
	test_header(tcnum ,"This test checks if Roman numerals does not consist of \
+, -, ~, !, @, #, $, %, ^, &, *, (, ).\n");
	
	for (i=0; i<n; i++){
		function_return = check_string(non_roman_chars[i]);
		Test_compare_int(function_return, 1);
	}
	Test_case_complete();
}
/* -------------------------------------------------------------------------
** Test Case: 4.0
** Description: This test checks decimal value of Roman numerals.
** Return: Integer
** Arguments: None
**
** -------------------------------------------------------------------------*/
void Test_case_4_0(){
	int tcnum = 4;
	int i = 0;
	int function_return = -1;
	int dec_val_roman[] = {1, 5, 10, 50, 100, 500, 1000};
	char *roman_chars[] = {"I", "V", "X", "L", "C", "D", "M"};
	int n = sizeof(roman_chars)/sizeof(roman_chars[0]);
	
	test_header(tcnum ,"This test checks decimal value of Roman numerals.\n");
	
	for (i=0; i<n; i++){
		function_return = digit(*roman_chars[i]);
		 
		Test_compare_int(function_return, dec_val_roman[i]);
	}
	Test_case_complete();
}
/* -------------------------------------------------------------------------
** Test Case: 5.0
** Description: This test checks occurence of I, X or C
** Return: Integer
** Arguments: None
**
** -------------------------------------------------------------------------*/
void Test_case_5_0(){
	int tcnum = 5;
	int i = 0;
	int function_return = -1;
	char *roman_chars[] = {"III", "XXX", "CCC"};
	int n = sizeof(roman_chars)/sizeof(roman_chars[0]);
	
	test_header(tcnum ,"This test checks occurence of I, X or C.\n");
	
	for (i=0; i<n; i++){
		function_return = check_string(roman_chars[i]);
		 
		Test_compare_int(function_return, 0);
	}
	Test_case_complete();
}

/* -------------------------------------------------------------------------
** Test Case: 6.0
** Description: This test checks occurence of I, X or C is more than 3 then 
**         the functions returns error.
** Return: Integer
** Arguments: None
**
** -------------------------------------------------------------------------*/
void Test_case_6_0(){
	int tcnum = 6;
	int i = 0;
	int function_return = -1;
	char *roman_chars[] = {"IIII", "XXXX", "CCCC"};
	int n = sizeof(roman_chars)/sizeof(roman_chars[0]);
	
	test_header(tcnum ,"This test checks occurence of I, X or C is more than 3 then \n\
the functions returns error.\n");
	
	for (i=0; i<n; i++){
		function_return = check_string(roman_chars[i]);
		 
		Test_compare_int(function_return, 1);
	}
	Test_case_complete();
}

/* -------------------------------------------------------------------------
** Test Case: 7.0
** Description: This test checks occurence of I, X or C is more than 3 and  
**         includes other valid Roman numerals then the functions returns error.
** Return: Integer
** Arguments: None
**
** -------------------------------------------------------------------------*/
void Test_case_7_0(){
	int tcnum = 7;
	int i = 0;
	int function_return = -1;
	char *roman_chars[] = {"IDIII", "XXVXX", "CCCIC"};
	int n = sizeof(roman_chars)/sizeof(roman_chars[0]);
	
	test_header(tcnum ,"This test checks occurence of I, X or C is more than 3 then \
and includes other valid Roman numerals then the functions returns error.\n");
	
	for (i=0; i<n; i++){
		function_return = check_string(roman_chars[i]);
		 
		Test_compare_int(function_return, 1);
	}
	Test_case_complete();
}
/* -------------------------------------------------------------------------
** Test Case: 8.0
** Description: This test checks occurence of V, L or D
** Return: Integer
** Arguments: None
**
** -------------------------------------------------------------------------*/
void Test_case_8_0(){
	int tcnum = 8;
	int i = 0;
	int function_return = -1;
	char *roman_chars[] = {"V", "L", "D"};
	int n = sizeof(roman_chars)/sizeof(roman_chars[0]);
	
	test_header(tcnum ,"This test checks occurence of V, L or D.\n");
	
	for (i=0; i<n; i++){
		function_return = check_string(roman_chars[i]);
		 
		Test_compare_int(function_return, 0);
	}
	Test_case_complete();
}

/* -------------------------------------------------------------------------
** Test Case: 9.0
** Description: This test checks occurence of V, L or D is more than 1 then 
**         the functions returns error.
** Return: Integer
** Arguments: None
**
** -------------------------------------------------------------------------*/
void Test_case_9_0(){
	int tcnum = 9;
	int i = 0;
	int function_return = -1;
	char *roman_chars[] = {"VV", "LL", "DD"};
	int n = sizeof(roman_chars)/sizeof(roman_chars[0]);
	
	test_header(tcnum ,"This test checks occurence of V, L or D is more than 1 then \
the functions returns error.\n");
	
	for (i=0; i<n; i++){
		function_return = check_string(roman_chars[i]);
		 
		Test_compare_int(function_return, 1);
	}
	Test_case_complete();
}

/* -------------------------------------------------------------------------
** Test Case: 10.0
** Description: This test checks occurence of V, L or D is more than 3 and  
**         includes other valid Roman numerals then the functions returns error.
** Return: Integer
** Arguments: None
**
** -------------------------------------------------------------------------*/
void Test_case_10_0(){
	int tcnum = 10;
	int i = 0;
	int function_return = -1;
	char *roman_chars[] = {"VIV", "LCL", "DXDIVC"};
	int n = sizeof(roman_chars)/sizeof(roman_chars[0]);
	
	test_header(tcnum ,"This test checks occurence of V, L or D is more than 1 then \
and includes other valid Roman numerals then the functions returns error.\n");
	
	for (i=0; i<n; i++){
		function_return = check_string(roman_chars[i]);
		 
		Test_compare_int(function_return, 1);
	}
	Test_case_complete();
}
/* -------------------------------------------------------------------------
** Test Case: 11.0
** Description: This test checks the roman number does not contain decimal.
** Return: Integer
** Arguments: None
**
** -------------------------------------------------------------------------*/
void Test_case_11_0(){
	int tcnum = 11;
	int i = 0;
	int function_return = -1;
	char *roman_chars[] = {"V.V", ".L", ".C"};
	int n = sizeof(roman_chars)/sizeof(roman_chars[0]);
	
	test_header(tcnum ,"This test checks the roman number does not contain decimals.\n");
	
	for (i=0; i<n; i++){
		function_return = check_string(roman_chars[i]);
		 
		Test_compare_int(function_return, 1);
	}
	Test_case_complete();
}

/* -------------------------------------------------------------------------
** Test Case: 12.0
** Description: This test checks the roman number does not contain integers.
** Return: Integer
** Arguments: None
**
** -------------------------------------------------------------------------*/
void Test_case_12_0(){
	int tcnum = 12;
	int i = 0;
	int function_return = -1;
	char *roman_chars[] = {"V.0", "123.L", "D.4"};
	int n = sizeof(roman_chars)/sizeof(roman_chars[0]);
	
	test_header(tcnum ,"This test checks the roman number does not contain integers.\n");
	
	for (i=0; i<n; i++){
		function_return = check_string(roman_chars[i]);
		 
		Test_compare_int(function_return, 1);
	}
	Test_case_complete();
}
/* -------------------------------------------------------------------------
** Test Case: 13.0
** Description: This test checks if a lesser numeral is put before a bigger,
** then it means substraction.
** Return: Integer
** Arguments: None
**
** -------------------------------------------------------------------------*/
void Test_case_13_0(){
	int tcnum = 13;
	int i = 0;
	int function_return = -1;
	char *roman_chars[] = {"IV", "IX", "IL", "IC", "ID", "IM", "VX", "VL", "VC",
	 "VD", "VM", "XL", "XC", "XD", "XM", "LC", "LD", "LM", "CD", "CM", "DM"};
	int dec_val_roman[] = {4, 9, 49, 99, 499, 999, 5, 45, 95, 495, 995,
	                        40, 90, 490, 990, 50, 450, 950, 400, 900, 500};	 
	int n = sizeof(roman_chars)/sizeof(roman_chars[0]);
	
	test_header(tcnum ,"This test checks if a lesser numeral is put before a\
bigger, then it means substraction.\n");
	
	for (i=0; i<n; i++){
		function_return = Roman_to_dec(roman_chars[i]);
		 
		Test_compare_int(function_return, dec_val_roman[i]);
	}
	Test_case_complete();
}
/* -------------------------------------------------------------------------
** Test Case: 14.0
** Description: This test checks the value when nuemrals are concatenated.
** Return: Integer
** Arguments: None
**
** -------------------------------------------------------------------------*/
void Test_case_14_0(){
	int tcnum = 14;
	int i = 0;
	int function_return = -1;
	char *roman_chars[] = {"VI", "XI", "LI", "CI", "DI", "MI", "XV", "LV", "CV",
	 "DV", "MV", "LX", "CX", "DX", "MX", "CL", "DL", "ML", "DC", "MC", "MD", "MM"};
	int dec_val_roman[] = {6, 11, 51, 101, 501, 1001, 15, 55, 105, 505, 1005,
	  60, 110, 510, 1010, 150, 550, 1050, 600, 1100, 1500, 2000};	 
	int n = sizeof(roman_chars)/sizeof(roman_chars[0]);
	
	test_header(tcnum ,"This test checks if a lesser numeral is put before a\
bigger, then it means substraction.\n");
	
	for (i=0; i<n; i++){
		function_return = Roman_to_dec(roman_chars[i]);
		 
		Test_compare_int(function_return, dec_val_roman[i]);
	}
	Test_case_complete();
}
