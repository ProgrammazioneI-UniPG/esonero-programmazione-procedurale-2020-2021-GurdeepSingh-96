#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(int argc, char * argv[]) {


    int a,i,e;
    char m[128];
    char k[128];
    char k_random[128];
    char ciphertext[128];
    char encripted[128];
    int lunghezza_m,lunghezza_k;

    puts("inserire il messaggio da criptare :\n");
    fgets(m,128,stdin);
    lunghezza_m=strlen(m)-1;

	do
	{

		printf("selezionare 1 per inserire una chiave personalizzata :\n");
		printf("selezionare 2 per generare una chiave casuale :\n");
		scanf("%d",&a);

	}while (a != 1 && a != 2);
	while (getchar()!='\n');


	if (a==1)
	{



		do{
			puts("inserisci la chiave \n");
			fgets(k,128,stdin);
			lunghezza_k=strlen(k)-1;
			printf("la chiave inserita è: %s", k);
		}while (lunghezza_k<lunghezza_m);


		for(i=0;i<lunghezza_k;i++)
		{
      //salvataggio in una variabile dell'operazione xor
			char b = m[i] ^ k[i];
			ciphertext[i]= b;
			encripted[i] = ciphertext[i] ^ k[i];


		}

		ciphertext[i] = '\0';

		printf("\n lunghezza del messaggio : \n %d", lunghezza_m);
		printf("\n lunghezza della chiave : \n %d", lunghezza_k);
		printf("\n messaggio criptata : \n %s", ciphertext);
		printf("\n messaggio decriptata è: \n %s " ,encripted);

	}

	if(a==2)
	{

		srand(time(0));


		printf("la chiave generata casualmente è : \n");
		for(e = 0;  e != lunghezza_m ; e++)
		{
			k[e]= 32 + rand()%128;
			printf("%c", k_random[e]=k[e]);

		}


		for(i=0;i<strlen(m);i++)
		{
			char c = m[i] ^ k_random[i];
			ciphertext[i]= c;
			encripted[i] = ciphertext[i] ^ k_random[i];
		}
		ciphertext[i] = '\0';



		printf("\n il messaggio criptata è : \n %s", ciphertext);
		printf("\n il messaggio decriptata è: \n %s " ,encripted);


	}



	return 0;
}
