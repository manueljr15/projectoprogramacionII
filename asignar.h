void desocuparCocinero(ARBOLB &arbol, int id){
	if(arbol!=NULL){
		if(id==arbol->id_cocinero && strcmp(arbol->turno, "O")==0){
			strcpy(arbol->turno, "D");
			cout<<"Se desocupó: "<<arbol->nombre<<endl;
			system("pause");
		}
		desocuparCocinero(arbol->izq, id);
		desocuparCocinero(arbol->der, id);
	}
}

void asignarCocinero(ARBOLB &arbol, float noPedido, int totalTacos, int totalHamburguesas, float total, bool &pedido, bool &asig){
		if(arbol!= NULL){
			if(strcmp(arbol->turno, "D")==0 && strcmp(arbol->status, "A")==0){
				if(pedido==false){
					strcpy(arbol->turno, "O");
					arbol->pedidosA++;
					arbol->promedio=(arbol->pedidosA/noPedido)*100;
					cout<<"Pedido asignado a "<<arbol->nombre<<endl;
					cout<<"Atendiendo pedido."<<endl;
					cout<<"Información del pedido: "<<endl;
					cout<<"No. Pedido: "<<noPedido<<endl;
					cout<<"Tacos: "<<totalTacos<<endl;
					cout<<"SubTotal: $"<<totalTacos*precioTacos<<endl;
					cout<<"Hamburguesas: "<<totalHamburguesas<<endl;
					cout<<"Subtotal: $"<<totalHamburguesas*precioHamburguesa<<endl;
					total=totalTacos*precioTacos+totalHamburguesas*precioHamburguesa;
					arbol->ganancias=arbol->ganancias+total;
					cout<<setw(30)<<"Total a pagar: $"<<total<<endl<<endl<<endl;
					pedido=true;
					asig=true;
				}
			}
			asignarCocinero(arbol->izq,noPedido, totalTacos, totalHamburguesas, total, pedido, asig);
			asignarCocinero(arbol->der,noPedido, totalTacos, totalHamburguesas, total, pedido, asig);
		}
}

