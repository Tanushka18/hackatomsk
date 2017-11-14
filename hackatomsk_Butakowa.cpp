#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

using namespace std;


int calc(int x){
	usleep( 0 + rand() % 1000);
	return (2 * x);
}

int main(){
	int result[10];
	omp_set_num_threads( 10 );
	#pragma omp parallel 
	{
		#pragma omp for 
	for(int i=0; i<10; i++){
		int thread_ID = omp_get_thread_num();
		result[omp_get_thread_num()] = calc(i);}
	
	}

	for(int i=0; i<10; i++){
		cout << result[i] <<endl;
	}

}
