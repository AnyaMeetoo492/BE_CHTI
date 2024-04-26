#ifndef GESTIONSON_H
#define GESTIONSON_H

/**
	* @brief 
				r�cup�rer l'�chantillon dans la table Son[ ] correspondant � l'index actuel, soit
				Son[GestionSon_Index], Son[] est une table se short int qui s'�tend sur toute l'�chelle permise,
				- mettre � l'�chelle l'�chantillon r�cup�r�. La nouvelle �chelle est [0 ;719] doit correspondre �
				l'intervalle maximum de l'�chantillon (0 correspond au minimum de l'�chantillon, 719 au maximum),
				- le r�sultat sera stock�e dans une variable � permanente � en RAM, pr�voir pour cela une variable
				globale qu'on appellera SortieSon sur 16bits, elle contiendra la valeur mise � l'�chelle de
				l'�chantillon courant,
				- la fonction ne doit plus rien faire lorsque tous les �chantillons du Son[ ] ont �t� trait�s.																													
						
		* @variableglobal  float * Son : tableau d'�chantillon son
							int GestionSon_Index : index courant du tableau
							int LongueurSon : longueur du tableau
	
  * @retval SortieSon : son echelonn� 
  */
float GestionSon_callback();


/**
	* @brief 
				 permet de lancer la s�quence sonore
				 reset GestionSon_Index 
						
		* @param  none
	
  * @retval none
  */
void GestionSon_Start();

#endif