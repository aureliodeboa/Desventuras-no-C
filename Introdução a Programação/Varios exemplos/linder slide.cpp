#include <stdio.h> 
main()
 { 
 char c;
  int i;
   short int si;
    unsigned int ui;
	 long int li;
	  float f;
	  double d;
	   printf("char %d \n",sizeof(c)); 
	   printf("int %d \n",sizeof(i));
	    printf("short int %d \n",sizeof(si)); 
		printf("unsigned int %d \n",sizeof(ui));
		 printf("long int %d \n",sizeof(li));
		  printf("float %d \n",sizeof(f));
		   printf("double %d \n",sizeof(d));
		    printf("double %d",sizeof(double));
}
