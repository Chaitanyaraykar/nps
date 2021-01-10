#include<stdio.h>
 
int main() {
    int data[10];
    int dataatrec[10],c,c1,c2,c0,i;
 
    printf("Enter 4 bits of data one by one\n");
    scanf("%d",&data[7]); //d3
    scanf("%d",&data[6]); //d2
    scanf("%d",&data[5]); //d1
    scanf("%d",&data[3]); //d0
 
    //Calculation of even parity
    data[4]=data[5]^data[6]^data[7];
	data[2]=data[3]^data[6]^data[7];
	data[1]=data[3]^data[5]^data[7];
 
	printf("\nEncoded data is\n");
	for(i=7;i>0;i--)
        printf("%d",data[i]);
        printf("\n");
        printf("redundant bits r2r1r0 is %d%d%d \n",data[4],data[2],data[1]);
 
    printf("\n\nEnter received data bits one by one\n");
    for(i=7;i>0;i--)
        scanf("%d",&dataatrec[i]);
 
    c0=dataatrec[3]^dataatrec[5]^dataatrec[7]^dataatrec[1];
	c1=dataatrec[3]^dataatrec[6]^dataatrec[7]^dataatrec[2];
	c2=dataatrec[5]^dataatrec[6]^dataatrec[7]^dataatrec[4];
	c=c2*4+c1*2+c0 ;
 
    if(c==0) {
		printf("\nNo error while transmission of data\n");
    }
	else {
		printf("\nError on position %d",c);
    	
		printf("\nData sent : ");
        for(i=7;i>0;i--)
        	printf("%d",data[i]);
        
		printf("\nData received : ");
        for(i=7;i>0;i--)
        	printf("%d",dataatrec[i]);
		
		printf("\nCorrect message is\n");
 
		//if errorneous bit is 0 we complement it else vice versa
		if(dataatrec[c]==0)
			dataatrec[c]=1;
        else
			dataatrec[c]=0;
		
		for (i=7;i>0;i--) {
			printf("%d",dataatrec[i]);
		}
		printf("\n");
	}
    return 0;
}
