#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d == NULL) {
        printf("Directory cannot be opened\n");
        return 0;
    }
    printf("Directory opened successfully\n");
    while ((dir = readdir(d)) != NULL) {
        printf("File: %s\n", dir->d_name);
    }

    closedir(d);
    printf("Directory closed\n");

    return 0;
}
