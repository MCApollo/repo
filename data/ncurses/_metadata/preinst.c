#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2 || (
        strcmp(argv[1], "install") != 0 && (
            strcmp(argv[1], "upgrade") != 0 ||
            strncmp(argv[2], "5.6-", 4) != 0
    ))) return 0;

    unlink("/usr/lib/_ncurses");
    if (symlink("/usr/lib", "/usr/lib/_ncurses") != 0)
        return 1;

    return 0;
}
