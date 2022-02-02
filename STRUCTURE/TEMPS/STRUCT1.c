#include <stdio.h>
#include <stdlib.h>

//1
struct T
{	int seconde;
	int centieme;};
	
//2	
typedef struct T Temps;

//4
Temps fabriquer_temps(int s, int c)
{		Temps t;
		t.seconde = s;
		t.centieme = c;
		return t; }

//5
void afficher_temps(Temps t)
{		printf("Temps : %d,%d s\n",t.seconde,t.centieme);
	
	 }

//6
int temps_centieme(Temps t)
{		return t.seconde*100+t.centieme; 
	
	}

//8
void tableanumero (Temps tab[], int couloir, Temps t){
	tab[couloir]=t;
	printf("Numéro du coureur: %d\n",couloir);
	afficher_temps(t);
	printf("Temps en centiemes: %d\n",temps_centieme(t));
}

//8bis  

//9
int numerogagant(Temps* t, int taille){
	int gagnant;
	int i=0;
	for(int y=0; y<taille;y++){
		if(y!=i){
			if(tempsCent(t[i])>tempsCent(t[y])){
				i=y;
			}

		}
		gagnant=i+1;
	}
	return gagnant; 
}

//10
void moyenne(Temps t1, Temps t2, Temps t3, Temps t4,Temps t5, Temps t6, Temps t7, Temps t8){
	t1=afficher_temps(t1);
	t2=afficher_temps(t2);
	t3=afficher_temps(t3);
	t4=afficher_temps(t4);
	t5=afficher_temps(t5);
	t6=afficher_temps(t6);
	t7=afficher_temps(t7);
	t8=afficher_temps(t8);
	moyenne=(t1+t2+t3+t4+t5+t6+t7+t8)/8;
	printf("Moyenne : \n",moyenne );
}


//11

//12

//13


int main()
{
	//3
	Temps t;
	t.seconde=10;
	t.centieme=08;
	afficher_temps(t);
	
	//7
	Temps t1,t2,t3,t4,t5,t6,t7,t8;
	Temps tab[8];
	t1=fabriquer_temps(12,12);
	
	//8
	t1=fabriquer_temps(10,04);
	tableanumero(tab,1,t1);
	t2=fabriquer_temps(9,96);
	tableanumero(tab,2,t2);
	t3=fabriquer_temps(9,91);
	tableanumero(tab,3,t3);
	t4=fabriquer_temps(9,81);
	tableanumero(tab,4,t4);
	t5=fabriquer_temps(9,89);
	tableanumero(tab,5,t5);
	t6=fabriquer_temps(9,93);
	tableanumero(tab,6,t6);
	t7=fabriquer_temps(10,06);
	ttableanumero(tab,7,t7);
	t8=fabriquer_temps(9,94);
	tableanumero(tab,8,t8);
	
	
	return 0; 
}
