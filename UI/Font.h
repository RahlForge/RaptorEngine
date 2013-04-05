/*
 *	Font.h
 */

#pragma once
class Font;
class FontID;

#include "platforms.h"

#include <string>
#include <GLEW/glew.h>
#include <OpenGL/gl.h>
#include <SDL/SDL.h>
#include <SDL_ttf/SDL_ttf.h>
#include "Clock.h"
#include "Pos.h"


class Font
{
public:
	int PointSize;
	bool Initialized;
	
	
	Font( std::string name, int point_size );
	virtual ~Font();
	
	void InitFont( void );
	
	int GetLineSkip( void );
	int GetHeight( void );
	
	void TextSize( std::string text, SDL_Rect *r );
	int TextHeight( std::string text );
	int LineWidth( std::string text );
	void DrawText( std::string text, int x, int y, uint8_t align );
	void DrawText( std::string text, int x, int y, uint8_t align, float r, float g, float b, float a );
	void DrawText( std::string text, SDL_Rect *rect, uint8_t align );
	void DrawText( std::string text, SDL_Rect *rect, uint8_t align, float r, float g, float b, float a );
	void DrawText3D( std::string text, const Pos3D *pos, uint8_t align, double scale = 1. );
	void DrawText3D( std::string text, const Pos3D *pos, uint8_t align, float r, float g, float b, float a, double scale = 1. );
	
	enum
	{
		ALIGN_TOP_LEFT = 0,
		ALIGN_TOP_CENTER,
		ALIGN_TOP_RIGHT,
		ALIGN_MIDDLE_LEFT,
		ALIGN_MIDDLE_CENTER,
		ALIGN_MIDDLE_RIGHT,
		ALIGN_BOTTOM_LEFT,
		ALIGN_BOTTOM_CENTER,
		ALIGN_BOTTOM_RIGHT
	};
	
private:
	struct Glyph
	{
		int MinX, MaxX;
		int MinY, MaxY;
		int Advance;
		SDL_Surface *Pic;
		GLuint Tex;
		GLfloat TexMinX, TexMinY;
		GLfloat TexMaxX, TexMaxY;
	};
	
	int Height;
	int Ascent;
	int Descent;
	int LineSkip;
	struct Glyph Glyphs[ 256 ];
	
	std::string Name;
	TTF_Font *TTFont;
	Clock LoadedTime;
	
	void LoadChar( char c );
};


class FontID
{
public:
	std::string Name;
	int PointSize;
	
	FontID( std::string name, int point_size );
	
	bool operator < ( const FontID &other ) const;
	bool operator == ( const FontID &other ) const;
	bool operator != ( const FontID &other ) const;
};
