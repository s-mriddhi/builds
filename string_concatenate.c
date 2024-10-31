#include <stdio.h>
#include <string.h>

int main() {
    char dest[100] = "Geeksfor";
    char src[100] = "Geeks";

    // Concatenate src to dest
    strcat(dest, src);

    printf("Concatenated String: %s\n", dest);
    return 0;
}