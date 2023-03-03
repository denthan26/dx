#include<stdio.h>
void defStrCat(char destination[], char source[]);
void defStrCat(char destination[], char source[]) {
    int i = 0;
    while (destination[i] != '\0') {
        i++;
    }
    int length = 0;
    while (source[length] != '\0') {
        length++;
    }
    int j;
    for (j = 0; j < length; j++) {
        destination[i + j] = source[j];
    }
    destination[i+j] = '\0';
}
int main1() {
    //char * destination, const char * source );
    char destination[80] = "this ";
    char source1[] = "is ";
    char source2[] = "strcat ";
    defStrCat(destination, source1);
    printf("%s\n", destination);
    defStrCat(destination, source2);
    printf("%s\n", destination);
}