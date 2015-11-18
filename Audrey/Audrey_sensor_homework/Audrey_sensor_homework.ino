//Audrey Fox CC Lab Sensor Homework Fall 2015
//This takes the ultrasonic rangefinder from Maxbotix and uses it to drive a DC motor. 
//Code to find the median point and filter out unstable data points is from Bill Gentles. Such Math! Much grateful!

int anPin = A0;
int mPin = 5;
int sensor = 0;//storing the incoming value

int arraysize = 5; //Sample size. Needs to be an odd number
int rangevalue[] = {0, 0, 0, 0, 0}; //0s are place holders for ease of reading code

void setup() {
  Serial.begin(9600);
  printArray(rangevalue, arraysize);
  pinMode(mPin, OUTPUT);  
  delay(500);//want to get the serial up and running before beginning the data
}

void loop() {
   digitalWrite(mPin, LOW);
   pinMode(anPin, INPUT);

   for(int i = 0; i < arraysize; i++)
  {                                                
    rangevalue[i] = analogRead(anPin);
         Serial.print("The range value for   ");
         Serial.print(i);
         Serial.print(" is:  ");
         Serial.print(rangevalue[i]);
         Serial.println();

    delay(10);  //wait between samples
   }  

   int midpoint = arraysize/2;    //midpoint of the array is the medain value in a sorted array
    Serial.print("The median range value is: ");
    Serial.print(rangevalue[midpoint]);
    Serial.println();  
    Serial.println();  

    if(midpoint> 30){
      digitalWrite(mPin, LOW);
      delay(30);
    }else{
      digitalWrite(mPin, HIGH);
      delay(30);
    }
 
 delay(3000);
}

// sort function
void isort(int *a, int n)
              //  *a is an array pointer function
{
 for (int i = 1; i < n; ++i)
 {
   int j = a[i];
   int k;
   for (k = i - 1; (k >= 0) && (j < a[k]); k--)
   {
     a[k + 1] = a[k];
   }
   a[k + 1] = j;
 }
}

//function to print array values
void printArray(int *a, int n)
{
 
 for (int i = 0; i < n; i++)
 {
   Serial.print(a[i], DEC);
   Serial.print(' ');
 }
 
 Serial.println();
}

