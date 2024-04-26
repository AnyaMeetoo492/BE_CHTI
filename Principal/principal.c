

#include "DriverJeuLaser.h"
#include "ServiceJeuLaser.h"

extern int PeriodeSonMicroSec;
extern float LeSignal[64];
extern void GestionSon_callback(void);
extern void GestionSon_Start();
extern float DFT(float*, int);

	
// void callback(){}

int main(void)
{
	float DFT_result[64];
	float signal[64];
// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

/* Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers */
CLOCK_Configure();

/* Configuration du son (voir ServiceJeuLaser.h) 
 Insérez votre code d'initialisation des parties matérielles gérant le son ....*/	

//ServJeuLASER_Son_Init(PeriodeSonMicroSec, 0, GestionSon_callback);
//GestionSon_Start();
	
for (int i=0;i<64;i++){
	signal[i] = 0.5*LeSignal[i];
}
	
for (int k = 0; k<64; k++){
	DFT_result[k] = DFT(LeSignal, k);
}
	
while	(1)
	{
	}
}




