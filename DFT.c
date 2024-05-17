#include "DFT.h"

int DFT(short * Signal, int k){
	
	long long Im = 0, Re = 0;
	int M = 64;
	int index;
	for (int i=0; i<M; i++){
			index = (k*i) % 64;
			
		// Im et Re en format 5,27 car Signal 4,12 et Tab 1,15		
			Im += (int)Signal[i]*(int)TabCos[index];
			Re += (int)Signal[i]*(int)TabSin[index];
	}
	// return format 10,54
	return ((Im*Im) + (Re*Re)) >> 32;
}


