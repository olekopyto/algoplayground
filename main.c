

#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

#define menu_h 24
#define menu_w 80
#define menu_x 0
#define menu_y 0

int draw_menu(char** menu_options,int menu_max){
    WINDOW *w_menu;
   
    
    initscr();
    cbreak();	
    noecho();

    w_menu = newwin(menu_h, menu_w, menu_x, menu_y);
    box(w_menu,0,0);
    //printw("Findmax \n");
    wprintw(w_menu, "Algoplayground_v0.1");
    //menu printing
    for(int i=0; i<menu_max; i++)
        mvwprintw(w_menu, 1 + i, 2, menu_options[i]);    
    mvwprintw(w_menu, 1, 1, "");
    refresh();
    wrefresh(w_menu);
    int menu_steer, menu_choice = 0;
    	

    keypad(stdscr, TRUE);
    while((menu_steer = getch()) != 'q'){
        switch(menu_steer){
            case KEY_UP:
                menu_choice--;
                if(menu_choice > 0){
                    attron(A_BOLD);	
                    mvwprintw(w_menu, 1 + menu_choice, 2, menu_options[menu_choice]);
                    attroff(A_BOLD);
                } else menu_choice = 0;
                mvwprintw(w_menu, 1 + menu_choice, 1, 0);
                wrefresh(w_menu);
                break;
            case KEY_DOWN:
                menu_choice++;
                if(menu_choice < menu_max ){
                    attron(A_BOLD);	
                    mvwprintw(w_menu, 1 + menu_choice, 2, menu_options[menu_choice]);
                    attroff(A_BOLD);
                } else menu_choice = menu_max - 1;
                mvwprintw(w_menu, 1 + menu_choice, 1, 0);
                wrefresh(w_menu);
                break;
            case KEY_ENTER:
            case '\n':
                
                mvwprintw(w_menu, 10, 10, "%d",menu_choice);
                wrefresh(w_menu);
                refresh();
                delwin(w_menu);
                endwin();
                return menu_choice;
                break;
        }
    }
    delwin(w_menu);
    endwin();

    return -1;
}

int main(void)
{
    char *menu_options[]={"Quicksort Hoare","Findmax","Karatsbua"};
    int menu_choice = draw_menu(menu_options, 3);
    printf("%d \n", menu_choice);
    return 0;
}
