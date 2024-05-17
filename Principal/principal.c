#include "DriverJeuLaser.h"
#include "ServiceJeuLaser.h"

#define SEUIL 0x000FFFFF

extern int PeriodeSonMicroSec;
extern short LeSignal[64];
extern void GestionSon_callback(void);
extern void GestionSon_Start(void);
int DFT(short*, int);

static short Signal[64];
static int DFT_result[64];
static int DFT_result_previous[64];

extern void Init_Affichage(void);
extern void Prepare_Afficheur(char Aff, char Valeur);
extern void Prepare_Set_Point_Unite(char Aff);
extern void Prepare_Clear_Point_Unite(char Aff);
extern void Prepare_Set_LED(char LED);
extern void Prepare_Clear_LED(char LED);
extern void Mise_A_Jour_Afficheurs_LED(void);
extern void Choix_Capteur(char Capteur);

//int fq[6] = {85,90,95,100,115,120};
int raie[6] = {17,18,19,20,23,24};
int score[6] = {0,0,0,0,0,0};

void Gestion_score(int DFT_result_score[64]){
	for (int i = 0; i<6 ; i++){
		if (DFT_result_score[raie[i]] >= SEUIL && DFT_result_previous[raie[i]]< SEUIL){
			score[i]++;
			
		}
	}
	for (int j=0; j<64; j++){
		DFT_result_previous[j] = DFT_result_score[j];
	}
}

void callback(void){
	ServJeuLASER_StartDMA();
	for (int k = 0; k<64; k++){
		DFT_result[k] = DFT(Signal, k);
	}
	Gestion_score(DFT_result);
}

int main(void)
{
	//long long DFT_result[64];
	//float signal[64];
// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

/* Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers */
CLOCK_Configure();

/* Configuration du son (voir ServiceJeuLaser.h) 
 Insérez votre code d'initialisation des parties matérielles gérant le son ....*/	
ServJeuLASER_ADC_DMA(Signal);
ServJeuLASER_Systick_IT_Init(5000, 1, callback);
Init_Affichage();

ServJeuLASER_Son_Init(PeriodeSonMicroSec, 0, GestionSon_callback);
GestionSon_Start();

//for (int i=0;i<64;i++){
//signal[i] = 0.5*LeSignal[i];
//}
	
//for (int k = 0; k<64; k++){
//	DFT_result[k] = DFT(LeSignal, k);
//}
//Gestion_score(DFT_result);


	
while	(1)
	{
	}
}




