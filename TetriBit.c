//Mărgineanu Adrian 313CB
#include <stdio.h>
#include <math.h>
#define wall_L 257
#define wall_R 32896
//Functie de afisarea hartii
int Harta (unsigned long long H)
{
	int i, nr = 0;
	for (i = 63 ; i >= 0 ; i --)
	{
		if (((H >> i) & 1) == 1) 
			printf ("#");
		else
		{ 
			printf (".");
			nr ++;
		}			
		if (i % 8 == 0)
			printf ("\n");
	}
	printf("\n");
	return nr;
}
int main ()
{
	unsigned long long copy1, H, piece, verify; 
	int i, M, move, numardelinii, zerosNumber, ok;					
	float score = 0;
	short line;
	scanf ("%llu%d", &H,&M); 
	numardelinii = 0;
	zerosNumber = Harta (H);
	//Executam fiecare linie 
	while (M > 0)	
	{
		scanf ("%llu", &piece);
		//Executam miscare a piesei 
		for (i = 7; i >= 0; i--)
		{
			scanf ("%d", &move);
			line = (short)(H >> (i * 8));
			if ((piece & line) == 0)
			{
				//Executam miscarea la dreapta
				while (move > 0)
				{
					if (((piece >> 1) & line) != 0 || (piece & wall_L) != 0)
						break;
					piece = piece >> 1;
					move --;
				}
				//Executam miscarea la stanga
    			while (move < 0)
    			{
    				if (((piece << 1) & line) != 0 || (piece & wall_R) != 0)
    					break;
    				piece = piece << 1;
    				move ++;
    			}
				copy1 = H | (piece << (i * 8));
				zerosNumber = Harta (copy1);
			}
			else //Coliziune
			{
				//Caz ca nu incape piece pe harta
				if (((piece >> 8 ) != 0 && i == 6) | (i ==7))
				{
					M = 0;
					zerosNumber = Harta (copy1);
					break;
				}
				//Coliziune simpla
				while (i > 0)
				{
					scanf ("%d", &move);
					i --;
				}
			}
		}
		H = copy1;
		ok = 0;
		//Taierea liniilor
		for (i = 0; i<=7; i++)
		{	
			line = (short)(H >> (i * 8));
			verify = 255 & line;
			if (verify == 255)
			{
				H = H ^ (verify << (i * 8));
				numardelinii ++;
				copy1 = (H >> (i * 8 + 8)) << (i*8);
				H = copy1 | (H << (63 - i * 8)) >> (63 - i*8);
				i --;
				ok = 1;
			}
		}
		//Verificarea daca a fost taiata linia
		if (ok == 1)
			zerosNumber = Harta (H);
		M --;
	}	
	// Punctajul
	score = sqrt(zerosNumber) + pow(1.25 , numardelinii);
	printf ("GAME OVER!\nScore:%.2f", score);
	return 0;
}