#include <stdio.h>

int main() {
	while(1){
		char x = getchar();
		if(x == '1'){
			printf("One for the money\n");
		}else if(x=='2'){
			printf("Two for the show\n");
			
		}else if(x=='3'){
			printf("Three to get ready\n");	
		}else if(x=='4'){
			printf("Four for the show\n");	
		} else if(x=='q'){
            return 0;
        }
	}
}
