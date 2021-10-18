//FREERTOS implementation 
//Task 1 -> led blinking evey 200 ms
//Task 2 -> string sent evey second

#define LED 32
String hello = "Hola mundo";
void Task1( void *pvParameters)
{
  const TickType_t xDelay200ms = pdMS_TO_TICKS (200); 
  TickType_t xLastWakeTime; 
  /*variable to save the current tick count, it has to be initialized to the 
   *current tick count before it is used for the first time,then with the  
   *function vTaskDelayUntil is updated atomatically
   */
   xLastWakeTime = xTaskGetTickCount();
 
  //Converts time in ms to the same time in system ticks
  while(1)
  {
    digitalWrite(LED, !digitalRead(LED)); //Blink led 
    /* Delay for a period. A call to vTaskDelay() is used which places
       the task into the Blocked state until the delay period has expired.*/
    vTaskDelayUntil(&xLastWakeTime, xDelay200ms);
  }
  
}

void Task2( void *pvParameters)
{
  const TickType_t xDelay1s = pdMS_TO_TICKS (1000);
  TickType_t xLastWakeTime; 
  xLastWakeTime = xTaskGetTickCount();
  while(1)
  {
    Serial.println(hello);
    vTaskDelayUntil(&xLastWakeTime, xDelay1s);
  }
   
}

void setup() {
  pinMode(LED, OUTPUT);   //Set pin as output
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  xTaskCreate( Task1, /* Pointer to the function that implements the task. */
               "Task 1",/* Text name for the task. This is to facilitate
                           debugging only. */
               1000, /* Stack depth - small microcontrollers will use much
                        less stack than this. */
               NULL, /* This example does not use the task parameter. */
               2, /* This task will run at priority 1. */
               NULL ); /* This example does not use the task handle. */
  xTaskCreate(Task2, "Task 2", 1000, NULL, 1, NULL);
  //vTaskStartScheduler();  //Not needed in Arduino IDE

}

void loop() {
}
