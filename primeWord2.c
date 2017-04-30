#include <stdio.h>
#include <stdlib.h>

int N = 3;
int j = 0;

// Compara vetor e retorna se é ou não "EOF"
int isEOF(char *buf){
	if (buf[0] == 'E' && buf[1] == 'O' && buf[2] == 'F' && buf[3] == '\0')
		return 1;
	return 0;
}

// Força bruta
int isPrimeWord(int word){
	int i = 3;
	if(word == 2)
		return 1;
	if(word%2 == 0 || word <2)
		return 0;
	while(i < word/2){
		if(word%i == 0)
			return 0;
		i++;
	}
	return 1;
}

// Adiciona em lista de saida
void add(char **ret, char n){
	int i;
	if(j==N){
		char *aux = (*ret);
		(*ret) = malloc(sizeof(char)*2*N);
		for(i=0; i<N; i++)
			(*ret)[i] = aux[i];
		N *= 2;
	}
	(*ret)[j] = n;
	(*ret)[j+1] = '\0';
	j++;
}

// Soma as letras de cada palavra (ignora chars que não estão em a-z e A-Z)
void countWord(char *buf, char **ret){
	int i, c, isLetter, word;
	word = 0;
	i = 0;
	c = (int)buf[i];
	while(buf[i] != '\0'){ // \0 representa utimo elemento do vetor
		isLetter = 0;
		if (c>=97 && c <= 122){  // Testa se c é letra a ajusta valor a=1, z=26, A=27, Z=52 
			c -= 96;
			isLetter = 1;
			word += c;
		}else if(c>= 65 && c<= 90){
			c -= 38;
			isLetter = 1;
			word += c;
		}
		i++;
	}
	if (isPrimeWord(word)){
		add(&(*ret), '1');
	}
	else{
		add(&(*ret), '0');
	}
}

// Imprime lista de retorno
void printReturnList(char *ret){
	int i = 0;
	while(ret[i] != '\0'){
		if (ret[i]  == '0')
			printf("It is not a prime word.\n");
		else if (ret[i] = '1')
			printf("It is a prime word.\n");
		i++;
	}
}

// Função principal
int main(int argc, char *argv[]){
	char buf[N];
	int word;
	char *ret;
	
	ret = malloc(sizeof(char)*N);
	ret[0] = '\0';
	
	scanf("%20s", buf);  // Le até 20 chars por palavra. Se palavra > 20, ela é cortada de 20 em 20.
	
	while(!isEOF(buf)){
		countWord(buf, &ret);
		scanf("%20s", buf);
	}	
	
	printReturnList(ret);
	
	return 0;
}
