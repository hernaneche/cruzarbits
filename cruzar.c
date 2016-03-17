#define SIZE_TABLA 16

int tabla[] = { 0,1,2,3,4,5,6,7,13,10,9,11,8,15,14,12 };  
                
//genera una tabla nueva para revertir el cruce
void revertir( int *tabla, int *tablaInv, int size) {
int ret = 0, num;  
for( num = 0; num < size; num++ ){            
        *(tablaInv+ *(tabla+num) )  = num;        
  }
}

//implementa cruce de bits segun tabla
int cruzar( int in , int *tabla, int size) {	  
  int ret = 0, num;  
  for( num = 0; num < size; num++ ){      
      if ( in & 0x01 ){
          ret |= 1 << tabla[num];
       }
      in >>= 1;
  }
  return ret;
}

//tabla ok
int health( int *tabla , int size){
	int times=0;
	int i,j;
for (i = 0; i < size; i++) {	
    for (j = i + 1; j < size; j++) {
        if ( *(tabla+i) == *(tabla+j) ||  *(tabla+i) >=size ) {
            return 0;//error repeat or out of range 
        }
    }    
 } 
 return 1;//ok no repeat nor out of range
}

int main(){	
    printf("health:[%d]", health(tabla, SIZE_TABLA) );
    int tablaInv[SIZE_TABLA];
    revertir(tabla,tablaInv,SIZE_TABLA);
	int nro=58433;		
	int cruzado=cruzar(nro, tabla, SIZE_TABLA);	
	int descruzado=cruzar(cruzado, tablaInv, SIZE_TABLA);
	printf("\n%d->%d->%d",nro, cruzado, descruzado);
}

