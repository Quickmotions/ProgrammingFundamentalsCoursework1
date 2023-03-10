// Author: Simon Powers
// Date of last modification: 28/02/2023
// Test 2 for Coursework 1.
#include <stdio.h>

// Calculates the mean of an array of integers.
// Parameters:
// items : array of ints
// num_items : size of the array
int average ( int items [ ] , int num_items )
{
	int total = 0 ;
	for ( int i = 0 ; i < num_items ; i++ )
	{
		total += items [ i ] ;
	}
	return total / num_items ;
}

int main ( )
{
	char * msg = "Hello world!" ;
	int grades [ 5 ] = { 100 , 90 , 80, 70, 0 } ; // Array of student grades.
	int av_grade = average ( grades , 5 ) ; // Call average function.
	printf ( "Average grade: %d\n" , av_grade ) ;
	return 0 ;
}