#pragma once
#include "../../common_includes.hpp"

enum font_flags {
	fontflag_none,
	fontflag_italic = 0x001,
	fontflag_underline = 0x002,
	fontflag_strikeout = 0x004,
	fontflag_symbol = 0x008,
	fontflag_antialias = 0x010,
	fontflag_gaussianblur = 0x020,
	fontflag_rotary = 0x040,
	fontflag_dropshadow = 0x080,
	fontflag_additive = 0x100,
	fontflag_outline = 0x200,
	fontflag_custom = 0x400,
	fontflag_bitmap = 0x800,
};

namespace render {
	void setup();

	void draw_3d_cube(float scalar, vec3_t angles, vec3_t middle_origin, color outline);
	void draw_line(int x1, int y1, int x2, int y2, color colour);
	void draw_line_fgui(int x1, int y1, int x2, int y2, fgui::color colour);
	void draw_text_wchar(int x, int y, unsigned long font, const wchar_t* string, color colour);
	void draw_text_string(int x, int y, unsigned long font, std::string string, bool text_centered, color colour);
	void drawcustom(int X, int Y, fgui::color Color, int Font, bool Center, const char* _Input, ...);
	void draw_text_string_fgui(int x, int y, unsigned long font, std::string string, bool text_centered, fgui::color colour);
	void draw_rect(int x, int y, int w, int h, color color);
	void draw_rect_fgui(int x, int y, int w, int h, fgui::color color);
	void draw_filled_rect(int x, int y, int w, int h, color colour);
	void draw_gradient_rect(int x, int y, int w, int h, color colour, color colour2, bool is_horizontal);
	void draw_outline(int x, int y, int w, int h, color colour);
	void draw_outline_fgui(int x, int y, int w, int h, fgui::color colour);
	void draw_textured_polygon(int n, fgui::vertex* vertice, color col);
	void draw_circle(int x, int y, int r, int s, color col);
	void get_text_size(unsigned long font, std::string string, int w, int h);

	namespace fonts {
		extern unsigned long watermark_font;
		extern unsigned long kill_font;
		extern unsigned long esp_font;
		extern unsigned long hp_font;
		extern unsigned long weapon_font;
		extern unsigned long name_font;
		extern unsigned long name_font_big;
		extern unsigned long esfirrafont;
		extern unsigned long speedfont2;
		extern unsigned long font_kz;
		extern unsigned long keystroke;
		extern unsigned long backspace;
		extern unsigned long menu_font;
	}

}