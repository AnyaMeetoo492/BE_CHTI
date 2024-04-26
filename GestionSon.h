#ifndef GESTIONSON_H
#define GESTIONSON_H

/**
	* @brief 
				récupérer l'échantillon dans la table Son[ ] correspondant à l'index actuel, soit
				Son[GestionSon_Index], Son[] est une table se short int qui s'étend sur toute l'échelle permise,
				- mettre à l'échelle l'échantillon récupéré. La nouvelle échelle est [0 ;719] doit correspondre à
				l'intervalle maximum de l'échantillon (0 correspond au minimum de l'échantillon, 719 au maximum),
				- le résultat sera stockée dans une variable « permanente » en RAM, prévoir pour cela une variable
				globale qu'on appellera SortieSon sur 16bits, elle contiendra la valeur mise à l'échelle de
				l'échantillon courant,
				- la fonction ne doit plus rien faire lorsque tous les échantillons du Son[ ] ont été traités.																													
						
		* @variableglobal  float * Son : tableau d'échantillon son
							int GestionSon_Index : index courant du tableau
							int LongueurSon : longueur du tableau
	
  * @retval SortieSon : son echelonné 
  */
float GestionSon_callback();


/**
	* @brief 
				 permet de lancer la séquence sonore
				 reset GestionSon_Index 
						
		* @param  none
	
  * @retval none
  */
void GestionSon_Start();

#endif