int validarNum(char numero[20]){
	if(strlen(numero)>1){
		return 0;
	}
	if(isdigit(numero[0])!=1){
		return 0;
	}
	if(atoi(numero)>0 && atoi(numero)<5){
		return atoi(numero);
	}
}

int validarModif(char numero[20]){
	if(strlen(numero)>1){
		return 0;
	}
	if(isdigit(numero[0])!=1){
		return 0;
	}
	if(atoi(numero)>0 && atoi(numero)<3){
		return atoi(numero);
	}
}

int validarAdmin(char numero[20]){
	if(strlen(numero)>1){
		return 0;
	}
	if(isdigit(numero[0])!=1){
		return 0;
	}
	if(atoi(numero)>0 && atoi(numero)<7){
		return atoi(numero);
	}
}

bool logIn(){
	char contrasenia[20];
	bool error;
	do{
		error=false;
		system("cls");
		cout<<"Presione 0 para volver a inicio o escriba la contraseña: ";
		cin>>contrasenia;
		if(strcmp(contrasenia, CONTRASENIA)==0){
			error=true;
		}
		if(strcmp(contrasenia, "0")==0){
			error=true;
		}
	}while(error==false);
	if(strcmp(contrasenia, CONTRASENIA)==0){
		return true;
	}
	if(strcmp(contrasenia, "0")==0){
			return false;
	}
}

bool validaStatus(char status[10]){
	if(strlen(status)>1) return false;
	if(status[0]=='A' || status[0] == 'I') return true;
}

bool validaId(char id[10]){
	if(strlen(id)==6){
		for(int i=0; i<strlen(id); i++){
			if(isdigit(id[i])==0){
				return false;
			}
		}
		if(atoi(id)>160725 && atoi(id)<160737){
			return true;
		}else return false;
	}else return false;
}

bool validaTH(char th[10]){
	if(strlen(th)>3){
		return false;
	}else{
		for(int i=0; i<strlen(th); i++){
			if(isdigit(th[i])==0){
				return false;
			}
		}
	}
	return true;
}
