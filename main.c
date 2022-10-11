#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <termios.h>

int main() {
    int ch;
    struct termios old_settings, settings;

    // Get STDIN settings
    tcgetattr(STDIN_FILENO, &old_settings);
    settings = old_settings;

    settings.c_lflag &= (~ICANON & ~ECHO);

    // Set STDIN settings
    tcsetattr(STDIN_FILENO, TCSANOW, &settings);


    while ((ch = getc(stdin)) != EOF) {
        if (isalpha(ch)) {
            putc('$', stdout);
            continue;
        }
        if (isdigit(ch)) {
            putc('!', stdout);
            continue;
        }
        putc('-', stdout);
    }

    // Set STDIN old settings
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);

    return 0;
}
