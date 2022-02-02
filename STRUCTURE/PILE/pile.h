#ifndef __PILE__H__
#define __PILE__H__
	


	//STRUCTURE DE DONNER

	struct element{
		int valeur;
		struct element *suivant;
	};
	
	struct pile{
		struct element *actuel;
	};

	// DECLARATION DES TYPE PILE ET ELEMENT
	typedef struct element element;
	typedef struct pile pile;
	
	pile initialisation();	
	void empile(pile *PileFc, int value);
	void depile(pile *PileFc);
	void depileTout(pile *PileFc);
	void affichePile(pile *PileFc);	

#endif
