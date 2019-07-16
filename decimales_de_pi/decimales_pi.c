#include <stdlib.h>
#include <stdio.h>
int main (void)
{
	system("clear");
	int aux = 0;
	int cont = 0;
	int pista = 3;
	char cadena[100];
	FILE *fp;
	FILE *sc;
	FILE *end;
	FILE *po;
	char caracter;
	fp = fopen ( "titulo.txt", "r" );
	while((caracter = fgetc(fp)) != EOF)
		printf("%c",caracter);
	fclose(fp);
	po = fopen ("points.txt", "r");
	char p1[10];
	char p2[10];
	char p3[10];
	while((caracter = fgetc(po)) != EOF)
	{
		cont++;
		if (cont <= 10)
			p1[cont -1] = caracter;
		if (cont > 10 && cont <= 20)
			p2[cont - 11] = caracter;
		if (cont > 20 && cont <= 30)
			p3[cont - 21] = caracter;
	}
	fclose(po);
	int player1 = 0;
	int player2 = 0;
	int player3 = 0;
	int i;
	for (i = 0; i < 3; i++)
		player1 = (player1 * 10) + (p1[i + 6] - '0');
	for (i = 0; i < 3; i++)
		player2 = (player2 * 10) + (p2[i + 6] - '0');
	for (i = 0; i < 3; i++)
		player3 = (player3 * 10) + (p3[i + 6] - '0');
	/* printf("%d\n", player1); */
	/* printf("%d\n", player2); */
	/* printf("%d\n", player3); */
	char *pi = "3,141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609433057270365759591953092186117381932611793105118548074462379962749567351885752724891227938183011949129833673362440656643086021394946395224737190702179860943702770539217176293176752384674818467669405132000568127145263560827785771342757789609173637178721468440901224953430146549585371050792279689258923542019956112129021960864034418159813629774771309960518707211349999998372978049951059731732816096318595024459455346908302642522308253344685035261931188171010003137838752886587533208381420617177669147303598253490428755468731159562863882353787593751957781857780532171226806613001927876611195909216420198938095257201065485863278865936153381827968230301952035301852968995773622599413891249721775283479131515574857242454150695950829533116861727855889075098381754637464939319255060400927701671139009848824012858361603563707660104710181942955596198946767837449448255379774726847104047534646208046684259069491293313677028989152104752162056966024058038150193511253382430035587640247496473263914199272604269922796782354781636009341721641219924586315030286182974555706749838505494588586926995690927210797509302955";
	printf("Juego Decimales de Pi\n");
	int a = 0;
	cont = 0;
	while (a == 0)
	{
		printf("Digite el decimal número: %d, para pista digite *\n", (cont + 1));
		scanf("%s",&cadena);
		if (*(pi + (cont + 2)) == cadena[0] && cadena[1] == 0)
		{
			printf("Muy bien :D \t");
			aux  = 0;
			while (aux <= (cont + 2))
			{
				printf("%c", *(pi + aux));
				aux++;
			}
			printf("\n");
			cont++;
		}
		else
		{
			if (cadena[0] == '*' && pista > 0)
			{
				printf("El número era %c \t", *(pi + (cont + 2)));
				aux  = 0;
				while (aux <= (cont + 2))
				{
					printf("%c", *(pi + aux));
					aux++;
				}
				printf("\n");
				printf("número de pistas: %d\n", --pista);
				cont++;
			}
			else
			{
				a = 1;
				printf("Llegaste hasta el decimal número %d\n", ++cont);
			}
		}
	}
	end = fopen ("final.txt", "r");
	while((caracter = fgetc(end)) != EOF)
		printf("%c",caracter);
	fclose(end);
	printf("Decepcionaste a Einstein :'v\n");
	//system("clear");
	if (cont > player1 || cont > player2 || cont > player3)
	{
		int k = 0;
		printf("¡Nuevo record!\n");
		printf("Ingresa tu nombre: ");
		char name[4];
		scanf("%s",&name);
		if (cont > player1)
		{
			for (k = 0; k < 10; k++)
			{
				p3[k] = p2[k];
				p2[k] = p1[k];
				if (k < 3)
					p1[k] = name[k];
				if (k == 6)
					p1[k] = (cont / 1000) + '0';
				if (k == 7)
					p1[k] = ((cont / 100) - 10) + '0';
				if (k == 8)
					p1[k] = (cont % 10) + '0';
			}
		}
		else if(cont > player2)
		{
			for (k = 0; k < 10; k++)
			{
				p3[k] = p2[k];
				if (k < 3)
					p2[k] = name[k];
				if (k == 6)
					p2[k] = (cont / 1000) + '0';
				if (k == 7)
					p2[k] = ((cont / 100) - 10) + '0';
				if (k == 8)
					p2[k] = (cont % 10) + '0';

			}
		}
		else
		{
			for (k = 0; k < 10; k++)
			{
				if (k < 3)
					p3[k] = name[k];
				if (k == 6)
					p3[k] = (cont / 1000) + '0';
				if (k == 7)
					p3[k] = ((cont / 100) - 10) + '0';
				if (k == 8)
					p3[k] = (cont % 10) + '0';
			}

		}
		po = fopen ("points.txt", "w");
		fwrite( p1, sizeof(char), sizeof(p1), po );
		fclose(po);
		po = fopen ("points.txt", "a");
		fwrite( p2, sizeof(char), sizeof(p2), po );
		fwrite( p3, sizeof(char), sizeof(p3), po );
		fclose(po);
	}
	sc = fopen ( "score.txt", "r" );
	while((caracter = fgetc(end)) != EOF)
		printf("%c",caracter);
	fclose(sc);
	po = fopen ("points.txt", "r");
	while((caracter = fgetc(end)) != EOF)
		printf("%c",caracter);
	fclose(po);
	return (0);
}
