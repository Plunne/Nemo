#include <stdio.h>
#include <stdlib.h>

int* fusion(int *vect1, int taille1, int *vect2, int taille2) {
	//Ecrire le code de la fonction
	if((vect1 == NULL) || (vect2 == NULL))
	{
		exit(EXIT_FAILURE);
	}

	int idx_vect1 = 0;
	int idx_vect2 = 0;

	int retVect_size = taille1 + taille2;
	int* retVect = (int*) malloc(retVect_size * sizeof(int));

	for (int i=0; i < retVect_size; i++)
	{
		if ((idx_vect1 < taille1) && (idx_vect2 < taille2))
		{
			if (*(vect1 + idx_vect1) < *(vect2 + idx_vect2))
			{
				*(retVect + i) = *(vect1 + idx_vect1);
				idx_vect1++;
			}
			else
			{
				*(retVect + i) = *(vect2 + idx_vect2);
				idx_vect2++;
			}
		}
		else if ((idx_vect2 < taille2) && (idx_vect1 >= taille1))
		{
			*(retVect + i) = *(vect2 + idx_vect2);
			idx_vect2++;
		}
		else
		{
			*(retVect + i) = *(vect1 + idx_vect1);
			idx_vect1++;
		}
	}

	return retVect;
}

int main(void)
{
    return 0;
}