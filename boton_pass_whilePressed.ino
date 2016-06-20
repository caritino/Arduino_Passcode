const int boton1 = 2; // número del pin para el botón
const int boton2 = 3;
const int botonSubmit = 4;

const int led1 = 12;  // número del pin del LED
const int led2 = 13;
const int led3 = 11;

int estadoBoton1 = 0;  // estado del botón (0 ó LOW es apagado y 1 ó HIGH es encendido)
int estadoBoton2 = 0;
int estadoBotonSubmit = 0;
int banderaEstado = 0;

int primerPassword()
{

	if(estadoBoton1 == HIGH && estadoBoton2 == HIGH)
		return 1;
	else
		return 0;
}

int segundoPassword()
{

	if(estadoBoton1 == HIGH && estadoBoton2 == LOW)
		return 1;
	else
		return 0;
}

void setup() {
	Serial.begin(9600);

	// Se identifica el pin 13 como salida
 	pinMode(led1, OUTPUT);     
 	pinMode(led2, OUTPUT);
 	pinMode(led3, OUTPUT);     
 	// Se identifica el pin 2 como entrada
 	pinMode(boton1, INPUT);  
 	pinMode(boton2, INPUT);  
 	pinMode(botonSubmit, INPUT);     
}

void loop(){
	estadoBoton1 = digitalRead(boton1);
	estadoBoton2 = digitalRead(boton2);
	estadoBotonSubmit = digitalRead(botonSubmit);

	if(estadoBotonSubmit == HIGH)
	{
		if(primerPassword() == 1)
		{
			digitalWrite(led1, HIGH); 
			banderaEstado = 1;
		}
		else if(segundoPassword() == 1 && banderaEstado != 0)
		{
			digitalWrite(led2, HIGH); 
			banderaEstado = 2;
		}
		else
		{
			digitalWrite(led1, LOW); 
			digitalWrite(led2, LOW); 
			digitalWrite(led3, LOW); 
			banderaEstado = 0;
		}
	}

	if(banderaEstado == 2)
	{
		digitalWrite(led1, HIGH); 
		digitalWrite(led2, HIGH); 
		digitalWrite(led3, HIGH); 
	}
}
