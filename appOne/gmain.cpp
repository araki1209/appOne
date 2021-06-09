#define _HSV
//02
#ifdef _w&c
#include"libOne.h"
void gmain() {
	window(450, 450);
	clear(200);
	pause();
}
#endif
//03
#ifdef _point
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	clear(200);
	strokeWeight(30);
	stroke(255, 0, 0);
	point(500, 500);
	//stroke(255,255,0);
	point(700, 500);
	//stroke(0,0,255);
	point(900, 500);
	pause();
}
#endif
//04
#ifdef _line
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	clear(255);
	strokeWeight(20);
	stroke(0, 255, 0);
	float sx = 100, sy = 500, ex = 900, ey = 600;
	line(sx, sy, ex, ey);
	line(500, 100, 500, 900);
	pause();
}
#endif
//05
#ifdef _circle
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	clear(200);
	strokeWeight(20);
	stroke(0, 255, 0);
	fill(255, 0, 0);
	float px = 500, py = 500, radius = 200;
	circle(px, py, radius*2);
	pause();
}
#endif
//06
#ifdef _rect
#include"libOne.h"
void gmain() {
	window(1000, 1000);
	clear(200);

	strokeWeight(128);
	stroke(255, 255, 0);

	rectMode(CENTER);
	angleMode(DEGREES);
	float px = 300, py = 200, w = 200, h = 300, angle = 45;
	rect(px, py, w, h, angle);

	pause();
}
#endif
//07
#ifdef _zukei
#include"libOne.h"
void gmain(){
	window(1980, 1080, full);
	float px = 1980 / 2;
	float py = 1080 / 2;
	float vx = 10;
	float radius = 150;
	float len = radius / 1.4142f * 2;
	float sw = radius / 8;
	float angle = 0;
	float angleSpeed = 0.03f;
	while (notQuit) {
		px += vx;
		angle += angleSpeed;
		if (px<0||px > width) { 
			vx = -vx; 
			angleSpeed = -angleSpeed;
		}
		clear(60);
		strokeWeight(sw);
		stroke(255, 0, 0);
		circle(px, py, radius * 2);
		rectMode(CENTER);
		rect(px, py, len, len,angle);
		strokeWeight(sw * 4);
		point(px, py);
		strokeWeight(sw);
		line(1980 / 2, 0, px, py);
	}
}
#endif#

//08
#ifdef _W&F
#include"libOne.h"
void gmain() {
	window(1980, 1080, full);
	int life = 5;
	float px = 700;
	float py = 200;
	float radius = 50;
	float space = 100;
	while (notQuit) {
		if (isTrigger(KEY_A)) { life--; }
		if (isTrigger(KEY_D)) { life++; }
		clear(74, 84, 89);
		fill(255, 255, 0);
		print((let)"life="+life);
		strokeWeight(20);
		stroke(255);

		//while
		int i = 0;
		fill(255,200,200);
		while (i < life) {
			float offsetX = space * i;
			circle(px + offsetX, py, radius * 2);
			i++;
		}
		//for
		fill(160,200,240);
		for (int i = 0; i < life;i++) {
			float offsetX = space * i;
			float offsetY = space * 2;
			circle(px + offsetX, py+offsetY, radius * 2);
		}


	}
}
#endif

//09
#ifdef _hpgage
#include"libOne.h"
void gmain() {
	window(1920, 1080);
	//ƒf[ƒ^
	struct COLOR green = { 0,255,0 };
	struct COLOR yellow{255,255,0};
	struct COLOR red {255,0,0};
	struct COLOR color= green;
	int hpMax = 500;
	int hpWaring = hpMax * 0.3f;
	int hpDanger = hpMax * 0.1;
	int hp = hpMax;
	float px = 700;
	float py = 200;
	float h = 60;
	while (notQuit) {
		if (isTrigger(KEY_SPACE)) {
			hp = hpMax;
		}
		if (hp > 0) {
			hp -= 1;
		}
		if (hp > hpWaring) {
			color = green;
		}
		else if (hp > hpDanger) {
			color = yellow;
		}
		else {
			color = red;
		}
		clear(74, 84, 89);
		fill(128);
	    rect(px, py, hpMax, h);
		fill(color);
		rect(px, py, hp, h);
		if (hp <= 0) {
			textSize(100);
			fill(255, 0, 0);
			text("Game Over", 700, 400);
		}
	}
}
#endif

//10
#ifdef _face
#include"libOne.h"
#include"face.h"
void gmain() {
	window(1920, 1080);
	float px = width / 2;
	float py = height / 2;
	float angle = 0;
	float ofsX=100;
	float ofsY=100;
	int sw = 1;
	while (notQuit) {
		ofsX = width / 2 - mouseX;
		ofsY = height / 2 - mouseY;
		if (isTrigger(KEY_SPACE)) { sw = 1 - sw; }
		angle += 0.01f;
		clear(60, 120, 240);
		strokeWeight(10);
		for (int i = -5; i <= 5; i++) {


			if (sw == 1) {
				roundFace(px+ofsX*i, py+ofsY*i);
			}
			else {
				squareFace(px+ofsX*i, py+ofsY*i, angle);
			}
		}
	}
}
#endif

//13
#ifdef _SHOOT
#include"libOne.h"
void gmain() {
	window(1920, 1080);
	struct PLAYER {
		float px, py, w, h, vx,ofsY;
	};
	struct BULLET {
		float px, py, w, h, vy;
		int hp = 0;
	};
	struct PLAYER p;
	p.px = width / 2;
	p.py = height - 150;
	p.w = 100;
	p.h = 200;
	p.vx = 10;
	p.ofsY = -100;
	const int numBullet = 10;
	struct BULLET b[numBullet];
	for (int i = 0; i < numBullet; i++) {
		b[i].px = p.px;
		b[i].py = p.py;
		b[i].w = 20;
		b[i].h = 40;
		b[i].vy = -10;
	}

	while (notQuit) {
		if (isPress(KEY_A)) { p.px += -p.vx; }
		if (isPress(KEY_D)) { p.px += p.vx; }
		if (isTrigger(KEY_SPACE)) {
			for (int i = 0; i < numBullet; i++) {
				if (b[i].hp == 0) {
					b[i].hp = 1;
					b[i].px = p.px;
					b[i].py = p.py + p.ofsY;
					i = numBullet;
				}
			}
		}
		for (int i = 0; i < numBullet; i++) {
			if (b[i].hp > 0) {
				b[i].py += b[i].vy;
				if (b[i].py < -b[i].h) {
					b[i].hp = 0;
				}
			}
		}
		clear();
		rectMode(CENTER);
		rect(p.px, p.py, p.w, p.h);
	    for (int i = 0; i < numBullet; i++) {
		    if (b[i].hp > 0) { 
				rect(b[i].px, b[i].py, b[i].w, b[i].h);
			}
		}

	}
}


#endif
//14
#ifdef _SORT
#include"libOne.h"
void gmain() {
	window(1100, 1000);
	const int num = 20;
	int score[num];
	int r, c;
	while (notQuit) {
		clear(60);

	    if (isTrigger(KEY_A)) {
			for (int i = 0; i < num; i++) {
				score[i] = random() % 1001;
			}
	    }

		if (isTrigger(KEY_D)) {
			for (r = 0; r < num - 1; r++) {
				for (c = r + 1; c < num; c++) {
					if (score[r] < score[c]) {
						int w = score[r];
						score[r] = score[c];
						score[c] = w;
					}
				}
			}
		}
		for (int i = 0; i < num; i++) {
			print(score[i]);
			rect(100, 50 * i, score[i], 40);
		}
	}
}
#endif
//15
#ifdef _HSV
#include"libOne.h"
void gmain() {
	window(1920, 1080);
	colorMode(HSV);
	float hue = 0;
	float satu = 255;
	float value = 255;
	angleMode(DEGREES);
	while (notQuit) {
		if (isPress(KEY_D)&&hue<360)hue += 5;
		if (isPress(KEY_A)&&hue>0)hue -= 5;
		if (isTrigger(KEY_W)&&hue < 360)hue += 5;
		if (isTrigger(KEY_S) && hue > 0)hue -= 5;
		if (isPress(KEY_R) && satu < 255)satu += 5;
		if (isPress(KEY_F) && satu > 0)satu -= 5;
		if (isPress(KEY_T) && value < 255)value += 5;
		if (isPress(KEY_G) && value > 0)value -= 5;
		clear(0);
		fill(hue, satu, value);
		textSize(120);
		text((let)"hue=" + hue, 600, 400);
		text((let)"satu=" + satu, 600, 600);
		text((let)"value=" + value, 600, 800);
		int num = 128;
		float angle = hue / num;
		for (int i = 0; i < num; i++) {
			float px = cos(angle*i) * 200;
			float py = -sin(angle*i) * 200;
			fill(angle * i, satu, value);
			noStroke();
			circle(px+1500, py+540, 50);
		}

	}
}
#endif
