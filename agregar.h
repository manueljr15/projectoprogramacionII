ARBOLB crearNodo(int id){//crear nodo y guardar en el archivo
	bool rep;
	char promedio[10];
	ARBOLB nuevoNodo = new(struct nodo);
	FILE *archivo;
	char status[10];
	archivo=fopen("cocineros.xls", "a");
	if(archivo!=NULL){
		nuevoNodo->id_cocinero=id;
		cout<<"ID generado: "<<nuevoNodo->id_cocinero<<endl;
		cout<<"Ingresa nombre: ";
		cin>>nuevoNodo->nombre;
		fflush(stdin);
		nuevoNodo->promedio=0;
		
		strcpy(nuevoNodo->turno, "D");
		nuevoNodo->pedidosA=0;
		nuevoNodo->ganancias=0;
		do{
			rep=true;
			cout<<"Status cocinero: ";
			cin>>status;
			rep=validaStatus(status);
		}while(rep==false);
		strcpy(nuevoNodo->status,status);
		fprintf(archivo, "%d\t", nuevoNodo->id_cocinero);
		fprintf(archivo, "%s\t", nuevoNodo->nombre);
		fprintf(archivo, "%.2f\t", nuevoNodo->promedio);
		fprintf(archivo, "%s\t", nuevoNodo->status);
		fprintf(archivo, "%s\t", nuevoNodo->turno);
		fprintf(archivo, "%.2f\t", nuevoNodo->pedidosA);
		fprintf(archivo, "%.2f\n", nuevoNodo->ganancias);
		
	}
	fclose(archivo);
	
	nuevoNodo->izq = NULL;
	nuevoNodo->der = NULL;
	cout<<"Cocinero agregado exitosamente."<<endl;
	system("pause");
	return nuevoNodo;
}

bool insertar (ARBOLB &arbol, int id){//insertar nuevo nodo
	if(arbol == NULL){
		arbol=crearNodo(id);
		return true;
	}
	else{
		if(id < arbol->id_cocinero){
			insertar(arbol->izq, id);
		} 
		else{
			if(id > arbol->id_cocinero){
				insertar(arbol->der, id);
			}
			else{
				return false;
			}
		}
		
	}
		
		
			
}

void inor(ARBOLB arbol){//imprimir datos 
	if(arbol!= NULL){
		inor(arbol->izq);
		cout<<endl<<setw(5)<<arbol->id_cocinero<<setw(15)<<arbol->nombre<<setw(10)<<fixed<<setprecision(2)<<arbol->promedio<<setw(15)<<arbol->status
		<<setw(15)<<arbol->turno;
		inor(arbol->der);
	}
}
