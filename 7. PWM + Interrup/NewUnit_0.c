// --- Mapeamento de Hardware ---
#define out  LATB7_bit

// --- Interrup��es ---
void interrupt()
{
    if(INT0IF_bit)         //Houve interrup��o externa?
    {                      //Sim...
        INT0IF_bit = 0x00; //limpa flag INT0IF

        out = ~out;        //inverte sa�da


    } //end if INT0IF

} //end interrupt


// --- Fun��o Principal ---
void main()
{
     INTCON  = 0x90;       //Habilita interrup��o global e interrup��o externa 0 (1001 0000) (GIE/GIEH E INT0IE)
     INTEDG0_bit = 0x00;   //Configura interrup��o externa 0 por borda de descida
     TRISB   = 0x7F;       //RB0 est� configurado como sa�da (0111 1111b)
     ADCON1  = 0x0F;       //Configura os pinos do PORTB como digitais

     out     = 0x00;        //Inicializa sa�da de teste em low

     while(1)              //Loop infinito
     {
        //aguarda as interrup��es...
        out = ~out;        //inverte sa�da
        delay_ms(1000);


     } // end while


} // end main