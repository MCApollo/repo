#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2 || (
        strcmp(argv[1], "remove") != 0
    )) return 0;

    if (unlink("/usr/lib/_ncurses") == -1)
        return 1;

    unlink("/usr/lib/libcurses.dylib");
    unlink("/usr/lib/libncurses.dylib");

    if (access("/usr/lib/libcurses.dylib", F_OK) != 0)
        symlink("libncurses.5.4.dylib", "/usr/lib/libcurses.dylib");
    if (access("/usr/lib/libncurses.dylib", F_OK) != 0)
        symlink("libncurses.5.4.dylib", "/usr/lib/libncurses.dylib");

    return 0;
}
