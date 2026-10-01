#include <ncurses.h>
#include <iostream>
#include <space.hpp>
#include <unistd.h>

// Simple function to draw a rectangle frame using text characters
void draw_rectangle(int start_y, int start_x, int width, int height, char ch) {
    // Draw top and bottom horizontal lines
    for (int x = 0; x < width; ++x) {
        mvaddch(start_y, start_x + x, ch);              // Top side
        mvaddch(start_y + height - 1, start_x + x, ch);  // Bottom side
    }
    
    // Draw left and right vertical lines
    for (int y = 0; y < height; ++y) {
        mvaddch(start_y + y, start_x, ch);              // Left side
        mvaddch(start_y + y, start_x + width - 1, ch);  // Right side
    }
}

int main() {
    // 1. Initialize ncurses screen mode
    initscr();            
    cbreak();             // Disable line buffering (get input instantly)
    noecho();             // Don't print user keystrokes to the screen
    curs_set(0);          // Hide the physical blinking cursor
    nodelay(stdscr, TRUE); // Enable non-blocking getch()

    Space s;
    s.Generate(5);
    s.ConnectSpace();

    // 2. Set up colors if the terminal supports them
    if (has_colors()) {
        start_color();
        // Create a color pair: Green text (1) on Black background
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        attron(COLOR_PAIR(1)); // Turn on this color pair
    }
    // 5. Wait for user input so the window doesn't immediately close
   
    do {
        if(getch() == 'x')
        {
            break;
        }

        clear();
        // 3. Draw shapes onto the terminal buffer
        // Syntax: draw_rectangle(y, x, width, height, character)
        // draw_rectangle(3, 5, 30, 10, '#');
        // draw_rectangle(5, 45, 15, 6, '*');


        // Add some text context inside the shape
        mvprintw(6, 8, "Emergence");
        mvprintw(15, 5, "Press 'x' to exit...");

        s.Compute();

        s.DrawSpace();

        // 4. Refresh the physical screen to push the memory buffer to the terminal
        refresh();
        usleep(100000);
    }
    while(1);




    // 6. Clean up and restore normal terminal state
    endwin();

    return 0;
}