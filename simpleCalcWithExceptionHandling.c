#include <reg51.h>
void calculate(int, int, int);
void serial_init(void);
void serial_tx(char);
void serial_tx_string(char *);
void HANDLE_ARITHMETIC_ERROR(void);
void HANDLE_ERROR_IN_INPUT(void);
void main(void){
		unsigned char choice, a, b;
		choice=P1;
		a=P2;
		b=P3;
		calculate(choice, a, b);
}
void calculate(int n, int op1, int op2){
	switch (n){
		case 0x01:
			P0=op1+op2;
			if (OV==1)
				HANDLE_ARITHMETIC_ERROR();
			break;
		case 0x02:
			P0=op1-op2;
			if (OV==1)
				HANDLE_ARITHMETIC_ERROR();
			break;
		case 0x03:
			P0=op1*op2;
			if (OV==1)
				HANDLE_ARITHMETIC_ERROR();
			break;
		case 0x04:
			P0=op1/op2;
			if (OV==1)
				HANDLE_ARITHMETIC_ERROR();
			break;
		case 0x05:
			P0=op1%op2;
			if (OV==1)
				HANDLE_ARITHMETIC_ERROR();
			break;		
		default:
			HANDLE_ERROR_IN_INPUT();
	}
}
void HANDLE_ARITHMETIC_ERROR(void){
	serial_init(); 
	serial_tx_string("\nERROR OUT OF RANGE\n");
}
void HANDLE_ERROR_IN_INPUT(void){
	serial_init(); 
	serial_tx_string("\nERROR INVALID INPUT\n");
}
void serial_init(void){
	TMOD=0x20;
	TH1=0xFD; 
	SCON=0x50;
	TR1=1;
}
void serial_tx(char ch){
	SBUF=ch; 
	while (TI==0);
	TI=0; 
}
void serial_tx_string(char *s){
	while (*s)
		serial_tx(*s++);
}


	
			
			
			
	

		
