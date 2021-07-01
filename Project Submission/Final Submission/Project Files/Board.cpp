

#include "Board.h"
#include <cstdio>
enum BoardParts {
	NILL, S_BRICK, G_BRICK, R_BRICK
};
Board::~Board(void) {
}
void Board::InitalizeBoard(int w, int h, int level) {
	if (Level == 1) {
		Lives = 3;
		Score = 0;
		BigSaucerGenerationPoint = GetRandInRange(2, 30.9);
		SmallSaucerGenerationPoint = GetRandInRange(2, 30.9);
		ObjArray[0] = new SpaceShip;
		ObjArray[1] = new Bomb;
		for (int count = 2; count < 6; count++) {
			ObjArray[count] = new BigAsteroid;
		}
		for (int count = 6; count < 14; count++) {
			ObjArray[count] = new MediumAsteroid;
		}
		for (int count = 14; count < 30; count++) {
			ObjArray[count] = new SmallAsteroid;
		}
		for (int count = 30; count < 32; count++) {
			ObjArray[count] = new VacantObject;
		}
		width = w;
		height = h;
		for (int i = 0; i < BOARD_Y - 1; ++i) {
			for (int j = 0; j < BOARD_X; ++j) {
				board_array[i][j] = NILL;
			}
		}
	}
	else {
		ObjArray[0] = new SpaceShip;
		ObjArray[1] = new Bomb;
		BigSaucerGenerationPoint = GetRandInRange(2, 30.9);
		SmallSaucerGenerationPoint = GetRandInRange(2, 30.9);
		for (int count = 2; count < 6; count++) {
			ObjArray[count] = new BigAsteroid;
		}
		for (int count = 6; count < 14; count++) {
			ObjArray[count] = new MediumAsteroid;
		}
		for (int count = 14; count < 30; count++) {
			ObjArray[count] = new SmallAsteroid;
		}
		for (int count = 30; count < 34; count++) {
			ObjArray[count] = new VacantObject;
		}
	}
}
Board::Board(int xsize, int ysize) {
	Level = 1;
	LifeIncrementPoints = 0;
	BigSaucerShoot = 0;
	SmallSaucerShoot = 0;
	GameSpeed = 0.1;
	ObjArray = new Objects*[34];
	xcellsize = xsize;
	ycellsize = ysize;
	pcolor = CHOCOLATE;
	bcolor = ORANGE_RED;
	gcolor = PINK;
	for (int i = 0; i < BOARD_Y; ++i)
		for (int j = 0; j < BOARD_X; ++j)
			board_array[i][j] = 0;
}
void Board::Draw() {
	glColor3f(0, 0, 1);
	glPushMatrix();
	for (int i = BOARD_Y - 2, y = 0; i >= 0; --i, y += xcellsize) {
		for (int j = 0, x = 0; j < BOARD_X; j++, x += (ycellsize)) {
			switch (board_array[i][j]) {
			case NILL:
				break;
			case S_BRICK:
				DrawRectangle(x - 10, y, ycellsize, xcellsize,
					colors[SLATE_GRAY]);
				break;
			case G_BRICK:
				DrawRectangle(x - 10, y, ycellsize, xcellsize,
					colors[LIGHT_GREEN]);
				break;
			case R_BRICK:
				DrawRectangle(x - 10, y, ycellsize, xcellsize, colors[RED]);
				break;
			}
		}
	}
	glPopMatrix();
}
void Board::GetInitTextPosition(int &x, int &y) {
	x = xcellsize;
	y = (BOARD_Y - 1) * ycellsize + ycellsize / 2;
}
float Board::GetDistance(float x1, float y1, float x2, float y2) {
	return sqrt(((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1)));;
}
void Board::DisplayGameDetails()
{//displays score, lives, and level, and controls
	float greypointer[3];
	greypointer[0] = 0.5;
	greypointer[1] = 0.5;
	greypointer[2] = 0.5;
	DrawString(10, 800, "Lives: ", greypointer);
	DrawString(70, 800, std::to_string(Lives), greypointer);
	DrawString(10, 750, "Score: ", greypointer);
	DrawString(75, 750, std::to_string(Score), greypointer);
	DrawString(10, 700, "Level: ", greypointer);
	DrawString(75, 700, std::to_string(Level), greypointer);
	DrawString(800, 800, "CONTROLS:", greypointer);
	DrawString(800, 750, "^: Forward ", greypointer);
	DrawString(800, 700, "< & >: Turn", greypointer);
	DrawString(800, 650, "B: Shoot Bomb ", greypointer);
	DrawString(800, 600, "H: Hyperspace ", greypointer);
}
void Board::DrawAndMoveObjects()
{
	//draws spaceship
	ObjArray[0]->Draw(ObjArray[0]->Get_x(), ObjArray[0]->Get_y(), ObjArray[0]->Get_theta());
	//draws and moves bombs
	if (ObjArray[1]->Get_x() < 1025 && ObjArray[1]->Get_y() < 845 && ObjArray[1]->Get_x() > -5 && ObjArray[1]->Get_y() > -5) {
		ObjArray[1]->Draw(ObjArray[1]->Get_x(), ObjArray[1]->Get_y(), 0.1);
		ObjArray[1]->Move(50 * (GameSpeed));
	}
	if (ObjArray[30]->Get_x() <= 1025 && ObjArray[30]->Get_x() >= -5 && ObjArray[30]->Get_y() <= 845 && ObjArray[30]->Get_y() >= -5) {
		if (ObjArray[32]->Get_dead() == 0) {
			if (ObjArray[32]->Get_x() < 1025 && ObjArray[1]->Get_y() < 845 && ObjArray[32]->Get_x() > -5 && ObjArray[32]->Get_y() > -5) {
				ObjArray[32]->Draw(ObjArray[32]->Get_x(), ObjArray[32]->Get_y(), 0.1);
				ObjArray[32]->Move(50 * (GameSpeed));
			}
		}
	}
	if (ObjArray[31]->Get_x() <= 1025 && ObjArray[31]->Get_x() >= -5 && ObjArray[31]->Get_y() <= 845 && ObjArray[31]->Get_y() >= -5) {
		if (ObjArray[33]->Get_dead() == 0) {
			if (ObjArray[33]->Get_x() < 1025 && ObjArray[1]->Get_y() < 845 && ObjArray[33]->Get_x() > -5 && ObjArray[33]->Get_y() > -5) {
				ObjArray[33]->Draw(ObjArray[33]->Get_x(), ObjArray[33]->Get_y(), 0.1);
				ObjArray[33]->Move(50 * (GameSpeed));
			}
		}
	}
	// draws and moves asteroids and saucers
	for (int count = 2; count < 6; count++) {
		ObjArray[count]->Draw(ObjArray[count]->Get_x(), ObjArray[count]->Get_y(), 0.1);
		ObjArray[count]->Move(1 * (Level)*(GameSpeed));
	}
	for (int count = 6; count < 14; count++) {
		if (ObjArray[count]->Get_x() <= 1025 && ObjArray[count]->Get_x() >= -5 && ObjArray[count]->Get_y() <= 845 && ObjArray[count]->Get_y() >= -5) {
			ObjArray[count]->Draw(ObjArray[count]->Get_x(), ObjArray[count]->Get_y(), 0.1);
			ObjArray[count]->Move(2 * (Level)*(GameSpeed));
		}
	}
	for (int count = 14; count < 30; count++) {
		if (ObjArray[count]->Get_x() <= 1025 && ObjArray[count]->Get_x() >= -5 && ObjArray[count]->Get_y() <= 845 && ObjArray[count]->Get_y() >= -5) {
			ObjArray[count]->Draw(ObjArray[count]->Get_x(), ObjArray[count]->Get_y(), 0.1);
			ObjArray[count]->Move(1 * (Level)*(GameSpeed));
		}
	}
	if (ObjArray[30]->Get_x() <= 1025 && ObjArray[30]->Get_x() >= -5 && ObjArray[30]->Get_y() <= 845 && ObjArray[30]->Get_y() >= -5) {
		ObjArray[30]->Draw(ObjArray[30]->Get_x(), ObjArray[30]->Get_y(), 0.1);
		ObjArray[30]->Move(2 * (Level)*(GameSpeed));
	}
	if (ObjArray[31]->Get_x() <= 1025 && ObjArray[31]->Get_x() >= -5 && ObjArray[31]->Get_y() <= 845 && ObjArray[31]->Get_y() >= -5) {
		ObjArray[31]->Draw(ObjArray[31]->Get_x(), ObjArray[31]->Get_y(), 0.1);
		ObjArray[31]->Move(4 * (Level)*(GameSpeed));
	}
}
void Board::DetectCollisions() {
	//checks for spaceship collision with asteroids and saucers
	for (int count = 2; count < 14; count++) {
		float distance = GetDistance(ObjArray[0]->Get_x(), ObjArray[0]->Get_y(), ObjArray[count]->Get_x(), ObjArray[count]->Get_y());
		float allowedDistance = (ObjArray[0]->Get_radius() + ObjArray[count]->Get_radius());
		if (distance < allowedDistance) {
			ObjArray[0]->Set_x(510);
			ObjArray[0]->Set_y(420);
			ObjArray[0]->Set_theta(0);
			Lives--;
			int first_asteroid_segment_position = (count * 2) + 2;
			for (int count_2 = first_asteroid_segment_position; count_2 <= first_asteroid_segment_position + 1; count_2++) {
				ObjArray[count_2]->Set_x(ObjArray[count]->Get_x() + (50 * sin(GetRandInRange(0, 7))));
				if (ObjArray[count_2]->Get_x() >= 1020) {
					ObjArray[count_2]->Set_x(ObjArray[count_2]->Get_x() - 1020);
				}
				else if (ObjArray[count_2]->Get_x() <= 0) {
					ObjArray[count_2]->Set_x(ObjArray[count_2]->Get_x() + 1020);
				}
				ObjArray[count_2]->Set_y(ObjArray[count]->Get_y() + (50 * cos(GetRandInRange(0, 7))));
				if (ObjArray[count_2]->Get_y() >= 840) {
					ObjArray[count_2]->Set_y(ObjArray[count_2]->Get_y() - 840);
				}
				else if (ObjArray[count_2]->Get_y() <= 0) {
					ObjArray[count_2]->Set_y(ObjArray[count_2]->Get_y() + 840);
				}
			}
			ObjArray[count] = new VacantObject;
		}
	}
	for (int count = 14; count < 32; count++) {
		float distance = GetDistance(ObjArray[0]->Get_x(), ObjArray[0]->Get_y(), ObjArray[count]->Get_x(), ObjArray[count]->Get_y());
		float allowedDistance = (ObjArray[0]->Get_radius() + ObjArray[count]->Get_radius());
		if (distance < allowedDistance) {
			ObjArray[0]->Set_x(510);
			ObjArray[0]->Set_y(420);
			ObjArray[0]->Set_theta(0);
			Lives--;
			ObjArray[count] = new VacantObject;

		}
	}
	//checks for saucers' collision with asteroids
	for (int saucer_count = 30; saucer_count < 32; saucer_count++) {
		for (int count = 2; count < 14; count++) {
			float distance = GetDistance(ObjArray[saucer_count]->Get_x(), ObjArray[saucer_count]->Get_y(), ObjArray[count]->Get_x(), ObjArray[count]->Get_y());
			float allowedDistance = (ObjArray[saucer_count]->Get_radius() + ObjArray[count]->Get_radius());
			if (distance < allowedDistance) {
				int first_asteroid_segment_position = (count * 2) + 2;
				for (int count_2 = first_asteroid_segment_position; count_2 <= first_asteroid_segment_position + 1; count_2++) {
					ObjArray[count_2]->Set_x(ObjArray[count]->Get_x() + (50 * sin(GetRandInRange(0, 7))));
					if (ObjArray[count_2]->Get_x() >= 1020) {
						ObjArray[count_2]->Set_x(ObjArray[count_2]->Get_x() - 1020);
					}
					else if (ObjArray[count_2]->Get_x() <= 0) {
						ObjArray[count_2]->Set_x(ObjArray[count_2]->Get_x() + 1020);
					}
					ObjArray[count_2]->Set_y(ObjArray[count]->Get_y() + (50 * cos(GetRandInRange(0, 7))));
					if (ObjArray[count_2]->Get_y() >= 840) {
						ObjArray[count_2]->Set_y(ObjArray[count_2]->Get_y() - 840);
					}
					else if (ObjArray[count_2]->Get_y() <= 0) {
						ObjArray[count_2]->Set_y(ObjArray[count_2]->Get_y() + 840);
					}
				}
				ObjArray[count] = new VacantObject;
				ObjArray[saucer_count] = new VacantObject;
			}
		}
		for (int count = 14; count < 30; count++) {
			float distance = GetDistance(ObjArray[saucer_count]->Get_x(), ObjArray[saucer_count]->Get_y(), ObjArray[count]->Get_x(), ObjArray[count]->Get_y());
			float allowedDistance = (ObjArray[saucer_count]->Get_radius() + ObjArray[count]->Get_radius());
			if (distance < allowedDistance) {
				ObjArray[count] = new VacantObject;
				ObjArray[saucer_count] = new VacantObject;
			}
		}
	}
	//checks for Spaceship's bomb collision with asteroids and saucers
	for (int count = 2; count < 6; count++) {
		float distance = GetDistance(ObjArray[1]->Get_x(), ObjArray[1]->Get_y(), ObjArray[count]->Get_x(), ObjArray[count]->Get_y());
		float allowedDistance = (ObjArray[1]->Get_radius() + ObjArray[count]->Get_radius());
		if (distance < allowedDistance) {
			ObjArray[1]->Set_x(-1500);
			ObjArray[1]->Set_y(-1500);
			Score += 10;
			LifeIncrementPoints += 10;
			int first_asteroid_segment_position = (count * 2) + 2;
			for (int count_2 = first_asteroid_segment_position; count_2 <= first_asteroid_segment_position + 1; count_2++) {
				ObjArray[count_2]->Set_x(ObjArray[count]->Get_x() + (50 * sin(GetRandInRange(0, 7))));
				if (ObjArray[count_2]->Get_x() >= 1020) {
					ObjArray[count_2]->Set_x(ObjArray[count_2]->Get_x() - 1020);
				}
				else if (ObjArray[count_2]->Get_x() <= 0) {
					ObjArray[count_2]->Set_x(ObjArray[count_2]->Get_x() + 1020);
				}
				ObjArray[count_2]->Set_y(ObjArray[count]->Get_y() + (50 * cos(GetRandInRange(0, 7))));
				if (ObjArray[count_2]->Get_y() >= 840) {
					ObjArray[count_2]->Set_y(ObjArray[count_2]->Get_y() - 840);
				}
				else if (ObjArray[count_2]->Get_y() <= 0) {
					ObjArray[count_2]->Set_y(ObjArray[count_2]->Get_y() + 840);
				}
			}
			ObjArray[count] = new VacantObject;
		}
	}
	for (int count = 6; count < 14; count++) {
		float distance = GetDistance(ObjArray[1]->Get_x(), ObjArray[1]->Get_y(), ObjArray[count]->Get_x(), ObjArray[count]->Get_y());
		float allowedDistance = (ObjArray[1]->Get_radius() + ObjArray[count]->Get_radius());
		if (distance < allowedDistance) {
			ObjArray[1]->Set_x(-1500);
			ObjArray[1]->Set_y(-1500);
			Score += 20;
			LifeIncrementPoints += 20;
			int first_asteroid_segment_position = (count * 2) + 2;
			for (int count_2 = first_asteroid_segment_position; count_2 <= first_asteroid_segment_position + 1; count_2++) {
				ObjArray[count_2]->Set_x(ObjArray[count]->Get_x() + (50 * sin(GetRandInRange(0, 7))));
				if (ObjArray[count_2]->Get_x() >= 1020) {
					ObjArray[count_2]->Set_x(ObjArray[count_2]->Get_x() - 1020);
				}
				else if (ObjArray[count_2]->Get_x() <= 0) {
					ObjArray[count_2]->Set_x(ObjArray[count_2]->Get_x() + 1020);
				}
				ObjArray[count_2]->Set_y(ObjArray[count]->Get_y() + (50 * cos(GetRandInRange(0, 7))));
				if (ObjArray[count_2]->Get_y() >= 840) {
					ObjArray[count_2]->Set_y(ObjArray[count_2]->Get_y() - 840);
				}
				else if (ObjArray[count_2]->Get_y() <= 0) {
					ObjArray[count_2]->Set_y(ObjArray[count_2]->Get_y() + 840);
				}
			}
			ObjArray[count] = new VacantObject;
		}
	}
	for (int count = 14; count < 30; count++) {
		float distance = GetDistance(ObjArray[1]->Get_x(), ObjArray[1]->Get_y(), ObjArray[count]->Get_x(), ObjArray[count]->Get_y());
		float allowedDistance = (ObjArray[1]->Get_radius() + ObjArray[count]->Get_radius());
		if (distance < allowedDistance) {
			ObjArray[count] = new VacantObject;
			ObjArray[1]->Set_x(-1500);
			ObjArray[1]->Set_y(-1500);
			Score += 40;
			LifeIncrementPoints += 40;
		}
	}
	float distance = GetDistance(ObjArray[1]->Get_x(), ObjArray[1]->Get_y(), ObjArray[30]->Get_x(), ObjArray[30]->Get_y());
	float allowedDistance = (ObjArray[1]->Get_radius() + ObjArray[30]->Get_radius());
	if (distance < allowedDistance) {
		ObjArray[30] = new VacantObject;
		ObjArray[1]->Set_x(-1500);
		ObjArray[1]->Set_y(-1500);
		Score += 100;
		LifeIncrementPoints += 100;
	}
	distance = GetDistance(ObjArray[1]->Get_x(), ObjArray[1]->Get_y(), ObjArray[31]->Get_x(), ObjArray[31]->Get_y());
	allowedDistance = (ObjArray[1]->Get_radius() + ObjArray[31]->Get_radius());
	if (distance < allowedDistance) {
		ObjArray[31] = new VacantObject;
		ObjArray[1]->Set_x(-1500);
		ObjArray[1]->Set_y(-1500);
		Score += 400;
		LifeIncrementPoints += 500;
	}
	//checks for saucers' bomb's collision with spaceship and asteroids
	for (int bomb_count = 32; bomb_count < 34; bomb_count++) {
		if (ObjArray[bomb_count - 2]->Get_dead() == 0) {
			if (ObjArray[bomb_count - 2]->Get_x() <= 1025 && ObjArray[bomb_count - 2]->Get_x() >= -5 && ObjArray[bomb_count - 2]->Get_y() <= 845 && ObjArray[bomb_count - 2]->Get_y() >= -5) {
				for (int count = 2; count < 14; count++) {
					float distance = GetDistance(ObjArray[bomb_count]->Get_x(), ObjArray[bomb_count]->Get_y(), ObjArray[count]->Get_x(), ObjArray[count]->Get_y());
					float allowedDistance = (ObjArray[bomb_count]->Get_radius() + ObjArray[count]->Get_radius());
					if (distance < allowedDistance) {
						ObjArray[bomb_count]->Set_x(-1500);
						ObjArray[bomb_count]->Set_y(-1500);
						int first_asteroid_segment_position = (count * 2) + 2;
						for (int count_2 = first_asteroid_segment_position; count_2 <= first_asteroid_segment_position + 1; count_2++) {
							ObjArray[count_2]->Set_x(ObjArray[count]->Get_x() + (50 * sin(GetRandInRange(0, 7))));
							if (ObjArray[count_2]->Get_x() >= 1020) {
								ObjArray[count_2]->Set_x(ObjArray[count_2]->Get_x() - 1020);
							}
							else if (ObjArray[count_2]->Get_x() <= 0) {
								ObjArray[count_2]->Set_x(ObjArray[count_2]->Get_x() + 1020);
							}
							ObjArray[count_2]->Set_y(ObjArray[count]->Get_y() + (50 * cos(GetRandInRange(0, 7))));
							if (ObjArray[count_2]->Get_y() >= 840) {
								ObjArray[count_2]->Set_y(ObjArray[count_2]->Get_y() - 840);
							}
							else if (ObjArray[count_2]->Get_y() <= 0) {
								ObjArray[count_2]->Set_y(ObjArray[count_2]->Get_y() + 840);
							}
						}
						ObjArray[count] = new VacantObject;
					}
				}
				for (int count = 14; count < 30; count++) {
					float distance = GetDistance(ObjArray[bomb_count]->Get_x(), ObjArray[bomb_count]->Get_y(), ObjArray[count]->Get_x(), ObjArray[count]->Get_y());
					float allowedDistance = (ObjArray[bomb_count]->Get_radius() + ObjArray[count]->Get_radius());
					if (distance < allowedDistance) {
						ObjArray[count] = new VacantObject;
						ObjArray[bomb_count]->Set_x(-1500);
						ObjArray[bomb_count]->Set_y(-1500);
					}
				}
				float distance = GetDistance(ObjArray[bomb_count]->Get_x(), ObjArray[bomb_count]->Get_y(), ObjArray[0]->Get_x(), ObjArray[0]->Get_y());
				float allowedDistance = (ObjArray[bomb_count]->Get_radius() + ObjArray[0]->Get_radius());
				if (distance < allowedDistance) {
					ObjArray[0]->Set_x(510);
					ObjArray[0]->Set_y(420);
					ObjArray[0]->Set_theta(0);
					Lives--;
					ObjArray[bomb_count] = new VacantObject;
				}
			}
		}
	}
}
void Board::DisplayGameOver()
{
	float greypointer[3];
	greypointer[0] = 0.5;
	greypointer[1] = 0.5;
	greypointer[2] = 0.5;
	DrawString(440, 420, " Game Over", greypointer);
	DrawString(425, 390, " Your Score : ", greypointer);
	DrawString(560, 390, std::to_string(Score), greypointer);
	DrawString(415, 360, " Press R to restart", greypointer);
}
void Board::GenerateAndShootSaucers()
{
	if (ObjArray[BigSaucerGenerationPoint]->Get_dead() == 1) {
		ObjArray[30] = new BigSaucer;
		BigSaucerGenerationPoint = 0;
	}
	BigSaucerShoot++;
	if (ObjArray[30]->Get_dead() == 0) {
		if (ObjArray[30]->Get_x() <= 1025 && ObjArray[30]->Get_x() >= -5 && ObjArray[30]->Get_y() <= 845 && ObjArray[30]->Get_y() >= -5) {
			if (BigSaucerShoot >= 600) {
				ObjArray[32] = new Bomb;
				ObjArray[32]->Set_x(ObjArray[30]->Get_x());
				ObjArray[32]->Set_y(ObjArray[30]->Get_y());
				ObjArray[32]->Set_theta(GetRandInRange(0, 7));
				BigSaucerShoot = 0;
			}
		}
	}
	if (ObjArray[SmallSaucerGenerationPoint]->Get_dead() == 1) {
		ObjArray[31] = new SmallSaucer;
		SmallSaucerGenerationPoint = 0;
	}
	SmallSaucerShoot++;
	if (ObjArray[31]->Get_dead() == 0) {
		if (ObjArray[31]->Get_x() <= 1025 && ObjArray[31]->Get_x() >= -5 && ObjArray[31]->Get_y() <= 845 && ObjArray[31]->Get_y() >= -5) {
			if (SmallSaucerShoot >= 400) {
				ObjArray[33] = new Bomb;
				ObjArray[33]->Set_x(ObjArray[31]->Get_x());
				ObjArray[33]->Set_y(ObjArray[31]->Get_y());
				ObjArray[33]->Set_theta(GetRandInRange(0, 7));
				SmallSaucerShoot = 0;
			}
		}
	}
}
void Board::IncrementLives()
{
	if (LifeIncrementPoints >= 40000) {
		Lives++;
		LifeIncrementPoints -= 40000;
	}
}
void Board::IncrementLevel()
{
	bool all_enemies_dead = 1;
	for (int count = 2; count < 32; count++) {
		if (ObjArray[count]->Get_dead() == 0) {
			all_enemies_dead = 0;
		}
	}
	if (all_enemies_dead == 1) {
		Level++;
		InitalizeBoard(0, 0, Level);
	}
}
void Board::RotateShipLeft()
{
	if (Lives > 0) {
		ObjArray[0]->Move(0, -0.1);
	}
}
void Board::RotateShipRight()
{
	if (Lives > 0) {
		ObjArray[0]->Move(0, 0.1);
	}
}
void Board::MoveShipForward()
{
	if (Lives > 0) {
		ObjArray[0]->Move(100 * (GameSpeed));
	}
}
void Board::ShootBomb()
{
	if (Lives > 0) {
		ObjArray[1]->Set_x(ObjArray[0]->Get_x() + (21 * sin(ObjArray[0]->Get_theta())));
		ObjArray[1]->Set_y(ObjArray[0]->Get_y() + (21 * cos(ObjArray[0]->Get_theta())));
		ObjArray[1]->Set_theta(ObjArray[0]->Get_theta());
	}
}
void Board::HyperSpaceShip()
{
	if (Lives > 0) {
		ObjArray[0]->Move(GetRandInRange(50, 1500), GetRandInRange(0, 7));
	}
}
void Board::RestartGame()
{
	if (Lives <= 0) {
		Level = 1;
		InitalizeBoard(1020, 840, Level);
		glutPostRedisplay();
	}
}

