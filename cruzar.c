#include<stdio.h>

//Implementa cruce de bits segun tabla
int cruzar( int in , const int *tableLSBFirst, int size) {	  
  int ret = 0, num;  
  for( num = 0; num < size; num++ ){      
      if ( in & 0x01 ){
          ret |= 1 << tableLSBFirst[num];
       }
      in >>= 1;
  }
  return ret;
}

//Genera una tabla nueva para revertir cruce
void revertir( const int *tableLSBFirst, int *tableLSBFirstInv, int size) {
  int ret = 0, num;  
  for( num = 0; num < size; num++ ){            
        *(tableLSBFirstInv+ *(tableLSBFirst+num) )  = num;        
  }
}

//Check tabla ok
int checkHealth( int *tableLSBFirst , int size){
  int times=0;
  int i,j;
  for (i = 0; i < size; i++) {	
    for (j = i + 1; j < size; j++) {
        if ( *(tableLSBFirst+i) == *(tableLSBFirst+j) ||  *(tableLSBFirst+i) >=size ) {
            return 0;//error, repeat or out of range 
        }
    }    
 } 
 return 1;//ok, no repeat nor out of range
}

int main(){	
	#define TABLE_SIZE 8
		 
	int nro=83;		
	int tableLSBFirst[] = { 0, 2, 1, 3, 4, 5, 7, 6 };  //int tableLSBFirst[] = { 0,1,2,3,4,5,6,7,13,10,9,11,8,15,14,12 };  
	int tableLSBFirstInv[TABLE_SIZE];
	
	printf("Tabla ok: %s", checkHealth(tableLSBFirst, TABLE_SIZE)? "yes":"no");    
	
	revertir(tableLSBFirst,tableLSBFirstInv,TABLE_SIZE);    

	int cruzado=cruzar(nro, tableLSBFirst, TABLE_SIZE);	
	int descruzado=cruzar(cruzado, tableLSBFirstInv, TABLE_SIZE);
	printf("\n\n%d->%d->%d",nro, cruzado, descruzado);
}
