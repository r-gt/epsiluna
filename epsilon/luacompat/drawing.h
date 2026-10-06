#ifndef LUA_DRAWING_H
#define LUA_DRAWING_H

int l_create_texture(lua_State *L){
	const char *path = luaL_checkstring(L, 1);

	texture *t = create_texture(path);
	if (!t) return luaL_error(L, "could not load texture '%s'", path);

	texture **ud = lua_newuserdata(L, sizeof(texture *));
	*ud = t;

	luaL_setmetatable(L, "texture");
	return 1;
}

int l_select_texture(lua_State *L){
	texture **ud = luaL_checkudata(L, 1, "texture");
	selected_texture = *ud;
	return 0;
}

int l_draw_texture(lua_State *L){
	draw_texture( luaL_checkinteger(L,1), luaL_checkinteger(L,2) );
	return 1;
}

int l_destroy_texture(){
	destroy_texture();
	return 1;
}


int l_set_scale(lua_State *L){
	set_scale( luaL_checkinteger(L,1), luaL_checkinteger(L,2) );
	return 1;
}


int l_set_mask(lua_State *L){
	set_mask( luaL_checkinteger(L,1), luaL_checkinteger(L,2),
			  luaL_checkinteger(L,3), luaL_checkinteger(L,4)
			  );
	return 1;
}


int l_set_origin(lua_State *L){
	set_origin( luaL_checkinteger(L,1), luaL_checkinteger(L,2) );
	return 1;
}




int l_draw_line(lua_State *L){
	draw_line( luaL_checkinteger(L,1), luaL_checkinteger(L,2),
			   luaL_checkinteger(L,3), luaL_checkinteger(L,4));
	return 1;
}

int l_draw_rect(lua_State *L){
	draw_rect( luaL_checkinteger(L,1), luaL_checkinteger(L,2),
			   luaL_checkinteger(L,3), luaL_checkinteger(L,4));
	return 1;
}

int l_draw_pixel(lua_State *L){
	draw_pixel( luaL_checkinteger(L,1), luaL_checkinteger(L,2));
	return 1;
}


int l_draw_polygon(lua_State *L){
	draw_polygon(   luaL_checkinteger(L,1), luaL_checkinteger(L,2),
                    luaL_checkinteger(L,3), luaL_checkinteger(L,4),
                    luaL_checkinteger(L,5), luaL_checkinteger(L,6));
	return 1;
}


int l_render(){
	render();
	return 1;
}


int l_set_render_color(lua_State *L){
	set_render_color(luaL_checkinteger(L,1));

	return 1;
}

int l_set_texture_color(lua_State *L){
	set_texture_color(luaL_checkinteger(L,1));
	return 1;
}



int l_clear_screen(){
	clear_screen();
	return 1;

}



#endif
