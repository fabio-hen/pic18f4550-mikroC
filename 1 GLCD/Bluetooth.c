char GLCD_DataPort at PORTD;
sbit GLCD_CS1 at RA5_bit;
sbit GLCD_CS2 at RC0_bit;
sbit GLCD_RS  at RE0_bit;
sbit GLCD_RW  at RE1_bit;
sbit GLCD_EN at RE2_bit;
sbit GLCD_RST at RB3_bit;
sbit GLCD_CS1_Direction at TRISA5_bit;
sbit GLCD_CS2_Direction at TRISC0_bit;
sbit GLCD_RS_Direction at TRISE0_bit;
sbit GLCD_RW_Direction at TRISE1_bit;
sbit GLCD_EN_Direction at TRISE2_bit;
sbit GLCD_RST_Direction at TRISB3_bit;

unsigned char msg [] = "Dado Recebido:";//variavel q recebe um valor da serial
unsigned char txt[20];

void main() org 0x1000
{
     delay_ms(3000); // Delay para estabilizar
     adcon1=0x0F; //Passa alguns pinos do pic para formato digital
     trisd=0x00;  // define a porta d como sa�da
     rcon=0x80;
     cmcon=0x0F;
     intcon2=0;

     UART1_Init(9600);//inicia o modulo UART com velocidade de 9600bps
     delay_ms(100);//espere 10ms para estabilizar

     Glcd_Init(); //Inicializar o GLCD
     Glcd_Fill(0);
     Glcd_Set_Font(Font_Glcd_System5x7,5,7,32);
     
     delay_ms(100);
     Glcd_Write_Text(msg,10,3,1);
     
     while(1)
     {
        if (UART1_Data_Ready() == 1) 
        {
           UART1_Read_Text(txt, "//",16);
           delay_ms(10);
           Glcd_Write_Text(txt,40,5,1);
         }
     }
}