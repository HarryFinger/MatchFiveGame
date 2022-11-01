#pragma once
#include <SFML/Graphics.hpp>
#include "FieldElementType.h"
#include "SoundManager.h"

extern const uint32_t WINDOW_SIZE;
extern const uint32_t TILE_SIZE;
extern const uint32_t GRID_NUMBER;
extern const uint32_t WALL_OFFSET;

using namespace sf;

class Selector
{
public:
	FieldElementType chip_type = FieldElementType::Empty;
	Texture texture;
	Sprite sprite; //selector sprite
	Sprite chip_sprite; //chip sprite if picked
	bool is_selected = false;
	uint32_t x = 400; //current position x
	uint32_t y = 500; //current position y

private:
	const float MIN_BLINK_THRESHOLD = 30.f;
	const float MAX_BLINK_THRESHOLD = 250.f;
	Clock blink_clock;
	uint32_t blink = 255;
	const uint32_t BLINK_SPEED = 1;
	enum BlinkState
	{
		Falling,
		Growing
	} blink_state = BlinkState::Falling;

public:
	Selector();
	void DrawSelector(RenderWindow&);
	void MoveSelector(const int&, const int&);
private:
	void SelectorBlink();

};