const int trigger_pin = 9; 
const int echo_pin = 10;
int buzzer = 8; 
long zaman ;
long mesafe ; 

void setup() 
{
pinMode(buzzer , OUTPUT); 
pinMode(trigger_pin , OUTPUT); 
pinMode(echo_pin , INPUT); 
Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigger_pin, LOW); 
  delayMicroseconds(5);
  digitalWrite(trigger_pin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigger_pin, LOW);  
  zaman = pulseIn(echo_pin, HIGH);
  mesafe= (zaman /2)/29.1;    

  if(mesafe >= 400 || mesafe <= 2)
  {
    Serial.println("Out of range"); 
  }
  else
  {
    Serial.print(mesafe);
    Serial.println(" cm");  
    delay(500); 

    if (mesafe <= 10) 
    {
     digitalWrite(buzzer , HIGH);
    }

    else if(mesafe>10 && mesafe<=20) 
    {

     digitalWrite(buzzer , HIGH);
     delay(150); 

     digitalWrite(buzzer , LOW);
     delay(100);
    }
    else if(mesafe>20 && mesafe<=30) 
    {
     digitalWrite(buzzer , HIGH);
     delay(150);

     digitalWrite(buzzer , LOW);
     delay(350);
    }
    else if(mesafe>30 && mesafe<=40) 
    {
     digitalWrite(buzzer , HIGH);
     delay(150);

     digitalWrite(buzzer , LOW);
     delay(550);
    }
    else if(mesafe>40 && mesafe<=50) 
    {
     digitalWrite(buzzer , HIGH);
     delay(150);

     digitalWrite(buzzer , LOW);
     delay(750);
    }
  }
}
