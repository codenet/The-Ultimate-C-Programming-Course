#include<stdio.h>
#include<unistd.h>

#define ROW_SZ 40
#define COL_SZ 140
#define TRUE 1
#define FALSE 0

#define PADDLE_LEN 7
#define PADDLE_MGN 3
#define PADDLE_DR 2

#define BALL_INIT_DR 1
#define BALL_INIT_DC 2

#define MOVE_UP 1
#define MOVE_DN 2
#define STAY 3

struct Ball {
	int r, c, dr, dc;
};

typedef struct Ball Ball;

int ai(Ball ball, int p_r, int p_c) {
	if(ball.r < p_r)
		return MOVE_UP;
	else if (ball.r > p_r + PADDLE_LEN -1)
		return MOVE_DN;
	return STAY;
}

void draw_grid(Ball ball, int p1_r, int p2_r) {
	printf("\033[2J");
	char a[ROW_SZ][COL_SZ+1];
	for(int r = 0; r < ROW_SZ; r++) {
		for(int c = 0; c < COL_SZ; c++) {
			a[r][c] = ' ';
		}
	}
	for(int r = 0; r < ROW_SZ; r++) {
		a[r][0] = '.';    // left boundary
		a[r][COL_SZ-1] = '.';  // right boundary
		a[r][COL_SZ] = 0; // null terminating the string
	}

	for(int c = 0; c < COL_SZ; c++) {
		a[0][c] = '.';  // top boundary
		a[ROW_SZ-1][c] = '.'; // bottom boundary
	}

	a[ball.r][ball.c] = '*';

	for(int r = p1_r; r < p1_r + PADDLE_LEN; r++) {
		a[r][PADDLE_MGN] = '1';
	}

	for(int r = p2_r; r < p2_r + PADDLE_LEN; r++) {
		a[r][COL_SZ-1 - PADDLE_MGN] = '2';
	}

	for(int r = 0; r < ROW_SZ; r++) {
		printf("%s\n", a[r]);
	}
}

int paddle1_hit(Ball ball, int p_r) {
	if(ball.c > PADDLE_MGN)
		return FALSE;
	if(ball.r < p_r)
		return FALSE;
	if(ball.r >= p_r + PADDLE_LEN)
		return FALSE;
	return TRUE;
}

int paddle2_hit(Ball ball, int p_r) {
	if(ball.c < COL_SZ - 1 - PADDLE_MGN)
		return FALSE;
	if(ball.r < p_r)
		return FALSE;
	if(ball.r >= p_r + PADDLE_LEN)
		return FALSE;
	return TRUE;
}

int move_paddle_up(int p_r) {
	p_r -= PADDLE_DR;
	if(p_r < 1)
		p_r = 1;
	return p_r;
}

int move_paddle_down(int p_r) {
	p_r += PADDLE_DR;
	if(p_r + PADDLE_LEN > ROW_SZ - 1)
		p_r = ROW_SZ - 1 - PADDLE_LEN;
	return p_r;
}

int move(int mv, int p_r) {
	if(mv == MOVE_UP)
		return move_paddle_up(p_r);
	if(mv == MOVE_DN)
		return move_paddle_down(p_r);
	return p_r;
}

int main() {
	Ball ball = {.r = ROW_SZ/2, .c = COL_SZ/2, .dr = BALL_INIT_DR, .dc = BALL_INIT_DC};

	int p1_r = ROW_SZ/2;
	int p2_r = ROW_SZ/2;
	// Homework
	// Add scores: first to 5 points win
	// Show score
	// >Change angle depending on where it hits the paddle
	// Ball keeps speeding up if the game goes for longer
	// "Smarter AI"
	//   Paddle is moving slower than the ball
	//   how to move paddle when ball keeps changing angle
	while(TRUE) {
		// draw a grid
		draw_grid(ball, p1_r, p2_r);
		
		// move the ball
		ball.r += ball.dr;
		ball.c += ball.dc;

		if(ball.r <= 0) {
			ball.r = 1;
			ball.dr *= -1;
			// ball_dc remains the same
		}
		if(ball.r >= ROW_SZ-1) {
			ball.r = ROW_SZ-2;
			ball.dr *= -1;
			// ball_dc remains the same
		}
		
		// check for winner
		if(ball.c < 0) {
			// ball_c = 0;
			printf("Player 2 wins\n");
			break;
		}
		if(ball.c > COL_SZ-1) {
			// ball_c = COL_SZ-1;
			printf("Player 1 wins\n");
			break;
		}

		if(paddle1_hit(ball, p1_r)) {
			ball.c = PADDLE_MGN;
			ball.dc *= -1;
			// ball_dr remains the same
		}

		if(paddle2_hit(ball, p2_r)) {
			ball.c = COL_SZ - 1 - PADDLE_MGN;
			ball.dc *= -1;
			// ball_dr remains the same
		}

		// Player 1 is run with ai
		int mv1 = ai(ball, p1_r, PADDLE_MGN);
		p1_r = move(mv1, p1_r);

		// Player 2 is run with ai
		int mv2 = ai(ball, p2_r, COL_SZ - 1 - PADDLE_MGN);
		p2_r = move(mv2, p2_r);

		// sleep(1);
		// faster than 1/16 seconds feels like movement
		// 30 frames per second = 30 fps = 1000/30 ~ new frame every 33 ms 
		// usleep(33000);
		usleep(99000);
		// usleep(1000000);
	}
}
