# HC-SR04 İLE PARK SENSÖRÜ UYGULAMASI
Bu projede HC-SR04 (Ultrasonik Mesafe Sensörü) ve buzzer kullanarak, Arduino üzerinden araç park sensörü yapacağız. Yaptığımız mesafe ölçümlerine göre buzzer, engele yakınlık derecesine göre frekansını artırarak bize uyarı vericek. Ayrıca engele olan mesafemizi LabVIEW aracılığıyla bir göstergede göstereceğiz.


## ULTRASONİK PARK SENSÖRÜ NEDİR VE NASIL ÇALIŞIR ?

Ultrasonik sensörler özellikle  **acemi şoförler**  için büyük bir avantaj sağlamaktadır. Günümüzde halen araçlarda kullanılan ultrasonik park sensörü bir dedektör yapısına sahip olarak, aracın özellikle arka kısmındaki yakın noktada bulunan cisimlerin tespit edilmesini sağlar.

Ultrasonik park dedektörleri sayesinde bir sonar yapısı elde edilirken, insan kulağının duyamayacağı 20.000 Hz üzerinde bir akustik ses yayılır. Bu sesler sayesinde çarpan cismin sağladığı ses yansımasından gelen geri dönüş hızı göz önüne alınarak, cismin bulunduğu nokta hesaplanır. Bu sisteme göre de sürücüye geri dönüş sinyali için çarpma ihtimali bulunabilecek cismin mesafesi, uzaklık ve yakınlığa göre belirlenirken, sürücüye aktarılan ses buna göre artar ve azalır.

## KULLANILAN MALZEMELER

-   [Arduino UNO](https://www.robotistan.com/arduino-uno-r3-klon-usb-kablo-hediyeli-usb-chip-ch340)
-   [Breadboard](http://www.robotistan.com/breadboard)
-   [1 adet Buzzer](http://www.robotistan.com/buzzer)
-   [1 adet 330Ω direnç](http://www.robotistan.com/14w-330r-direnc-paketi-10-adet)
-   [1 adet HC-SR04 ultrasonik mesafe sensörü](http://www.robotistan.com/hc-sr04-ultrasonik-mesafe-sensoru)
-   [İki ucu erkek jumper kablo](http://www.robotistan.com/40-pin-ayrilabilen-erkek-erkek-m-m-jumper-kablo-200-mm)



##  BAĞLANTI ŞEMASI

![enter image description here](https://www.teknolojikogretmenler.com/wp-content/uploads/2019/03/buzzer-hcsr04_bb-1068x643.png)

##  ARDUINO KODU

   

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

## LABVIEW FRONT PANEL

[Front paneli görüntülemek için lütfen tıklayınız.](https://drive.google.com/file/d/1CQ8qJQ4FBQRthMbSWcY9sJv8aMKR_lLI/view?usp=sharing)


## LABVIEW BLOCK DIAGRAM

[Block diyagramını görüntülemek için lütfen tıklayınız.](https://drive.google.com/file/d/1uG3mLBj60Jpb0gRbcTaHQ1QZVjXzzIJV/view?usp=sharing)
