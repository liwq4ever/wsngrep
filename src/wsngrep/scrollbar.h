#pragma once
#ifndef __SNGREP_SCROLLBAR_H
#define __SNGREP_SCROLLBAR_H

#include "ncursesw/ncurses.h"

//! Shorter declaration of scrollbar
typedef struct scrollbar scrollbar_t;

//! Available scrollbar alignments
enum sb_alignment
{
    SB_HORIZONTAL,
    SB_VERTICAL
};

#define SB_TOP MY_SB_TOP
#define SB_BOTTOM MY_SB_BOTTOM
#define SB_LEFT MY_SB_LEFT
#define SB_RIGHT MY_SB_RIGHT

//! Available scrollbar positions
enum sb_dock
{
    SB_TOP,
    SB_BOTTOM,
    SB_LEFT,
    SB_RIGHT
};

/**
 * @brief Window scrollbar
 *
 * This struct contains the required information to draw
 * a scrollbar into a ncurses window
 */
struct scrollbar
{
    //! Ncurses window associated to this scrollbar
    WINDOW* win;
    //! Alignment
    enum sb_alignment alignment;
    //! Position
    enum sb_dock dock;
    //! Current scrollbar position
    int pos;
    //! Max scrollbar positions
    int max;
};

scrollbar_t ui_set_scrollbar(WINDOW* win, int alignment, int dock);


void ui_scrollbar_draw(scrollbar_t sb);

#endif /* __SNGREP_SCROLLBAR_H */