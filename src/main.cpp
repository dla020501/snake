#include <ncurses.h>
#include "SnakeGame.hpp"

using namespace snake;

int main()
{   
    // ncurses 시작
    initscr();
    // 일단 초기화 진행
    refresh();
    // 입력된 키 표시 안함
    noecho();
    // 커서 안보이게 설정
    curs_set(0);

    // 게임 스타트
    SnakeGame game;

    // 게임 오버가 될 때까지
    while (!game.isOver())
    {   
        // 게임에서 입력 값에 따라 바뀌는 로직
        game.getInputState();

        // 게임하는 중 진행되는 로직
        game.playingState();

        // 게임 새로고침(= 실제로 창에 표시하는 단계)
        game.redraw();
    }

    // 게임 오버 되어서 빠져 나왔을 때 스테이지 넘버가 4라는 것은 클리어 했다는 뜻
    if (game.getStageNum() == 4)
    {
        printw("Game Clear!!!");
    }
    // 그게 아니라면 진짜로 게임 오버라는 뜻
    else
    {
        printw("Game Over!!!");
    }
    
    // 입력 값 받을 때 까지 대기
    getch();
    // ncurses 종료
    endwin();
}