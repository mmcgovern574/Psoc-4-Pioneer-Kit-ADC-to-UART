/* ========================================
 *
 * Mike McGovern
 *
 * PRINT ADC VALUE TO PUTTY VIA UART
 *
 * ========================================
*/
#include <project.h>
#include <stdio.h> // allows sprintf conversion

/*Global Variables*/
char send_value[1];
float32 adc_val;
//uint8adc_val;
//float32 adcvoltage;  //Uncomment if using voltage

int main()
{
    
    CyGlobalIntEnable; 
    UART_Start();
    ADC_Start();
    ADC_StartConvert();
    
    UART_UartPutString("\n ADC Started \r");
    
    for(;;)
    {
        
        adc_val = ADC_GetResult16(0);
        //adcvoltage = ADC_CountsTo_mVolts(0,adc_val);
        sprintf(send_value,"%.4f", adc_val);  //"%.4f indicates number of decimals
        UART_UartPutString(send_value);  //prints ADC value
        UART_UartPutString("\n send_value \r");  //prints "send value" for debugging purposes
        
    }
}

/* [] END OF FILE */
