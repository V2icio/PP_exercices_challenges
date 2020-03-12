typedef struct No{
    int info;
    struct No *link;
} no;

void iniLista(no **L)
{
    *L = NULL;
}

void percoreLista(no *L)
{
    no *P;
    P = L;
    while(P != NULL)
    {
        printf("%d  ",P->info);
        P = P->link;
    }
	printf("\n");
}

void insereFinalLista(no **L, int valor)
{
    no *P, *N;
    N = (no *) malloc (sizeof(no));
    N->info = valor;
    N->link = NULL;
    if(*L == NULL)
    {
        *L = N;
    }
    else
	{
		P = *L;
	    while(P->link != NULL)
	    {
	        P = P->link;
	    }
	    P->link = N;
	}
}

int removeFinalLista(no **L)
{
	no *P;
	//P = (no *) malloc (sizeof(no));
	P = *L;
	int valor;
	if(P == NULL)
	{
		printf("lista vazia");
		return -1;
	}
	if(P->link == NULL)
	{
		valor = P->info;
		//free(P->link);
		free(P);
		*L = NULL;
		return valor;
	}
	while(P->link->link != NULL)
	{
		P = P->link;
	}
	valor = P->link->info;
	free(P->link);
	P->link = NULL;
	return valor;
}

void insereInicio(no **L, int valor)
{
	no *P;
    P = (no *) malloc (sizeof(no));
	P->info = valor;
	P->link = *L;
	*L = P;
}

int removeInicio(no **L)
{
	no *P;
    //P = (no *) malloc (sizeof(no));
	P = *L;
	int valor;
	if(P==NULL)
	{
		printf("lista vazia");
		return -1;
	}
	valor = P->info;
	*L = P->link;
	free(P);
	return valor;
}

void RemoveValor(no **L, int valor)
{
    no *P;
    //P = (no *)malloc(sizeof(no));

    no *Ant;
    //Ant = (no *)malloc(sizeof(no));

    if(L==NULL)
    {
        printf("fila vazia\n");
        return ;
    }

    P = *L;
    
    if(P->info == valor || P->link == NULL)
    {
        if(P->link == NULL)
        {
            if(P->info == valor)
            {
                free(P);
                *L = NULL;
            }            
            return ;
        }
		else
		{
			*L = P->link;
			free(P);
			return ;
		}
    }
    
    P = P->link;
    Ant = *L;

    while(P != NULL)
    {
        if(P->info == valor)
        {
            Ant->link = P->link;
            free(P);            
            return ;
        }
		/*
        if(P->link == NULL)
        {
            return ;
        }
		*/
        Ant = Ant->link;
        P = P->link;
    }
}

void insereOrdenada(no **L, int valor)
{
	no *P, *N;
    N = (no *)malloc(sizeof(no));
	N->info = valor;
	
	if(*L == NULL)
	{
		*L = N;
		N->link = NULL;
		return ;
	}

	P = *L;
	
	if(P->info > valor)
	{
		N->link = P;
		*L = N;
		return ;
	}

	while(P->link!=NULL && P->link->info < valor)
	{
		P = P->link;
	}
	N->link = P->link;
	P->link = N;
}

int retornaUltimo(no *L)
{
	if(L == NULL)
	{
		return -1;
	}
    no *P;
    P = L;
    while(P->link != NULL)
    {
        P = P->link;
    }
	return P->info;
}

int retLength(no *L)
{
	no *P;
	int cont = 0;
	P = L;
	while(P != NULL)
	{
		cont++;
		P = P->link;
	}
}

int retTermo(no *L, int x)
{
	no *P;
	P=L;
	for(int i=0; i<x; i++)
	{
		P=P->link;
	}
	return P->info;
}

no* pesquisaItem(no **L, int valor)
{
	no *P;
	P = *L;
	if(*L == NULL)
	{
		return NULL;
	}
	if(P->info == valor )
	{
		return P;
	}
	while(P->link != NULL)
	{
		if(P->info == valor )
		{
			return P;
		}

		P = P->link;
	}
	return NULL;
}



