#include <stdio.h>
#include <stdlib.h>

int isPrimeWord(int word){  // Força bruta
	int i = 3;
	if (word == 2)
		return 1;
	if (word%2 == 0 || word <2)
		return 0;
	while (i < word/2){
		if (word%i == 0)
			return 0;
		i++;
	}
	return 1;
}

void countWord(char *buf, int *word){ // Soma as letras de cada palavra (ignora chars que não estão em a-z e A-Z)
	int i, c, letter;
	i = 0;
	while(buf[i] != '\0'){ // \0 representa utimo elemento do vetor
		c = (int)buf[i];
		letter = 0;
		if (c>=97 && c <= 122){  // Testa se c é letra a ajusta valor a=1, z=26, A=27, Z=52 
			c -= 96;
			letter = 1;
			*word += c;
		}else if(c>= 65 && c<= 90){
			c -= 38;
			letter = 1;
			*word += c;
		}else	if (c == 10){ // 10 é \n, então acabou a palavra
			if (isPrimeWord(*word))
				printf("It is a prime word.\n");
			else
				printf("It is not a prime word.\n");
			*word = 0;
		}
		i++;
	}
}


int main(int argc, char *argv[]){
//funcao principal
	int i, word, n = 22;
	FILE *file;
	char buf[n];

	if (argc < 2) {
		fprintf(stderr, "Digite: %s <Arquivo txt>.\n", argv[0]);
		exit(EXIT_FAILURE);
	}	

	file = fopen( argv[1], "r");

	if (file == NULL) {
		fprintf(stderr, "Erro ao abrir o arquivo de texto.\n");
		exit(EXIT_FAILURE);
	}
	
	word = 0;
	
	while(fgets(buf, n, file)!=NULL){		
		countWord(buf, &word);
	}

	fclose(file);

	return 0;
}
