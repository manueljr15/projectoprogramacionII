void inorModificar(ARBOLB arbol, int id){//modificar datos de un nodo del arbol
	char opc[20], status[10];
	int validado;
	bool rep;
	if(arbol!= NULL){
		inorModificar(arbol->izq, id);
		if(id==arbol->id_cocinero){
			do{
				system("cls");
				cout<<"Cocinero encontrado, mostrando datos: "<<endl;
				cout<<"ID"<<setw(15)<<"NOMBRE"<<setw(15)<<"PROMEDIO"<<setw(15)<<"STATUS"<<endl;
				cout<<arbol->id_cocinero<<setw(15)<<arbol->nombre<<setw(10)<<fixed<<setprecision(2)<<arbol->promedio<<setw(15)<<arbol->status<<endl;
				cout<<"Seleccione una opcion"<<endl<<"1.Modificar nombre"<<endl<<"2.Modificar status"<<endl;
				cin>>opc;
				validado=validarModif(opc);
			}while(validado==0);
			
			switch(validado){
				case 1:
					cout<<"Ingrese nuevo nombre: ";
					cin>>arbol->nombre;
					break;
				case 2:
					cout<<"Ingrese cambio de status: ";
					do{
						rep=true;
						cin>>status;
						rep=validaStatus(status);
					}while(rep==false);
					strcpy(arbol->status,status);
					break;
			}
			cout<<"Cocinero modificado."<<endl;
			system("pause");
		}
		inorModificar(arbol->der, id);
	}
}

void inorReportar(ARBOLB arbol, int id){
	if(arbol!=NULL){
		inorReportar(arbol->izq, id);
		if(id==arbol->id_cocinero){
			cout<<"ID"<<setw(15)<<"NOMBRE"<<setw(15)<<"PROMEDIO"<<setw(15)<<"STATUS"<<endl;
			cout<<arbol->id_cocinero<<setw(15)<<arbol->nombre<<setw(10)<<fixed<<setprecision(2)<<arbol->promedio<<setw(15)<<arbol->status<<endl<<endl;
			cout<<"Pedidos atendidos por el cocinero: "<<arbol->pedidosA<<endl;
			cout<<"Ganancias generadas: $"<<arbol->ganancias<<endl<<endl;
			system("pause");
		}
		inorReportar(arbol->der, id);
	}
}
