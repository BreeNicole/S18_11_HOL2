//Breann Birch & Andrea Pyle
//S18-11-Hol2
//Spring - Fall 2018
//Adopted from:
//Shivam Kundan
//S17-71-HOL1
//Fall 2017
//Variable to keep track of how many on/off's for each device
int device_one_counter=0;  
int device_two_counter=0;
int device_three_counter=0;

void sig_handler(int signo)
/*Ensures proper termination of all running hardware/threads.*/
{ 
    //Turn off all devices in case they are on
    system("gpio -g write 17 0");
    system("gpio -g write 27 0");
    system("gpio -g write 22 0");

    //Stop any music that is playing   
    system("killall omxplayer.bin");
    sleep(1);

    //Kill all threads associated with this program
    system("killall screen") ;
    
    exit(0);
}

void control_hardware(int data)
/*Receives input integers and controls processes/threads accordingly.*/
{
    //Device 1
    if (data == DEVICE_ONE_ID) {        
        device_one_counter++;
        printf("Device 1 Counter: %d\n",device_one_counter);
   
        if (device_one_counter%2==1) {
    	  printf("Device 1 turning on...\n");
    	  digitalWrite (DEVICE_ONE_PIN, HIGH) ;
	}
        else {
    	  printf("Device 1 turning of...\n");
    	  digitalWrite (DEVICE_ONE_PIN, LOW);
	}   
    }
    //Device 2
    else if (data == DEVICE_TWO_ID) {
        device_two_counter++;
        printf("Device 2 Counter: %d\n",device_two_counter);
        if (device_two_counter%2==1) {
    	  printf("Device 2 Turning on...\n");
    	  digitalWrite (DEVICE_TWO_ID, HIGH);
	}
          else {
    	    printf("Device 2 Turning off...\n");
    	    digitalWrite (DEVICE_TWO_ID, LOW);
        }  
    }
    //Device 3
	else if (data == DEVICE_THREE_ID) {
		device_three_counter++;
		printf("Device 3 Counter:\n");

		if (device_three_counter % 2 == 1) {
			printf("Device 3 turning on...\n");
			digitalWrite(DEVICE_THREE_ID, HIGH);
		}
		else {
			printf("Device 3 turning off...\n");
			digitalWrite(DEVICE_THREE_ID, LOW);
		}
	}
    else {
      printf("Variable input does not match any inputs or functions.\n");
    }
}
