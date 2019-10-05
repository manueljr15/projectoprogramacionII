bool personal(){//funciones de personal
	recuperarDatos(arbol);
	bool entrar, rep, asig, pedido=false, pers;
	char accion[20], atendido[2];
	int validado,totalTacos=0, totalHamburguesas=0, id, tacos2, hamburguesas2;
	char tacos[10], hamburguesas[10]; 
	int a;
	float aa, noPedido=0;
	float total;
	FILE *archivo;
	archivo=fopen("pedidos.xls", "r");
	if(archivo!=NULL){
		while(!feof(archivo)){
			fscanf(archivo, "%f\t", &noPedido);
			fscanf(archivo, "%d\t", &a);
			fscanf(archivo, "%d\t", &a);
			fscanf(archivo, "%f\n", &aa);
		}
	} 
	fclose(archivo);
	
	do{
		rep=true;
			do{
				system("cls");
				cout<<"PEDIDOS:"<<endl<<endl;
				cout<<"Menu de comida"<<endl;
				cout<<"1. Tacos "<<endl<<"2. Hamburguesas"<<endl<<"3. Finalizar Pedido"<<endl<<"4. Volver a inicio"<<endl;
				cin>>accion;
				validado=validarNum(accion);
			}while(validado==0);
			switch(validado){
				case 1:
					cout<<"Cantidad de tacos: ";
					fflush(stdin);
					
					do{
						rep=true;
						cin>>tacos;
						rep=validaTH(tacos);	
					}while(rep==false);
					
					tacos2=atoi(tacos);
					
					fflush(stdin);
					totalTacos=totalTacos+tacos2;
					
					rep=false;
					
					break;
				case 2:
					cout<<"Cantidad de hamburguesas: ";
					fflush(stdin);
					do{
						rep=true;
						cin>>hamburguesas;
						rep=validaTH(hamburguesas);	
					}while(rep==false);
					
					hamburguesas2=atoi(hamburguesas);
					fflush(stdin);
					totalHamburguesas=totalHamburguesas+hamburguesas2;
					
					rep=false;
					
					break;
				case 3:
					if(totalHamburguesas==0 && totalTacos==0){
						cout<<"Agregue tacos y/o hamburguesas."<<endl;
						system("pause");
					}else{
						noPedido++;
						recuperarDatos(arbol);
						asignarCocinero(arbol, noPedido, totalTacos, totalHamburguesas, total, pedido, asig);
						if(asig==true){
							total=totalTacos*precioTacos+totalHamburguesas*precioHamburguesa;
							archivo=fopen("pedidos.xls", "a");
							fprintf(archivo, "%f\t", noPedido);
							fprintf(archivo, "%d\t", totalTacos);
							fprintf(archivo, "%d\t", totalHamburguesas);
							fprintf(archivo, "%.2f\n", total);
							fclose(archivo);
						}
						else cout<<"No hay cocineros disponibles"<<endl;
					}
					cout<<endl<<"¡Gracias!"<<endl;
					system("pause");
					id=160726+rand()%11;
					desocuparCocinero(arbol, id);
					actualizarDatos();
					rep=true;
					
					break;
				case 4:
					
					break;
				default:
					rep=false;
					break;
			}
	}while(rep==false);
	return true;
}
