#include <stdio.h>
#include <fcntl.h>  
#include <unistd.h>  
int main() {
    int fd;
    char buffer[50];
    fd = open("demo.txt", O_CREAT | O_RDWR, 0644);
    write(fd, "Hello World\n", 12);
    lseek(fd, 0, SEEK_SET);
    read(fd, buffer, sizeof(buffer));
    printf("File content: %s\n", buffer);
    close(fd);
    return 0;
}
