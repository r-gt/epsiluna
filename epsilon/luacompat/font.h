#ifndef LUA_FONT_H
#define LUA_FONT_H


int l_create_font(lua_State *L){
	const char *path = luaL_checkstring(L, 1);
	int size = luaL_checkinteger(L, 2);

	font *t = create_font(path, size);
	if (!t) return luaL_error(L, "could not load font '%s'", path);

	font **ud = lua_newuserdata(L, sizeof(font *));
	*ud = t;

	luaL_setmetatable(L, "font");
	return 1;
}


int l_select_font(lua_State *L){
	font **ud = luaL_checkudata(L, 1, "font");
	selected_font = *ud;
	return 0;
}


int l_set_font_scale(lua_State *L){
	set_font_scale(luaL_checknumber(L,1));
	return 1;
}

int l_draw_text(lua_State *L){
	draw_text(luaL_checkstring(L,1), luaL_checkinteger(L,2), luaL_checkinteger(L,3));
	return 1;
}

int l_destroy_font(lua_State *L){
	destroy_font();
	return 1;
}

#endif
