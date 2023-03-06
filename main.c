#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
#define MAX(a,b,c) (a>b && a>c)? a: (b>a && b>c ?b: c)
#define SWAP(a,b) {int aux=a; a=b;b=aux;  }
#define SWAP2(a,b,t) {t aux=a; a=b;b=aux;  }
*/
/*
definir estructura de alumno:(legajo, apellido_nombre, localidad
cargar informacion
listar y ordenar: xlegajo, x apynom, x localidad
*/
#define MAX 80
#define MAXALUM 5
#define MAXLINEAS 5
typedef struct {
	int leg;
	char apnom[MAX];
	char loc[MAX];
} t_alumno;
typedef enum {t_ordLeg=1,t_ordAyN,t_ordLoc} t_ordenOp;
typedef enum {Asc=0,Desc} t_SentidoOrden;
static t_ordenOp tipoOrden=t_ordLeg;
static t_SentidoOrden sentido=Asc;
int compara_apellido(const void *a,const void *b)
{
	t_alumno *alum1 = (t_alumno *) a;
	t_alumno *alum2 = (t_alumno *) b;
	return strcmp(alum1->apnom,alum2->apnom);
}
int compara_apellidoDesc(const void *a,const void *b)
{
	t_alumno *alum1 = (t_alumno *) a;
	t_alumno *alum2 = (t_alumno *) b;
	return strcmp(alum2->apnom,alum1->apnom);
}
int compara_legajoDesc(const void *a,const void *b)
{
	t_alumno *alum1 = (t_alumno *) a;
	t_alumno *alum2 = (t_alumno *) b;
	return alum2->leg - alum1->leg;
}

int compara(const void *a,const void *b)
{
	int result=0;
	t_alumno *alum1 = (t_alumno *) a;
	t_alumno *alum2 = (t_alumno *) b;
	if(tipoOrden == t_ordLeg)
	{
	  if(sentido==Desc)	
	    result = alum2->leg - alum1->leg;	
	  else
	    result = alum1->leg - alum2->leg;	
	}
	else
	{
		if(tipoOrden == t_ordAyN)
		{
			if(sentido==Desc)	
				result = strcmp(alum2->apnom,alum1->apnom);
			else
				result = strcmp(alum1->apnom,alum2->apnom);
		}
		else
		{ 
		  if(tipoOrden == t_ordLoc)
		  {
		  	if(sentido==Desc)	
		  		result = strcmp(alum2->loc,alum1->loc);
			  else
		  		result = strcmp(alum1->loc,alum2->loc);
		  }			
		}
	}
	return result;
}
int main(int argc, char *argv[]) {
	/*
	int i;
	t_alumno lista[MAXALUM];	
	
	tipoOrden = atoi(argv[1]);
	sentido = (strcmp(argv[2],"A")==0?Asc:Desc);
	
	lista[0].leg = 1000;
	strcpy(lista[0].apnom , "Jose Lopez") ;
	strcpy(lista[0].loc , "Gaiman");
	
	lista[1].leg = 1001;
	strcpy(lista[1].apnom , "Marcelo Santander") ;
	strcpy(lista[1].loc , "Trelew");
	
	lista[2].leg = 1002;
	strcpy(lista[2].apnom , "Facundo Gomez") ;
	strcpy(lista[2].loc , "Rawson");
	
	lista[3].leg = 1003;
	strcpy(lista[3].apnom , "Agustin Pacheco") ;
	strcpy(lista[3].loc , "Gaiman");
	
	lista[4].leg = 1004;
	strcpy(lista[4].apnom , "Brian Barrio") ;
	strcpy(lista[4].loc , "Miami");
	
	
	for(i=0;i < MAXALUM; ++i)
	{
		printf("Alumno %d) leg:%d - ApyNom:%s Loc: %s\n",(i+1),lista[i].leg,lista[i].apnom,lista[i].loc);
	}
	
	printf("\nLista Ordenada\n\n");
	// orderar por apellido y nombre
	
	//qsort(lista, MAXALUM,sizeof(t_alumno), compara_apellidoDesc);
	qsort(lista, MAXALUM,sizeof(t_alumno), compara);

	for(i=0;i < MAXALUM; ++i)
	{
		printf("Alumno %d) leg:%d - ApyNom:%s Loc: %s\n",(i+1),lista[i].leg,lista[i].apnom,lista[i].loc);
	}*/
	char buffer[MAX];
	int i, cant_alum=0;
	t_alumno *alumnos[MAXALUM];
	int legajo;

	for(i=0;i<MAXALUM;++i)
	{
		printf("Ingrese nro de Legajo:(El 0 corta el ingreso)\n");
		fflush(stdin);
		scanf("%d",&legajo);
		if(legajo==0)
		  break;
		alumnos[i]  = (t_alumno *)malloc(sizeof(t_alumno));
		alumnos[i]->leg = legajo;
		printf("ingrese nombre y apellido:\n");
		fflush(stdin);
		gets(buffer);
		strcpy(alumnos[i]->apnom , buffer);
		printf("ingrese localidad:\n");
		fflush(stdin);
		gets(buffer);
		strcpy(alumnos[i]->loc , buffer);
		cant_alum++;		
	}
	for(i=0;i<cant_alum;++i)
	{
		printf("%d %s %s\n",alumnos[i]->leg,alumnos[i]->apnom,alumnos[i]->loc);
		free(alumnos[i]);
	}
	
	
	/*t_alumno *alum1;
	alum1 = (t_alumno*)malloc(sizeof(t_alumno));
	alum1->leg = 1000;
	strcpy(alum1->apnom,"Jose Ariel Lopez");
	strcpy(alum1->loc,"Trelew");	
	printf("%d , %s, %s\n",alum1->leg,alum1->apnom,alum1->loc);*/
	
	/*
	char *lineas[MAXLINEAS];
	
	for(i=0;i<MAXLINEAS;++i)
	{
		if(gets(buffer) != NULL)
		{
			lineas[i] = (char *)malloc((strlen(buffer)+1) * sizeof(char));
			if(lineas[i] !=NULL)
			{			
			  strcpy(lineas[i],buffer);
			  cant_lineas++;
			}
		}
	}
	for(i=0;i<cant_lineas;++i)		
	{
		printf("%s\n",lineas[i]);
		free(lineas[i]);
	}*/
		
	system("pause")	;
}





/*void swap(int *a,int *b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

int main(int argc, char *argv[]) {
	int n1=1,n2=10,n3=30;
	long a1=1000, a2=4000;
	printf("%d  -  %d\n",n1,n2);
	SWAP2(n1,n2,int);
	//swap(&n1, &n2);
	//swap(&a1,&a2);
	printf("%d  -  %d\n",n1,n2);
	printf("%d  -  %d\n",a1,a2);
	SWAP2(a1,a2,long);
	printf("%d  -  %d\n",a1,a2);
	//printf("El maximo de 3 nros es: %d\n", (n1>b && n1>n3)? n1: (n2>n1 && n2>n3 ?n2: n3));
     system("pause");
	return 0;
}*/
