#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef struct carta{
	int valore;
	char seme[10];
};
carta c;

void mazzo(FILE *f){
	strncpy(c.seme,"denari",sizeof(c.seme)-1);
	//Questa è una cosa orribile.Stampa sizeof(c.seme) e ne riparliamo. 
	for(int i=1;i<11;i++){c.valore=i;
		fwrite(&c,sizeof(c),1,f);
	}
	//Perchè un ciclo da 1 a 11? 
	strncpy(c.seme,"spade",sizeof(c.seme)-1);
	for(int i1=1;i1<11;i1++){c.valore=i1;
		fwrite(&c,sizeof(c),1,f);
	}
	strncpy(c.seme,"coppe",sizeof(c.seme)-1);
	for(int i2=1;i2<11;i2++){c.valore=i2;
		fwrite(&c,sizeof(c),1,f);
	}
	strncpy(c.seme,"bastoni",sizeof(c.seme)-1);
	for(int i3=1;i3<11;i3++){c.valore=i3;
		fwrite(&c,sizeof(c),1,f);
	}
}
/*

      NON HO CAPITO COME FARE
      
      Estrai un numero casuale da 0 a 39 (Posiziona prima carta)
      Estrai un secondo numero casuale da 0 a 39 (Posiziona seconda carta)
      Scambia il contenuto del file nelle posizione stabilite. 
      -- Questa non la puoi fare con un unica operazione, ma ALMENO TRE operazioni...Ricordati come si scambiano due dati un un'array e adatta il metodo al file. 

void mischia(FILE *f){
	for(int i=0;i<40;i++){
		
	}
}*/
carta ultima(FILE *f){
	fseek(f,sizeof(carta),SEEK_END);
	fread(&c,sizeof(carta),1,f);
	cout<<c.valore<<" "<<c.seme;
}



int main(){
	
	FILE *f;	
	f=fopen("carte.dat","wb");
	mazzo(f);
	/*mischia(f);*/
	fclose(f);
	f=fopen("carte.dat","rb");
	c=ultima(f);
	fclose(f);
	
	
}
