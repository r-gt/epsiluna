#ifndef LUA_GOODIES_H
#define LUA_GOODIES_H


int l_wrap(lua_State *L){
	lua_pushinteger(L, wrap(luaL_checkinteger(L,1), luaL_checkinteger(L,2) ));
	return 1;
}


int l_point_in_circle(){

	lua_pushboolean(L,
		point_in_circle(
			luaL_checkinteger(L,1), // px
			luaL_checkinteger(L,2), // py
			luaL_checkinteger(L,3), // cx
			luaL_checkinteger(L,4), // cy
			luaL_checkinteger(L,5)  // radious
		)
	);

	return 1;
}


int l_circle_in_circle(){

	lua_pushboolean(L,
		circle_in_circle(
			luaL_checkinteger(L,1), // c1x
			luaL_checkinteger(L,2), // c1y
			luaL_checkinteger(L,3), // c1r
			luaL_checkinteger(L,4), // c2x
			luaL_checkinteger(L,5), // c2y
			luaL_checkinteger(L,6)  // c2r
		)
	);

	return 1;
}


int l_point_in_box(){

	lua_pushboolean(L,
		point_in_box(
			luaL_checkinteger(L,1), // px
			luaL_checkinteger(L,2), // py
			luaL_checkinteger(L,3), // bx
			luaL_checkinteger(L,4), // by
			luaL_checkinteger(L,5), // w
			luaL_checkinteger(L,6)  // h
		)
	);

	return 1;

}


int l_box_in_box(){

	lua_pushboolean(L,
		box_in_box(
			luaL_checkinteger(L, 1), // x1
			luaL_checkinteger(L, 2), // y1
			luaL_checkinteger(L, 3), // w1
			luaL_checkinteger(L, 4), // h1
			luaL_checkinteger(L, 5), // x2
			luaL_checkinteger(L, 6), // y2
			luaL_checkinteger(L, 7), // w2
			luaL_checkinteger(L, 8)  // h2
		)
	);

	return 1;

}


#endif
