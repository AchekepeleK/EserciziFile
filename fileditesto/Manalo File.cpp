#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
 
int main()
{
	FILE *file, *file2;
	float x,y,z;
	char str[10];
	char nomef[20], nomef2[20];
 	
	cout<<"Inserisci il nome del file : ";
	cin>>nomef;
	strcpy(nomef2,nomef);
	strcat(nomef, ".txt");
	file=fopen(nomef,"r");

	file=fopen(nomef,"r");
	
	if (file == NULL)
  	{
		cout<<"IMPOSSIBILE APRIRE IL FILE";
		return 0;
  	
	} 	
	
	/*while (fgets(str,10,file) != NULL)
	{
 		cout<<str;
	}
	rewind(file); */
 
	fscanf(file,"%f",&x);
	strcat(nomef2, ".mod");
	file2=fopen(nomef2,"w+");
	
	if (file2 == NULL)
	{
		cout<<"IMPOSSIBILE APRIRE IL FILE";
		return 0;
	}
	
	fprintf(file2,"%f;",x);
	fprintf(file2,"0.000000\n");
	
	do
	{
		
		fscanf(file,"%f",&y);
		z=y-x;
		fprintf(file2,"%f;",y);
		fprintf(file2,"%f\n",z);
		
	}while (!feof(file));
  
  
	fclose(file);
	fclose(file2);	
 	
 }

