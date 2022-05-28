// lab 13 - for draw poligone with click functionality
#include <graphics.h>
#include <iostream>
#include <windows.h>
#include <shapes.h>
#include <pthread.h>
#include <cstdlib>
using namespace std;

void print_game_over_page(int game_Score)
{
	int initial_vertex = 100;
	char page_b_text[][20] = {"Restart", "main_menu", "exit ", "GAME OVER!!", "Your Score Is : "};
	cout << "in game over page score is " << game_Score << endl;
	for (int i = 0; i < 3; i++)
	{
		rectangle(initial_vertex + i * 150, getmaxy() - 75, initial_vertex + (i + 1) * 150, getmaxy() - 25);
		print_text(page_b_text[i], initial_vertex + 75 + i * 150, getmaxy() - 50, 2);
	}
	// print game score
	string gs = to_string(game_Score);
	// rectangle(getmaxx()/2 - 200 , getmaxy()/2, getmaxx()/2 , getmaxy()/2);
	print_text(page_b_text[3], getmaxx() / 2, getmaxy() / 2 - 150, 4);
	print_text(page_b_text[4], getmaxx() / 2 - 85, getmaxy() / 2, 1);
	print_text(gs, getmaxx() / 2 + 13, getmaxy() / 2, 3);
}
void print_game_dificulty_page()
{
	int initial_vertex = 100;
	char page_b_text[][26] = {"Easy", "Medium", "Hard", "Expert", "Choose Difficulty level :"};
	// cout << "in game over page score is " << game_Score << endl;
	for (int i = 0; i < 4; i++)
	{
		rectangle(initial_vertex + i * 150, getmaxy() - 200, initial_vertex + (i + 1) * 150, getmaxy() - 150);
		print_text(page_b_text[i], initial_vertex + 75 + i * 150, getmaxy() - 175, 2);
	}

	print_text(page_b_text[4], getmaxx() / 2, getmaxy() / 2, 3); // lable printing
}
void *update_game_score(void  *game_score)
{
	char page_b_text[][26] = {"score :"};
	print_text(page_b_text[0], 50, 10, 1);
	// print game score
	long gst;
	gst = (long)game_score;
	string gs = to_string(gst);
	print_text(gs, 105, 10, 1); // lable printing
	return 0;
}
void draw_home_page()
{

	char page_b_text[][15] = {"Start", "exit"};

	rectangle(getmaxx() / 2 - 100, getmaxy() / 2 - 50, getmaxx() / 2, getmaxy() / 2 + 50);
	print_text(page_b_text[0], getmaxx() / 2 - 50, getmaxy() / 2, 3);
	rectangle(getmaxx() / 2, getmaxy() / 2 - 50, getmaxx() / 2 + 100, getmaxy() / 2 + 50);
	print_text(page_b_text[1], getmaxx() / 2 + 50, getmaxy() / 2, 3);
}
int game_over_page_click_event()
{
	while (1)
	{
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			POINT CursorPosition;
			GetCursorPos(&CursorPosition);
			// std::cout << CursorPosition.x << "\n";
			// std::cout << CursorPosition.y << "\n";
			int x = CursorPosition.x;
			int y = CursorPosition.y;

			if (getmaxy() - 75 < y && y < getmaxy() - 25)
			{
				if (100 < x && x < 250)
				{
					cleardevice();
					return 1;
				}
				else if (250 < x && x < 400)
				{
					cleardevice();
					return 2;
				}
				else if (400 < x && x < 550)
				{
					cleardevice();
					return 0;
				}
			}
		}
		delay(10);
	}
}
int game_difficulty_click_event()
{
	while (1)
	{
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			POINT CursorPosition;
			GetCursorPos(&CursorPosition);
			// std::cout << CursorPosition.x << "\n";
			// std::cout << CursorPosition.y << "\n";
			int x = CursorPosition.x;
			int y = CursorPosition.y;

			if (getmaxy() - 200 < y && y < getmaxy() - 150)
			{
				if (100 < x && x < 250)
				{
					cleardevice();
					return 0;
				}
				else if (250 < x && x < 400)
				{
					cleardevice();
					return 1;
				}
				else if (400 < x && x < 550)
				{
					cleardevice();
					return 2;
				}
				else if (550 < x && x < 700)
				{
					cleardevice();
					return 3;
				}
			}
		}
		delay(10);
	}
}
int home_page_click_event()
{
	while (1)
	{
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			POINT CursorPosition;
			GetCursorPos(&CursorPosition);
			// std::cout << CursorPosition.x << "\n";
			// std::cout << CursorPosition.y << "\n";
			int x = CursorPosition.x;
			int y = CursorPosition.y;

			if (getmaxy() / 2 - 50 < y && y < getmaxy() / 2 + 50)
			{
				if (getmaxx() / 2 - 100 < x && x < getmaxx() / 2)
				{
					cleardevice();
					return 1;
				}
				else if (getmaxx() / 2 < x && x < getmaxx() / 2 + 100)
				{
					cleardevice();
					return 2;
				}
			}
		}
		delay(10);
		Sleep(60);
	}
}

int main_game()
{
	//creating threade
	pthread_t threads1;
	int rc;
	

	// draw base li in tectangle shape
	// int update_gs_f = 0;
	int cx = 100, cy = 50; // initial position of circle
	int vx = 3, vy = 5;	   // vector component
	int fx = 0, fy = 0;	   // fx and fy are flags;
	int radius = 10;	   //  radius of cirle

	print_game_dificulty_page();
	int game_diffi_level = game_difficulty_click_event();

	// set component and values according difficulty level
	int d_yindex; // main difficulty variable

	int d_e_yindex = 300;
	int d_h_yindex = 200;
	int d_m_yindex = 100;
	int d_ea_yindex = 0;

	// set difficulty level
	if (game_diffi_level == 0)
	{
		d_yindex = d_ea_yindex;
	}
	else if (game_diffi_level == 1)
	{
		vx = 1.5 * (vx);
		vy = 1.5 * (vy);
		d_yindex = d_m_yindex;
	}
	else if (game_diffi_level == 2)
	{
		vx = 2 * (vx);
		vy = 2 * (vy);
		d_yindex = d_h_yindex;
	}
	else if (game_diffi_level == 3)
	{
		vx = 2.5 * (vx);
		vy = 2.5 * (vy);
		d_yindex = d_e_yindex;
	}

	// score counter init...
	int score_counter = 0;

	// base line init
	int x = getmaxx(), y = getmaxy();													 // x and y have the maximum screen dimensions; vx and vy are components of the vector for text;
	int bx1 = x / 2 - 75, by1 = y - d_yindex - 20, bx2 = x / 2 + 75, by2 = y - d_yindex; // posision of ractangle

	setcolor(7);
	rectangle(bx1, by1, bx2, by2); // base line
	setfillstyle(LTSLASH_FILL, WHITE);
	delay(1000);
	// main whilw loop
	while (1)
	{
		cleardevice();
		// if(update_gs_f != init_)
		// {
		
		// update_gs_f = 0;
		// }
		// for key fehing and move ractangel
		if (GetAsyncKeyState(VK_LEFT))
		{
			if (bx1 <= 0)
			{
				;
			}
			else
			{

				bx1 -= 10;
				bx2 -= 10;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			if (bx2 >= x)
			{
				;
			}
			else
			{

				bx1 += 10;
				bx2 += 10;
			}
		}
		if (GetAsyncKeyState(VK_UP))
		{
			if (by1 <= 400) // 400 for y index not going to top
			{
				;
			}
			else
			{

				by1 -= 10;
				by2 -= 10;
			}
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			if (by2 >= (y - d_yindex))
			{
				;
			}
			else
			{

				by1 += 10;
				by2 += 10;
			}
		}
		rectangle(bx1, by1, bx2, by2);
		// ball/aquremovment process
		// setfillstyle(SLASH_FILL, RED);
		circle(cx, cy, radius); // draw bouncing ball
		// floodfill(cx, cy, RED);
		// print game score with threading
		rc = pthread_create(&threads1, NULL, update_game_score, (void*)score_counter);

		// update_game_score(score_counter);
		// delay(10);

		// this condition is for to change position of rectangle until it hit the side of window
		if (fx == 0)
		{
			cx += vx;
		}
		else
		{
			cx -= vx;
		}
		if (fy == 0)
		{
			cy += vy;
		}
		else
		{
			cy -= vy;
		}

		// collisin decide code that rectangle hit the side or not ,,  if hit change direction as chang in direction flags(fx,fy)
		// now we change the drawing positions according to the flags.
		// fx determines if movement is in right direction (0) or in the left direction (1) and fy determines if movement is in the downward direction (0) or upward direction (1)

		if (bx1 < cx && cx < bx2 && by2 > (cy + radius) && (cy + radius) > by1)
		{
			delay(2);
			fy = 1;
			score_counter++;
			
			cout << "enter in condition" << endl;
		}
		// delay(10);
		if ((y - (radius)) < (cy))
		{
			cleardevice();
			return score_counter;
			break;
		}

		if (cy <= radius)
		{
			fy = 0;
		}
		if ((x - (radius)) < (cx))
		{
			fx = 1;
		}
		if (cx <= radius)
		{
			fx = 0;
		}

		delay(10);
	}
}

int main()
{
	int game_score;
	int p_r_v;
	initwindow(1000, 800);
mainmenu:
	// drwa home page
	draw_home_page();
	int h_p_e = home_page_click_event();
	cout << h_p_e << endl;
	if (h_p_e == 2)
	{
		goto end_game;
	}

restart:
	game_score = main_game();

	// now print game score and game over page/menu

	cleardevice();
	cout << "game is over";
	print_game_over_page(game_score);

	p_r_v = game_over_page_click_event();
	if (p_r_v == 1)
	{
		goto restart;
	}
	else if (p_r_v == 2)
	{
		goto mainmenu;
	}
	else
	{
		goto end_game;
	}

end_game:
	cout << "quiting the game";

	return 0;
}
