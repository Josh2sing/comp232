#include <stdio.h>

int main() {
    while(1){
        char x = getchar();
        switch(x){
            case '1': printf("One for the money\n");
                      break;
            case '2': printf("Two for the show\n");
                      break;
            case '3': printf("Three to get ready\n");
                      break;
            case '4': printf("Four for the show\n");
                      break;
            case 'q':
                return 0; 
        }
    }
}
