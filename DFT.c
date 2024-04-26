#include "DFT.h"

float power(float num){
	return num*num;
}

float DFT(float * Signal, int k){
	
	float Im = 0, Re = 0;
	int M = 64;
	int index;
	for (int i=0; i<M; i++){
			index = (k*i) % 64;
		
			Im += Signal[i]*(TabCos[index])
			Re += Signal[i]*(TabSin[index]);
	}
	return power(Im) + power(Re);
}


