#include "librerias.h"
main(){
	setlocale(LC_CTYPE, "Spanish");
	int validado;
	bool menu;
	char opc[20];
	do{
		menu=false;
		do{
			system("cls");
			cout<<"Bienvenido a Rafa & Manolo's restaurant."<<endl;
			cout<<"Seleccione una opción"<<endl;
			cout<<"1.Administrador"<<endl<<"2.Personal"<<endl<<"3.Créditos"<<endl<<"4.Salir"<<endl;
			cin>>opc;
			validado=validarNum(opc);
		}while(validado==0 && validado!=1 && validado!=2 && validado!=3 && validado!=4);
	
		if(validado==1) menu=administrador();
		if(validado==2) menu=personal();
		if(validado==3) menu=creditos();
		if(validado==4) menu=false;
	}while(menu==true);
}
