ARBOLB recuperarNodo(char nombre[20], int id, float promedio, char status[10], char turno[10], float pedidosA, float ganancias){
	ARBOLB nuevoNodo=new(struct nodo);
	nuevoNodo->promedio=promedio;
	strcpy(nuevoNodo->nombre, nombre);
	strcpy(nuevoNodo->status, status);
	strcpy(nuevoNodo->turno, turno);
	nuevoNodo->pedidosA=pedidosA;
	nuevoNodo->ganancias=ganancias;
	nuevoNodo->id_cocinero=id;
	nuevoNodo->izq=NULL;
	nuevoNodo->der=NULL;
	return nuevoNodo;
}

void recuperando(ARBOLB &arbol, char nombre[20], int id, float promedio, char status[10], char turno[10], float pedidosA, float ganancias){
	if(arbol==NULL){
		arbol=recuperarNodo(nombre, id, promedio, status, turno, pedidosA, ganancias);
	}
	else if (id<arbol->id_cocinero)
		recuperando(arbol->izq, nombre, id, promedio, status, turno, pedidosA, ganancias);
		else if(id>arbol->id_cocinero)
			recuperando(arbol->der, nombre, id, promedio, status, turno, pedidosA, ganancias);
}

void recuperarDatos(ARBOLB &arbol){//recuperar datos de cocineros de archivo
	FILE *recuperarArchivo;
	int id;
	char nombre[20], status[10], turno[10];
	float promedio, ganancias,pedidosA;
	recuperarArchivo=fopen("cocineros.xls", "r");
	if(recuperarArchivo!=NULL){
		while(!feof(recuperarArchivo)){
			fscanf(recuperarArchivo, "%d\t", &id);
			fscanf(recuperarArchivo, "%s\t", &nombre);
			fscanf(recuperarArchivo, "%f\t", &promedio);
			fscanf(recuperarArchivo, "%s\t", &status);
			fscanf(recuperarArchivo, "%s\t", &turno);
			fscanf(recuperarArchivo, "%f\t", &pedidosA);
			fscanf(recuperarArchivo, "%f\t", &ganancias);
			recuperando(arbol, nombre, id, promedio, status, turno, pedidosA, ganancias);
		}
	}else{
		fclose(recuperarArchivo);	
		remove("cocineros.xls");
	}
	fclose(recuperarArchivo);	
	
}
