#include <iostream>
#include <fstream>
#include <string>
#include <termios.h>
#include <unistd.h>

using namespace std;

// Function to set terminal to unbuffered mode
void enableRawMode() {
    termios tty;
    tcgetattr(STDIN_FILENO, &tty); // Get current terminal attributes
    tty.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &tty); // Apply the new settings
}

// Function to reset terminal to its original mode
void disableRawMode(const termios &orig_tty) {
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_tty); // Restore original settings
}

int main() {
    // Save original terminal settings
    termios orig_tty;
    tcgetattr(STDIN_FILENO, &orig_tty);

    // Enable unbuffered (raw) mode
    enableRawMode();

    // Open the file with truncation mode to clear previous content
    ofstream fout("fileByCpp.txt", ios::trunc);
    if (!fout) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    char c;
    int size = 0;
    cout << "Press any key (press '-' to quit):" << endl;

    // Buffer to keep track of what's written to the file
    string buffer;

    while (true) {
        read(STDIN_FILENO, &c, 1); // Unbuffered read from stdin

        if (c == 127) { // Handle Backspace (ASCII 127)
            if (!buffer.empty()) {
                // Remove the last character from the buffer
                buffer.pop_back();

                // Move the cursor back, overwrite with space, move back again
                cout << "\b \b" << flush;
                size--;
            }
        } else if (c == '-') {
            break; // Exit if '-' is pressed
        } else {
            // Add character to the buffer and file
            buffer.push_back(c);
            fout.put(c);
            fout.flush(); // Ensure immediate write

            // Print the character to the terminal
            cout << c << flush;
            size++;
        }
    }

    // Write the final buffer to the file
    fout.close();

    // Restore the original terminal settings
    disableRawMode(orig_tty);

    // Output the total size written
    cout << "\nWrote " << size << " bytes!" << endl;

    return 0;
}
