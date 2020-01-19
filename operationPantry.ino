#include <HX711.h>
#include <math.h>

#define calibration_factor 190000.0 //This value is obtained using the SparkFun_HX711_Calibration sketch

#define DOUT  3
#define CLK  2

int LED = 5;

HX711 scale;
double oneItem = 0.006;

void setup() {
  Serial.begin(9600);

  pinMode(LED, OUTPUT);
 
  scale.begin(DOUT, CLK);
  scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0
}

void loop() {
  double totalWeight = scale.get_units();
  int noItems = round(totalWeight / oneItem);
  
 /* Serial.print("Weight: ");
  Serial.print(totalWeight, 3); //scale.get_units() returns a float
  Serial.print(" lbs"); //You can change this to kg but you'll need to refactor the calibration_factor
  Serial.println();
  Serial.println("Number of Items left: ");
  Serial.println(noItems);
  Serial.println();
  */

  Serial.println(noItems);
  delay(5000);
  
  if (noItems < 5){
    digitalWrite(LED, HIGH);
    delay(2000);
    digitalWrite(LED, LOW);
  }
  
}
