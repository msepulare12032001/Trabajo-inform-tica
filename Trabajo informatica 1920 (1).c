#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
char nombre[100];
char apellido[100];
char seguridadsocial[100];
char email[100];
char fecha[100];
char ingreso[100];
}paciente;


void registro_pacientes();
void leer_pacientes();
int contador();
void eliminar_paciente(int a);
void apellido();
void menu();
void modificar();

int main()
{
    
	int pass;
	printf("...........BASE DE DATOS DE PACIENTES...........\n\n");
		
	do{
		fflush(stdin);
		printf("Clave de acceso:    ");
		scanf("%d",&pass);
		
		if(pass==1920) printf("\nClave correcta. \n\n");
		else printf("\nClave incorrecta. \n");
	
	}while(pass!=1920);
	
    menu();
    system("pause");
}
//FIN FUNCION MAIN

void menu()
{   
int opcion,a;
FILE *pf;
paciente c;
	
	do{
	    printf("\n\n..............MENU PRINCIPAL.............. \n\n");
	    printf("\n");
        printf("1. Registro del paciente.\n");
        printf("2. Listado de pacientes.\n");
        printf("3. Consulta de datos de un paciente.\n");
        printf("4. Modificar datos de un paciente.\n");
        printf("5. Eliminar paciente.\n");
        printf("6. Salir\n");
        printf("\n");
        printf("..........................................\n");
       
        do{
        printf("\nIntroduzca su opcion\n");
        scanf("%d",&opcion);
        printf("\n");
        }while(opcion<1 || opcion>6);
        
        switch(opcion)
		{
            case 1:
                registro_pacientes();
                
            break;
            
            case 2:
            	
                leer_pacientes();
				
            break;	
                        
			case 3:
				
				apellido();
			
			break;	
			
			case 4:
				leer_pacientes();
               	printf("Elija el numero correspondiente al paciente que desea modificar:   ");
            	scanf("%d",&a);
                eliminar_paciente(a);
                modificar();
                printf("\n\n\tPACIENTE MODIFICADO CORRECTAMENTE \n");

			break;	
			
			case 5:
                leer_pacientes();
               	printf("Elija el numero correspondiente al paciente que desea eliminar de la lista:   ");
            	scanf("%d",&a);
                eliminar_paciente(a);
                printf("\n\n\tPACIENTE ELIMINADO CORRECTAMENTE \n");
				
            break;
			
			case 6:
				printf("Saliendo del programa \n");
			break;	
				
          
            default:
                printf("Opcion no valida\n");
        
		}
    }while(opcion!=6);
    
			
}
//FIN FUNCION M

void registro_pacientes()
{
	
	    FILE*pf;
        paciente c;
	    int i; 
        int longitud;
        int x=0;
	    
	    
	    fflush(stdin);
	    printf("Nombre del paciente: ");
        gets(c.nombre);
        
        fflush(stdin);
        printf("Apellido del paciente: ");
        gets(c.apellido);
        
        fflush(stdin);
        printf("Numero de la seguridad social: ");
        gets(c.seguridadsocial);
        
        do{
        fflush(stdin);
        printf ("Email del paciente: "); 
        gets(c.email);
        longitud=strlen(c.email);

for(i = 0; i<longitud; i++)
{ 
	if (c.email[i] ==64)
	{
		x=1;
		break;
	} 
}

if (x==1)
{
	while(i<longitud)
	{
		i++;
		if(c.email[i]==46) x=2;
	}
}  
if(x==2) printf("Direccion de email valida\n\n")  ;
else printf("Direccion incorrecta\n");
}while(x!=2);
        
   		fflush(stdin); 
        printf("Fecha de nacimiento del Paciente: ");
        gets(c.fecha);  
		
		fflush(stdin); 
		printf("Fecha de ingreso: ");
        gets(c.ingreso);
        
        pf=fopen("pacientes.txt","a");
        
        fprintf(pf,"%s  ",c.nombre);
        fprintf(pf,"%s  ",c.apellido);
        fprintf(pf,"%s  ",c.seguridadsocial);
        fprintf(pf,"%s  ",c.email);
        fprintf(pf,"%s  ",c.fecha);
        fprintf(pf,"%s  \n",c.ingreso);
        
        fclose(pf);
}
//FIN FUNCION PEDIR ALUMNO

void leer_pacientes()
{    
    FILE* pf;
	paciente c;
    int i=0,j=0;    
    int cont=contador();
    
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("#:  %-10s %-10s %-25s %-20s %-15s %-15s \n","NOMBRE","APELLIDO","N.SEGURIDAD SOCIAL","\tEMAIL","F.NACIMIENTO","F.INGRESO");
	printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
	
	
	pf=fopen("pacientes.txt","r");
	for(i=0;i<cont-1;i++)
	{

	fscanf(pf,"%s",c.nombre);
	fscanf(pf,"%s",c.apellido);
	fscanf(pf,"%s",c.seguridadsocial);
	fscanf(pf,"%s",c.email);
	fscanf(pf,"%s",c.fecha);
	fscanf(pf,"%s",c.ingreso);

    printf("%d:",i);
    printf(" %s\t",c.nombre);
    printf("%s      ",c.apellido);
    printf("%s\t\t",c.seguridadsocial);
    printf("%s\t",c.email);
    printf("     %s\t",c.fecha);
    printf("   %s\n",c.ingreso);
    
	}
	
    fclose(pf);
    
    printf("----------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n");
    

}
//FIN FUNCION VER PACIENTE

int contador()
{	
FILE*pf;
pf=fopen("pacientes.txt","r");
	
char basur[100];
int cont=0,N;

while(!feof(pf))
{
	fgets(basur,100,pf);
	
	cont++;
}
fclose(pf);

return (cont);
}
//FIN FUNCION CONTADOR

void eliminar_paciente(int a)
{
  FILE*pf=fopen("pacientes.txt","r");
  FILE*temp=fopen("temp.txt","a");
  paciente c;
  int i=0;    
  int cont=contador();
  
  for(i=0;i<cont-1;i++)
	{
	fscanf(pf,"%s",c.nombre);
	fscanf(pf,"%s",c.apellido);
	fscanf(pf,"%s",c.seguridadsocial);
	fscanf(pf,"%s",c.email);
	fscanf(pf,"%s",c.fecha);
	fscanf(pf,"%s",c.ingreso);
	 
	if(i!=a)
	{	 
	fscanf(pf,"%s",c.nombre);
	fscanf(pf,"%s",c.apellido);
	fscanf(pf,"%s",c.seguridadsocial);
	fscanf(pf,"%s",c.email);
	fscanf(pf,"%s",c.fecha);
    fprintf(temp,"%s  \n",c.ingreso);
    }
} 

fclose(pf);
fclose(temp);

remove("pacientes.txt");
rename("temp.txt","pacientes.txt");
}
//FIN FUNCION ELIMINAR PACIENTE

void apellido()
{
      FILE *pf=fopen("pacientes.txt","r");
      paciente c;
      char buscanm[100];
      char buscanom[100];
      int i=0,j=0,op=0;
      int cont=contador();
      printf("\n..........TIPO DE BUSQUEDA...........\n\n");
      printf("1. Nombre completo \n");
      printf("2. N. tarjeta sanitaria \n\n");
      printf("Eilja una opcion \n");
      scanf("%d",&op);
      
      switch(op)
      {
      	case 1:
      		
      	fflush(stdin);
        printf("Introduca el nombre del paciente a buscar:     ");
        gets(buscanom);
  
       	printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
	    printf("#:  %-10s %-10s %-25s %-20s %-15s %-15s \n","NOMBRE","APELLIDO","N.SEGURIDAD SOCIAL","\tEMAIL","F.NACIMIENTO","F.INGRESO");
	    printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for(i=0;i<cont;i++)
	{
	fscanf(pf,"%s",c.nombre);
	fscanf(pf,"%s",c.apellido);
	fscanf(pf,"%s",c.seguridadsocial);
	fscanf(pf,"%s",c.email);
	fscanf(pf,"%s",c.fecha);
	fscanf(pf,"%s",c.ingreso);
	
	   
      if(strcmp(c.nombre,buscanom)==0){
	    
	printf("%d:",i);
    printf(" %s\t",c.nombre);
    printf("%s      ",c.apellido);
    printf("%s\t\t",c.seguridadsocial);
    printf("%s\t",c.email);
    printf("     %s\t",c.fecha);
    printf("   %s\n",c.ingreso);
        
        
        i++;
        j++;
         }
      }
      printf("------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
      if(i==0) printf("\nNo se ha encontrado a dicho paciente. \n");
      
      else printf("Se han encontrado %d coincidencias. \n",j);
      		
      		break;
      	
      	
      	
		  case 2: 
		              
      fflush(stdin);
      printf("Introduca el N. tarjeta sanitaria del paciente a buscar:     ");
      gets(buscanm);
  
  for(i=0;i<cont-1;i++)
	{
	fscanf(pf,"%s",c.nombre);
	fscanf(pf,"%s",c.apellido);
	fscanf(pf,"%s",c.seguridadsocial);
	fscanf(pf,"%s",c.email);
	fscanf(pf,"%s",c.fecha);
	fscanf(pf,"%s",c.ingreso);

	
         if(strcmp(c.seguridadsocial,buscanm)==0){
        
     	printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
	    printf("#:  %-15s %-20s %-25s %-30s %-20s %-15s \n","NOMBRE COMPLETO","apellido","N. TARJETA SANITARIA","\tEMAIL","F.NACIMIENTO","F.INGRESO");
	    printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
	    
	    printf("%d:",i);
	    printf(" %s\t",c.nombre);
	    printf("%s      ",c.apellido);
	    printf("%s\t\t",c.seguridadsocial);
	    printf("%s\t",c.email);
	    printf("     %s\t",c.fecha);
	    printf("   %s\n",c.ingreso);
        
        printf("----------------------------------------------------------------------------------------------------------------------------------------------\n\n");
        
        i++;
        j++;
         }
      }
      if(i==0) printf("\nNo se ha encontrado a dicho paciente. \n");
      else printf("Se han encontrado %d coincidencias. \n",j);
		  
		    break;
			
		default: printf("Opcion no valida \n");
	  }
	  
      fclose(pf);
}
//FIN FUNCION CONSULTA INDIVIDUAL


void modificar()
{
	    FILE*pf;
        paciente c;
	    int i; 
        int longitud;
        int x=0;
	    
	    
	    fflush(stdin);
	    printf("\nNuevo nombre del paciente: ");
        gets(c.nombre);
        
        fflush(stdin);
        printf("Nuevo apellido: ");
        gets(c.apellido);
        
        fflush(stdin);
        printf("Nuevo numero de la seguridad social: ");
        gets(c.seguridadsocial);
        
    do{    
        fflush(stdin);
        printf ("Nuevo e-mail del paciente: "); 
        gets(c.email);
        longitud=strlen(c.email);

		for(i = 0; i<longitud; i++)
		{ 
			if (c.email[i] ==64)
			{
				x=1;
				break;
			} 
		}

		if (x==1)
		{
			while(i<longitud)
			{
				i++;
				if(c.email[i]==46) x=2;
			}
		}  
		if(x==2) printf("Direccion de email valida\n\n")  ;
		else printf("Direccion incorrecta\n");
	}while(x!=2);
        
   		fflush(stdin); 
        printf("Nueva fecha de nacimiento del paciente: ");
        gets(c.fecha);  
		
		fflush(stdin); 
		printf("Nueva fecha de ingreso: ");
        gets(c.ingreso);
        
        
        pf=fopen("pacientes.txt","a");
        
		fprintf(pf,"%s  ",c.nombre);
        fprintf(pf,"%s  ",c.apellido);
        fprintf(pf,"%s  ",c.seguridadsocial);
        fprintf(pf,"%s  ",c.email);
        fprintf(pf,"%s  ",c.fecha);
        fprintf(pf,"%s  \n",c.ingreso);

        
        fclose(pf);
}
//FIN FUNCION MODIFICAR PACIENTE
