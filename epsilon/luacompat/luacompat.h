#ifndef LUACOMPAT_H
#define LUACOMPAT_H


#include "engine.h"
#include "events.h"
#include "drawing.h"
#include "audio.h"
#include "font.h"
#include "extra/goodies.h"
#include "extra/easelib.h"
#include "extra/maploader.h"

#include "demo.h"

void bind_lua(){

	//
	//  engine.h
	//

	luaL_newmetatable(L, "texture");
	luaL_newmetatable(L, "audio");
	luaL_newmetatable(L, "map");

	lua_register(L, "create_window", l_create_window);
	lua_register(L, "select_window", l_select_window);
	lua_register(L, "set_window_scale", l_set_window_scale);
	lua_register(L, "update_window", l_update_window);
	lua_register(L, "toggle_fullscreen", l_toggle_fullscreen);

	lua_register(L, "end_frame", l_end_frame);



	//
	//  events.h
	//

	lua_pushboolean(L, 1);
	lua_setglobal(L, "running");
	lua_setglobal(L, "delta_time");

	lua_register(L, "key_is_pressed",          l_key_is_pressed);
	lua_register(L, "key_just_pressed",        l_key_just_pressed);
	lua_register(L, "key_just_released",       l_key_just_released);
	lua_register(L, "mouse_x",                 l_mouse_x);
	lua_register(L, "mouse_y",                 l_mouse_y);
	lua_register(L,"mouse_button_is_pressed",  l_mouse_button_is_pressed);
	lua_register(L, "check_close_button",      l_check_close_button);



	//
	//  drawing.h
	//

	lua_register(L, "create_texture",    l_create_texture);
	lua_register(L, "draw_texture",      l_draw_texture);

	lua_register(L, "select_texture",    l_select_texture);

	lua_register(L, "destroy_texture",   l_destroy_texture);
	lua_register(L, "set_scale",         l_set_scale);
	lua_register(L, "set_mask",          l_set_mask);
	lua_register(L, "set_origin",        l_set_origin);
	lua_register(L, "draw_line",         l_draw_line);
	lua_register(L, "draw_rect",         l_draw_rect);
	lua_register(L, "draw_pixel",        l_draw_pixel);
	lua_register(L, "draw_polygon",      l_draw_polygon);

	lua_register(L, "render",            l_render);

	lua_register(L, "set_render_color",  l_set_render_color);
	lua_register(L, "set_texture_color", l_set_texture_color);

	lua_register(L, "clear_screen",      l_clear_screen);



	//
	//  audio.h
	//

	lua_register(L, "create_audio",   l_create_audio);
	lua_register(L, "select_audio",   l_select_audio);
	lua_register(L, "play_audio",     l_play_audio);
	lua_register(L, "stop_audio",     l_stop_audio);
	lua_register(L, "resume_audio",   l_resume_audio);
	lua_register(L, "set_speed",      l_set_speed);
	lua_register(L, "set_volume",     l_set_volume);
	lua_register(L, "unload_audio",   l_unload_audio);

	lua_register(L, "is_playing",     l_is_playing);



	//
	//  font.h
	//

	lua_register(L, "create_font", l_create_font);
	lua_register(L, "select_font", l_select_font);
	lua_register(L, "set_font_scale", l_set_font_scale);
	lua_register(L, "draw_text", l_draw_text);
	lua_register(L, "destroy_font", l_destroy_font);



	//
	//   goodies.h
	//

	lua_pushnumber(L, deg);
	lua_setglobal(L, "deg");

	lua_pushnumber(L, rad);
	lua_setglobal(L, "rad");

	lua_pushnumber(L, tau);
	lua_setglobal(L, "tau");

	lua_pushnumber(L, euler);
	lua_setglobal(L, "euler");

	lua_pushnumber(L, golden);
	lua_setglobal(L, "golden");

	lua_pushnumber(L, pythagoras);
	lua_setglobal(L, "pythagoras");

	lua_register(L, "wrap", l_wrap);
	lua_register(L, "point_in_circle", l_point_in_circle);
	lua_register(L, "circle_in_circle", l_circle_in_circle);
	lua_register(L, "point_in_box", l_point_in_box);
	lua_register(L, "box_in_box", l_box_in_box);




	//
	//  easelib.h
	//

	lua_pushnumber(L, NONE);
	lua_setglobal(L, "NONE");

	lua_pushnumber(L, LINEAR);
	lua_setglobal(L, "LINEAR");

	lua_pushnumber(L, SINE);
	lua_setglobal(L, "SINE");

	lua_pushnumber(L, CUBIC);
	lua_setglobal(L, "CUBIC");

	lua_pushnumber(L, QUINT);
	lua_setglobal(L, "QUINT");

	lua_pushnumber(L, CIRC);
	lua_setglobal(L, "CIRC");

	lua_pushnumber(L, ELASTIC);
	lua_setglobal(L, "ELASTIC");

	lua_pushnumber(L, QUAD);
	lua_setglobal(L, "QUAD");

	lua_pushnumber(L, QUART);
	lua_setglobal(L, "QUART");

	lua_pushnumber(L, EXPO);
	lua_setglobal(L, "EXPO");

	lua_pushnumber(L, BACK);
	lua_setglobal(L, "BACK");

	lua_pushnumber(L, BOUNCE);
	lua_setglobal(L, "BOUNCE");

	lua_register(L, "ease", l_ease);



	//
	// maploader.h
	//

	lua_register(L, "create_map", l_create_map);
	lua_register(L, "select_map", l_select_map);
	lua_register(L, "get_tile_map", l_get_tile_map);
	lua_register(L, "set_tile_map", l_set_tile_map);
	lua_register(L, "destroy_map", l_destroy_map);

}

#endif
