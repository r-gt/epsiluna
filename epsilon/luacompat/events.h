#ifndef LUA_EVENTS_H
#define LUA_EVENTS_H



int l_key_is_pressed(lua_State *L){
	lua_pushboolean(L, key_is_pressed(luaL_checkstring(L, 1)));
	return 1;
}

int l_key_just_pressed(lua_State *L){
	lua_pushboolean(L, key_just_pressed(luaL_checkstring(L, 1)));
	return 1;
}


int l_key_just_released(lua_State *L){
	lua_pushboolean(L, key_just_released(luaL_checkstring(L, 1)));
	return 1;
}

int l_mouse_x(lua_State *L){
	lua_pushinteger(L, mouse_x());
	return 1;
}

int l_mouse_y(lua_State *L){
	lua_pushinteger(L, mouse_y());
	return 1;
}


int l_check_close_button(lua_State *L){

	check_close_button();

	lua_pushnumber(L, delta_time);
	lua_setglobal(L, "delta_time");

	if (!running) {
		lua_pushboolean(L, 0);
		lua_setglobal(L, "running");

	}
	return 1;
}

int l_mouse_button_is_pressed(lua_State *L){
	mouse_button_is_pressed(luaL_checkstring(L, 1));
}



#endif
