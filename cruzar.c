#include<stdio.h>
#include<stdint.h>

//Implementa cruce de bits segun tabla
int cruzar( int in , const int *transLSB1st, int size) {	  
  int ret = 0, num;  
  for( num = 0; num < size; num++ ){      
      if ( in & 0x01 ){
          ret |= 1 << transLSB1st[num];
       }
      in >>= 1;
  }
  return ret;
}

//Genera una tabla nueva para revertir cruce
void revertirTabla( const int *transLSB1st, int *transLSB1stInv, int size) {
  int ret = 0, num;  
  for( num = 0; num < size; num++ ){            
        *(transLSB1stInv+ *(transLSB1st+num) )  = num;        
  }
}


//Check tabla ok
int checkTableHealth(const int *transLSB1st, int size){
  int times=0;
  int i,j;
  for (i = 0; i < size; i++) {
    for (j = i + 1; j < size; j++) {
        if ( *(transLSB1st+i) == *(transLSB1st+j) ||  *(transLSB1st+i) >=size ) {
        	printf("%d",i);
            return 0;//error, repeat or out of range 
        }
    }
 }
 return 1;//ok, no repeat nor out of range
}

void cruzarBytes( const uint8_t *arrayIn,  uint8_t *arrayOut, const int *tableTransform, int size){    
	int i;
    for(i=0;i<size;i++){
         arrayOut[i]= arrayIn[tableTransform[i]];
    }       
}

int main(){	
	#define TABLE_SIZE 8
		 
	int nro=83;		
	int transLSB1st[] = { 0, 2, 1, 3, 4, 5, 7, 6 }; 
	int transLSB1stInv[TABLE_SIZE];
	
	printf("Tabla ok: %s", checkTableHealth(transLSB1st, TABLE_SIZE)? "yes":"no");    
	
	revertirTabla(transLSB1st,transLSB1stInv,TABLE_SIZE);    

	int cruzado=cruzar(nro, transLSB1st, TABLE_SIZE);	
	int descruzado=cruzar(cruzado, transLSB1stInv, TABLE_SIZE);
	printf("\n\n0x%X->0x%X->0x%X",nro, cruzado, descruzado);
	
	
	#define DATA_SIZE 5
	uint8_t inputData[DATA_SIZE]={'a','b','c','d','e'};
	uint8_t outputData[DATA_SIZE];
	uint8_t outputDataInv[DATA_SIZE];
 	int transform[DATA_SIZE]={1,0,3,4,2};
 	int transformInv[DATA_SIZE];
				//			 1, 0, 4, 2, 3,
	
	cruzarBytes( inputData, outputData, transform, DATA_SIZE );
	
	int i;
	printf("\n");
	for(i=0;i<DATA_SIZE;i++){		
		printf(" %d", transform[i]);
	}
	
	printf("\n");
	for(i=0;i<DATA_SIZE;i++){		
		printf(" %c", outputData[i]);
	}
		
	revertirTabla(transform,transformInv,DATA_SIZE);
	
	printf("\n");
	for(i=0;i<DATA_SIZE;i++){		
		printf(" %d", transLSB1stInv[i]);
	}
	
	cruzarBytes( outputData, outputDataInv, transformInv, DATA_SIZE );	
	printf("\n");
	for(i=0;i<DATA_SIZE;i++){		
		printf(" %c", outputDataInv[i]);
	}
		
}
