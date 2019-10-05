bool agregarCocinero(){
	int id;
	bool rep;
	srand(time(0));
	do{
		rep=true;
		system("cls");
		id=160726+rand()%11;
		cout<<"Generando ID de cocinero..."<<endl; 
		Sleep(500);
		rep=insertar(arbol, id);
		if(rep==false){
			cout<<"Alcanzó el cupo máximo de cocineros"<<endl;
			system("pause");
			rep=true;
		}
	}while(rep==false);
	
	return false;
}

bool consultaCocinero(){
	cout<<"ID"<<setw(15)<<"NOMBRE"<<setw(15)<<"PROMEDIO"<<setw(15)<<"STATUS"<<setw(15)<<"ASIGNACION"<<endl;
	inor(arbol);
	cout<<endl<<endl;
	system("pause");
	return false;
}

bool modificarCocinero(){
	system("cls");
	bool rep;
	char id[10];
	int id2;
	recuperarDatos(arbol);
	cout<<"ID"<<setw(15)<<"NOMBRE"<<setw(15)<<"PROMEDIO"<<setw(15)<<"STATUS"<<setw(15)<<"ASIGNACION"<<endl;
	inor(arbol);
	cout<<endl<<endl<<"Ingrese ID del cocinero que desea modificar"<<endl;
	
	do{
		rep=true;
		cin>>id;
		rep=validaId(id);
	}while(rep==false);
	
	id2=atoi(id);
	system("cls");
	inorModificar(arbol, id2);
	actualizarDatos();
	return false;
}

bool reporteVentas(){
	system("cls");
	FILE *archivo;
	int totalTacos, totalHamburguesas;
	float total=0, ganancias=0,noPedido=0;
	archivo=fopen("pedidos.xls", "r");
	if(archivo!=NULL){
		while(!feof(archivo)){
			fscanf(archivo, "%f\t", &noPedido);
			fscanf(archivo, "%d\t", &totalTacos);
			fscanf(archivo, "%d\t", &totalHamburguesas);
			fscanf(archivo, "%f\n", &total);
			ganancias=ganancias+total;
		}
	}
	fclose(archivo);
	cout<<"             REPORTE DE VENTAS"<<endl<<"---------------------------------------------"<<endl;
	cout<<"--Rafa & Manolo's Restaurant--"<<endl;
	cout<<"Urbano Villalón num.500, Col. La Ladrillera, San Luis Potosí, S.L.P. México,"<<endl;
	cout<<"C.P. 78363 Conmutador: +52 (444) 812-65-19 / 812-63-67"<<endl;
	cout<<"RFC JURO971015 y LEHF980225"<<endl<<endl;
	cout<<"No. de pedidos realizados en el dia: "<<noPedido<<endl;
	cout<<"Ganancias obtenidas: $"<<ganancias<<endl<<endl;
	system("pause");
	return false;
}

bool reporteCocinero(){
	char id[10];
	bool rep;
	int id2;
	system("cls");
	recuperarDatos(arbol);
	cout<<"ID"<<setw(15)<<"NOMBRE"<<setw(15)<<"PROMEDIO"<<setw(15)<<"STATUS"<<setw(15)<<"ASIGNACION"<<endl;
	inor(arbol);
	cout<<endl<<endl<<"Ingrese ID del cocinero a reportar: "<<endl;
	
	do{
		rep=true;
		cin>>id;
		rep=validaId(id);
	}while(rep==false);
	
	id2=atoi(id);
	inorReportar(arbol, id2);
	return false;
}

bool administrador(){//funciones de administrador
	bool entrar, rep, menu;
	char accion[20];
	int validado;
	entrar=logIn();
	
	if(entrar==true){
		recuperarDatos(arbol);
		do{
			rep=true;
			do{
				system("cls");
				cout<<"Bienvenido. Por favor seleccione una opción"<<endl;
				cout<<"1.Ingresar cocinero nuevo"<<endl<<"2.Consultar cocineros"<<endl<<"3.Modificar cocinero"<<endl<<"4.Realizar reporte de ventas"<<endl
				<<"5.Realizar reporte de ventas de un cocinero"<<endl<<"6.Volver a inicio"<<endl;
				cin>>accion;
				validado=validarAdmin(accion);					
			}while(validado==0);
			
			switch(validado){
				case 1:
					rep=agregarCocinero();
					break;
				case 2:
					rep=consultaCocinero();
					break;
				case 3:
					rep=modificarCocinero();
					break;
				case 4:
					rep=reporteVentas();
					break;
				case 5:
					rep=reporteCocinero();
					break;
				case 6:
					rep=true;
					break;
				default:
					rep=false;
					break;
			}	
		}while(rep==false);
	}
	if(entrar==false) return true;
	return true;
}
