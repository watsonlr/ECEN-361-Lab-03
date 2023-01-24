#include "ti_drivers_config.h"
#include <stddef.h>
#include <stdint.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <ti/drivers/GPIO.h>
#include <ti/drivers/Timer.h>
#include <ti/drivers/UART.h>
/* BIOS Module Headers */
/* Board Header file */
/* Driver configuration */
/* Driver Header files */
/* Driver Header files */
// #include <ti/drivers/Board.h>
// #include <ti/sysbios/BIOS.h>


/*   Some shortcuts */
// Standalone RED
#define RED_ON      MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0)
#define RED_OFF     MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0)
#define RED_TOGGLE  MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN0)
    /* Turn on user LED */
///     Can also do this:      GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_ON);

// RGB RED
#define RGB_RED_ON      MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN0)
#define RGB_RED_OFF     MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0)
#define RGB_RED_TOGGLE  MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN0)
// RGB GREEN
#define RGB_GREEN_ON      MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN1)
#define RGB_GREEN_OFF     MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN1)
#define RGB_GREEN_TOGGLE  MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN1)
// RGB BLUE
#define RGB_BLUE_ON      MAP_GPIO_setOutputHighOnPin(GPIO_PORT_P2, GPIO_PIN2)
#define RGB_BLUE_OFF     MAP_GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN2);
#define RGB_BLUE_TOGGLE  MAP_GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN2);





/**********************************************/



typedef void (*task_cb)();
#define MAXTASKS 8

int millis =0; // Updated on each SysTick
int pin1_status = 0;
int pin2_status= 0;
int idle_pin_status = 0;
int last_runtime;
int num_tasks = 0;



char        input;
const char  echoPrompt[] = "Echoing characters:\r\n";
UART_Handle uart;
UART_Params uartParams;

void setup_UART()
    {
    /* Call driver init functions */
    UART_init();
    /* Create a UART with data processing off. */
    UART_Params_init(&uartParams);
    uartParams.writeDataMode = UART_DATA_BINARY;
    uartParams.readDataMode = UART_DATA_BINARY;
    uartParams.readReturnMode = UART_RETURN_FULL;
    uartParams.readEcho = UART_ECHO_OFF;
    uartParams.baudRate = 115200;
    uart = UART_open(CONFIG_UART_0, &uartParams);
    if (uart == NULL) {
        /* UART_open() failed */
        while (1);
        }
    }

void setup_LEDs()
    {
    /* Halting the Watchdog */
    GPIO_init();
    MAP_WDT_A_holdTimer();

    // Either way works:
    // GPIO_setConfig(CONFIG_GPIO_LED_0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0); // Standalone Red_led
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN0); // RGB Red LED
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN1); // RGB Green LED
    MAP_GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN2); // RGB Blue LED
    /* Turn off the lights */
    RED_OFF;
    RGB_RED_OFF;
    RGB_GREEN_OFF;
    RGB_BLUE_OFF;

        /* Setting MCLK to REFO at 128Khz for LF mode */
    MAP_CS_setReferenceOscillatorFrequency(CS_REFO_128KHZ);
    MAP_CS_initClockSignal(CS_MCLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_1);
    MAP_PCM_setPowerState(PCM_AM_LF_VCORE0);
    /* Switch 1 */
    MAP_GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN1);
    MAP_GPIO_clearInterruptFlag(GPIO_PORT_P1, GPIO_PIN1);
    /* Setup the Serial port */
    // Serial.begin(115200);
    // Serial.println("Scheduler started");
    }



/**
 * Initialize the scheduler.  This should be called once in the setup routine.
 */
void Scheduler_Init();

/* Function to add a task to the scheduling matrix */
void Scheduler_StartTask(int period, task_cb task);

/* Function that will be run when no other functions are running. */
void idle_process();

/* Go through the task list and run any tasks that need to be run. */
void Scheduler_Dispatch();


/*
 *  ======== scheduler_setup.c ========
 */


#define CONFIG_TIMER_0              0



#define slice_period 10000

/* Callback used for Each Timer ISR */
void timerCallback(Timer_Handle myHandle);
void SysTick_Handler(void);


/*
 *  ======== mainThread ========
 */

void setup_Systick()
{

    /* Setting up the timer in continuous callback mode that calls the callback
     * function every 1,000 microseconds, or 1 millisecond.
     * This is set by the slice_period above
     */

    /* Configuring SysTick to trigger at 1000000 (MCLK is 3MHz so this will make
         * it toggle every 0.5s) */
        MAP_SysTick_enableModule();
        MAP_SysTick_setPeriod(slice_period);
        // MAP_Interrupt_enableSleepOnIsrExit();
        SysTick_registerInterrupt(SysTick_Handler);


        MAP_SysTick_enableInterrupt();

        /* Enabling MASTER interrupts */
        MAP_Interrupt_enableMaster();


}

/*
 * This callback is called every 1,000,000 microseconds, or 1 second. Because
 * the LED is toggled each time this function is called, the LED will blink at
 * a rate of once every 2 seconds.
 * */
void SysTick_Handler(void)
    {
    millis += slice_period;
    RGB_BLUE_TOGGLE;

    }










typedef struct
{
    int period;
    int remaining_time;
    int is_running;
    task_cb callback;
} taskControlBlock;

taskControlBlock tasks[MAXTASKS];

/******************* Student editable below here ******************/



void Scheduler_Init()
{
    last_runtime = millis;
}

void Scheduler_StartTask(int period, task_cb task)
{
    if (num_tasks < MAXTASKS)
    {
        tasks[num_tasks].period = period;
        tasks[num_tasks].remaining_time = 0;
        tasks[num_tasks].is_running = 1;
        tasks[num_tasks].callback = task;
        num_tasks++;
    }
}

void Scheduler_Dispatch()
{

//  Your code goes here

  return;
}


// task function for PulsePin task
void blue_task()
    {
    //Serial.println("Pin1 task");
    RGB_BLUE_TOGGLE;
    }

// task function for PulsePin task
void green_task()
    {
    // Serial.println("Pin2 task");
    RGB_GREEN_TOGGLE;
    }

void idle_process()
    {
    // this function can perform some low-priority task while the scheduler has nothing to do
    // It should return before the idle period (measured in ms) has expired.  For example, it
    // could sleep or respond to I/O.
    // example idle function that just pulses a pin.
    //     Serial.println("idle process");
    RED_TOGGLE;
    }



/*
 *  ======== mainThread ========
 */
// void *mainThread(void *arg0)
void main()
{
    GPIO_init();
    setup_LEDs();
    setup_Systick();
    setup_UART();

    Scheduler_Init();
    // Start task arguments are:
    //      start offset in ms, period in ms, function callback
    Scheduler_StartTask(1000, blue_task);
    Scheduler_StartTask(1500, green_task);
    //
    // RGB_GREEN_ON;
    while(1){
        UART_write(uart, echoPrompt, sizeof(echoPrompt));
        }
    /* Loop forever echoing */
    /*
    while (1) {
        UART_read(uart, &input, 1);
        UART_write(uart, &input, 1);
        */

   Scheduler_Dispatch();
}
