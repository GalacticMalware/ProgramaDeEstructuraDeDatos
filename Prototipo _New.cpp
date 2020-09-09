    #include <iostream>
    #include <windows.h>
    #include<stdlib.h>
    #include<stdio.h>
    #include<conio.h>
    #define ARRIBA 'i'
    #define ABAJO 'k'
    #define ENTER 13
     //Librerias mas definiciones
    using namespace std;
    
    //Componete Gotoxy 
    char getch2 ()
    {
       char c=0;
       DWORD modo, contador;
       HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);
       // Desactivacion escritura en terminal
       SetConsoleMode (ih, modo & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT)); 
       ReadConsoleA(ih,&c,1,&contador,NULL);
       if (c==0) {
          ReadConsoleA (ih,&c,1,&contador,NULL);
       }
       SetConsoleMode (ih,modo); // Devolvemos control normal
       return c;
    }
    //Gotoxy-------------------------------------------
    int gotoxy(USHORT x,USHORT y) {
       COORD cp = {x,y};
       SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
     }
     //Estrutura---------------------------------
     struct proyecto{
	char nom[40];
	int expe;
    int hrsx;
	int edad;
	char sex[40];
	float suel;
	struct proyecto *psig;
};

struct lisdob{
	char nom[40];
	int expe;
	int edad;
	int hrsx;
	char sex[50];
	float suel;	
	struct lisdob *psig, *pant;
};

struct proyecto *nuevo=NULL, *aux=NULL,*aux1=NULL,*cabecera=NULL;
struct lisdob *nuevo_Doble=NULL,*aux_Doble=NULL,*aux1_Doble=NULL,*cabecera_Doble=NULL,*fin=NULL;
int opc,opc1,opc2,opc3,opc4,opc5,opc6,opc7,contnodo_Simple=0,contnodo_Doble=0,Posi_Simple,Posi_Doble,i,nummod,damod,num_Doble;
     
     
     
    //Listados de los void  
    int menu(const char titulo[], const char *opciones[], int n);
    void listas();
    void pilas();
    void menu_resta();
    void menu_producto();
    void menu_division();
    void menu();
    void Listas_Simples();
    void Listas_Dobles();
    void Listas_Simple_Insertar();
    void Listas_Simple_Eliminar();
    void Listas_Simple_Modificar();
    void Listas_Simple_Mostrar();
    void CrearCab_Simple();
    void Insertar_Inicio_Simple();
    void Insertar_Final_Simple();
    void Insertar_Entre_Simple();
    void Eliminar_Inicio_Simple();
    void Eliminar_Final_Simple();
    void Eliminar_Entre_Simple();
    void CrearCab_Doble();
    void Insertar_Inicio_Doble();
    void Insertar_Final_Doble();
    void Insertar_Entre_Doble();
    void Eliminar_Inicio_Doble();
    void Eliminar_Final_Doble();
    void Eliminar_Entre_Doble();
    void Listas_Dobles_Insertar();
    void Listas_Dobles_Eliminar();
    void Listas_Dobles_Modificar();
    void Listas_Dobles_Mostrar();

    int main()
    {
       menu();
       getch();
       return 0;
    }
     
    void menu()
    {
       bool repite = true;
       int opcion;   
     
       // Titulo del menú y nombres de las opciones
       const char *titulo = "MENU DE OPCIONES";
       const char *opciones[] = {"LISTAS", "PILAS", "SALIR"};
       int n = 3;  // Numero de opciones
     
       do {
          opcion = menu(titulo, opciones, n);
     
          switch (opcion) {
             case 1:
                listas();
                break;     
     
             case 2:
                pilas();
                break;
     
             case 3:
                printf("\nUsted aca de salir del programa\n");
                exit(0);
                //repite = false;
                system("pause>nul");
                break;
          }
     
       } while(repite);
    }
    
    void pilas(){
        system("cls");
        printf("\t\nBienvenido\n");
        system("pause<nul");
        getch();
        bool repite = true;
       int opcion;
       // Titulo del menú y nombres de las opciones
       const char *titulo = "\tMENU PISLAS";
       const char *opciones[] = {"\tCREAR DATOS DEL TRABAJADOR", "\tINGRESAR MAS DATOS","MOSTRAR LOS DATOS","\tELIMINR DATOS DEL TRABAJADOR", "\tREGRESAR AL MENU"};
       int n = 5;  // Numero de opciones
       do {
          opcion = menu(titulo, opciones, n);
     
          system("cls");
          switch (opcion) {
             case 1:
                CrearCab_Simple();
                break;
     
             case 2:
                Insertar_Inicio_Simple();
                break;
                
             case 3:
                Listas_Simple_Mostrar();   
     
             case 4:
               Eliminar_Final_Simple();
                break;
                
             case 5:
             repite=false;
             break;   
          }
     
       } while(repite);
        
    }
     
    void listas()
    {
       bool repite = true;
       int opcion;
       // Titulo del menú y nombres de las opciones
       const char *titulo = "\tMENU LISTAS";
       const char *opciones[] = {"\tLISTAS SIMPLES", "\tLISTAS DOBLES", "\tREGRESAR AL MENU"};
       int n = 3;  // Numero de opciones
       do {
          opcion = menu(titulo, opciones, n);
     
          system("cls");
          switch (opcion) {
             case 1:
                Listas_Simples();
                break;
     
             case 2:
                Listas_Dobles();
                break;
     
             case 3:
                menu();
               //repite = false;
                break;
          }
     
       } while(repite);
    }
     
    void Listas_Simples()
    {
       bool repite = true;
       int opcion;
     
       // Titulo del menú y nombres de las opciones
       const char *titulo = "MENU PARA LISTAS SIMPLES";
       const char *opciones[] = {"INGRESAR NUEVOS DATOS DEL TRABAJADOR", "ELIMINAR DATOS DE ALGUN TRABAJOR", "MODIFICAR DATOS DE ALGUN TRABAJADOR", "MOSTRAR DATOS DE TODOS LOS TRABAJADORES", "REGRESAR AL MENU"};
       int n = 5;  // Numero de opciones
     
       do {
          opcion = menu(titulo, opciones, n);
     
          system("cls");
          switch (opcion) {
             case 1:
                Listas_Simple_Insertar();
                break;
     
     
             case 2:
               Listas_Simple_Eliminar();
                break;
                
             case 3:
             Listas_Simple_Modificar();
             break;
             
             case 4:
             Listas_Simple_Mostrar();
             break;    
     
             case 5:
                listas();
                //repite = false;
                break;
          }
     
       } while(repite);
    }
     
    void Listas_Simple_Insertar()
    {
       bool repite = true;
       int opcion;
     
       // Titulo del menú y nombres de las opciones
       const char *titulo = "MENU PARA INSERTAR";
       const char *opciones[] = {"CREAR NUEVOS DATOS", "INSERTAR DATOS AL INICIO", "INSERTAR ENTRE DATOS", "INSERTAR DATOS AL FINAL", "REGRESAR AL MENU ANTERIOR"};
       int n = 5;  // Numero de opciones
     
       do {
          opcion = menu(titulo, opciones, n);
     
          system("cls");
          switch (opcion) {
             case 1:
                CrearCab_Simple();
                break;
     
             case 2:
                Insertar_Inicio_Simple();
                break;
            
             case 3:
                Insertar_Entre_Simple();
                break;
                
             case 4:
                Insertar_Final_Simple();
                break;   
     
             case 5:
                //repite = false;
                Listas_Simples();
                break;
          }
     
       } while(repite);
    }
     
     
     void CrearCab_Simple(){
	 if(cabecera!=NULL)
           printf("Ya se an ingresado dotos antes!!\n");
           else
           {
              nuevo=(struct proyecto*)malloc(sizeof(struct proyecto));
              if(nuevo==NULL)
              printf("Error de ingresar datos\n");
           else
           {
              printf("\tIngrese nombre del empleado:\t");
              scanf("%s",&nuevo->nom);
              printf("\tIngrese a%cos de experiencia de 1  a  5 a%cos:\t",164,164);
              scanf("%d",&nuevo->expe);
              printf("\tIngrese su edad:\t ");
              scanf("%d",&nuevo->edad);
              printf("\tIngrese horas extras trabajdas \t(POR 1 HORA EXTRA SE LE PAGA $50): ");
              scanf("%d",&nuevo->hrsx);
              nuevo->suel=nuevo->hrsx*50;
              nuevo->psig=NULL;
              cabecera=nuevo;
              contnodo_Simple=contnodo_Simple+1;
}
 }
                      
      system("CLS");
      getch();
      Listas_Simple_Insertar();
  }
  
  void Insertar_Inicio_Simple(){
	system("CLS");
    
     if(cabecera==NULL || contnodo_Simple==0)
    {
            printf("\tImposible insertar, al menos debe de existir un dato de cualquier empleado\n");
            getch();
            system("CLS");
            Listas_Simple_Insertar();
            }
       else
        {
             nuevo=(struct proyecto*)malloc(sizeof(struct proyecto));
              if(nuevo==NULL)
        	{
            printf("Error de asignacion\n");
        	}
           else
           {
             printf("\tIngrese nombre del empleado:\t");
              scanf("%s",&nuevo->nom);
              printf("\tIngrese a%cos de experiencia de 1  a  5 a%cos:\t",164,164);
              scanf("%d",&nuevo->expe);
              printf("\tIngrese su edad:\t ");
              scanf("%d",&nuevo->edad);
              printf("\tIngrese horas extras trabajdas \t(POR 1 HORA EXTRA SE LE PAGA $50): ");
              scanf("%d",&nuevo->hrsx);
              nuevo->suel=nuevo->hrsx*50;
              nuevo->psig=NULL;
              aux=cabecera;
              nuevo->psig=aux;
              cabecera=nuevo;
              contnodo_Simple=contnodo_Simple+1;
           }
           }
               getch();
               system("CLS");
               Listas_Simple_Insertar(); 
	
}
void Insertar_Entre_Simple(){
	if(cabecera==NULL || contnodo_Simple==1)
     {
     printf("Imposible insertar, al menos deben existir 2 nodos\n");
     getch();
     }
     else
     {
       printf("Posicion a Insertar:\n");
         scanf("%d",&Posi_Simple);
         if(Posi_Simple==1 || Posi_Simple==contnodo_Simple)
         printf("Invalido insertar en extremos\n");
         else
         {
             aux=cabecera;
             for(i=1;i<Posi_Simple;i++)
             {
                               aux1=aux;
                               aux=aux->psig;
             }
             
             nuevo=(struct proyecto*)malloc(sizeof(struct proyecto));
              if(nuevo==NULL)
               {
                printf("Error de asignacion\n");
               }
             else
             {
              printf("\tIngrse nombre del empleado:\t");
              scanf("%s",&nuevo->nom);
              printf("\tIngrese a%cos de experiencia de 1  a  5 a%cos:\t",164,164);
              scanf("%d",&nuevo->expe);
              printf("\tIngrese su edad:\t ");
              scanf("%d",&nuevo->edad);
              printf("\tIngrese horas extras trabajdas \t(POR 1 HORA EXTRA SE LE PAGA $50): ");
              scanf("%d",&nuevo->hrsx);
              nuevo->suel=nuevo->hrsx*50;
              nuevo->psig=NULL;
         
             nuevo->psig=aux;
             aux1->psig=nuevo;
             contnodo_Simple=contnodo_Simple+1;
         }
         }
         }
         getch();
         system("CLS");
          Listas_Simple_Insertar();
}
void Insertar_Final_Simple(){
	system("CLS");
     nuevo=(struct proyecto*)malloc(sizeof(struct proyecto));
     if(nuevo==NULL)
     {
       printf("Error de asignacion\n");
     }
     else
  {
         if(cabecera==NULL)
           printf("Imposible Insertar, al menos debe existir un nodo\n");
         else
         {
              printf("\tIngrse nombre del empleado:\t");
              scanf("%s",&nuevo->nom);
              printf("\tIngrese a%cos de experiencia de 1  a  5 a%cos:\t",164,164);
              scanf("%d",&nuevo->expe);
              printf("\tIngrese su edad:\t ");
              scanf("%d",&nuevo->edad);
              printf("\tIngrese horas extras trabajdas \t(POR 1 HORA EXTRA SE LE PAGA $50): ");
              scanf("%d",&nuevo->hrsx);
              nuevo->suel=nuevo->hrsx*50;
              nuevo->psig=NULL;
         aux=cabecera;
         while(aux->psig!=NULL)
         {
            aux=aux->psig;
         }
            aux->psig=nuevo;
            contnodo_Simple=contnodo_Simple+1;
         }
            getch();
         }
system("CLS");
Listas_Simple_Insertar();
}
    
void Listas_Simple_Eliminar()
    {
       bool repite = true;
       int opcion;
     
       // Titulo del menú y nombres de las opciones
       const char *titulo = "MENU PARA ELIMINAR";
       const char *opciones[] = {"ELIMINAR DATOS DEL PRIMER EMPLEADO", "ELIMINAR DATOS DEL ULTIMO EMPLEADO", "ELEGIR LA ELIMINAR DE DATOS ", "REGRESAR AL MENU ANTERIOR"};
       int n = 4;  // Numero de opciones
     
       do {
          opcion = menu(titulo, opciones, n);
     
          system("cls");
          switch (opcion) {
             case 1:
                Eliminar_Inicio_Simple();
                break;
     
             case 2:
                Eliminar_Final_Simple();
                break;
            
             case 3:
                Eliminar_Entre_Simple();
                break;
                
             case 4:
                Listas_Simples();
                break;
          }
     
       } while(repite);
    }    
    
    void Eliminar_Inicio_Simple(){
    if(cabecera==NULL)
       printf("No hay elementos para eliminar\n");
       else
       { 
           if(contnodo_Simple==1)
            {
                           //tneto=tneto-cabecera->total;  // el salario que descuenta
                           free(cabecera);
                           cabecera=NULL;
                           
                           contnodo_Simple=contnodo_Simple-1;
            }
            else
            {
            aux=cabecera;
            //tneto=tneto-aux->total;  //poner la variable del salario
            cabecera=cabecera->psig;
            free(aux);
            aux=NULL;
           contnodo_Simple=contnodo_Simple-1;
            }
       }
            system("CLS");
            getch();
            Listas_Simple_Eliminar();  //poner que vuelva al menu
}


//eliminacion de listas SIMPLES de medio 

void Eliminar_Entre_Simple(){
    
    system("CLS");
     if(cabecera==NULL || contnodo_Simple <=2)
     printf("Imposible eliminar\n");
     else
     {
         printf("\tIngrese la posicion a eliminar:    ");
         scanf("%d",&Posi_Simple);
         if(Posi_Simple==1 || Posi_Simple==contnodo_Simple)
         printf(" !!!No se puede eliminar en los extremos!!!\n");
         else
         {
             aux=cabecera;
             for(i=1;i<Posi_Simple;i++)
             {
                               aux1=aux;
                               aux=aux->psig;
             }
                               aux1->psig=aux1->psig->psig;
                               free(aux);
                               aux=NULL;
                               contnodo_Simple=contnodo_Simple-1;
         }
     }
     getch();
     system("CLS");
     Listas_Simple_Eliminar();
}

void Eliminar_Final_Simple(){
    system("CLS");
     if(cabecera==NULL || contnodo_Simple <=2)
     printf("Imposible eliminar\n");
     else
     {
         printf("Ingrse la posicion a eliminar:\n");
         scanf("%d",&Posi_Simple);
         if(Posi_Simple==1 || Posi_Simple==contnodo_Simple)
         printf("!!!No se puede eliminar en los extremos!!!\n");
         else
         {
             aux=cabecera;
             for(i=1;i<Posi_Simple;i++)
             {
                               aux1=aux;
                               aux=aux->psig;
             }
                               aux1->psig=aux1->psig->psig;
                               free(aux);
                               aux=NULL;
                               contnodo_Simple=contnodo_Simple-1;
         }
     }
     getch();
     system("CLS");
     Listas_Simple_Eliminar();
}

     void Listas_Simple_Modificar(){
	if (cabecera==NULL){
	    printf("¡¡¡Alvertencia!!!\n");
		printf("¡¡¡La lista de datos esta vacia!!!");
		getch();
		
	}
	else
	{
		aux=cabecera;
		printf("\n\n");
		printf("\tIngrese el numero ha modificar:\t");
		scanf("%d",&nummod);
		if(nummod<1 || nummod >contnodo_Simple){
		    printf("\n\n");
		    printf("\tEl numero no existe/n");
		    getch();
        }
        else{
		for(i=1;i<nummod;i++)
		{
			aux=aux->psig;
		}
		printf("\tLos datos de esta lista es:\n");
		printf("\n\n");
		printf("\t1.-Nombre del empleado: %s\n",aux->nom);
		printf("\t2.-A%cos de experiencia: %d\n",164,aux->expe);
		printf("\t3.-Edad del empleado: %d\n",aux->edad);
		printf("\t4.-Horas trabajadas (POR 1 HORA EXTRA SE LE PAGA $50)\n",nuevo->hrsx);
		printf("\n\n");
		printf ("\n\tCual desea modificar?\n");
		scanf("%d",&damod);
		switch(damod)
		{
			case 1:
				printf("\tIngrese el nuevo nombre:\t");
				scanf("%s",&nuevo->nom);
				break;
			case 2:
				printf("\tIngrese los a%cos de exériencia:\t",164);
				scanf("%d",&nuevo->expe);
				break;
			case 3:
				printf("\tIngrese la nueva edad:\t");
				scanf("%d",&nuevo->edad);
				break;
				
			case 4:
                printf("\tIngrese las nuevas horas trabajadas:\t");
                scanf("%d",&nuevo->hrsx);
                nuevo->suel=nuevo->hrsx*50;
                break;
				
				default:
				    system("cls");
                printf("Opcion no valida");
                getch();
		}
	}
	system("cls");
	Listas_Simples();
}
}

void Listas_Simple_Mostrar(){
	    
     system("CLS");
     if(cabecera==NULL)
     printf("Lista de datos vacio\n");
     else
     {
     printf("====Los datos ingresados son:====\n\n");
     aux=cabecera;
     while(aux!=NULL)
     {
              printf("\n\tNombre del empleado:%s\n",aux->nom);
              printf("\tA%cos de experiencia:%d \n",164,aux->expe);
              printf("\tEdad:%d...\n",aux->edad);
			if(aux->expe==1){
				printf("\tSu sueldo por tener  un 1 año de experiencia es: $2500 \n");
				
				printf("\tLas horas extras que trabajo son: %d\n", aux->hrsx);
				aux->suel=aux->hrsx*50;
				aux->suel=aux->suel+2500;
				printf("\tSu sueldo es total es de: %0.2f \n",aux->suel);
				
			}else if(aux->expe==2){
				printf("\tSu sueldo por tener  un 2 a%co de experiencia es: $3500\n"),164;
				
				printf("\tLas horas extras que trabajo son: %d\n", aux->hrsx);
				aux->suel=aux->hrsx*50;
				aux->suel=aux->suel+3500;
				printf("\tSu sueldo es total es de: %0.2f \n",aux->suel);
				
			}else if(aux->expe==3){
				printf("\tSu sueldo por tener  un 3 año de experiencia es: $4500\n");
				
				printf("\tLas horas extras que trabajo son: %d \n", aux->hrsx);
				aux->suel=aux->hrsx*50;
				aux->suel=aux->suel+4500;
				printf("\tSu sueldo es total es de: %0.2f \n",aux->suel);
				
			}else if(aux->expe==4){
				printf("\tSu sueldo por tener  un 4 a%co de experiencia es: $5500\n",164);
				
				printf("\tLas horas extras que trabajo son: %d\n", aux->hrsx);
				aux->suel=aux->hrsx*50;
				aux->suel=aux->suel+5500;
				printf("\tSu sueldo es total es de: %0.2f \n",aux->suel);
				
			}else if(aux->expe==5){
				printf("\tSu sueldo por tener  mayor de 5 a%cso de experiencia es: $6500\n",164);
				
				printf("\tLas horas extras que trabajo son: %d \n", aux->hrsx);
				aux->suel=aux->hrsx*50;
				aux->suel=aux->suel+6500;
				printf("\tSu sueldo es total es de: %0.2f \n",aux->suel);
			}
        
        aux=aux->psig;
        printf("\n");
     }
     }
     printf("Total de nodos:%d\n",contnodo_Simple); 
     getch();
     system("CLS");
     Listas_Simples();
} 



///////////////////////////////////////////////////////////////Listas Dobles-----------------------------------------

void Listas_Dobles()
    {
       bool repite = true;
       int opcion;
       // Titulo del menú y nombres de las opciones
       const char *titulo = "MENU PARA LISTAS DOBLES";
       const char *opciones[] = {"INGRESAR NUEVOS DATOS DEL TRABAJADOR", "ELIMINAR DATOS DE ALGUN TRABAJOR", "MODIFICAR DATOS DE ALGUN TRABAJADOR", "MOSTRAR DATOS DE TODOS LOS TRABAJADORES", "REGRESAR AL MENU"};
       int n = 5;  // Numero de opciones
       do {
          opcion = menu(titulo, opciones, n);
     
          system("cls");
          switch (opcion) {
             case 1:
                Listas_Dobles_Insertar();
                break;
     
             case 2:
                Listas_Dobles_Eliminar();
                break;
            
             case 3:
                Listas_Dobles_Modificar();
                break;
                
             case 4:
                Listas_Dobles_Mostrar();
                break;   
     
             case 5:
                listas();
                break;
          }
     
       } while(repite);
    }    
    
    void Listas_Dobles_Insertar()
    {
       bool repite = true;
       int opcion;
       // Titulo del menú y nombres de las opciones
       const char *titulo = "MENU PARA INSERTAR";
       const char *opciones[] = {"CREAR NUEVOS DATOS", "INSERTAR DATOS AL INICIO", "INSERTAR ENTRE DATOS", "INSERTAR DATOS AL FINAL", "REGRESAR AL MENU ANTERIOR"};
       int n = 5;  // Numero de opciones 
       do {
          opcion = menu(titulo, opciones, n);
     
          system("cls");
          switch (opcion) {
             case 1:
                CrearCab_Doble();
                break;
     
             case 2:
                Insertar_Inicio_Doble();
                break;
            
             case 3:
                Insertar_Entre_Doble();
                break;
                
             case 4:
                Insertar_Final_Doble();
                break;   
     
             case 5:
                Listas_Dobles();
                break;
          }
       } while(repite);
    }
    
    void CrearCab_Doble(){
	 if(cabecera_Doble!=NULL)
           printf("Ya existe cabecera!!\n");
           else
           {
              nuevo_Doble=(struct lisdob*)malloc(sizeof(struct lisdob));
              if(nuevo_Doble==NULL)
              printf("Error de asignacion\n");
           else
           {
              printf("\tIngrese el nombre del empleado: ");
              scanf("%s",&nuevo_Doble->nom);
              printf("\tIngrese a%cos de experiencia de 1  a  5 a%cos: ",164,164);
              scanf("%d",&nuevo_Doble->expe);
              printf("\tIngrese la edad del empleado:  ");
              scanf("%d",&nuevo_Doble->edad);
              printf("\tIngrese horas extras trabajdas  (POR 1 HORA EXTRA SE LE PAGA $50): ");
              scanf("%d",&nuevo_Doble->hrsx);
              nuevo_Doble->suel=nuevo_Doble->hrsx*50;
              nuevo_Doble->psig=NULL;
              nuevo_Doble->pant=NULL;
              cabecera_Doble=nuevo_Doble;
              fin=cabecera_Doble;
              contnodo_Doble=contnodo_Doble+1;
              }
 }           
      system("CLS");
      getch();
      Listas_Dobles_Insertar();
  }
  void Insertar_Inicio_Doble(){
	system("CLS");
     if(cabecera_Doble==NULL || contnodo_Doble==0)
    {
            printf("\t¡¡¡Alvertencia!!!\n\n");
            printf("Imposible insertar, al menos debe de existir 1 solo dato\n");
            system("CLS");
            Listas_Dobles_Insertar();
            }
       else
        {
             nuevo_Doble=(struct lisdob*)malloc(sizeof(struct lisdob));
              if(nuevo_Doble==NULL)
          {
            printf("Error de asignacion\n");
           }
           else
           {
              printf("\tIngrese el nombre del trabajador: ");
              scanf("%s",&nuevo_Doble->nom);
              printf("\tIngrese años de experiencia del trabajador: ");
              scanf("%d",&nuevo_Doble->expe);
              printf("Ingrese la edad del trabajador:  ");
              scanf("%d",&nuevo_Doble->edad);
              printf("Ingrese horas extras trabajdas (POR 1 HORA EXTRA SE LE PAGA $50):  ");
              scanf("%d",&nuevo_Doble->hrsx);
              nuevo_Doble->suel=nuevo_Doble->hrsx*50;
              nuevo_Doble->psig=NULL;
			  nuevo_Doble->pant=NULL;    
              aux_Doble=cabecera_Doble;
              nuevo_Doble->psig=aux_Doble;
              nuevo_Doble->pant=aux_Doble;
              cabecera_Doble=nuevo_Doble;
              contnodo_Doble=contnodo_Doble+1;
           }
           }
               getch();
               system("CLS");
               Listas_Dobles_Insertar(); 
	
} 
void Insertar_Entre_Doble(){
	if(cabecera_Doble==NULL || contnodo_Doble==1)
     {
     printf("Imposible insertar, al menos deben existir 2 datos\n");
     getch();
     }
     else
     {
       printf("Posicion a Insertar:\n");
         scanf("%d",&Posi_Doble);
         if(Posi_Doble==1 || Posi_Doble==contnodo_Doble){
         printf("Invalido insertar en extremos\n");
         }
         else
         {
             aux_Doble=cabecera_Doble;
             for(i=1;i<Posi_Doble;i++)
             {
                               aux1_Doble=aux_Doble;
                               aux_Doble=aux_Doble->psig;
             }
             
             nuevo_Doble=(struct lisdob*)malloc(sizeof(struct lisdob));
              if(nuevo_Doble==NULL)
               {
                printf("Error de asignacion\n");
               }
             else
             {
               printf("\tIngrese el nombre del trabajador: ");
               scanf("%s",&nuevo_Doble->nom);
               printf("\tIngrese a%cos de experiencia del trabajador: ",164);
               scanf("%d",&nuevo_Doble->expe);
               printf("\tIngrese la edad del trabajador:  ");
               scanf("%d",&nuevo_Doble->edad);
               printf("Ingrese horas extras trabajdas (POR 1 HORA EXTRA SE LE PAGA $50): ");
               scanf("%d",&nuevo_Doble->hrsx);
               nuevo_Doble->psig=NULL;
               nuevo_Doble->pant=NULL;
               nuevo_Doble->suel=nuevo_Doble->hrsx*50;
             nuevo_Doble->psig=aux_Doble;
             aux1_Doble->psig=nuevo_Doble;
             //nuevo_Doble->pant=;
             aux_Doble->pant=nuevo_Doble;
             contnodo_Doble=contnodo_Doble+1;
         }
         }
         }
         getch();
         system("CLS");
          Listas_Dobles_Insertar();
}
void Insertar_Final_Doble(){
	system("CLS");
     nuevo_Doble=(struct lisdob*)malloc(sizeof(struct lisdob));
     if(nuevo_Doble==NULL)
     {
       printf("Error de asignacion\n");
     }
     else
  {
         if(cabecera_Doble==NULL){
         printf("¡¡¡Alvertencia!!!\n");
           printf("Imposible Insertar, al menos debe existir un dato\n");
         }
         else
         {
         printf("\tIngrese el nombre del trabajador: ");
               scanf("%s",&nuevo_Doble->nom);
               printf("\tIngrese a%cos de experiencia del trabajador: ",164);
               scanf("%d",&nuevo_Doble->expe);
               printf("\tIngrese la edad del trabajador:  ");
               scanf("%d",&nuevo_Doble->edad);
               printf("Ingrese horas extras trabajdas \t(POR 1 HORA EXTRA SE LE PAGA $50): ");
               scanf("%d",&nuevo_Doble->hrsx);
         nuevo_Doble->psig=NULL;
         nuevo_Doble->pant=NULL;
         aux_Doble=cabecera_Doble;
         while(aux_Doble->psig!=NULL)
         {
            aux_Doble=aux_Doble->psig;
         }
            aux_Doble->psig=nuevo_Doble;
            nuevo_Doble->pant=aux_Doble;
            fin=nuevo_Doble;
            contnodo_Doble=contnodo_Doble+1;
         }
            getch();
         }
system("CLS");
Listas_Dobles_Insertar();
}
    
     void Listas_Dobles_Eliminar()
    {
       bool repite = true;
       int opcion;
     
       // Titulo del menú y nombres de las opciones
       const char *titulo = "MENU PARA ELIMINAR";
       const char *opciones[] = {"ELIMINAR DATOS DEL PRIMER EMPLEADO", "ELIMINAR DATOS DEL ULTIMO EMPLEADO", "ELEGIR LA ELIMINAR DE DATOS ", "REGRESAR AL MENU ANTERIOR"};
       int n = 4;  // Numero de opciones
     
       do {
          opcion = menu(titulo, opciones, n);
     
          system("cls");
          switch (opcion) {
             case 1:
                Eliminar_Inicio_Doble();
                break;
     
             case 2:
                Eliminar_Final_Doble();
                break;
            
             case 3:
                Eliminar_Entre_Doble();
                break;
     
             case 4:
                Listas_Dobles();
                break;
          }
     
       } while(repite);
    }   
    
    void Eliminar_Inicio_Doble(){
    if(cabecera==NULL)
       printf("No hay datos para eliminar\n");
       else
       { 
           if(contnodo_Doble==1)
            {
                           //tneto=tneto-cabecera->total;  // el salario que descuenta
                           free(cabecera);
                           cabecera=NULL;
                           
                           contnodo_Doble=contnodo_Doble-1;
            }
            else
            {
            aux=cabecera;
            //tneto=tneto-aux->total;  //poner la variable del salario
            cabecera=cabecera->psig;
            free(aux);
            aux=NULL;
           contnodo_Doble=contnodo_Doble-1;
            }
       }
            system("CLS");
            getch();
            Listas_Dobles_Eliminar();  
}

void Eliminar_Entre_Doble(){
    
    system("CLS");
     if(cabecera==NULL || contnodo_Doble <=2){
     printf("¡¡¡Alvertencia!!!\n");
     printf("Imposible eliminar\n");
     }
     else
     {
         printf("Posicion a eliminar:\n");
         scanf("%d",&Posi_Doble);
         if(Posi_Doble==1 || Posi_Doble==contnodo_Doble)
         printf("No se puede eliminar en los extremos\n");
         else
         {
             aux=cabecera;
             for(i=1;i<Posi_Doble;i++)
             {
                               aux1=aux;
                               aux=aux->psig;
             }
                               //tneto=tneto-aux->total;
                               aux1->psig=aux1->psig->psig;
                               free(aux);
                               aux=NULL;
                               contnodo_Doble=contnodo_Doble-1;
         }
     }
     getch();
     system("CLS");
     Listas_Dobles_Eliminar();
}


void Eliminar_Final_Doble()
{
     system("CLS");
     if(cabecera==NULL){
     printf("La lista esta  vacia\n");
     }
     else
     { aux_Doble=cabecera_Doble;
         if(contnodo_Doble==1)
         {
                       free(cabecera_Doble);
                       cabecera_Doble=NULL;
                       contnodo_Doble=contnodo_Doble-1;
                       printf("Datos del trabajador eliminado!!\n");
         }
         else
         {
         aux_Doble=cabecera_Doble;
         
         while(aux_Doble->psig!=NULL)
         {
                               aux1_Doble=aux_Doble;
                               aux_Doble=aux_Doble->psig;
         }
         free(aux_Doble);
         aux_Doble=NULL;
         aux1_Doble->psig=NULL;
         contnodo_Doble=contnodo_Doble-1;
         printf("Datos del trabajador eliminado!!\n");
         }
     }
     getch();
     system("CLS");
     Listas_Dobles_Eliminar();
}


void Listas_Dobles_Modificar(){
	if (cabecera==NULL){
		printf("La lista esta vacia");
		
	}
	else
	{
		aux=cabecera;
		printf("Ingrese el numero de lista que desea modificar");
		scanf("%d",&nummod);
		for(i=1;i<nummod;i++)
		{
			aux_Doble->psig;
			aux_Doble->pant;
			
		}
		
		printf("los datos de esta lista es:");
		printf("\n\n");
		printf("\t1.-Nombre del trabajador: %s",aux_Doble->nom);
		printf("\t2.-Años de experiencia del trabajador: %d",aux_Doble->expe);
		printf("\t3.-Edad del trabajador: %d",aux_Doble->edad);
		printf("\t4.-Horas trabajadas (POR 1 HORA EXTRA SE LE PAGA $50)\n",aux_Doble->hrsx);
		printf("\n\n");
		printf ("cual desea modificar");
		scanf("%d",&damod);
		switch(damod)
		{
			case 1:
				printf("Ingrese el nuevo nombre del trabajador:\t");
				scanf("%s",&nuevo_Doble->nom);
				nuevo_Doble->psig=NULL;
				nuevo_Doble->pant=NULL;
				break;
				
			case 2:
				printf("\tIngrese los a%cos de exeriencia:\t",164);
				scanf("%d",&nuevo_Doble->expe);
				nuevo_Doble->psig=NULL;
				nuevo_Doble->pant=NULL;
				break;
			case 3:
				printf("\tIngrese la nueva edad:\t");
				scanf("%d",&nuevo->edad);
				nuevo_Doble->psig=NULL;
				nuevo_Doble->pant=NULL;
				break;
				
				case 4:
				    printf("\tIngrese las nuevas horas trabajadas:\t");
                scanf("%d",&nuevo_Doble->hrsx);
                nuevo->suel=nuevo->hrsx*50;
                break;
                
                default:
                printf("La opcion que eligio no exixte\n");
                break;
		}
	}

	getch();
	Listas_Dobles();
}
    void Listas_Dobles_Mostrar(){
     system("CLS");
     
     if(cabecera_Doble==NULL)
     printf("Lista vacia\n");
       else
     {
         printf("En que sentido quieres ver la informacion: 1.Izq-der   2. Der-Izq\n");
         scanf("%d",&num_Doble);
         if(num_Doble==1)
         {
         
            printf("====Los datos ingresados son:====\n\n");
            aux_Doble=cabecera_Doble;
            while(aux_Doble!=NULL)
            {
              printf("\n\tNombre del empleado:%s\n",aux_Doble->nom);
              printf("\tA%cos de experiencia:%d \n",164,aux_Doble->expe);
              printf("\tEdad:%d...\n",aux_Doble->edad);
              
              if(aux_Doble->expe==1){
				printf("\tSu sueldo por tener  un 1 a%co de experiencia es: $2500 \n",164);
				
				printf("\tLas horas extras que trabajo son: %d\n", aux_Doble->hrsx);
				aux_Doble->suel=aux->hrsx*50;
				aux_Doble->suel=aux->suel+2500;
				printf("\tSu sueldo es total es de: %0.2f \n",aux_Doble->suel);
				
			}else if(aux_Doble->expe==2){
				printf("\tSu sueldo por tener  un 2 a%co de experiencia es: $3500\n"),164;
				
				printf("\tLas horas extras que trabajo son: %d\n", aux_Doble->hrsx);
				aux_Doble->suel=aux_Doble->hrsx*50;
				aux_Doble->suel=aux_Doble->suel+3500;
				printf("\tSu sueldo es total es de: %0.2f \n",aux_Doble->suel);
				
			}else if(aux_Doble->expe==3){
				printf("\tSu sueldo por tener  un 3 a%co de experiencia es: $4500\n",164);
				
				printf("\tLas horas extras que trabajo son: %d \n", aux_Doble->hrsx);
				aux_Doble->suel=aux_Doble->hrsx*50;
				aux_Doble->suel=aux_Doble->suel+4500;
				printf("\tSu sueldo es total es de: %0.2f \n",aux_Doble->suel);
				
			}else if(aux_Doble->expe==4){
				printf("\tSu sueldo por tener  un 4 a%co de experiencia es: $5500\n",164);
				
				printf("\tLas horas extras que trabajo son: %d\n",aux_Doble->hrsx);
				aux_Doble->suel=aux_Doble->hrsx*50;
				aux_Doble->suel=aux_Doble->suel+5500;
				printf("\tSu sueldo es total es de: %0.2f \n",aux_Doble->suel);
				
			}else if(aux_Doble->expe==5){
				printf("\tSu sueldo por tener  mayor de 5 a%cso de experiencia es: $6500\n",164);
				
				printf("\tLas horas extras que trabajo son: %d \n", aux_Doble->hrsx);
				aux_Doble->suel=aux_Doble->hrsx*50;
				aux_Doble->suel=aux_Doble->suel+6500;
				printf("\tSu sueldo es total es de: %0.2f \n",aux_Doble->suel);
			}
             
              
               aux_Doble=aux_Doble->psig;
               printf("\n");
            }
     
     
                printf("Total de datos de trabajadores: %d\n",contnodo_Doble); 
     }
     
     else
     {
         if(num_Doble==2)
         {
                       aux_Doble=fin;
                       while(aux_Doble!=NULL)
                       {
                         printf("\n\tNombre del empleado:%s\n",aux_Doble->nom);
              printf("\tA%cos de experiencia:%d \n",164,aux_Doble->expe);
              printf("\tEdad:%d...\n",aux_Doble->edad);
              
              if(aux_Doble->expe==1){
				printf("\tSu sueldo por tener  un 1 a%co de experiencia es: $2500 \n",164);
				
				printf("\tLas horas extras que trabajo son: %d\n", aux_Doble->hrsx);
				aux_Doble->suel=aux->hrsx*50;
				aux_Doble->suel=aux->suel+2500;
				printf("\tSu sueldo es total es de: %0.2f \n",aux_Doble->suel);
				
			}else if(aux_Doble->expe==2){
				printf("\tSu sueldo por tener  un 2 a%co de experiencia es: $3500\n"),164;
				
				printf("\tLas horas extras que trabajo son: %d\n", aux_Doble->hrsx);
				aux_Doble->suel=aux_Doble->hrsx*50;
				aux_Doble->suel=aux_Doble->suel+3500;
				printf("\tSu sueldo es total es de: %0.2f \n",aux_Doble->suel);
				
			}else if(aux_Doble->expe==3){
				printf("\tSu sueldo por tener  un 3 a%co de experiencia es: $4500\n",164);
				
				printf("\tLas horas extras que trabajo son: %d \n", aux_Doble->hrsx);
				aux_Doble->suel=aux_Doble->hrsx*50;
				aux_Doble->suel=aux_Doble->suel+4500;
				printf("\tSu sueldo es total es de: %0.2f \n",aux_Doble->suel);
				
			}else if(aux_Doble->expe==4){
				printf("\tSu sueldo por tener  un 4 a%co de experiencia es: $5500\n",164);
				
				printf("\tLas horas extras que trabajo son: %d\n",aux_Doble->hrsx);
				aux_Doble->suel=aux_Doble->hrsx*50;
				aux_Doble->suel=aux_Doble->suel+5500;
				printf("\tSu sueldo es total es de: %0.2f \n",aux_Doble->suel);
				
			}else if(aux_Doble->expe==5){
				printf("\tSu sueldo por tener  mayor de 5 a%cso de experiencia es: $6500\n",164);
				
				printf("\tLas horas extras que trabajo son: %d \n", aux_Doble->hrsx);
				aux_Doble->suel=aux_Doble->hrsx*50;
				aux_Doble->suel=aux_Doble->suel+6500;
				printf("\tSu sueldo es total es de: %0.2f \n",aux_Doble->suel);
			}  
                          aux_Doble=aux_Doble->pant;
                          }
        printf("\n"); 
        }
        printf("Total de datos de trabajadores: %d\n",contnodo_Doble); 
        }               
 }    
     getch();
     system("CLS");
     Listas_Dobles();
    }
    
    
    
    
    
    
    
    
    
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////Controladores----------
     
    int menu(const char titulo[], const char *opciones[], int n)
    {
       int opcionSeleccionada = 1;  // Indica la opcionSeleccionada
       int tecla;
       bool repite = true; // controla el bucle para regresar a la rutina que lo llamo, al presionar ENTER     
       do {
          system("cls");
          system("color 1e");
          gotoxy(5, 3 + opcionSeleccionada); cout << "==>" << endl;
     
          // Imprime el título del menú
          gotoxy(15, 2); cout << titulo;

          // Imprime las opciones del menú
          for (int i = 0; i < n; ++i) {
             gotoxy(10, 4 + i); cout << i + 1 << ") " << opciones[i];
          }
     
          // Solo permite que se ingrese ARRIBA, ABAJO o ENTER
          do {
             tecla = getch2();
             // gotoxy(15, 15); cout << "tecla presionada: " << (char)tecla << " = " << tecla;
          } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);
          switch (tecla) {
             case ARRIBA:   // En caso que se presione ARRIBA
                opcionSeleccionada--;
                if (opcionSeleccionada < 1) {
                   opcionSeleccionada = n;
                }
                break;
             case ABAJO:
                opcionSeleccionada++;
                if (opcionSeleccionada > n) {
                   opcionSeleccionada = 1;
                }
                break;
             case ENTER:
                repite = false;
                break;
          }
       } while (repite);
       return opcionSeleccionada;
    }
