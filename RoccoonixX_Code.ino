// Define pin connections & motor's steps per revolution
const int dirPin = 2;
const int stepPin = 3;
const int stepsPerRevolution = 100;

void setup()
{
  // Declare pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  Serial.begin(9600); //inicializa el SERIAL y le da la velocidad de transmisión
}
void loop()
{

//int Giro = Serial.parseInt(); //Asigna una nueva variable /Giro/ y le da el valor de 
                  //la cadena de caracteres que escribes en el monitor en serie despues de presionar ENTER
                  //Despuesd de tomar este valor su valor regresa a cero 
  
  while (Serial.available()==0);  
  {
 Serial.println("escribe A adelante B Atras");
 
  int Sentido = Serial.read();
    
   if(Sentido =='A'){ 
      digitalWrite(dirPin, HIGH);
      Serial.write("adelante");
  }

     else if(Sentido =='B'){ 
      digitalWrite(dirPin, LOW);
      Serial.write("atras");
  }

  Serial.println("escribe CUANTO AVANZAS");
 int Giro = Serial.read();
  //int Giro = Serial.parseInt();
  
  // Spin motor slowly
  for(int x = 0; x < Giro; x++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
  delay(10); // Wait a second
  }
 
  }
