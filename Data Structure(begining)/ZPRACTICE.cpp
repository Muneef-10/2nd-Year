#include <stdio.h>
#include <string.h>

int main() {
    char ans[20] = "Hello";
    char t = '!';
    strncat(ans, &t, 4);
    
    printf("%s\n", ans); 
    return 0;
}