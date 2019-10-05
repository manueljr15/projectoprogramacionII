void preActualizar(ARBOLB arbol){//actualizar los datos en un archivo auxiliar
	FILE *archivo;
	if(arbol!= NULL){
		archivo=fopen("auxiliar.xls", "a");
		if(archivo!=NULL){
			fprintf(archivo, "%d\t", arbol->id_cocinero);
			fprintf(archivo, "%s\t", arbol->nombre);
			fprintf(archivo, "%f\t", arbol->promedio);
			fprintf(archivo, "%s\t", arbol->status);
			fprintf(archivo, "%s\t", arbol->turno);
			fprintf(archivo, "%f\t", arbol->pedidosA);
			fprintf(archivo, "%f\n", arbol->ganancias);
		}
		fclose(archivo);
		preActualizar(arbol->izq);
		preActualizar(arbol->der);
	}
}

void actualizarDatos(){//pasar los datos del archivo auxiliar al archivo principal
	FILE *archivo, *auxiliar;
	int id;
	float promedio, ganancias,pedidosA;
	char nombre[20], status[10], turno[10];
	preActualizar(arbol);
	archivo=fopen("cocineros.xls", "w");
	auxiliar=fopen("auxiliar.xls", "r");
	if(auxiliar!=NULL){
		while(!feof(auxiliar)){
			fscanf(auxiliar, "%d\t", &id);
			fscanf(auxiliar, "%s\t", &nombre);
			fscanf(auxiliar, "%f\t", &promedio);
			fscanf(auxiliar, "%s\t", &status);
			fscanf(auxiliar, "%s\t", &turno);
			fscanf(auxiliar, "%f\t", &pedidosA);
			fscanf(auxiliar, "%f\n", &ganancias);
			if(archivo!=NULL){
				fprintf(archivo, "%d\t", id);
				fprintf(archivo, "%s\t", nombre);
				fprintf(archivo, "%f\t", promedio);
				fprintf(archivo, "%s\t", status);
				fprintf(archivo, "%s\t", turno);
				fprintf(archivo, "%f\t", pedidosA);
				fprintf(archivo, "%f\n", ganancias);
			}
		}
	}
	fclose(auxiliar);
	fclose(archivo);
	remove("auxiliar.xls");
}


