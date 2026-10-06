#ifndef LUA_ENGINE_H
#define LUA_ENGINE_H

#include <string.h>


int l_create_window(lua_State *L){

	luaL_newmetatable(L, "window");


	window *w = lua_newuserdata(L, sizeof(window));
	memset(w, 0, sizeof(*w));


		const char *title = luaL_checkstring(L, 1);

		int title_length = strlen(title) + 1;
		w->title = malloc(title_length);
		if (w->title) memcpy(w->title, title, title_length);

		w->w=luaL_checkinteger(L, 2);
		w->h=luaL_checkinteger(L, 3);


	create_window(w);

	luaL_setmetatable(L, "window");
	return 1;
}



int l_select_window(lua_State *L){
	selected_window = luaL_checkudata(L, 1, "window");
	return 1;
}


int l_set_window_scale(lua_State *L){
	set_window_scale(luaL_checknumber(L,1));
	return 1;
}


int l_update_window(lua_State *L){
	update_window(luaL_checkudata(L, 1, "window"));
	return 1;
}

int l_toggle_fullscreen(lua_State *L){
	toggle_fullscreen();
	return 1;
}





int l_end_frame(lua_State *L){
	end_frame();
	return 1;
}

#endif
